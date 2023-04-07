#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int prime[N >> 1]; // 质数数量没那么多除2也行.
int vis[N];        // 记录是不是质数.
int cnt;           // 记录prime数组中有几个质数.

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; // 质数最大是多少.
    cin >> n;
    for (int i = 2; i <= n; ++i) // 从2开始枚举质数.
    {
        if (!vis[i]) // 为0代表是质数.
        {
            prime[++cnt] = i; // 存入质数,下标从1开始.
        }
        for (int j = 1; j <= cnt && prime[j] <= n / i; ++j)
        {
            vis[prime[j] * i] = 1; // 标记不是质数的数字.
            if (i % prime[j] == 0) // 后面不用枚举了.
            {
                break; // 每个数的排除只会被他最小的质因数排掉.
            }
        }
    }
    for (int i = 1; i <= cnt; ++i)
    {
        cout << prime[i] << " \n"[i == cnt]; // 输出n以内所有质数.
    }
    return 0;
}
