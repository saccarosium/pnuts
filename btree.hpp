#pragma once

struct Node {
    int key;
    Node* left;
    Node* right;
};

typedef Node* PNode;

void btreePrint(const PNode t);
void btreeFlush(PNode t);
PNode btBuildBalanced(int h);
