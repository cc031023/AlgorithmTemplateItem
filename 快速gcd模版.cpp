#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) // a,b不能为0
{
    while (b ^= a ^= b ^= a %= b)
        ;
    return a;
}
inline int gcd(int a, int b) // a,b可以为0.
{
    if (b)
        while ((a %= b) && (b %= a))
            ;
    return a + b;
}