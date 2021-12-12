// By Vishwam Shriram Mundada
// https://www.codechef.com/problems/DISTELE
// Decent

/**
 * let f1, f2, f3 ... be frequencies of elements
 * The answer comes out to be 
 * f1 + f2 + f3 .... (taking subsets containing 1 element at a time)
 * + f1f2 + f2f3 + f1f3 + ... (taking subsets containing 2 elements at a time)
 * + f1f2f3 ... (taking subsets containing 3 elements at a time)
 * The formula becomes (1+f1)(1+f2)(1+f3)... -1
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		
		vector<ll> a(n);
		for(ll i = 0; i < n; ++i)
			cin >> a[i];
		
		unordered_map<ll, ll> m;
		for(auto x : a)
			m[x]++;
		
		ll ans = 1;
		for(auto it : m)
		{
			ans *= (1+it.second);
			ans %= mod;
		}
		cout << (ans+mod-1)%mod << endl;
	}
}
