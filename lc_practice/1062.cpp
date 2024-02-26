#include <iostream>
#include <vector>
#include <limits>

// Assume 32-bit integers, change this if you're using a different integer size
const int INT_BITS = 32;

class TrieNode {
public:
    TrieNode* children[2];

    TrieNode() {
        children[0] = children[1] = nullptr;
    }
};

void insert(TrieNode* root, int key) {
    TrieNode* node = root;

    for (int i = INT_BITS - 1; i >= 0; i--) {
        bool currentBit = (key & (1 << i));
        if (node->children[currentBit] == nullptr) {
            node->children[currentBit] = new TrieNode();
        }
        node = node->children[currentBit];
    }
}

int findMaximumXOR(TrieNode* root, const std::vector<int>& arr) {
    int maxXOR = std::numeric_limits<int>::min();

    for (int num : arr) {
        TrieNode* node = root;
        int currentXOR = 0;

        for (int i = INT_BITS - 1; i >= 0; i--) {
            bool currentBit = (num & (1 << i));
            bool oppositeBit = !currentBit;
            
            if (node->children[oppositeBit] != nullptr) {
                currentXOR |= (1 << i);
                node = node->children[oppositeBit];
            } else {
                node = node->children[currentBit];
            }
        }
        maxXOR = std::max(maxXOR, currentXOR);
    }

    return maxXOR;
}

int main() {
    std::vector<int> arr = {8, 2, 4, 12, 1}; // Example array

    TrieNode* root = new TrieNode();
    for (int num : arr) {
        insert(root, num);
    }

    int maxXOR = findMaximumXOR(root, arr);

    std::cout << "The highest value possible by XORing subarrays is: " << maxXOR << std::endl;

    return 0;
}