// 1.求后序.
inline void BuildPostTree(int root, int l, int r)
{
    if (l > r || root >= len)
    {
        return;
    }
    int i = l;
    while (in[i] != pre[root])
    {
        ++i;
    }
    buildTree(root + 1, l, i - 1);         // 左子树.
    buildTree(root + i - l + 1, i + 1, r); // 右子树.
    v.push_back(pre[root]);
}
// 2.求前序.
inline void buildPreTree(int root, int l, int r)
{
    if (l > r || root < 0)
    {
        return;
    }
    int i = l;
    while (i <= r && in[i] != post[root])
    {
        ++i;
    }
    ans.push_back(post[root]);
    buildPreTree(root + i - r - 1, l, i - 1); // 左子树.
    buildPreTree(root - 1, i + 1, r);         // 右子树.
}