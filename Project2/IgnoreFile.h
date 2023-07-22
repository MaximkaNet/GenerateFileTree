#pragma once
#include <string>
using std::string;

struct IgnoreFilename
{
	string stem; // file name
	string extension; // extension of file
	IgnoreFilename();
	IgnoreFilename(string stem);
	IgnoreFilename(string stem, string extension);
	IgnoreFilename(const IgnoreFilename& obj);

	string filename();
};

