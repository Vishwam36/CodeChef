// By Vishwam Shriram Mundada
// https://www.codechef.com/START25B/problems/EQUALMEX
// Easy

/**
 * @author Vishwam Shriram Mundada
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
 
	while(t--)
	{
		int n;
		cin >> n;

		vector<int> a(2*n);
		map<int, int> m;
		for(int i = 0; i < 2*n; ++i)
		{
			cin >> a[i];
			m[a[i]]++;
		}

		string ans = "YES";
		for(int i = 0; i <= n; ++i)
		{
			if(m[i] == 0)
			{
				break;
			}
			if(m[i] == 1)
			{
				ans = "NO";
				break;
			}
		}
		cout << ans << '\n';
	}
}
