#include<bits/stdc++.h>
using namespace std;

int solve(int l,int r,vector<int>&piles,vector<vector<int>>&dp)
{
    if(l>r)
    {
        return 0;
    }
    if(dp[l][r]!=-1)
    {
        return dp[l][r];
    }
    int ans=max(piles[l]-solve(l+1,r,piles,dp),piles[r]-solve(l,r-1,piles,dp));
    return dp[l][r]=ans;
}
bool stoneGame(vector<int> piles) {
    int n=piles.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return solve(0,n-1,piles,dp)>0;
}