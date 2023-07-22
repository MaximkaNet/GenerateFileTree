#include "IgnoreFile.h"

IgnoreFilename::IgnoreFilename() {}

IgnoreFilename::IgnoreFilename(string stem)
{
    this->stem = stem;
}

IgnoreFilename::IgnoreFilename(string stem, string extension)
{
    this->stem = stem;
    this->extension = extension;
}
IgnoreFilename::IgnoreFilename(const IgnoreFilename& obj)
{
    this->stem = obj.stem;
    this->extension = obj.extension;
}

string IgnoreFilename::filename()
{
    return stem + extension;
}
