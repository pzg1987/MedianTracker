#ifndef BST_MEDIAN_TRACKER_H
#define BST_MEDIAN_TRACKER_H

struct BSTNode;

// BSTMedianTracker is a class that tracks the median value of a growing set of random integer numbers.
// The numbers are kept in a Binary Search Tree. This means that traversing the tree in order will return
// a sorted set of growing numbers. The fact that the subsequently inserted numbers are unsorted and random
// causes the tree to be balanced. That means inserting a new value as well as finding a predecessor or
// successor to any value has a complexity of O(log(n)). Creation of such a tree requires a single insertion
// for each new number, so the whole median tracking approach represented by the BSTMedianTracker has a
// time complexity of O(n log(n)) and a space complexity of O(n), as each tree node represents a single number.
class BSTMedianTracker {
public:
    BSTMedianTracker();
    virtual ~BSTMedianTracker();

    void InsertNumber(int number);

    float GetMedian() const { return medianValue_; }

private:
    BSTNode* GetMaximumNode(BSTNode* subtreeRoot) const;
    BSTNode* GetMinimumNode(BSTNode* subtreeRoot) const;
    BSTNode* GetSuccessorNode(BSTNode* subtreeRoot) const;
    BSTNode* GetPredecessorNode(BSTNode* subtreeRoot) const;

    void InsertNewValue(int value);

    BSTNode* root_;
    BSTNode* medianNode_;

    int nodeCount_;

    float medianValue_;
};

#endif // BST_MEDIAN_TRACKER_H
