#include "btree.hpp"
#include <iostream>

int main() {
    PNode root = bt::build_balanced(3);
    bt::print(root);
    std::vector<std::optional<int>> v = bt::dfs(root, "pre-order");
    for (auto x : v) {
        if (x)
            std::cout << x.value() << ", ";
        else
            std::cout << "N, ";
    }
    std::cout << std::endl;
    bt::flush(root);
}
