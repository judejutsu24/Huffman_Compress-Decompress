#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

//constants
const unsigned short asciiLimit = 255; //ASCII table size
const char endChar = 3; //End of text signal //Needed for encoding
const char nodeChar = 2; //Node containing frequency //No need to encode in compressed
const char treeEndChar = 1; //End of huffman tree signal

//Data Structs
struct File{
  std::string name;
  std::string contents;
};
struct NodeData{
  NodeData* left;
  NodeData* right;
  int frequency;
  char letter;
  NodeData (NodeData* node1, NodeData* node2) : left(node1), right(node2), frequency(node1->frequency+node2->frequency), letter(nodeChar) {}
  NodeData (char letter, int frequency) : left(nullptr), right(nullptr), frequency(frequency), letter(letter) {}
};
struct Node{
  Node* next;
  NodeData* nodeData;
  Node (NodeData* nodeData) : next(nullptr), nodeData(nodeData) {}
}; 

//formatters
bool binarySearch(const int &target, unsigned short high, unsigned short low);
int asciiNumbertoInteger(char &character);
std::string formatCharacter(const char &character);
std::string reverseString(std::string code);
//Shared behaviour
void destroyTree(NodeData* &nodeData);

#endif