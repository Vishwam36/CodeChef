// By Vishwam Shriram Mundada
// https://www.codechef.com/START29B/problems/CCD
// Decent

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n, q;
        cin >> n >> q;
        
        string a, b;
        cin >> a >> b;
        
        vector<int> pre(n+1, 0);
        for(int i = 0; i < n; ++i)
        {
            char c1 = a[i], c2 = b[i];
            int diff = 0;
            if(c2 >= c1)
                diff = c2-c1;
            else
                diff = c2+26-c1;
            
            if(i % 2 == 1)
                pre[i+1] = pre[i] - diff;
            else
                pre[i+1] = pre[i] + diff;
            
            pre[i+1] = (pre[i+1] + 26) % 26;
        }
        
        while(q--)
        {
            int l, r;
            cin >> l >> r;
            
            if(pre[r] == pre[l-1])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
