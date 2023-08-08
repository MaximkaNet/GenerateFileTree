#include "Ignore.h"

IgnoreFileProvider::IgnoreFileProvider(wstring _filename) {
    this->filename = fs::path(_filename).filename().c_str();
    this->filepath = fs::absolute(_filename);

    if (!fs::exists(this->filepath)) {
        ofstream file;
        file.open(this->filepath);

        if (!file.is_open()) throw CREATE_FILE_ERROR;

        file.close();
    }
}

wstring IgnoreFileProvider::getFilename() { return this->filename; }

wstring IgnoreFileProvider::getFilepath() { return this->filepath.lexically_normal().c_str(); }

wstring IgnoreFileProvider::info()
{
    wstring title = L"Ignore file";
    wstring path = L"\n path: " + filepath.wstring();
    wstring name = L"\n name: " + filename;
    return title + path + name;
}


list<IgnoreFilename> IgnoreFileProvider::getIgnoreNames()
{
    list<IgnoreFilename> filenames;

    wifstream file;
    file.open(this->filepath);

    wstring in, stem, extension;
    fs::path temp;
    while (getline(file, in)) {
        temp = in;
        in.clear();
        if (!temp.has_filename()) continue;

        IgnoreFilename ignFile; // create new IgnoreFile structure
        ignFile.stem = temp.stem().wstring();
        ignFile.extension = temp.extension().wstring();
        filenames.push_back(ignFile); // write record
    }
    temp.clear();
    return filenames;
}

list<IgnoreFilename> IgnoreFileProvider::getIgnoreNames(wstring filter)
{
    list<IgnoreFilename> filenames;

    wifstream file;
    file.open(this->filepath);

    wstring in, stem, extension, filename;
    fs::path temp;
    while (!file.eof()) {
        file >> temp; // read line from file
        
        filename = temp.filename().wstring();
        transform(filename.begin(), filename.end(), filename.begin(), ::tolower); // to lower case
        bool include = filename.find(filter) != std::string::npos;

        if (!temp.has_filename() || include) continue;

        IgnoreFilename ignFile; // create new IgnoreFile structure
        ignFile.stem = temp.stem().wstring();
        ignFile.extension = temp.extension().wstring();
        filenames.push_back(ignFile); // write record
    }
    temp.clear();
    return filenames;
}

void IgnoreFileProvider::addFile(wstring stem)
{
    wofstream file;
    file.open(this->filepath, std::ios_base::app);

    if (!file.is_open()) throw OPEN_FILE_ERROR;

    file << stem << '\n';

    file.close();
}

void IgnoreFileProvider::addFile(wstring stem, wstring extension)
{
    wofstream file;
    file.open(this->filepath, std::ios_base::app);

    if (!file.is_open()) throw OPEN_FILE_ERROR;

    file << stem << extension << '\n';

    file.close();
}

void IgnoreFileProvider::addFile(IgnoreFilename file)
{
    addFile(file.stem, file.extension);
}

IgnoreFileProvider::IgnoreFileProvider(wstring _filename, wstring _dist)
{
    this->filename = fs::path(_filename).filename().wstring();

    fs::path absolute_dist = fs::absolute(_dist);

    if (!fs::exists(absolute_dist))
        throw DIST_PATH_ERROR;

    this->filepath = fs::absolute(_dist + L"\\" + _filename);

    if (!fs::exists(this->filepath)) {
        ofstream file;
        file.open(this->filepath);

        if (!file.is_open()) throw CREATE_FILE_ERROR;

        file.close();
    }
}

IgnoreFileProvider::IgnoreFileProvider(const IgnoreFileProvider& obj)
{
    this->filename = obj.filename;
    this->filepath = obj.filepath;
}