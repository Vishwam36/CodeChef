// By Vishwam Shriram Mundada
// https://www.codechef.com/START17B/problems/BININV
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin >> t;
	while(t--)
	{
		ll ans = 0;
		int n, m;
		cin >> n >> m;
		vector<string> v(n);
		for(int i = 0; i < n; ++i)
			cin >> v[i];

		map<int, multiset<string> > mp;
		for(int i = 0; i < n; ++i)
		{
			int o = 0, z = 0;
			for(int j = 0; j < m; ++j)
				if(v[i][j] == '1')
					o++;

			mp[o].insert(v[i]);
		}

		string s;
		for(auto it : mp)
			for(auto str : it.second)
				s += str;
		
		int l = s.size();
		vector<int> pre(l+1, 0);

		for(int i = l-1; i >= 0; --i)
		{
			pre[i] = pre[i+1] + (s[i] == '0' ? 1 : 0);

			if(s[i] == '1')
				ans += pre[i];
		}

		cout << ans << endl;
	}
}
