#include "BreadthFirstIterator.h"

BreadthFirstIterator::BreadthFirstIterator(FarmLand* root) {
    bfsQueue.push(root);  // Start with the root node
    current = nullptr;
    if (bfsQueue.empty()) {
        cout << "Error: bfsQueue is empty at initialization!" << endl;
    }
}

void BreadthFirstIterator::firstFarm() {
    if (!bfsQueue.empty()) {
        current = bfsQueue.front();  // Get the first farm
    }
}

void BreadthFirstIterator::next() {
    if (!bfsQueue.empty()) {
        FarmUnit* farm = bfsQueue.front();  // Get the current farm
        bfsQueue.pop();  // Remove it from the queue

        // If it's a FarmLand, add its units to the queue
        FarmLand* farmLand = dynamic_cast<FarmLand*>(farm);
        if (farmLand) {
            for (FarmUnit* unit : farmLand->units) {
                bfsQueue.push(unit);
            }
        }

        // Set the next current farm
        if (!bfsQueue.empty()) {
            current = bfsQueue.front();
        } else {
            current = nullptr;
        }
    }
}

bool BreadthFirstIterator::isDone() {
    bool empty = bfsQueue.empty();
    return empty;
}

FarmUnit* BreadthFirstIterator::currentFarm() {
    return current;
}
