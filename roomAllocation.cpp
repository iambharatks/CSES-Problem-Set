#include <bits/stdc++.h>
#define ar array

using namespace std;
const int N = 2e5;
int ans[N];
void print(set<ar<int, 2>> s, ar<int, 3> a[])
{
	for (auto it : s)
	{
		std::cout << a[(it)[1]][1] << " " << a[(it)[1]][0] << " " << a[(it)[1]][2] << " " << ans[(it)[1]] << "\n";
	}
	cout << "\n";
}
int main()
{
	int n;
	cin >> n;
	ar<int, 3> a[n];
	int ind = 0;
	for (auto &i : a)
	{
		cin >> i[1] >> i[0];
		i[2] = ind++;
	}
	sort(a, a + n);
	set<ar<int, 2>> s;
	for (int i = 0; i < n; i++)
	{
		auto it = s.lower_bound({a[i][1]});
		if (it != s.begin())
		{
			--it;
			ans[a[i][2]] = (*it)[1];
			s.erase(it);
		}
		else
		{
			ans[a[i][2]] = s.size();
		}
		s.insert({a[i][0], ans[a[i][2]]});
		print(s, a);
	}
	std::cout << s.size() << "\n";
	for (int i = 0; i < n; ++i)
	{
		std::cout << ans[i] + 1 << " ";
	}
}