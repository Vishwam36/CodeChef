// By Vishwam Shriram Mundada
// https://www.codechef.com/START19B/problems/P_NP
// Decent

// REF : https://www.youtube.com/watch?v=9yWgafun9uM

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
        string s;
        cin >> s;
        int n = s.size();
        int ans = 0;
        
        int req = n/3;
        
        for(int i = 1; i < n; ++i)
        {
            if(s[i-1] == 'N' && s[i] == 'N')
            {
                ++ans;
                s[i] = 'P';
            }
        }
        
        if(s[n-1] == 'N')
        {
            ans++;
            s[n-1] = 'P';
        }
        
        int ns = 0;
        for(int i = 0; i < n; ++i)
            if(s[i] == 'N')
                ns++;
        
        ans += abs(ns-req);
        cout << ans << '\n';
    }
    
	return 0;
}
