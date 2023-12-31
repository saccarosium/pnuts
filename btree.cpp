#include "btree.hpp"
#include <iostream>
#include <queue>

static PNode btBuildBalancedAux(int h, int n) {
    if (h-- < 0)
        return nullptr;
    return new Node{n, btBuildBalancedAux(h, n + 1),
                    btBuildBalancedAux(h, n + 1)};
}

PNode btBuildBalanced(int h) {
    return btBuildBalancedAux(h, 1);
}

static void btDFSAux(const PNode t, std::vector<std::optional<int>>& v) {
    if (!t) {
        v.push_back({});
        return; 
    }

    btDFSAux(t->left, v);
    v.push_back(t->key);
    btDFSAux(t->right, v);
}

std::vector<std::optional<int>> btDFS(const PNode t) {
    std::vector<std::optional<int>> v;
    btDFSAux(t, v);
    return v;
}

std::vector<std::optional<int>> btBFS(const PNode t) {
    std::queue<PNode> q;
    std::vector<std::optional<int>> v;

    q.push(t);
    while (!q.empty()) {
        PNode tmp = q.front();
        if (tmp) {
            v.push_back(tmp->key);
            q.push(tmp->left);
            q.push(tmp->right);
        } else {
            v.push_back({});
        }
        q.pop();
    }

    return v;
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
    std::vector<std::optional<int>> v = btBFS(root);
    for (const auto& x : v)
        if (x)
            std::cout << x.value() << std::endl;
        else
            std::cout << 'N' << std::endl;
    /* btPrint(root); */
    btFlush(root);
}
