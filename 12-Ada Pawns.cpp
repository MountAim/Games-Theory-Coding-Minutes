#include<bits/stdc++.h>
using namespace std;

string solve( string board){
    int n=board.size(),last=-1;
    vector<int>temp;
    for(int i=0;i<n;i++)
    {
        if(board[i]=='P')
        {
            temp.push_back(i-last-1);
            last=i;
        }
    }
    int xor_sum=0;
    reverse(temp.begin(),temp.end());
    for(int i=0;i<temp.size();i+=2)
    {
        xor_sum^=(temp[i]%3);
    }
    if(xor_sum)
    {
        return "Yes";
    }
    else{
        return "No";
    }
}