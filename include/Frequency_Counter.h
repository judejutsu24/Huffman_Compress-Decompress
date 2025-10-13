#ifndef FREQUENCY_COUNTER
#define FREQUENCY_COUNTER
#include "Data_Structure.h"
#include "Priority_Queue.h"

class FrequencyCounter{
  private:
    unsigned short frequencyTable[asciiLimit] = {0}; 
  public:
    void countCharacterFrequency(const std::string &userFile);
    void TabletoPriorityQueue(PriorityQueue &queue); 
};

#endif