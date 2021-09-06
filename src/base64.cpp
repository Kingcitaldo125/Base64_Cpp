#include <bitset>
#include <map>
#include <sstream>

// TBD: Remove - only for debugging/testing
#include <iostream>

using std::cout;
using std::endl;

#include "base64.h"

static std::map<std::string, std::string> mmap_encode
{
{"000000","A"},{"000001","B"},{"000010","C"},{"000011","D"},
{"000100","E"},{"000101","F"},{"000110","G"},{"000111","H"},
{"001000","I"},{"001001","J"},{"001010","K"},{"001011","L"},
{"001100","M"},{"001101","N"},{"001110","O"},{"001111","P"},
{"010000","Q"},{"010001","R"},{"010010","S"},{"010011","T"},
{"010100","U"},{"010101","V"},{"010110","W"},{"010111","X"},
{"011000","Y"},{"011001","Z"},{"011010","a"},{"011011","b"},
{"011100","c"},{"011101","d"},{"011110","e"},{"011111","f"},
{"100000","g"},{"100001","h"},{"100010","i"},{"100011","j"},
{"100100","k"},{"100101","l"},{"100110","m"},{"100111","n"},
{"101000","o"},{"101001","p"},{"101010","q"},{"101011","r"},
{"101100","s"},{"101101","t"},{"101110","u"},{"101111","v"},
{"110000","w"},{"110001","x"},{"110010","y"},{"110011","z"},
{"110100","0"},{"110101","1"},{"110110","2"},{"110111","3"},
{"111000","4"},{"111001","5"},{"111010","6"},{"111011","7"},
{"111100","8"},{"111101","9"},{"111110","+"},{"111111","/"}
};

static std::map<std::string, std::string> mmap_decode
{
{"A","000000"},{"B","000001"},{"C","000010"},{"D","000011"},
{"E","000100"},{"F","000101"},{"G","000110"},{"H","000111"},
{"I","001000"},{"J","001001"},{"K","001010"},{"L","001011"},
{"M","001100"},{"N","001101"},{"O","001110"},{"P","001111"},
{"Q","010000"},{"R","010001"},{"S","010010"},{"T","010011"},
{"U","010100"},{"V","010101"},{"W","010110"},{"X","010111"},
{"Y","011000"},{"Z","011001"},{"a","011010"},{"b","011011"},
{"c","011100"},{"d","011101"},{"e","011110"},{"f","011111"},
{"g","100000"},{"h","100001"},{"i","100010"},{"j","100011"},
{"k","100100"},{"l","100101"},{"m","100110"},{"n","100111"},
{"o","101000"},{"p","101001"},{"q","101010"},{"r","101011"},
{"s","101100"},{"t","101101"},{"u","101110"},{"v","101111"},
{"w","110000"},{"x","110001"},{"y","110010"},{"z","110011"},
{"0","110100"},{"1","110101"},{"2","110110"},{"3","110111"},
{"4","111000"},{"5","111001"},{"6","111010"},{"7","111011"},
{"8","111100"},{"9","111101"},{"+","111110"},{"/","111111"}
};

std::string get_bytes(const std::string& asdf)
{
	std::string bytes;
	for (auto& i : asdf)
	{
		short v = i;
		std::bitset<8> bits(v);
		bytes += bits.to_string();
	}

	return bytes;
}

std::string base64encode(const std::string& conv)
{
	if (conv.size() == 0)
		return "";

	// Convert the input string into a byte array
	// processing/lookups on the byte representation of the input
	// will be done to convert the ascii to base64
	auto bytes = get_bytes(conv);

	while (1)
	{
		// Insert extra bits if the size is not already a multiple of six
		// six-bytes chunks are needed in order to do lookups in the encoding
		// set
		if (bytes.size() % 6 == 0)
			break;
		bytes += '0';
	}

	// Calculate the number of pads that will be present in the encoded string
	// If the length of the input is a multiple of three, we won't have any
	// additional characters (pads) to take into account;
	// otherwise, we can count the number of bytes that lie between the current
	// input size, and a multiple of three, to calculate the padding for the
	// encoded string
	short pads = 0;
	{
		unsigned long x_len = static_cast<unsigned long>(conv.size());
		while (1)
		{
			if (x_len % 3 == 0)
				break;
			++x_len;
			++pads;
		}
	}

	// Perform lookups in the encoding table to get the base64 character for each
	// truncated byte representing a char in the input
	// The first six bits, in the input char, are processed while the
	// remaining two bits are processed during the next pass/iteration
	std::string n_str;
	int i = 0;
	while(1)
	{
		if (i >= bytes.size())
			break;
		auto subs = bytes.substr(i, 6);
		n_str += mmap_encode[subs];
		i += 6;
	}

	// Insert padding, if necessary
	for (i = 0; i < pads; ++i)
	{
		n_str += "=";
	}

	return n_str;
}

