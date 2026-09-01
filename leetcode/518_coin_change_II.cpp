#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int> ways(amount+1, 0);

        ways[0]=1;

        for(int c:coins){
            for(int j=c; j<=amount; j++){
                ways[j] = ways[j] + ways[j-c];
            }
        }
        return ways[amount];
    }
};