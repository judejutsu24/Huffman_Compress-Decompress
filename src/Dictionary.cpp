#include <iostream>
#include <fstream>
#include "../include/Dictionary.h"

unsigned char Dictionary::reverseByte(unsigned char byte){
  unsigned char reversed = 0;
  for(int i = 0; i < 8; i++){
    reversed <<= 1;
    if(byte & 1){
      reversed ^= 1;
    }
    byte >>= 1;
  }
  return reversed;
}
void Dictionary::assignHuffCode(const unsigned char &character, const std::string &huffCode){
  if (huffCode == ""){
    std::cout << "\033[33mWARNING: Empty Huff Code found\033[0m\n";
    return;
  }
  for (int i = 0; i < asciiLimit; i++)
    if (i == character)
      huffCodeTable[i] = huffCode;
}
void Dictionary::compressFile(const std::string &originalFileContent){
  for ( auto &character : originalFileContent )
    if (binarySearch(int(character), asciiLimit, 0))
      compressedFileContent += huffCodeTable[int(character)];
}
void Dictionary::writeBit(int bit, unsigned char &byte, int &position, std::ostream& file){
  if(position == 8){
    byte = reverseByte(byte);
    file.write((char*)&byte, sizeof(byte));
    position = 0;
    byte = 0;
  }
  if(bit){
    byte = byte | 1<<position;
  }
    position++;
}
void Dictionary::writeHeader(const unsigned char &key, unsigned char &byte, int &position, std::ostream& file){
  if(position > 8){ 
    std::cout << "\033[33mWARNING: Byte overflow\033[0m\n";
    return;
  }
  if(position == 8){
    byte = reverseByte(byte);
    file.write((char*)&byte, sizeof(byte));
    position = 0;
    byte = 0;
  }
  if(formatCharacter(key) == "NDE"){
    position++;
    return;
  } else {
    byte = byte | 1<<position;
    position++;
  }
  short keyPosition = 7;
  while (keyPosition >= 0){
    if(position == 8){
      byte = reverseByte(byte);
      file.write((char*)&byte, sizeof(byte));
      position = 0;
      byte = 0;
    }
    if (key & 1<<keyPosition){
      byte = byte | 1<<position;
      keyPosition--;
      position++;
    } else {
      keyPosition--;
      position++;
    }
    if(position > 8){
      std::cout << "\033[33mWARNING: Byte overflow.\033[0m\n";
      return;
    }
  }
}
void Dictionary::flushBits(unsigned char &byte, int &position, std::ostream& file){
  while (byte)
    writeBit(0, byte, position, file);  
}
void Dictionary::exportCompressedFile(const std::string &filename, const std::string &treeKey){
  std::ofstream compressedFile(filename + ".huff", std::ios_base::binary);
  if(!compressedFile) {
     std::cout << "\033[31mERROR: Cannot open file!\033[0m" << std::endl;
     return;
  }
  for ( char key : treeKey)
    writeHeader(key, byte, position, compressedFile);
  for ( char bit : compressedFileContent)
    writeBit(asciiNumbertoInteger(bit), byte, position, compressedFile);
  flushBits(byte, position, compressedFile);
  if(!compressedFile.good()) {
    std::cout << "\033[31mError occurred at writing time!\033[0m" << std::endl;
    return;
  }
  compressedFile.close();
}
void Dictionary::readHuffCodes(const unsigned char &headerByte){
  while(position != 8){
    if (headerByte & 1<<position){
      encodedContent += '1';
    } else {
      encodedContent += '0';
    }
    position++;
  }
  if (position == 8){
    position = 0;
  }
}
void Dictionary::readHeader(const unsigned char &headerByte){
  if (position > 8){
    std::cout << "\n\033[33mWARNING: Byte overflow...\033[0m\n";
    return;
  }
  if (position == 8)
    position = 0;
  while (position != 8){
  if (!(headerByte & 1<<position) && !charBits) {
    treeKey += nodeChar;
    position++;
  }
  if ((headerByte & 1<<position) && !charBits){
    charBits = 8;
    position++;
  }
  while (charBits){
      if (position == 8){ 
        position = 0;
        return;
      }
      if (headerByte & 1<<position)
        byte = byte | 1<<(charBits - 1);
      charBits--;
      position++;
      if (charBits == 0){
        if(formatCharacter(byte) == "EOT") 
          return;
        treeKey += byte;
        byte = 0;
      }
    }
  }
}
void Dictionary::readCompressedFile(const std::string &compressedContent){
  if(compressedContent.empty()){ 
    std::cout << "\033[31mERROR: Compressed Contents are Empty\033[0m\n";
    return;
  }
  bool readContent = false;
  for (unsigned char headerByte : compressedContent){
    if (!readContent)
      readHeader(reverseByte(headerByte));
    if(formatCharacter(byte) == "EOT" && !readContent)
      readContent = true;
    if (readContent == true)
      readHuffCodes(reverseByte(headerByte));
  }
  if (readContent == false)
    std::cout << "\033[31mERROR: Encoded content was not read.\033[0m\n";
}