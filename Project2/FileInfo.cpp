#include "FileInfo.h"

FileInfo::FileInfo() { _size = 0; }
FileInfo::FileInfo(wstring filename, wstring stem, wstring extension, uintmax_t size) {
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

wostream& FileInfo::operator<< (wostream& out) {
	out << _filename;
	return out;
}

void FileInfo::show(int col_width) {
	int s_offset = col_width - _filename.size();

	if (s_offset < 0)
		wcout << _filename.substr(0, col_width - 3) << wstring(3, '.');
	else
		wcout << _filename << wstring(s_offset, ' ');

	wcout << '\t' << FileInfo::toHumanStyle(_size).c_str();
}
wstring FileInfo::filename()
{
	return this->_filename;
}
wstring FileInfo::stem()
{
	return this->_stem;
}
wstring FileInfo::extension()
{
	return this->_extension;
}
string FileInfo::toHumanStyle(uintmax_t _Size)
{
	const int size = 5;
	string sizenames[size]{ "B", "KB", "MB", "GB", "TB" };

	double_t d_size = static_cast<double_t>(_Size);

	for (int i = 0; i < size; i++) {
		if (d_size < 1024)
			return to_string(round(d_size * 100) / 100) + " " + sizenames[i];
		d_size /= 1024;
	}
	return to_string(round(d_size * 100) / 100) + " " + sizenames[size - 1];
}
uintmax_t FileInfo::size() const { return _size; }