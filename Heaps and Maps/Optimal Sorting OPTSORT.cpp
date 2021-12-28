// By Vishwam Shriram Mundada
// https://www.codechef.com/LTIME103B/problems/OPTSORT
// Decent 

// REF : https://www.youtube.com/watch?v=oFFXxfolf7k

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

		vector<ll> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		
		vector<ll> b = a;
		sort(b.begin(), b.end());

		ll ans = 0;
		multiset<ll> sa, sb;

		for(int i = 0; i < n; ++i)
		{
			sa.insert(a[i]);
			sb.insert(b[i]);

			if(sa == sb)
			{
				ans += *sa.rbegin() - *sa.begin();
				sa.clear();
				sb.clear();
			}
		}

		cout << ans << '\n';
	}
}
