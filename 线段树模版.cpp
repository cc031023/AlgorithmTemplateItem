#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
long long a[N];
long long v[(N << 2)], f[(N << 2)];
inline void buildTree(int k, int l, int r) {
    if (l == r) {
        f[k] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(k * 2, l, mid);
    buildTree(k * 2 + 1, mid + 1, r);
    f[k] = f[2 * k] + f[2 * k + 1];
    return;
}
inline void addNumber(int k, int l, int r, int x, int y, long long z) {
    if (l == x && r == y) {
        v[k] += z;
        return;
    }
    f[k] += (y - x + 1) * z;
    int mid = (l + r) >> 1;
    if (y <= mid)
        addNumber(k * 2, l, mid, x, y, z);
    else if (x > mid)
        addNumber(k * 2 + 1, mid + 1, r, x, y, z);
    else
        addNumber(k * 2, l, mid, x, mid, z),
            addNumber(k * 2 + 1, mid + 1, r, mid + 1, y, z);
}
inline long long calculate(int k, int l, int r, int x, int y, long long p) {
    p += v[k];
    if (l == x && r == y)
        return p * (y - x + 1) + f[k];
    int mid = (l + r) >> 1;
    if (y <= mid)
        return calculate(k * 2, l, mid, x, y, p);
    else if (x > mid)
        return calculate(k * 2 + 1, mid + 1, r, x, y, p);
    else
        return calculate(k * 2, l, mid, x, mid, p) +
               calculate(k * 2 + 1, mid + 1, r, mid + 1, y, p);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    buildTree(1, 1, n);
    while (m--) {
        int opt;
        cin >> opt;
        if (opt & 1) {
            int x, y;
            long long z;
            cin >> x >> y >> z;
            addNumber(1, 1, n, x, y, z);  // 某区间x,y内所有数加上z
        } else {
            int x, y;
            cin >> x >> y;
            cout << calculate(1, 1, n, x, y, 0ll) << endl;  // 计算区间x,y的和.
        }
    }
    return 0;
}
