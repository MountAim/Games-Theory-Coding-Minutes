#include<bits/stdc++.h>
using namespace std;

int dp[101][101];
int solve(int pos,int m,vector<int>&a)
{
    if(pos>=a.size())
    {
        return 0;
    }
    if(dp[pos][m]!=-1)
    {
        return dp[pos][m];
    }
    int ans=INT_MIN,cnt=1,val=0;
    for(int i=pos;i<min(pos+2*m,(int)a.size());i++)
    {
        val+=a[i];
        ans=max(ans,val-solve(pos+cnt,max(m,cnt),a));
        cnt++;
    }
    
    return dp[pos][m]=ans;
}
int stoneGameII(vector<int> piles) {
    memset(dp,-1,sizeof(dp));
    int n=piles.size(),sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=piles[i];
    }
    int ans=solve(0,1,piles);
    sum-=ans;
    sum/=2;
    return ans+sum;
}