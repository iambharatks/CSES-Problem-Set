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
#define PB push_back
#define MP make_pair
#define sz(a) ((int)(a.size()))
#define checkbit(n, b) ((n >> b) & 1)
#define gc getchar_unlocked
#define ll long long
#define F first
#define S second
const ll M = 1000000007;

using namespace std;

vector<pair<int, int>> movements;
void towersOfHanoi(int n, int left, int right, int mid)
{
    if (n == 1)
    {
        movements.push_back({left, right});
        return;
    }
    towersOfHanoi(n - 1, left, mid, right);
    movements.push_back({left, right});
    towersOfHanoi(n - 1, mid, right, left);
}

int main()
{
    int n;
    cin >> n;
    towersOfHanoi(n, 1, 3, 2);
    cout << movements.size() << "\n";
    for (auto i : movements)
        cout << i.F << " " << i.S << "\n";
}