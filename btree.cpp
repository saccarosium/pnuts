#include "btree.hpp"
#include <iostream>
#include <random>

    if (h-- < 0)
        return nullptr;
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
