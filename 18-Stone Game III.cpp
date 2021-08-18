#include<bits/stdc++.h>
using namespace std;

int dp[501][501];
int solve(int start,int end,vector<int>&pre){
    if(start==end){
        return 0;
    }
    if(dp[start][end]!=-1)
    {
        return dp[start][end];
    }
    int ans=0;
    for(int i=start;i<end;i++){
        int left=pre[i]- (start-1>=0?pre[start-1]:0);
        int right=pre[end] - pre[i];
        if(left<=right){
            ans=max(ans,left + solve(start,i,pre));
        }
        if(right<=left){
            ans=max(ans,right + solve(i+1,end,pre));
        }
    }
    return dp[start][end]=ans;
}
int stoneGameIII(vector<int> stoneValue) {
    int n=stoneValue.size();   
    memset(dp,-1,sizeof(dp));
    vector<int>pre(n);
    for(int i=0;i<n;i++)
    {
        pre[i]=stoneValue[i];
        if(i!=0)
        {
            pre[i]+=pre[i-1];
        }
    }
    return solve(0,n-1,pre);
}