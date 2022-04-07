/**
 * @author Vishwam Shriram Mundada
 * @link https://www.codechef.com/START33B/problems/DISTDILEM
 * @brief easy binary search
 */

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

ll find(ll sum)
{
	ll l = 0, r = 1e9;
	while(r-l > 1)
	{
		ll mid = (l+r)/2;
		if(((mid)*(mid+1))/2 > sum)
			r = mid;
		else
			l = mid;
	}

	if(((r)*(r+1))/2 <= sum)
		return r;
	return l;
}

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n = 0;
		cin >> n;
		vector<int> a(n);
		ll sum = 0;
		for(int i = 0; i < n; ++i)
		{
			cin >> a[i];
			sum += (ll)a[i];
		}

		cout << find(sum) << '\n';
		
	}
}
