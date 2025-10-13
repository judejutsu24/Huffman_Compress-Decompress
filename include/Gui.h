#ifndef GUI_H
#define GUI_H
#include "Data_Structure.h"

const std::string sayThankYou = "\033[2J\033[1;1H\n\t\tThank you for using the program...\n";
const std::string sayRerun = "\033[2J\033[1;1H\n\033[32mPROGRAM: Rerunning program...\033[0m\n";
const std::string sayValidOptions = "\033[2J\033[1;1H\n\033[33mWARNING: Please input 'y' or 'n'!\033[0m\n";
const std::string sayOverwrite = "\033[32mPROGRAM: Overwriting existing file...\033[0m\n";
const std::string saySaveAsCopy = "\033[32mPROGRAM: Saving as Decompressed_Text.txt...\033[0m\n";
const unsigned short headerLine = 100;
const unsigned short tableLine = 50;

//Shared 
std::string menu();
std::string askOverwriteFile();
void clearScreen();
void bigLine(const int &length);
void line(const int &length);
//Compressor
void compressorTitle();
void printFinalTableTitle();
void printPriorityQueueTableTitle();
void printPriorityQueueNode(const char &node, const int &frequency);
void printFinalTableCharacters(const char &letter, const int &frequency, const std::string &huffCode);
void printComparedFileSize(const int &originalByte, const int &compressedByte);
//Decompressor GUI
void decompressorTitle();
void printHuffTreeTitle();
void printHuffTreeCharacters(const char &letter);

#endif