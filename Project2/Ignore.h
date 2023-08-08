#pragma once
#include <string>
#include <filesystem>
#include <list>
#include <fstream>
#include "IgnoreFile.h"

constexpr auto CREATE_FILE_ERROR = "File not created.";
constexpr auto OPEN_FILE_ERROR = "File not opened.";
constexpr auto DIST_PATH_ERROR = "Incorrect distination path."; 

namespace fs = std::filesystem;

using std::string;
using std::list;
using std::pair;

using std::ofstream;
using std::ifstream;
using std::transform;
using std::getline;
using std::wofstream;
using std::wifstream;

/*
	Available paths
	1. Full path like "c:\example\file.ignore"
	2. Directory path "c:\example"
	3. Relative path "example" or "example\nested", "example\nested\second"
	*/

class IgnoreFileProvider {
private:
	wstring filename;
	fs::path filepath; // file location
public:
	IgnoreFileProvider(wstring _filename);
	IgnoreFileProvider(wstring _filename, wstring _dist);
	IgnoreFileProvider(const IgnoreFileProvider& obj);

	wstring getFilename(); // get name of ignore file
	wstring getFilepath(); // get path of ignore file

	wstring info();

	list<IgnoreFilename> getIgnoreNames(); // get ignore file contents
	list<IgnoreFilename> getIgnoreNames(wstring filter);
	
	void addFile(wstring stem);
	void addFile(wstring stem, wstring extension);
	void addFile(IgnoreFilename file);

	/*void removeFile(string stem);
	void removeFile(string stem, string extension);
	void removeFile(IgnoreFile file);

	void changeFile(string stem, string new_stem);
	void changeFile(IgnoreFile file, string new_stem);
	void changeFile(IgnoreFile file, IgnoreFile new_file);

	bool is_exist(string stem);
	bool is_exist(string stem, string extension);
	bool is_exist(IgnoreFile file);*/
};


