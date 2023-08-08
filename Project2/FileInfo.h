#pragma once
#include <string>
#include<iostream>

using std::wstring;
using std::string;
using std::wcout;
using std::wostream;
using std::to_wstring;
using std::to_string;
using std::floor;

class FileInfo
{
private:
	wstring _filename;
	wstring _stem;
	wstring _extension;
	uintmax_t _size;
public:
	FileInfo();
	FileInfo(wstring _Filename, wstring _Stem, wstring _Extension, uintmax_t _Size);
	FileInfo(const FileInfo&);

	wostream& operator<< (wostream&);

	void show(int _ColWidth = 50);

	wstring filename();
	wstring stem();
	wstring extension();

	static string toHumanStyle(uintmax_t _Size);

	uintmax_t size() const;
};