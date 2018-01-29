#include "BSTNode.h"

BSTNode::BSTNode()
  : parent_(nullptr)
  , left_(nullptr)
  , right_(nullptr)
  , value_(0) {
}

BSTNode::BSTNode(BSTNode* parent, int value)
  : parent_(parent)
  , left_(nullptr)
  , right_(nullptr)
  , value_(value) {
}

BSTNode::~BSTNode() {
    if (parent_) {
        // If this node has a parent check if it is
        // still connected as one (or both - checking
        // just in case someone wrongly used the structure)
        // of its children.
        if (parent_->left_ == this) {
            parent_->left_ = nullptr;
        }
        if (parent_->right_ == this) {
            parent_->right_ = nullptr;
        }
        parent_ = nullptr;
    }

    if (right_) { // Disconnect right subtree.
        if (right_->parent_ == this) {
            right_->parent_ = nullptr;
        }
        right_ = nullptr;
    }

    if (left_) { // Disconnect left subtree.
        if (left_->parent_ == this) {
            left_->parent_ = nullptr;
        }
        left_ = nullptr;
    }
}
