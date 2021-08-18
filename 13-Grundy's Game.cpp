#include<bits/stdc++.h>
using namespace std;

int mex(vector<int>&v){
    set<int>s;
    for(int i=0;i<v.size();i++)
    {
        s.insert(v[i]);
    }
    for(int i=0;i<1000001;i++)
    {
        if(s.count(i)==0)
        {
            return i;
        }
    }
}
string solve(int n){
    int limit=2000;
    int dp[limit];
    dp[0]=dp[1]=dp[2]=0;
    for(int i=3;i<limit;i++)
    {
        vector<int>v;
        for(int j=1;2*j<i;j++){
            v.push_back(dp[j]^dp[i-j]);
        }
        dp[i]=mex(v);
    }
    if(n>=limit)
    {
        return "first";
    }
    else{
        if(dp[n]==0)
        {
            return "second";
        }
        else{
            return "first";
        }
    }
}