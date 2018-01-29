#include "BSTMedianTracker.h"

#include "BSTNode.h"

BSTMedianTracker::BSTMedianTracker()
  : root_(nullptr)
  , medianNode_(nullptr)
  , nodeCount_(0)
  , medianValue_(0.0f) {
}

BSTMedianTracker::~BSTMedianTracker() {
    if (nodeCount_ == 0)
        return;

    BSTNode** nodesToDelete = new BSTNode*[nodeCount_];
    nodesToDelete[0] = root_;
    int nodesToDeleteEnd = 1;
    for (int i = 0; i < nodeCount_; i++) {
        if (nodesToDelete[i]->right_) {
            nodesToDelete[nodesToDeleteEnd] = nodesToDelete[i]->right_;
            nodesToDeleteEnd++;
        }
        if (nodesToDelete[i]->left_) {
            nodesToDelete[nodesToDeleteEnd] = nodesToDelete[i]->left_;
            nodesToDeleteEnd++;
        }
        delete nodesToDelete[i];
        nodesToDelete[i] = nullptr;
    }
    delete[] nodesToDelete;

    root_ = nullptr;
    medianNode_ = nullptr;
}

void BSTMedianTracker::InsertNumber(int number) {
    InsertNewValue(number); // Inserting new value to the BST.

    nodeCount_++; // Keeping track of the size of the BST.

    if (nodeCount_ == 1) { // The first node has just been created.
        medianNode_ = root_;
        medianValue_ = root_->value_;
    } else if (nodeCount_ % 2 == 1) { // Odd number of nodes.
        if (number < medianNode_->value_) { 
            // The new node was added before the median node,
            // so the median is in the right place as for
            // even number of nodes the median node points to
            // the lower node of those two needed to determine
            // the exact medianvalue.
            // But the exact median value needs to be updated.
            medianValue_ = medianNode_->value_;
        } else {
            // The new node was added after the median node,
            // so the median needs to be shifted by one.
            medianNode_ = GetSuccessorNode(medianNode_);
            medianValue_ = medianNode_->value_;
        }
    } else { // Even number of nodes.
        if (number < medianNode_->value_) {
            // The new node was added before the median node,
            // so the exact median value is a mean value of
            // the current median node and its predecessor.
            // Current median node should be shifted so that 
            // it points to its predecessor.
            medianValue_ = medianNode_->value_;
            medianNode_ = GetPredecessorNode(medianNode_);
            medianValue_ += medianNode_->value_;
            medianValue_ /= 2.0f;
        } else {
            // The new node was added after the median node,
            // so the exact median value is a mean value of
            // the current median node and its successor, but
            // the current median node should not be shifted.
            medianValue_ = static_cast<float>(medianNode_->value_ + GetSuccessorNode(medianNode_)->value_) / 2.0f;
        }
    }
}

BSTNode* BSTMedianTracker::GetMaximumNode(BSTNode* subtreeRoot) const {
    BSTNode* maximumNode = subtreeRoot;
    while (maximumNode->right_) {
        maximumNode = maximumNode->right_;
    }

    return maximumNode;
}

BSTNode* BSTMedianTracker::GetMinimumNode(BSTNode* subtreeRoot) const {
    BSTNode* minimumNode = subtreeRoot;
    while (minimumNode->left_) {
        minimumNode = minimumNode->left_;
    }

    return minimumNode;
}

BSTNode* BSTMedianTracker::GetSuccessorNode(BSTNode* subtreeRoot) const {
    BSTNode* node = subtreeRoot;
    if (node->right_) {
        node = GetMinimumNode(node->right_);
    } else {
        while (node->parent_ && node->parent_->right_ == node) {
            node = node->parent_;
        }
        if (node->parent_) {
            node = node->parent_;
        } else {
            node = subtreeRoot;
        }
    }

    return node;
}

BSTNode* BSTMedianTracker::GetPredecessorNode(BSTNode* subtreeRoot) const {
    BSTNode* node = subtreeRoot;
    if (node->left_) {
        node = GetMaximumNode(node->left_);
    } else {
        while (node->parent_ && node->parent_->left_ == node) {
            node = node->parent_;
        }
        if (node->parent_) {
            node = node->parent_;
        } else {
            node = subtreeRoot;
        }
    }

    return node;
}

void BSTMedianTracker::InsertNewValue(int value) {
    if (!root_) {
        root_ = new BSTNode(nullptr, value);
        return;
    }

    BSTNode* node = root_;
    while (true) {
        if (value < node->value_) {
            if (node->left_) {
                node = node->left_;
            } else {
                node->left_ = new BSTNode(node, value);
                return;
            }
        } else { // value >= node->value
            if (node->right_) {
                node = node->right_;
            } else {
                node->right_ = new BSTNode(node, value);
                return;
            }
        }
    }
}
