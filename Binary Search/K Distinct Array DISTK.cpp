/**
 * @author Vishwam Shriram Mundada
 * @link https://www.codechef.com/START25B/problems/DISTK
 * @ref https://www.youtube.com/watch?v=NcdlW88qMZ0
 * @brief Good question
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll nc2(ll a)
{
	return (a*(a-1))/2;
}

ll find_x(ll n, ll k)
{
	ll l = 1, r = n;
	while(r-l > 1)
	{
		ll mid = (l+r)/2;
		if(nc2(mid) < k)
			l = mid;
		else
			r = mid;
	}
	if(k >= nc2(l) && k < nc2(r))
		return l;
	return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		ll n, k;
		cin >> n >> k;
		k = k-n;

		ll x = find_x(n, k);
		k -= nc2(x);

		for(int i = 1; i <= x; ++i)
		    cout << i << " ";
		for(int i=  x+1; i <= n; ++i)
		    cout << x-k << " ";
		cout << '\n';
	}
}
