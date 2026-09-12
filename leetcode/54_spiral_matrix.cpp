#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //  right= 0
    //  down= 1
    //  left= 2
    //  up= 3


    pair<int,int> nextPos(int h, int k, int dir){
        vector<int> dh = {0,1,0,-1};
        vector<int> dk = {1,0,-1,0};

        return {h+dh[dir], k+dk[dir]};
    }

    int nextDir(int dir){
        return (++dir)%4;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dir = 0;
        int h = 0;
        int k = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int flag =0;

        vector<int> spiral;

        for(int i=0; i<m; i++){
            for(int j = 0; j<n; j++){
                spiral.push_back(matrix[h][k]);
                matrix[h][k] = -101;

                auto p = nextPos(h, k, dir);
                
                int count =0;
                while(p.first>=m || p.second>=n || p.first <0 ||p.second<0 || matrix[p.first][p.second] == -101){
                    dir = nextDir(dir);
                    p = nextPos(h, k, dir);
                    count++;
                
                    if(count>3){
                    flag =1;
                    break;
                    }
                }
                
                h = p.first;
                k = p.second;
            }
            if(flag == 1) break;
        }
        return spiral;
    }
};