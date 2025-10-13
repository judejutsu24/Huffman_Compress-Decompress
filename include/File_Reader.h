#ifndef FILE_READER_H
#define FILE_READER_H
#include "Data_Structure.h"

class FileReader{
  private:
    File userFile;
  public:
    File getUserFile();
    bool isFileFound();
    bool isHuffFile();
    bool isTxtFile();
    void appendEndofText();
    void setFilename();
    void readFile();
    void readBytes(const std::string &filename);
};

#endif