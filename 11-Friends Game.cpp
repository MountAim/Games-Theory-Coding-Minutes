#include<bits/stdc++.h>
using namespace std;

void dfs(int x, int p,int d, vector<int>&depth,vector<vector<int>>&v)
{
    depth[x]=d;
    for(auto itr:v[x])
    {
        if(itr!=p)
        {
            dfs(itr,x,d+1,depth,v);
        }
    }
}

string solve(int n, vector<int> stones, vector<vector<int>>edges){
    int x,y;
    vector<vector<int>>v(n);
    for(int i=0;i<edges.size();i++)
    {
        x=edges[i][0],y=edges[i][1];
        x--;
        y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<int>depth(n);
    dfs(0,-1,0,depth,v);
    for(int i=0;i<n;i++)
    {
        if(stones[i]%2)
        {
            stones[i]--;
        }
        stones[i]/=2;
    }
    vector<int>grundy(n);
    for(int i=0;i<n;i++)
    {
        if(stones[i]%2==0)
        {
            grundy[i]=0;
            continue;
        }
        grundy[i]=depth[i];
    }
    x=0;
    for(int i=0;i<n;i++)
    {
        x^=grundy[i];
    }
    if(x)
    {
        return "Rachel";
    }
    else{
        return "Ross";
    }
}