#include <bits/stdc++.h>

#define boost                \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define max1(x, y) (x) > (y) ? (x) : (y)
#define s(n) scanint(n)
#define sc(n) scanf(" %c", &n)
#define sl(n) scanf("%ld", &n)
#define sll(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define ss(n) scanf("%s", n)
#define INF (int)1e9
#define EPS 1e-9
#define bitcount __builtin_popcount
#define gcd __gcd
#define loop(i, a, b) for (ll i = a; i <= b; i++)
#define all(a) a.begin(), a.end()
#define pb push_back
#define sz(a) ((int)(a.size()))
#define mp make_pair
#define checkbit(n, b) ((n >> b) & 1)
#define gc getchar_unlocked
#define ll long long

using namespace std;

int main()
{
    boost;
    string s;
    cin >> s;
    ll freq[26] = {0};
    ll oddCount = 0;
    char oddChar;
    for (char i : s)
        freq[i - 'A']++;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] & 1)
        {
            oddCount++;
            oddChar = i + 'A';
        }
    }
    if (oddCount > 1 || (oddCount == 1 && s.size() % 2 == 0))
    {
        cout << "NO SOLUTION\n";
    }
    else
    {
        string left = "";
        string right = "";
        for (int i = 0; i < 26; i++)
        {
            if (freq[i])
            {
                string t(freq[i] / 2, i + 'A');
                left += t;
                right = t + right;
            }
        }
        if (oddCount == 1)
        {
            cout << left + oddChar + right << "\n";
        }
        else
        {
            cout << left + right << "\n";
        }
    }
}