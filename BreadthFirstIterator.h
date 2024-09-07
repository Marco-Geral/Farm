#ifndef BREADTHFIRSTITERATOR_H
#define BREADTHFIRSTITERATOR_H
#include "Iterator.h"
#include "FarmLand.h"
#include <queue>

class BreadthFirstIterator : public Iterator {
private:
    std::queue<FarmUnit*> bfsQueue;  // Queue for BFS
    FarmUnit* current;  // Pointer to current farm

public:
    BreadthFirstIterator(FarmLand* root);

    void firstFarm() override;
    void next() override;
    bool isDone() override;
    FarmUnit* currentFarm() override;
};

#endif
