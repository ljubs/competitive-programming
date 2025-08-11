#include <iostream>
#include <vector>

class SegmentTree {
private:
    std::vector<int> arr;
    int arraySize;

    void createTree(int node, int segmentStart, int segmentEnd) {
        if (segmentStart == segmentEnd) {
            arr[node] = 1;
            return;
        }
        int mid = (segmentStart + segmentEnd) / 2;
        createTree(node * 2, segmentStart, mid);
        createTree(node * 2 + 1, mid + 1, segmentEnd);
        arr[node] = arr[node * 2] + arr[node * 2 + 1];
    }

    int queryHelper(int node, int segmentStart, int segmentEnd, int rangeStart, int rangeEnd) {
        if (rangeStart > rangeEnd)
            return 0;
        
        if (segmentStart >= rangeStart && segmentEnd <= rangeEnd)
            return arr[node];

        if (segmentEnd < rangeStart || segmentStart > rangeEnd)
            return 0;

        int mid = (segmentStart + segmentEnd) / 2;
        int leftSum = queryHelper(node * 2, segmentStart, mid, rangeStart, rangeEnd);
        int rightSum = queryHelper(node * 2 + 1, mid + 1, segmentEnd, rangeStart, rangeEnd);
        return leftSum + rightSum;
    }

    void updateHelper(int node, int segmentStart, int segmentEnd, int idx, int val) {
        if (segmentStart == segmentEnd) {
            arr[node] = val;
            return;
        }

        int mid = (segmentStart + segmentEnd) / 2;
        if (idx <= mid)
            updateHelper(node * 2, segmentStart, mid, idx, val);
        else
            updateHelper(node * 2 + 1, mid + 1, segmentEnd, idx, val);

        arr[node] = arr[node * 2] + arr[node * 2 + 1];
    }
public:
    SegmentTree(int size) {
        arraySize = size;
        arr.resize(4 * arraySize, 0);
        createTree(1, 0, arraySize - 1);
    }

    int query(int rangeStart, int rangeEnd) {
        return queryHelper(1, 0, arraySize - 1, rangeStart, rangeEnd);
    }
    
    void update(int idx, int val) {
        updateHelper(1, 0, arraySize - 1, idx, val);
    }
};

int main() {
    int numberOfElements;
    std::cin >> numberOfElements;
    std::vector<int> numbers(numberOfElements);
    std::vector<int> positions(numberOfElements + 1);
    SegmentTree segmentTree(numberOfElements);

    for (int i = 0; i < numberOfElements; i++) {
        std::cin >> numbers[i];
        positions[numbers[i]] = i;
    }

    int smallest = 1;
    int biggest = numberOfElements;
    for (int phase = 1; phase <= numberOfElements; phase++) {
        int swaps = 0;
        if (phase % 2 != 0) {
            int position = positions[smallest];
            swaps = segmentTree.query(0, position - 1);
            segmentTree.update(position, 0);
            smallest++;
        } else {
            int position = positions[biggest];
            swaps = segmentTree.query(position + 1, numberOfElements - 1);
            segmentTree.update(position, 0);
            biggest--;
        }
        std::cout << swaps << std::endl;
    }

    return 0;
}