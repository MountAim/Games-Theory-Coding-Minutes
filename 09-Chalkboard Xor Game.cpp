#include<bits/stdc++.h>
using namespace std;

bool xorGame(vector<int> nums) {
    int val=0,n=nums.size();
    for(auto itr:nums)
    {
        val^=itr;
    }
    return val==0 || n%2==0;
}