//
// Created by Abner Correa on 3/7/22.
//

#ifndef ALGORITHMS_C_BINARYTREE_H
#define ALGORITHMS_C_BINARYTREE_H

#include <vector>
#include <queue>
#include <stddef.h>
#include "commonutils.h"

template <class T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

template <class T>
class BinaryTree {
protected:
    BinaryTreeNode<T> *root;

    void insert(BinaryTreeNode<T> **nodeP, T data) {
        BinaryTreeNode<T> *node = *nodeP;

        if (!node) {
            *nodeP = new BinaryTreeNode(data);
            return;
        }

        if (data <= node->data) {
            insert(&node->left, data);
        } else {
            insert(&node->right, data);
        }
    }

    int height(BinaryTreeNode<T> *node) {
        if (!node) return 0;

        return 1 + max(height(node->left), height(node->right));
    }

    void preOrder(BinaryTreeNode<T> *node, std::vector<T> &result) {
        if (! node) return;

        result.push_back(node->data);
        preOrder(node->left, result);
        preOrder(node->right, result);
    }

    void inOrder(BinaryTreeNode<T> *node, std::vector<T> &result) {
        if (! node) return;

        inOrder(node->left, result);
        result.push_back(node->data);
        inOrder(node->right, result);
    }

    void postOrder(BinaryTreeNode<T> *node, std::vector<T> &result) {
        if (! node) return;

        postOrder(node->left, result);
        postOrder(node->right, result);
        result.push_back(node->data);
    }

    std::vector<T> levelOrder(BinaryTreeNode<T> *node) {
        std::vector<T> result;
        if (! node) return result;
        std::queue<BinaryTreeNode<T> *> q;
        q.push(node);
        while (!q.empty()) {
            BinaryTreeNode<T>* n = q.front();
            result.push_back(n->data);
            q.pop();
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
        return result;
    }

    BinaryTreeNode<T> *lowestCommonAncestor(BinaryTreeNode<T> *node, T low, T high) {
        if (!node) return NULL;

        if (low <= node->data && high >= node->data) {
            return node;
        }
        else if (low <= node->data) {
            return lowestCommonAncestor(node->left, low, high);
        }
        else {
            return lowestCommonAncestor(node->right, low, high);
        }
    }

    void buildBST(std::vector<T> data, int start, int end) {
        if (start > end) return;

        int mid = (start + end) / 2;

        insert(data[mid]);

        buildBST(data, start, mid - 1);
        buildBST(data, mid + 1, end);
    }

public:
    BinaryTree(std::vector<T> data) {
        std::sort(data.begin(), data.end());

        buildBST(data, 0, data.size() - 1);
    }

    void insert(T data) {
        insert(&root, data);
    }

    int height() {
        return height(root);
    }

    std::vector<T> preOrder() {
        std::vector<T> result;
        preOrder(root, result);
        return result;
    }

    /*
     * The result vector is sorted.
     */
    std::vector<T> inOrder() {
        std::vector<T> result;
        inOrder(root, result);
        return result;
    }

    std::vector<T> postOrder() {
        std::vector<T> result;
        postOrder(root, result);
        return result;
    }

    std::vector<T> levelOrder() {
        return levelOrder(root);
    }

    BinaryTreeNode<T> *lowestCommonAncestor(T v1, T v2) {
        int h = max(v1, v2), l = min(v1, v2);

        return lowestCommonAncestor(root, l, h);
    }
};

#endif //ALGORITHMS_C_BINARYTREE_H
