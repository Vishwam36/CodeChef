// By Vishwam Shriram Mundada
// https://www.codechef.com/START24B/problems/DIVREC
// Decent

#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool can(ll n, ll x, ll a, ll b)
{
	double sq = sqrt(n);
	double z = 0;

	for(ll i = 1; i <= sq; ++i)
	{
		if(n % i == 0 && i*i != n)
		{
			x -= i;
			x -= n/i;
			
			z += (double)(1)/i;
			z += (double)(1)/((double)n/i);
		}
		else if(i*i == n)
		{
			x -= i;
			z += (long double)(1)/i;
		}
	}

	double eps = 1e-5;
	return (x == 0) && abs((((double)a/b) - z)) < eps;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		ll x, a, b;
		cin >> x >> a >> b;
        
        string ans = "-1";
		if((x*b) % a == 0)
		{
			ll n = (x*b)/a; // do mathematical calculations you will get this
			if(n <= x)
				if(can(n, x, a, b))
					ans = to_string(n);
		}
		cout << ans << '\n';
	}
}