std::string base64decode(const std::string& conv)
{
	if(conv.size() <= 1)
		return "INVALID";

	// Store the decoded byte
	std::bitset<8> decoded_bits;

	// Store any remaining, encoded, bits for a subsequent pass
	std::bitset<4> bitbucket;
	int bbucket_count = 0;

	std::stringstream ss;

	for(auto& chr : conv)
	{
		std::string chr_str(1, chr);

		// Should not have to process padding chars
		if(chr_str == "=")
			continue;

		std::bitset<6> base64_bits(mmap_decode[chr_str]);

		cout << "Processing: " << chr << endl;
		cout << (decoded_bits.any() ? "Bits in decoded" : "No bits in decoded") << endl;
		cout << (bitbucket.any() ? "Bits in bitbucket" : "No bits in bitbucket") << endl;

		// If there are bits in the general container, use those to decode
		if (decoded_bits.any())
		{
			decoded_bits.set(1, base64_bits[5]);
			decoded_bits.set(0, base64_bits[4]);

			char n_chr = decoded_bits.to_ulong() & 0xFF;
			cout << "(decoded_bits.any) Pushing '" << n_chr << "'" << endl;
			ss << n_chr;

			// Set the remaining 4 bits for the next pass
			bitbucket.set(3, base64_bits[3]);
			bitbucket.set(2, base64_bits[2]);
			bitbucket.set(1, base64_bits[1]);
			bitbucket.set(0, base64_bits[0]);

			bbucket_count = 4;

			decoded_bits.reset();
		}
		// If there aren't bits in the primary bit container, check the bitbucket
		else if(bitbucket.any())
		{
			/**/
			cout << "base64 bits" << "\n";
			for(int i = 0; i < 6; ++i)
				cout << i << "," << base64_bits[i] << "\n";
			/**/
			/**/
			cout << "bitbucket" << "\n";
			for(int i = 0; i < 4; ++i)
				cout << i << "," << bitbucket[i] << "\n";
			/**/

			cout << "bits" << "\n";
			int decoded_index = 7;
			for(int i = 3; i > 3-bbucket_count; --i)
			{
				cout << decoded_index << "," << i << "\n";
				decoded_bits.set(decoded_index, bitbucket[i]);
				--decoded_index;
			}

			cout << "decoded:\n";
			cout << "bbucket_count: " << bbucket_count << "\n";
			cout << "decoded_index: " << decoded_index << "\n";
			/**/
			for(int j = decoded_index + (bbucket_count - 2); decoded_index >= 0; --decoded_index, --j)
			{
				cout << decoded_index << "," << j << "\n";
				decoded_bits.set(decoded_index, base64_bits[j]);
			}
			/**/

			/*
			decoded_bits.set(3, base64_bits[5]);
			decoded_bits.set(2, base64_bits[4]);
			decoded_bits.set(1, base64_bits[3]);
			decoded_bits.set(0, base64_bits[2]);
			*/

			/**/
			cout << "decoded_bits" << "\n";
			for(int i = 0; i < 8; ++i)
				cout << decoded_bits[i] << "\n";
			/**/

			char n_chr = decoded_bits.to_ulong() & 0xFF;
			cout << "(bitbucket.any) Pushing '" << n_chr << "'" << endl;
			ss << n_chr;

			decoded_bits.reset();
			bitbucket.reset();
			bbucket_count = 0;

			// There should be two additional bits that are lingering - store those
			bitbucket.set(3, base64_bits[1]);
			bitbucket.set(2, base64_bits[0]);
			bbucket_count = 2;
		}
		else // store the contents of the base64 bits, and continue
		{
			cout << "Setting decoded bits to Base64 bits\n";
			decoded_bits.set(7, base64_bits[5]);
			decoded_bits.set(6, base64_bits[4]);
			decoded_bits.set(5, base64_bits[3]);
			decoded_bits.set(4, base64_bits[2]);
			decoded_bits.set(3, base64_bits[1]);
			decoded_bits.set(2, base64_bits[0]);
		}

		cout << "\n";
	}

	return ss.str();
}
