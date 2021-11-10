// By Vishwam Shriram Mundada
// https://www.codechef.com/NOV21B/problems/XOREQN
// Problem Code: XOREQN

// HINT : https://www.youtube.com/watch?v=IexLpOFAdX8

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int arrayXor(vector<ll> &a)
{
	ll ans = 0;
	for(auto x : a)
		ans = ans ^ x;
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t = 0;
	cin >> t;
	while(t--)
	{
        int n;
		cin >> n;
		vector<ll> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		
		if(n % 2 == 0)
		{
			if(arrayXor(a) == 0)
				cout << 0 << endl;
			else
				cout << -1 << endl;
		}
		else
		{
			ll ans = 0;
			for(int k = 0; k <= 62; ++k)
			{
				int setBits = 0;
				for(int i = 0; i < n; ++i)
					if(((a[i]) & (1LL << k)) != 0)
						setBits++;

				if(setBits % 2 != 0)
				{
					ans += (1LL << k);

					for(int i = 0; i < n; ++i)
						a[i] += (1LL << k);
				}
			}

			if(arrayXor(a) == 0 && ans >= 0 && ans <= 1000000000000000000)
				cout << ans << endl;
			else
				cout << -1 << endl;
		}
    }
}
