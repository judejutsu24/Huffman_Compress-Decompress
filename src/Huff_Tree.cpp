#include <iostream>
#include <fstream>
#include "../include/Huff_Tree.h"

HuffTree::~HuffTree() {
  destroyTree(root);
  std::cout << "\033[32mPROGRAM: Huff Tree Deallocated Successfully\033[0m\n";
}
void HuffTree::buildTree(NodeData* &root, const std::string &treeKey, unsigned short &count){
  NodeData* newNode = new NodeData(treeKey.at(count), 1);
  if (treeKey.at(count) != nodeChar){
    root = newNode;
    count++;
    return;
  }
  root = newNode;
  count++;
  buildTree(root->left, treeKey, count);
  buildTree(root->right, treeKey, count);
}
void HuffTree::showTree(NodeData* root){
  if(!root)
    return;
  printHuffTreeCharacters(root->letter);
  showTree(root->left);
  showTree(root->right);
}
void HuffTree::decodeHuffCode(const std::string& encodedContent) {
  NodeData* currentNode = root;
  for (char bit : encodedContent) {
    if (bit == '0') {
      if (currentNode->left) {
        currentNode = currentNode->left;
      } else {
        std::cout << "\033[31mERROR: Invalid Huffman code encountered.\033[0m\n";
        return;
      }
    } else if (bit == '1') {
      if (currentNode->right) {
        currentNode = currentNode->right;
      } else {
        std::cout << "\033[31mERROR: Invalid Huffman code encountered.\033[0m\n";
        return;
      }
    }
    if (!currentNode->left && !currentNode->right) {
      if (currentNode->letter == endChar)
        return;
      decompressedContents += currentNode->letter;
      currentNode = root;
    }
  }
}
bool HuffTree::fileExists(const std::string &filename){
  std::ifstream file(filename);
  return file.good();
}
void HuffTree::exportTxtFile(std::string filename) {
  std::string txtNameFormat = filename.erase(filename.size() - 5); 
  if(fileExists(txtNameFormat)){
    if(askOverwriteFile() == "n")
      txtNameFormat = "Decompressed_Text.txt";
  }
  std::ofstream outFile(txtNameFormat);
  if (!outFile) {
    std::cout << "\033[33mERROR: Unable to create output file.\033[0m\n";
    return;
  }
  outFile << decompressedContents;
  outFile.close();
}
