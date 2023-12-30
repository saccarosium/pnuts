#pragma once

struct Node {
    int key;
    Node* left;
    Node* right;
};

typedef Node* PNode;

PNode btreeBuildBalanced(int h, bool random);
void btreePrint(const PNode t);
void btreeFlush(PNode t);
