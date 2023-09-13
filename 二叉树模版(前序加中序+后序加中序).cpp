// 1.求后序.
inline void BuildPostTree(int root, int l, int r) {
    if (l > r || root >= len) return;
    int i = l;
    while (in[i] != pre[root])
        ++i;

    BuildPostTree(root + 1, l, i - 1);          // 左子树.
    BuildPostTree(root + i - l + 1, i + 1, r);  // 右子树.
    v.push_back(pre[root]);
}
// 2.求前序.
inline void BuildPreTree(int root, int l, int r) {
    if (l > r || root < 0) return;
    int i = l;
    while (i <= r && in[i] != post[root])
        ++i;

    v.push_back(post[root]);
    BuildPreTree(root + i - r - 1, l, i - 1);  // 左子树.
    BuildPreTree(root - 1, i + 1, r);          // 右子树.
}