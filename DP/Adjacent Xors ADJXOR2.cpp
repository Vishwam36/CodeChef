// By Vishwam Shriram Mundada
// https://www.codechef.com/submit/ADJXOR2
// REF : https://www.youtube.com/watch?v=n2WkMEXrFa8

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        
        vector<vector<ll> > dp(n, vector<ll>(2, 0));
        
        for(int i = 1; i < n; ++i)
        {
            dp[i][0] = max((a[i]^a[i-1]) + dp[i-1][0], ((a[i-1]+x) ^ a[i]) + dp[i-1][1]);
            dp[i][1] = max(((a[i]+x)^a[i-1]) + dp[i-1][0], ((a[i]+x)^(a[i-1]+x)) + dp[i-1][1]);
        }
        
        cout << max(dp[n-1][0], dp[n-1][1]) << endl;
    }
    
	return 0;
}
