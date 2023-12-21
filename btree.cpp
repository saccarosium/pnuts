#include "btree.hpp"
#include <iostream>
#include <random>

PNode btreeBuildBalanced(int h, bool random) {
    if (h-- < 0)
        return nullptr;
    int n = 1;
    if (random) {
        std::random_device rd;
        std::uniform_int_distribution<int> dist(0, 99);
        n = dist(rd);
    }
    return new Node{n, btreeBuildBalanced(h, random),
                    btreeBuildBalanced(h, random)};
}

static void btreePrintAux(const std::string& prefix, const PNode node,
                          bool isLeft) {
    std::cout << prefix;
    std::cout << (isLeft ? "├── " : "└── ");

    if (!node) {
        std::cout << "N" << std::endl;
        return;
    }

    std::cout << node->key << std::endl;
    btreePrintAux(prefix + (isLeft ? "│   " : "    "), node->left, true);
    btreePrintAux(prefix + (isLeft ? "│   " : "    "), node->right, false);
}

void btreePrint(const PNode node) {
    btreePrintAux("", node, false);
}

void btreeFlushAux(PNode t) {
    if (!t)
        return;

    btreeFlushAux(t->left);
    btreeFlushAux(t->right);

    delete t;
}
void btreeFlush(PNode t) {
    btreeFlushAux(t);
}

int main() {
    PNode root = btreeBuildBalanced(2, true);
    btreePrint(root);
    btreeFlush(root);
}
