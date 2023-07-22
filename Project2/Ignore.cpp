#include "Ignore.h"

IgnoreFileProvider::IgnoreFileProvider(string _filename) {
    this->filename = fs::path(_filename).filename().string();
    this->filepath = fs::absolute(_filename);

    if (!fs::exists(this->filepath)) {
        ofstream file;
        file.open(this->filepath);

        if (!file.is_open()) throw CREATE_FILE_ERROR;

        file.close();
    }
}

string IgnoreFileProvider::getFilename() { return this->filename; }

string IgnoreFileProvider::getFilepath() { return this->filepath.lexically_normal().string(); }

string IgnoreFileProvider::info()
{
    string title = "Ignore file";
    string path = "\n path: " + filepath.string();
    string name = "\n name: " + filename;
    return title + path + name;
}


list<IgnoreFilename> IgnoreFileProvider::getIgnoreNames()
{
    list<IgnoreFilename> filenames;

    ifstream file;
    file.open(this->filepath);

    string in, stem, extension;
    fs::path temp;
    while (getline(file, in)) {
        temp = in;
        in.clear();
        if (!temp.has_filename()) continue;

        IgnoreFilename ignFile; // create new IgnoreFile structure
        ignFile.stem = temp.stem().string();
        ignFile.extension = temp.extension().string();
        filenames.push_back(ignFile); // write record
    }
    temp.clear();
    return filenames;
}

list<IgnoreFilename> IgnoreFileProvider::getIgnoreNames(string filter)
{
    list<IgnoreFilename> filenames;

    ifstream file;
    file.open(this->filepath);

    string in, stem, extension, filename;
    fs::path temp;
    while (!file.eof()) {
        file >> temp; // read line from file
        
        filename = temp.filename().string();
        transform(filename.begin(), filename.end(), filename.begin(), ::tolower); // to lower case
        bool include = filename.find(filter) != std::string::npos;

        if (!temp.has_filename() || include) continue;

        IgnoreFilename ignFile; // create new IgnoreFile structure
        ignFile.stem = temp.stem().string();
        ignFile.extension = temp.extension().string();
        filenames.push_back(ignFile); // write record
    }
    temp.clear();
    return filenames;
}

void IgnoreFileProvider::addFile(string stem)
{
    ofstream file;
    file.open(this->filepath, std::ios_base::app);

    if (!file.is_open()) throw OPEN_FILE_ERROR;

    file << stem << '\n';

    file.close();
}

void IgnoreFileProvider::addFile(string stem, string extension)
{
    ofstream file;
    file.open(this->filepath, std::ios_base::app);

    if (!file.is_open()) throw OPEN_FILE_ERROR;

    file << stem << extension << '\n';

    file.close();
}

void IgnoreFileProvider::addFile(IgnoreFilename file)
{
    addFile(file.stem, file.extension);
}

IgnoreFileProvider::IgnoreFileProvider(string _filename, string _dist)
{
    this->filename = fs::path(_filename).filename().string();

    fs::path absolute_dist = fs::absolute(_dist);

    if (!fs::exists(absolute_dist))
        throw DIST_PATH_ERROR;

    this->filepath = fs::absolute(_dist + "\\" + _filename);

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