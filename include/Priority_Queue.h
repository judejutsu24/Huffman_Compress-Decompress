#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "Data_Structure.h"
#include "Dictionary.h"
#include "Gui.h"

class PriorityQueue{
  private:
    Node* front;
    Node* queueCopy;
    std::string treeKey;
    std::string encode(NodeData* nodeData, char &character);
    void insertSortNode(NodeData* &newNode, Node* &node);
    void mergeNode(NodeData* leftNode, NodeData* rightNode);
  public:
    PriorityQueue() : front(nullptr), queueCopy(nullptr) {}
    ~PriorityQueue();
    std::string getTreeKey();
    void formatTreeKey();
    void traversePreOrder(NodeData* nodeData);
    void enqueueNode(char character, int frequency);
    void dequeue(Node* &queue);
    void backupNode(char character, int frequency);
    void buildHuffmanTree(Dictionary &objDictionary);
    void displayQueue();
    void buildTree();
};

#endif