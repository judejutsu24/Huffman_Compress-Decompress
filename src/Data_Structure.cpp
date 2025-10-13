#include <iostream>
#include "../include/Data_Structure.h"

//global functions
bool binarySearch(const int &target, unsigned short high, unsigned short low){
  while (low <= high){
    int mid = low + (high-low)/2;
    if (target == char(mid))
      return true;
    if (target > char(mid))
      low = mid++;
    if (target < char(mid))
      high = mid--;
  }
  std::cout << "WARNING: Invalid elements found: " << target << '\n';
  return false;
}
//formatters
int asciiNumbertoInteger(char &asciiNumber){
  return asciiNumber-'0';
}
std::string formatCharacter(const char &character){
  switch(character){
  case nodeChar: return "NDE"; break;
  case ' ': return "SPC"; break;
  case '\n': return "NWL"; break;
  case '\t': return "TAB"; break;
  case endChar: return "ETX"; break; 
  case treeEndChar: return "EOT"; break;
  default: return std::string(1, character); break;
  }
}
std::string reverseString(std::string huffCode){
  if(huffCode.empty()){
    std::cout << "WARNING: Code empty:\n";
    return std::string();
  }
  return std::string(huffCode.rbegin(), huffCode.rend());
}
//shared behaviours
void destroyTree(NodeData* &nodeData){
  if(!nodeData)
    return;
  destroyTree(nodeData->left);
  destroyTree(nodeData->right);
  delete(nodeData);
}