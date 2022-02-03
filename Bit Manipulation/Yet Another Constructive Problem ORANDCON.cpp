// By Vishwam Shriram Mundada
// https://www.codechef.com/START24B/problems/ORANDCON
// Easy

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int x;
		cin >> x;
		cout << 0 << " " << x << " " << (x | (1<<28)) << '\n';
    }
}
