#include <bits/stdc++.h>
using namespace std;
inline int gcd(int a, int b) // ��0����,����0�Լ�����һ��. 
{
    while (b ^= a ^= b ^= a %= b);
    return a;
}
