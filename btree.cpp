#include "btree.hpp"
#include <iostream>
#include <random>

static PNode btBuildBalancedAux(int h, int n) {
    if (h-- < 0)
        return nullptr;
    return new Node{n, btBuildBalancedAux(h, n + 1),
                    btBuildBalancedAux(h, n + 1)};
}

PNode btBuildBalanced(int h) {
    return btBuildBalancedAux(h, 0);
}

static void btPrintAux(const std::string& prefix, const PNode node,
                       bool isLeft) {
    std::cout << prefix;
    std::cout << (isLeft ? "├── " : "└── ");

    if (!node) {
        std::cout << "N" << std::endl;
        return;
    }

    std::cout << node->key << std::endl;
    btPrintAux(prefix + (isLeft ? "│   " : "    "), node->left, true);
    btPrintAux(prefix + (isLeft ? "│   " : "    "), node->right, false);
}

void btPrint(const PNode node) {
    btPrintAux("", node, false);
}

static void btFlushAux(PNode t) {
    if (!t)
        return;

    btFlushAux(t->left);
    btFlushAux(t->right);

    delete t;
}

void btFlush(PNode t) {
    btFlushAux(t);
}

int main() {
    PNode root = btBuildBalanced(2);
    btPrint(root);
    btFlush(root);
}
