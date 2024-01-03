#pragma once

#include <optional>
#include <string>
#include <vector>

struct Node {
    int key;
    Node* left;
    Node* right;
};

typedef Node* PNode;

namespace bt {
PNode build(const std::vector<std::optional<int>>& v);
PNode build(const std::vector<std::optional<int>>&& v);
PNode build_balanced(int h);

std::vector<std::optional<int>> dfs(const PNode t, std::string order);
std::vector<std::optional<int>> bfs(const PNode t);

void print(const PNode t);
void flush(PNode t);
} // namespace bt
