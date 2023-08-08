#include "IgnoreFile.h"

IgnoreFilename::IgnoreFilename() {}

IgnoreFilename::IgnoreFilename(wstring stem)
{
    this->stem = stem;
}

IgnoreFilename::IgnoreFilename(wstring stem, wstring extension)
{
    this->stem = stem;
    this->extension = extension;
}
IgnoreFilename::IgnoreFilename(const IgnoreFilename& obj)
{
    this->stem = obj.stem;
    this->extension = obj.extension;
}

wstring IgnoreFilename::filename()
{
    return stem + extension;
}
