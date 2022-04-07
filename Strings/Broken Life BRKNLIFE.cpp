/**
 * @author Vishwam Shriram Mundada
 * @link https://www.codechef.com/START33B/problems/BRKNLIFE
 * @brief Easy 2 pointers subsequence check
 */

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		string s, a;
		cin >> s >> a;

		int i = 0, j = 0;
		while(i < n && j < m)
		{
			if(s[i] == '?')
				s[i] = 'a' + ((a[j]-'a' + 1) % 5);
			else if(s[i] == a[j])
				++j;
			
			i++;
		}

		if(j < m)
			cout << s << '\n';
		else
			cout << -1 << '\n';
	}
}
