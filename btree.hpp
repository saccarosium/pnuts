#pragma once

struct Node {
    int key;
    Node* left;
    Node* right;
};

enum Direction {
    LEFT,
    RIGHT,
};

typedef Node* PNode;

PNode btreeBuildBalanced(int h, bool random);
PNode btreeBuildUnBalanced(int h, Direction d);
void btreePrint(const PNode t);
void btreeFlush(PNode t);
