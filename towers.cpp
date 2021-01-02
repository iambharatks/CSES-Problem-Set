#include <bits/stdc++.h>

using namespace std;
#define boost                \
    ios::sync_with_stdio(0); \
    cin.tie(0);
//Example of LONGEST NON~DECREASING SUBSEQUENCE
int main()
{
    boost;
    int n;
    cin >> n;
    vector<long long> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int p = upper_bound(v.begin(), v.end(), a) - v.begin();
        cout << p << " ";
        if (p < v.size())
            v[p] = a, cout << v[p] << "\n";
        else
            v.push_back(a), cout << a << "\n";
    }
    cout << v.size();
}