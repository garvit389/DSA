#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int C(int n, int r){
        long long c=1;
        for(int i=n, j = 1; i>n-r; i--){
            int d =j;
            c= (c*i)/d;
            j++;
        }

        return (int)c;
    }

    int uniquePaths(int m, int n) {
        int total = (m-1) + (n-1);
        int r = n-1;

        if(n-1>m-1) r = m-1;

        return C(total, r);
    }
};