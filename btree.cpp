#include "btree.hpp"
#include <iostream>
#include <queue>

namespace bt {

static PNode build_balanced_aux(int h, int n) {
    if (h-- < 0)
        return nullptr;
    return new Node{n, build_balanced_aux(h, n + 1),
                    build_balanced_aux(h, n + 1)};
}

PNode build_balanced(int h) {
    return build_balanced_aux(h, 1);
}

static PNode build_aux(const std::vector<std::optional<int>>& v, int i, int n) {
    PNode root = nullptr;
    if (i < n && v[i]) {
        root = new Node{v[i].value(), nullptr, nullptr};
        root->left = build_aux(v, 2 * i + 1, n);
        root->right = build_aux(v, 2 * i + 2, n);
    }
    return root;
}

PNode build(const std::vector<std::optional<int>>& v) {
    return build_aux(v, 0, v.size());
}

PNode build(const std::vector<std::optional<int>>&& v) {
    return build_aux(v, 0, v.size());
}

static void dfs_pre_aux(const PNode t, std::vector<std::optional<int>>& v) {
    if (!t) {
        v.push_back({});
        return;
    }

    v.push_back(t->key);
    dfs_pre_aux(t->left, v);
    dfs_pre_aux(t->right, v);
}

static void dfs_in_aux(const PNode t, std::vector<std::optional<int>>& v) {
    if (!t) {
        v.push_back({});
        return;
    }

    dfs_in_aux(t->left, v);
    v.push_back(t->key);
    dfs_in_aux(t->right, v);
}

static void dfs_post_aux(const PNode t, std::vector<std::optional<int>>& v) {
    if (!t) {
        v.push_back({});
        return;
    }

    dfs_post_aux(t->left, v);
    dfs_post_aux(t->right, v);
    v.push_back(t->key);
}

std::vector<std::optional<int>> dfs(const PNode t, std::string order) {
    std::vector<std::optional<int>> v;

    if (order == "pre-order")
        dfs_pre_aux(t, v);
    else if (order == "in-order")
        dfs_in_aux(t, v);
    else if (order == "post-order")
        dfs_post_aux(t, v);

    return v;
}

std::vector<std::optional<int>> bfs(const PNode t) {
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

/* void insert(PNode root, int x) { */
/*     PNode y = nullptr; */
/*     PNode t = root; */
/*     while (t) { */
/*         y = x; */
/*     } */
/* } */

static void print_aux(const std::string& prefix, const PNode node,
                      bool isLeft) {
    std::cout << prefix;
    std::cout << (isLeft ? "├── " : "└── ");

    if (!node) {
        std::cout << "N" << std::endl;
        return;
    }

    std::cout << node->key << std::endl;
    print_aux(prefix + (isLeft ? "│   " : "    "), node->left, true);
    print_aux(prefix + (isLeft ? "│   " : "    "), node->right, false);
}

void print(const PNode node) {
    print_aux("", node, false);
}

static void flush_aux(PNode t) {
    if (!t)
        return;

    flush_aux(t->left);
    flush_aux(t->right);

    delete t;
}

void flush(PNode t) {
    flush_aux(t);
}

} // namespace bt
