#pragma once

struct Node {
    int key;
    Node* left;
    Node* right;
};

typedef Node* PNode;

PNode btBuildBalanced(int h);

void btPrint(const PNode t);
void btFlush(PNode t);
