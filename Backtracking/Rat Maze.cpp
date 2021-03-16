// By Vishwam Shriram Mundada
// https://www.codechef.com/problems/BPHC03
// Stamdard good question

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int c = 0;

bool isValidCell(int x, int y, vector<vector<int> > &a, vector<vector<bool> > &visited, int n)
{
    if(x >= 0 && x < n && y >= 0 && y < n && a[x][y] == 0 && !visited[x][y])
        return true;
    return false;
}

void paths(int i, int j, vector<vector<int> > &a, vector<vector<bool> > &visited, int n)
{
    if(!isValidCell(i, j, a, visited, n))
        return;
    
    if(i == n-1 && j == n-1)
    {
        c++;
        return;
    }
    
    visited[i][j] = true;
    
    paths(i-1, j, a, visited, n);
    paths(i+1, j, a, visited, n);
    paths(i, j-1, a, visited, n);
    paths(i, j+1, a, visited, n);
    
    visited[i][j] = false;
}

int main()
{
    c = 0;
    int n = 0;
    cin >> n;
    
    vector<vector<int> > a(n, vector<int>(n, 0));
    vector<vector<int> > ans(n, vector<int>(n, -1));
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    
    vector<vector<bool> > visited(n, vector<bool>(n, false));
    
    paths(0, 0, a, visited, n);
    
    cout << c << endl;
}
