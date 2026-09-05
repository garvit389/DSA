#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    pair<int, int> newLoc(int i, int j, int n){
        int temp = i;
        i = j;
        j = n-1-temp;
        
        return {i,j};
    }

    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int w=n-1;

        for(int i = 0; i<n/2; i++){
            for(int j = i; j<w; j++){
                int temp = matrix[i][j];
                int x = i;
                int y = j;
                for(int z = 0; z<4; z++){
                    auto [a,b] = newLoc(x,y,n);

                    swap(matrix[a][b], temp);

                    x = a;
                    y = b;
                }
            }
            w--;
        }
    }
};