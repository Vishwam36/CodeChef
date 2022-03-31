/**
 * @author Vishwam Shriram Mundada
 * @brief Good question, map, priority_queue
 * @link https://www.codechef.com/START32B/problems/TRAINPLN
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
		ll n;
		cin >> n;

		vector<int> a(n), b(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];

		for(int i = 0; i < n; ++i)
			cin >> b[i];
			
		double ans = 0.0;
		double sum = 0.0;
		int curr = 0;

		unordered_map<int, vector<int> > mp;
		for(int i = 0; i < n; ++i)
			mp[b[i]].push_back(a[i]);
		
		for(auto& it : mp)
			sort(it.second.begin(), it.second.end());
		
		priority_queue<pair<int, int> > pq;
		if(mp[curr].size() > 0) 
			pq.push({mp[curr].back(), curr});
		
		for(int k = 0; k < n; ++k)
		{
			if(pq.size() == 0)
			    break;
			
			double ele = (double)pq.top().first;
			int maxi = pq.top().second; 
			pq.pop();

			if(maxi != -1)
			{
				mp[maxi].pop_back();
				sum += ele;
				ans = max(ans, (sum)/(double)(k+1));
				curr++;

				if(mp[maxi].size() == 0)
					mp.erase(maxi);
				else
					pq.push({mp[maxi].back(), maxi});
				
				if(mp[curr].size() > 0)
					pq.push({mp[curr].back(), curr});
			}
		}

		cout << fixed << setprecision(6) << ans << endl;
	}
}
