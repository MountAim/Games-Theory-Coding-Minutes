#include<bits/stdc++.h>
using namespace std;

string solve(int d,int k){
    long long x=0,y=0;
    while(true){
        if(x<=y && ((x+k)*(x+k) + y*y)<= (long long)d*(long long)d){
            x+=k;
        }
        else
        if(x>y &&  ((y+k)*(y+k) + x*x)<= (long long)d*(long  long)d){
            y+=k;
        }
        else{
            break;
        }
    }
    if(x==y)
    {
        return "Utkarsh";
    }
    else{
        return "Ashish";
    }
}