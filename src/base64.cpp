#include <iostream>
#include <bitset>
#include <map>

#include "base64.h"

using std::cout;
using std::endl;

static std::map<std::string, std::string> mmap
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

	auto bytes = get_bytes(conv);

	while (1)
	{
		if (bytes.size() % 6 == 0)
			break;
		bytes += '0';
	}

	short pads = 0;
	unsigned long x_len = static_cast<unsigned long>(conv.size());
	while (1)
	{
		if (x_len % 3 == 0)
			break;
		++x_len;
		++pads;
	}

	std::string n_str;
	int i = 0;
	while(1)
	{
		if (i >= bytes.size())
			break;
		auto subs = bytes.substr(i, 6);
		n_str += mmap[subs];
		i += 6;
	}

	for (i = 0; i < pads; ++i)
	{
		n_str += "=";
	}

	return n_str;
}
