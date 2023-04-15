#include <bits/stdc++.h>
using namespace std;
vector<int> next1;
inline void getNext(string s2, int len2)
{
    next1.push_back(-1);
    int i = 0, j = -1; // 一前一后.
    while (i < len2)
    {
        if (j == -1 || s2[i] == s2[j])
        {
            next1.push_back(++j);
            ++i;
        }
        else
        {
            j = next1[j];
        }
    }
    return;
}
inline void KMP(string s1, string s2, int len1, int len2)
{
    int i = 0, j = 0;
    while (i < len1)
    {
        if (j == -1 || s1[i] == s2[j]) // 匹配成功继续往前推进.
        {
            ++i, ++j;
        }
        else
        {
            j = next1[j];
        }
        if (j == len2)
        {
            cout << i - len2 + 1 << endl;
            j = next1[j];
        }
    }
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.length();
    int len2 = s2.length();
    getNext(s2, len2);
    KMP(s1, s2, len1, len2);
    for (auto x : next1)
    {
        if (x != -1)
        {
            cout << x << " ";
        }
    }
    return 0;
}