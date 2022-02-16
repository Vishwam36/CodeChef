// By Vishwam Shriram Mundada
// https://www.codechef.com/START25B/problems/TOWERTOP
// Easy

/**
 * @author Vishwam Shriram Mundada
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll find_power(ll x)
{
	ll i = 0;
	while(1)
	{
		if(x <= pow(2, i))
			return i;
		++i;
	}
	return -1;
}

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		ll x, m;
		cin >> x >> m;

		ll max_p = find_power(x);
		cout << max((long long)0, m - max_p) << '\n';
	}
}
