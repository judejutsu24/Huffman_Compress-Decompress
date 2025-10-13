#include <iostream>
#include "include/Gui.h"
#include "include/File_Reader.h"
#include "include/Frequency_Counter.h"
#include "include/Priority_Queue.h"
#include "include/Dictionary.h"

int main(void){
  compressorTitle();
  do{
    FileReader objFileReader;
    FrequencyCounter objFrequencyCounter;
    PriorityQueue objPriorityQueue;
    Dictionary objDictionary;
    //input
    objFileReader.setFilename();
    if(objFileReader.isTxtFile() && objFileReader.isFileFound()){
      //process
      objFileReader.readFile();
      objFileReader.appendEndofText();
      objFrequencyCounter.countCharacterFrequency(objFileReader.getUserFile().contents);
      objFrequencyCounter.TabletoPriorityQueue(objPriorityQueue);
      //output
      objPriorityQueue.buildTree();
      bigLine(tableLine);
      objPriorityQueue.buildHuffmanTree(objDictionary);
      objDictionary.compressFile(objFileReader.getUserFile().contents);
      objPriorityQueue.formatTreeKey();
      objDictionary.exportCompressedFile(objFileReader.getUserFile().name, objPriorityQueue.getTreeKey());
    } else {
      std::cout << "\033[31mERROR: The file is not a valid format\033[0m\n";
    }
  } while (menu() != "n");
  return 0;
}
//BSCS-2A
//MARCO ELIJAH P RODIL & JUDE S TABUZO JR.