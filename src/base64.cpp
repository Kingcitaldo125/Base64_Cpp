#include <bitset>
#include <vector>
#include <map>
#include <sstream>

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

static std::string get_bytes(const std::string& asdf)
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
	{
		long unsigned int i = 0;
		while(1)
		{
			if (i >= bytes.size())
				break;
			auto subs = bytes.substr(i, 6);
			n_str += mmap_encode[subs];
			i += 6;
		}
	}

	// Insert padding, if necessary
	for (short i = 0; i < pads; ++i)
	{
		n_str += "=";
	}

	return n_str;
}

std::string base64decode(const std::string& conv)
{
	if(conv.size() <= 1 || conv.size() % 4 != 0)
		return "INVALID";

	std::vector<std::bitset<6>> chunks;

	// Build the collection of 'chunks'
	// each chunk is the 6-bit representation of a single base64 encoded character
	for(long unsigned int index = 0; index < conv.size(); index += 4)
	{
		for(long unsigned int encoded_idx = index; encoded_idx < index + 4; ++encoded_idx)
		{
			std::string holdr(1, conv.at(encoded_idx));
			std::string encoded_bytes = holdr == "=" ? "000000" : mmap_decode[holdr];

			// Take the chunk string and trnasfer the bits into the chunk bitset
			std::bitset<6> chunk;
			for(short i = 0; i < 6; ++i)
			{
				chunk.set(i, encoded_bytes[i] == '1' ? 1 : 0);
			}

			// add to the collection of encoded chunks
			chunks.push_back(chunk);
		}
	}

	// Convert the chunks to bytes and write out the decoded byte to the stringstream
	// return after 'all' bytes were written out to the stream
	// Don't write out padding bytes to the stream
	std::stringstream ss;
	std::vector<std::bitset<8>> bytes;
	{
		int i = 0;
		int j = 7;
		std::bitset<8> byte;
		bool got_zero_byte = false;
		for(auto& chunk : chunks)
		{
			if(got_zero_byte)
				break;

			for(short itx = 0; itx < 6; ++itx)
			{
				byte.set(j, chunk[itx]);
				++i;
				--j;

				if(i%8==0)
				{
					if(!byte.to_ulong())
					{
						got_zero_byte = true;
						break;
					}

					bytes.push_back(byte);
					byte.reset();
					i=0;
					j=7;
				}
			}
		}
	}

	// Actually write out the bytes to the stream
	for(auto& byte : bytes)
	{
		ss << static_cast<char>(byte.to_ulong() & 0xFF);
	}

	return ss.str();
}
