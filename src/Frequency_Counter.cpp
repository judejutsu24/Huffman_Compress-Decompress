#include <iostream>
#include "../include/Frequency_Counter.h"

void FrequencyCounter::countCharacterFrequency(const std::string &fileContent){
  if (fileContent.empty()){
    std::cout << "\033[33mWARNING: File does not contain text.\033[0m\n";
    return;
  }
  for(auto &character : fileContent)
    if (binarySearch(character, asciiLimit, 0))
      frequencyTable[int(character)]++;
}
void FrequencyCounter::TabletoPriorityQueue(PriorityQueue &queue) {
  for(int i = 0; i < asciiLimit; i++){
    if(frequencyTable[i] != 0){
      queue.enqueueNode(char(i), frequencyTable[i]);
      queue.backupNode(char(i), frequencyTable[i]);
    }
  }
}