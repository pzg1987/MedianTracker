#ifndef BST_NODE_H
#define BST_NODE_H

struct BSTNode {
    BSTNode();
    BSTNode(BSTNode* parent, int value);
    virtual ~BSTNode();

    BSTNode* parent_;
    BSTNode* left_;
    BSTNode* right_;

    int value_;
};

#endif // BST_NODE_H
