#include <iostream>
#include "../include/Priority_Queue.h"

PriorityQueue::~PriorityQueue(){ 
  while (queueCopy != nullptr){
    destroyTree(queueCopy->nodeData);
    dequeue(queueCopy);
  }
  while (front != nullptr){//Front must not be null before destroying a tree
    destroyTree(front->nodeData);
    dequeue(front);
  }  
  std::cout << "\033[32mPROGRAM: Priority Queue sucessfully deallocated.\033[0m\n";
}
std::string PriorityQueue::encode(NodeData* nodeData, char &character){
  std::string huffCode;
  if(!nodeData)
    return std::string();
  huffCode = encode(nodeData->left, character);
  if(!huffCode.empty())
    return huffCode.append("0");
  huffCode = encode(nodeData->right, character);
  if(!huffCode.empty())
    return huffCode.append("1");
  if(nodeData->letter == character)
    return huffCode = character;
  return std::string();
}
std::string PriorityQueue::getTreeKey(){
  return treeKey;
}
void PriorityQueue::insertSortNode(NodeData* &newNode, Node* &queue){
  Node* newQNode = new Node(newNode);
  if (!queue || newQNode->nodeData->frequency < queue->nodeData->frequency){
    newQNode->next = queue;
    queue = newQNode;
    return;
  }
  Node* current = queue;
  while (current->next && newQNode->nodeData->frequency >= current->next->nodeData->frequency)
    current = current->next;
  newQNode->next = current->next;
  current->next = newQNode;
}
void PriorityQueue::displayQueue(){
  if (!front){
    std::cout << "\033[33mWARNING: Table is empty\033[0m\n";
    return;
  }
  Node* current = front;
  while (current){
      std::cout << int(current->nodeData->letter) << "\t'" << formatCharacter(current->nodeData->letter) << "'\t" << current->nodeData->frequency << '\n';
    current = current->next;
  }
}
void PriorityQueue::traversePreOrder(NodeData* nodeData){
  if (!nodeData) 
    return;
  printPriorityQueueNode(nodeData->letter, nodeData->frequency);
  treeKey += nodeData->letter;
  traversePreOrder(nodeData->left);
  traversePreOrder(nodeData->right);
}
void PriorityQueue::formatTreeKey(){
  treeKey += treeEndChar;
}
void PriorityQueue::enqueueNode(char character, int frequency){
  NodeData* newNode = new NodeData(character, frequency);
  insertSortNode(newNode, front);
}
void PriorityQueue::dequeue(Node* &queue){
  if (!queue)
    return;    
  Node* target = queue;
  queue = queue->next;
  delete(target);
}
void PriorityQueue::mergeNode(NodeData* leftNode, NodeData* rightNode){ //Function para magjoin ng dalawang Tree nodes
  NodeData* newNode = new NodeData(leftNode, rightNode);
  insertSortNode(newNode, front);
}
void PriorityQueue::backupNode(char character, int frequency){
  NodeData* newNode = new NodeData(character, frequency);
  insertSortNode(newNode, queueCopy);
}
void PriorityQueue::buildTree(){
  if(!front){
    std::cout << "\033[33mWARNING: There is no front queue\033[0m\n";
    return;
  }
  while (front->next) { // Check if front.next is NULL
    NodeData* left = front->nodeData;
    dequeue(front);
    NodeData* right = front->nodeData;
    dequeue(front);
    mergeNode(left, right);
  }
  printPriorityQueueTableTitle();
  traversePreOrder(front->nodeData);
}
void PriorityQueue::buildHuffmanTree(Dictionary &objDictionary){
  if(!front){
    std::cout << "\033[33mWARNING: There is no node.\033[0m\n";
    return; 
  }
  Node* current = queueCopy;
  int compressedByte = 0;
  int originalByte = 0;
  printFinalTableTitle(); //Replace
  while(current){
    std::string huffCode = encode(front->nodeData, current->nodeData->letter);  
    huffCode.erase(huffCode.begin());
    huffCode = reverseString(huffCode);
    objDictionary.assignHuffCode(current->nodeData->letter, huffCode);
    printFinalTableCharacters(current->nodeData->letter, current->nodeData->frequency, huffCode);
    compressedByte += current->nodeData->frequency*huffCode.size();
    originalByte += current->nodeData->frequency*8;
    current = current->next;
  }
  printComparedFileSize(originalByte, compressedByte);
}