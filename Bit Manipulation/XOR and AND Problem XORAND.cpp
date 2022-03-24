/**
 * @author Vishwam Shriram Mundada
 * @link https://www.codechef.com/START31B/problems/XORAND
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin >> n;

		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		
		vector<vector<int> > pre(n, vector<int>(32, 0));

		for(int i = 0; i < n; ++i)
		{
			bool f = 0;
			for(int j = 31; j >= 0; --j)
			{
				if((((a[i]) & (1 << j)) != 0) && (f == 0))
				{
					pre[i][j] = (i-1 >= 0 ? pre[i-1][j] : 0) + 1;
					f = 1;
				}
				else
				{
					pre[i][j] = (i-1 >= 0 ? pre[i-1][j] : 0);
				}
			}
		}

		ll ans = 0;
		for(int i = 1; i < n; ++i)
			for(int j = 31; j >= 0; --j)
				if(((a[i]) & (1 << j)) != 0)
				{
					ans += max(0, pre[i][j]-1);
					break;
				}

		cout << ans << '\n';
	}
}
