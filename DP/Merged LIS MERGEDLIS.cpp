// By Vishwam Shriram Mundada
// https://www.codechef.com/COOK137B/problems/MERGEDLIS
// Decent

#include <bits/stdc++.h>
using namespace std;

void insert(int x, vector<int> &v)
{
	int idx = upper_bound(v.begin(), v.end(), x) - v.begin();
	if(idx >= v.size())
		v.push_back(x);
	else
		v[idx] = x;
}

int lis(vector<int> &a)
{
	vector<int> v;
	for(auto x : a)
		insert(x, v);

	return v.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;

	while(t--)
	{
		int n, m;
		cin >> n >> m;

		vector<int> a(n), b(m);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < m; ++i)
			cin >> b[i];
		
		cout << lis(a) + lis(b) << '\n';
	}
}
