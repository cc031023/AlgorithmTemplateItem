#include <bits/stdc++.h>
using namespace std;
inline int gcd(int a, int b) // 非0才行,遇到0自己特判一下. 
{
    while (b ^= a ^= b ^= a %= b);
    return a;
}
