#pragma once
#include <string>
using std::wstring;

struct IgnoreFilename
{
	wstring stem; // file name
	wstring extension; // extension of file
	IgnoreFilename();
	IgnoreFilename(wstring stem);
	IgnoreFilename(wstring stem, wstring extension);
	IgnoreFilename(const IgnoreFilename& obj);

	wstring filename();
};

