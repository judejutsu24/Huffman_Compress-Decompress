#include <iostream>
#include "../include/Gui.h"

std::string choice;

//Common GUI
std::string menu(){
  bigLine(headerLine);
  std::cout << "\n\t\tWould you like to run the program again? yes [y] / no [n]?\n";
  bigLine(headerLine);
  do{
    std::cin >> choice;
    switch (choice.at(0)){
      case 'n': std::cout << sayThankYou; return "n"; break;
      case 'N': std::cout << sayThankYou; return "n"; break;
      case 'y': std::cout << sayRerun; return "y"; break;
      case 'Y': std::cout << sayRerun; return "y"; break;
      default : std::cout << sayValidOptions;
    }
  }while (choice != "y" || choice != "Y" || choice != "n" || choice != "N");
  std::cout << "\n\033[33mWARNING: Unexpected behaviour at menu\033[0m\n";
  return std::string();
}
std::string askOverwriteFile(){
  std::cout << "\033[33mWARNING: File already exists, overwrite? yes [y] / no [n]\033[0m\n";
  do{
    std::cin >> choice;
    switch (choice.at(0)){
      case 'n': std::cout << saySaveAsCopy; return "n"; break;
      case 'N': std::cout << saySaveAsCopy; return "n"; break;
      case 'y': std::cout << sayOverwrite; return "y"; break;
      case 'Y': std::cout << sayOverwrite; return "y"; break;
      default : std::cout << sayValidOptions;
    }
  }while (choice != "y" || choice != "Y" || choice != "n" || choice != "N");
  std::cout << "\n\033[33mWARNING: Unexpected behaviour at askOverwriteFile\033[0m\n";
  return std::string();
}
void bigLine(const int &length){
  std::string bigLine;
  for(int i = 0; i <= length; i++)
    bigLine += "\033[1m=\033[0m";
  std::cout << "\n\t" << bigLine << '\n';
}
void line(const int &length){
  std::string line;
  for(int i = 0; i <= length; i++)
    line += "\033[1m-\033[0m";
  std::cout << "\n\t" << line << '\n';
}
void clearScreen(){
  std::cout << "\033[2J\033[H";
}
//Compressor GUI
void compressorTitle(){
  clearScreen();
  bigLine(headerLine);
  std::cout << "\n\t\t8   8                                                           ";
  std::cout << "\n\t\t8   8 e   e eeee eeee eeeeeee eeeee eeeee                       ";
  std::cout << "\n\t\t8eee8 8   8 8    8    8  8  8 8   8 8   8                       ";
  std::cout << "\n\t\t88  8 8e  8 8eee 8eee 8e 8  8 8eee8 8e  8                       ";
  std::cout << "\n\t\t88  8 88  8 88   88   88 8  8 88  8 88  8                       ";
  std::cout << "\n\t\t88  8 88ee8 88   88   88 8  8 88  8 88  8                       ";
  std::cout << "\n\t\t                                                                ";
  std::cout << "\n\t\t8\"\"\"\"8                                                          ";
  std::cout << "\n\t\t8    \" eeeee eeeeeee eeeee eeeee  eeee eeeee eeeee eeeee eeeee  ";
  std::cout << "\n\t\t8e     8  88 8  8  8 8   8 8   8  8    8   \" 8   \" 8  88 8   8  ";
  std::cout << "\n\t\t88     8   8 8e 8  8 8eee8 8eee8e 8eee 8eeee 8eeee 8   8 8eee8e ";
  std::cout << "\n\t\t88   e 8   8 88 8  8 88    88   8 88      88    88 8   8 88   8 ";
  std::cout << "\n\t\t88eee8 8eee8 88 8  8 88    88   8 88ee 8ee88 8ee88 8eee8 88   8 \n";
  line(headerLine);
  std::cout << "\n\t\t\033[1mAuthors:\033[0m Marco Elijah P. Rodil & Jude S. Tabuzo Jr.\t\033[1mCourse & Section:\033[0m BSCS-2A";
  line(headerLine);
  std::cout << "\n\n\t\tWelcome to the Huffman Compressor program. To compress a file, please ensure the file";
  std::cout << "\n\t\tis in the same directory as the executable file. The Compressor program only accepts \".txt\"";
  std::cout << "\n\t\tformat files. Finally please ensure to include the -\".txt\" portion of the filename,"; 
  std::cout << "\n\t\tessentially writing the full filename\n\n";
  bigLine(headerLine);
}
void printFinalTableTitle(){
  bigLine(tableLine);
  std::cout << "\n\t\t\033[1mFINAL TABLE:\033[0m\n\t\tASCII\tCHAR\tFREQU\tHUFF\n";
  line(tableLine);
}
void printPriorityQueueTableTitle(){
  bigLine(tableLine);
  std::cout << "\n\t\t\033[1mHUFFMAN TREE:\033[0m\n\t\tASCII\tCHAR\tFREQ\n";
  line(tableLine);
}
void printPriorityQueueNode(const char &node, const int &frequency){
  std::cout << "\t\t" << int(node) << "\t'" << formatCharacter(node) << "'\t" << frequency << '\n';
}
void printFinalTableCharacters(const char &letter, const int &frequency, const std::string &huffCode){
  std::cout << "\t\t" << int(letter) << "\t'" << formatCharacter(letter) << "'\t" << frequency << '\t' << huffCode << '\n';
}
void printComparedFileSize(const int &originalByte, const int &compressedByte){
  line(tableLine);
  std::cout << "\n\t\tSize in:\t" << "Original" << "\tCompressed\n"; 
  std::cout << "\t\t(bit ): \t" << originalByte << "\t->\t" << compressedByte << " bits\n";
  std::cout << "\t\t(byte): \t" << originalByte/8 << "\t->\t" << compressedByte/8 << " bytes\n";
  bigLine(tableLine);
}
//Decompressor GUI
void decompressorTitle(){
  bigLine(headerLine);
  std::cout << "\n\t\t8   8                                                                     ";
  std::cout << "\n\t\t8   8 e   e eeee eeee eeeeeee eeeee eeeee                                 ";
  std::cout << "\n\t\t8eee8 8   8 8    8    8  8  8 8   8 8   8                                 ";
  std::cout << "\n\t\t88  8 8e  8 8eee 8eee 8e 8  8 8eee8 8e  8                                 ";
  std::cout << "\n\t\t88  8 88  8 88   88   88 8  8 88  8 88  8                                 ";
  std::cout << "\n\t\t88  8 88ee8 88   88   88 8  8 88  8 88  8                                 ";
  std::cout << "\n\t\t                                                                          ";
  std::cout << "\n\t\t8\"\"\"\"8                                                                    ";
  std::cout << "\n\t\t8    8 eeee eeee eeeee eeeeeee eeeee eeeee  eeee eeeee eeeee eeeee eeeee  ";
  std::cout << "\n\t\t8e   8 8    8  8 8  88 8  8  8 8   8 8   8  8    8   \" 8   \" 8  88 8   8  ";
  std::cout << "\n\t\t88   8 8eee 8e   8   8 8e 8  8 8eee8 8eee8e 8eee 8eeee 8eeee 8   8 8eee8e ";
  std::cout << "\n\t\t88   8 88   88   8   8 88 8  8 88    88   8 88      88    88 8   8 88   8 ";
  std::cout << "\n\t\t88eee8 88ee 88e8 8eee8 88 8  8 88    88   8 88ee 8ee88 8ee88 8eee8 88   8 \n";
  line(headerLine);
  std::cout << "\n\t\t\033[1mAuthors:\033[0m Marco Elijah P. Rodil & Jude S. Tabuzo Jr.\t\033[1mCourse & Section:\033[0m BSCS-2A";
  line(headerLine);
  std::cout << "\n\n\t\tWelcome to the Huffman Decompressor program. To Decompress a file, please ensure the file is";
  std::cout << "\n\t\tin the same directory as the executable file. The Decompressor program only accepts \".huff\"";
  std::cout << "\n\t\tformat files produced by the Compressor Program. additionally ensure to include the -\".huff\""; 
  std::cout << "\n\t\tportion of the filename, essentially writing the full filename\n\n";
  bigLine(headerLine);
}
void printHuffTreeTitle(){
  bigLine(tableLine);
  std::cout << "\n\t\t\033[1mReconstructed Huff Tree:\033[0m\n\t\tASCII\tCHAR\n";
  line(tableLine);
}
void printHuffTreeCharacters(const char &letter){
  std::cout << "\t\t" << int(letter) << "\t'" << formatCharacter(letter) << "'\t\n";
}