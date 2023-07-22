#pragma once
#include <string>
#include<iostream>

using std::string;
using std::cout;
using std::ostream;
using std::to_string;
using std::floor;

class FileInfo
{
private:
	string _filename;
	string _stem;
	string _extension;
	uintmax_t _size;
public:
	FileInfo();
	FileInfo(string _Filename, string _Stem, string _Extension, uintmax_t _Size);
	FileInfo(const FileInfo&);

	ostream& operator<< (ostream&);

	void show(int _ColWidth = 5);
	const uintmax_t size();
};

string to_humanic_style(uintmax_t);