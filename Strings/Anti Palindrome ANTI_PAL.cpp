// By Vishwam Shriram Mundada
// https://www.codechef.com/START24B/problems/ANTI_PAL
// Decent

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		string s;
		cin >> s;

		if(n % 2 == 1)
		{
			cout << "NO\n";
		}
		else
		{
			bool can = 1;
			vector<int> f(26);
			for(auto ch : s)
			{
				f[ch-'a']++;
				if(f[ch-'a'] > n/2)
				{
					can = 0;
					break;
				}
			}

			if(can)
			{
				priority_queue<pair<int, char> > pq;
				for(int i = 0; i < 26; ++i)
					if(f[i] > 0)
						pq.push({f[i], 'a'+i});

				cout << "YES\n";
				string ss(n, ' ');
				int i = 0;

				while(pq.size() > 1)
				{
					auto p = pq.top(); pq.pop();
					auto q = pq.top(); pq.pop();

					ss[i] = p.second;
					ss[n-1-i] = q.second;
					i++;
					p.first--;
					q.first--;

					if(p.first > 0)
						pq.push(p);
					if(q.first > 0)
						pq.push(q);
				}
				cout << ss << '\n';
			}
			else
			{
				cout << "NO\n";
			}
		}
	}
}
