#include <iostream>
#include "include/Gui.h"
#include "include/Data_Structure.h"
#include "include/File_Reader.h"
#include "include/Dictionary.h"
#include "include/Huff_Tree.h"

int main(void){
  decompressorTitle();
  do{
    FileReader objFileReader;
    //input
    objFileReader.setFilename();
    if (objFileReader.isHuffFile()){
    //process
    Dictionary objDictionary;
    HuffTree objHuffTree;

    objFileReader.readBytes(objFileReader.getUserFile().name);
    objDictionary.readCompressedFile(objFileReader.getUserFile().contents);
    objHuffTree.buildTree(objHuffTree.root, objDictionary.treeKey, objHuffTree.count);
    //output
    printHuffTreeTitle();
    objHuffTree.showTree(objHuffTree.root);
    bigLine(tableLine);
    objHuffTree.decodeHuffCode(objDictionary.encodedContent);
    objHuffTree.exportTxtFile(objFileReader.getUserFile().name);
    } else {
      std::cout << "\033[31mERROR: The file is not .huff format.\033[0m\n";
    }
  } while(menu() != "n");
  return 0;
}
//BSCS-2A
//MARCO ELIJAH P RODIL & JUDE S TABUZO JR.