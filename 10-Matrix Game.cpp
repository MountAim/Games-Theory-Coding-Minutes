#include<bits/stdc++.h>
using namespace std;

string solve(int n,int m, vector<vector<int>> mat){
    int x=0;
    for(int i=0;i<n;i++)
    {
        int ans=0;
        for(int j=m-1;j>=0;j--)
        {
            ans=mat[i][j]-(mat[i][j]<=ans);
        }
        x^=ans;
    }
    if(x)
    {
        return "First";
    }
    else{
        return "Second";
    }
}