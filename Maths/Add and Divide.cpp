// By Vishwam Shriram Mundada
// https://www.codechef.com/START13B/problems/ADDNDIV
// Decent

#include <bits/stdc++.h>
using namespace std;

#define ll long 

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
		ll a, b;
		cin >> a >> b;
		
		ll gcd;
		while(a > 1)
		{
			gcd = __gcd(a,b);
			
			if(gcd == 1) // no further factor
				break;

			while(a % gcd == 0)
				a /= gcd;
		}

		if(a == 1) // atleast all prime factors of a are of b also.
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
