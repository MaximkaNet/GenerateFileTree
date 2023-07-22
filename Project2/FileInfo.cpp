#include "FileInfo.h"

FileInfo::FileInfo() { _size = 0; }
FileInfo::FileInfo(string filename, string stem, string extension, uintmax_t size) {
	this->_filename = filename;
	this->_stem = stem;
	this->_extension = extension;
	this->_size = size;
}
FileInfo::FileInfo(const FileInfo& obj) {
	_filename = obj._filename;
	_stem = obj._stem;
	_extension = obj._extension;
	_size = obj._size;
}

ostream& FileInfo::operator<< (ostream& out) {
	out << _filename;
	return out;
}

void FileInfo::show(int col_width) {
	cout << _filename << " ";
	double dsize = _size;

	if (_size < 1024) {
		cout << _size << " " << "B";
		return;
	}

	dsize /= 1024;
	if (dsize < 1024) {
		cout << (round(dsize * 100) / 100) << " " << "kB";
		return;
	}

	dsize /= 1024;
	if (dsize < 1024) {
		cout << (round(dsize * 100) / 100) << " " << "MB";
		return;
	}

	dsize /= 1024;
	if (dsize < 1024) {
		cout << (round(dsize * 100) / 100) << " " << "GB";
		return;
	}

	dsize /= 1024;
	if (dsize < 1024) {
		cout << (round(dsize * 100) / 100) << " " << "TB";
		return;
	}
}
const uintmax_t FileInfo::size() { return _size; }