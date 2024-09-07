#include "DepthFirstIterator.h"

DepthFirstIterator::DepthFirstIterator(FarmLand* root) {
    dfsStack.push(root);  // Start with the root node
    current = nullptr;
}

void DepthFirstIterator::firstFarm() {
    if (!dfsStack.empty()) {
        current = dfsStack.top();  // Get the first farm
    }
}

void DepthFirstIterator::next() {
    if (!dfsStack.empty()) {
        FarmUnit* farm = dfsStack.top();  // Get the current farm
        dfsStack.pop();  // Remove it from the stack

        // If it's a FarmLand, add its units to the stack (in reverse order to simulate DFS)
        FarmLand* farmLand = dynamic_cast<FarmLand*>(farm);
        if (farmLand) {
            for (auto it = farmLand->units.rbegin(); it != farmLand->units.rend(); ++it) {
                dfsStack.push(*it);
            }
        }

        // Set the next current farm
        if (!dfsStack.empty()) {
            current = dfsStack.top();
        } else {
            current = nullptr;
        }
    }
}

bool DepthFirstIterator::isDone() {
    return dfsStack.empty();
}

FarmUnit* DepthFirstIterator::currentFarm() {
    return current;
}
