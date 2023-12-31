#pragma once

#include <optional>
#include <vector>

struct Node {
    int key;
    Node* left;
    Node* right;
};

typedef Node* PNode;

PNode btBuild(const std::vector<int>&& v);
PNode btBuildBalanced(int h);

std::vector<std::optional<int>> btDFS(const PNode t);
std::vector<std::optional<int>> btBFS(const PNode t);

void btPrint(const PNode t);
void btFlush(PNode t);
