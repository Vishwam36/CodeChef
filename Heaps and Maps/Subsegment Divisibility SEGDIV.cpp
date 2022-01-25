// By Vishwam Shriram Mundada
// https://www.codechef.com/COOK137B/problems/SEGDIV
// Decent

#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<int> ans;

bool fit(int num, vector<int> &pre)
{
	bool f = true;
	ans.push_back(num);
	pre.push_back(pre.back()+num);
	int n = ans.size();

	for(int i = 2; i <= n && f; ++i)
	{
		int sum = pre[n-1] - (n-1-i >= 0 ? pre[n-1-i] : 0);
		if(sum % i == 0)
			f = false;
	}

	ans.pop_back();
	pre.pop_back();

	return f;
}

void init()
{
	set<int> s;
	for(int i = 2; i <= 100000; ++i)
		s.insert(i);
	
	ans = vector<int>({1});
	vector<int> pre = ans;
	int temp = 500;
	while(temp--)
	{
		for(auto it : s)
		{
			if(fit(it, pre))
			{
				s.erase(s.find(it));
				ans.push_back(it);
				pre.push_back(pre.back()+it);
				break;
			}
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	init();

	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		for(int i = 0; i < n; ++i)
			cout << ans[i] << " ";
		cout << '\n';
	}
}
