#include<bits/stdc++.h>
using namespace std;

int solve(int start,int end,vector<int>&nums){
    if(start==end){
        return nums[start];
    }
    return max(nums[start]- solve(start+1,end,nums),nums[end] - solve(start,end-1,nums));
}
bool PredictTheWinner(vector<int> nums) {
    int n=nums.size();
    return solve(0,n-1,nums)>=0;
}