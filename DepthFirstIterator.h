#ifndef DEPTHFIRSTITERATOR_H
#define DEPTHFIRSTITERATOR_H
#include "Iterator.h"
#include "FarmLand.h"
#include <stack>

class FarmLand;

class DepthFirstIterator : public Iterator {
private:
    std::stack<FarmUnit*> dfsStack;  // Stack for DFS
    FarmUnit* current;  // Pointer to current farm

public:
    DepthFirstIterator(FarmLand* root);

    void firstFarm() override;
    void next() override;
    bool isDone() override;
    FarmUnit* currentFarm() override;
};

#endif
