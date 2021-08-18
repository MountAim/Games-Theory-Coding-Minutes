#include<bits/stdc++.h>
using namespace std;

string solve(int n, vector<int> a){
    int maxPile= *max_element(a.begin(),a.end());
    int numStones= accumulate(a.begin(),a.end(),0);

    if(maxPile*2 >numStones || (numStones&1)){
        return "T";
    }
    else{
        return "HL";
    }
}