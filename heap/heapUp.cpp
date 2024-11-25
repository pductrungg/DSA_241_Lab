void reheapDown(int maxHeap[], int numberOfElements, int index) {
    int parent = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    
    // Find the larger child (if it exists)
    int largerChild = parent;
    if (leftChild < numberOfElements && maxHeap[leftChild] > maxHeap[largerChild]) {
        largerChild = leftChild;
    }
    if (rightChild < numberOfElements && maxHeap[rightChild] > maxHeap[largerChild]) {
        largerChild = rightChild;
    }
    
    // If the larger child is different from the parent, swap them and reheapify
    if (largerChild != parent) {
        std::swap(maxHeap[parent], maxHeap[largerChild]);
        // Recursively reheapify downwards
        reheapDown(maxHeap, numberOfElements, largerChild);
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index) {
    if (index <= 0) return; // Base case: already at the root
    
    int parent = (index - 1) / 2;
    
    // If the current element is greater than its parent, swap them
    if (maxHeap[index] > maxHeap[parent]) {
        std::swap(maxHeap[index], maxHeap[parent]);
        // Recursively reheapify upwards
        reheapUp(maxHeap, numberOfElements, parent);
    }
}
