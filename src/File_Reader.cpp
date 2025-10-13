#include <iostream>
#include <fstream>
#include "../include/File_Reader.h"

File FileReader::getUserFile(){
  return userFile;
}
bool FileReader::isHuffFile(){
  return userFile.name.substr(userFile.name.size()-5) == ".huff";
} 
bool FileReader::isTxtFile(){
  if (userFile.name.size() < 4)
    return false;
  if (userFile.name.substr(userFile.name.size()-4) == ".txt")
    return true;
  if (userFile.name.substr(userFile.name.size()-4) == ".cpp")
    return true;
  if (userFile.name.substr(userFile.name.size()-4) == ".c")
    return true;
  return false;
}
bool FileReader::isFileFound(){
  std::ifstream file(userFile.name);
  if(file.is_open())
    return true;
  return false;
}
void FileReader::setFilename(){
  std::cout << "\n\t\033[1mInput filename: \033[0m";
  std::cin >> userFile.name;
}
//function that reutrns a bool value if a file is found and opened sucessfully
void FileReader::readFile(){
  std::fstream file;
  file.open(userFile.name);
  if (file.fail()){
    std::cout << "\033[31mERROR: File could not be accessed\033[0m\n";
    return;
  }
  char character;
  while (file.get(character)){
    userFile.contents += character;
  }
  file.close();
}
void FileReader::readBytes(const std::string &filename){
  std::ifstream huffFile(filename, std::ios_base::binary);
  if (!huffFile){
    std::cout << "\033[31mERROR: File not found\033[0m\n";
    return;
  }
  for ( char character; huffFile.get(character); )
    userFile.contents += character;
  huffFile.close();
}
void FileReader::appendEndofText(){
  userFile.contents += endChar;
}