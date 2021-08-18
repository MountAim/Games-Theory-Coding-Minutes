#include<bits/stdc++.h>
using namespace std;

bool squareGame(int n){
    vector<bool>dp(n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sqrt(i);j++)
        {
            int x=j*j;
            if(dp[i-x]==false)
            {
                dp[i]=true;
                break;
            }
        }
    }
    return dp[n];
}