#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "Data_Structure.h"

class Dictionary{
  private:
    unsigned char byte = 0;
    int position = 0; 
    short charBits = 0;
    std::string huffCodeTable[asciiLimit] = {""};
    unsigned char reverseByte(unsigned char byte);
  public:
    std::string compressedFileContent; 
    std::string encodedContent;
    std::string treeKey;  
    void exportCompressedFile(const std::string &filename, const std::string &treeKey);
    void assignHuffCode(const unsigned char &character, const std::string &huffCode);
    void compressFile(const std::string &originalFileContent);
    void writeBit(int bit, unsigned char &byte, int &position, std::ostream& file);
    void flushBits(unsigned char &byte, int &position, std::ostream& file);
    void writeHeader(const unsigned char &key, unsigned char &byte, int &position, std::ostream& file);
    void readHuffCodes(const unsigned char &headerByte);
    void readHeader(const unsigned char &headerByte);
    void readCompressedFile(const std::string &compressedContent);
};

#endif