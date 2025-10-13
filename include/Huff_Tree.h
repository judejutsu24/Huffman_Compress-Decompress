#ifndef HUFF_TREE_H
#define HUFF_TREE_H
#include "Data_Structure.h"
#include "Gui.h"

class HuffTree{
  private:
    std::string decompressedContents;
  public: 
    NodeData* root;
    HuffTree() : root(nullptr) {}
    ~HuffTree();
    unsigned short count = 0;
    bool fileExists(const std::string &filename);
    void showTree(NodeData* root);
    void buildTree(NodeData* &root,const std::string &treeKey, unsigned short &count );
    void decodeHuffCode(const std::string &encodedContent); 
    void exportTxtFile(std::string filename);
};

#endif