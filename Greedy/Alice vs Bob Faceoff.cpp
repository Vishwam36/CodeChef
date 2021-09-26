// By Vishwam Shriram Mundada
// https://www.codechef.com/problems/ALBOFACE/
// Decent

// REF : https://www.youtube.com/watch?v=5Xt-Z3c7Qbs

#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool win(ll n)
{
	if(n == 0)
		return 0;
	if(n % 2 != 0)
		return !win(n-1);
	if(n % 4 != 0)
		return !win(n/2);
	return 1;
}

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
		ll n;
		cin >> n;

		if(win(n))
			cout << "Alice" << endl;
		else
			cout << "Bob" << endl;
	}
}
