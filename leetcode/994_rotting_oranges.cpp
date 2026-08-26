#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> check_neighbor(vector<vector<int>>& grid, int i, int j){

        vector<pair<int,int>> v;

        if(i-1>=0 && grid[i-1][j] == 1) v.push_back({i-1,j});
        if(i+1<grid.size() && grid[i+1][j] == 1) v.push_back({i+1,j});
        if(j-1>=0 && grid[i][j-1] == 1) v.push_back({i,j-1});
        if(j+1<grid[i].size() && grid[i][j+1] == 1) v.push_back({i,j+1});

        return v;        
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rotten;
        vector<pair<int,int>> fresh;
        
        //case for no fresh oranges to begin with
        for(int i = 0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){

                if(grid[i][j] == 1) fresh.push_back({i,j});
            }
        }
        if(fresh.empty()) return 0;

        //normal cases
        int minute = -1;

        for(int i = 0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){

                if(grid[i][j] == 2) rotten.push({i,j});
            }
        }

        while(!(rotten.empty())){
            int count = rotten.size();
            minute++;
            while(count){
                auto [i,j] = rotten.front();
                vector<pair<int,int>> v = check_neighbor(grid,i,j);

                for(auto[a,b] : v){
                    grid[a][b] = 2;
                    rotten.push({a,b});
                }
                rotten.pop();
                count--;
            }
        }

        //if after the rot an orange survives
        fresh.clear();
        for(int i = 0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){

                if(grid[i][j] == 1) fresh.push_back({i,j});
            }
        }
        if(!fresh.empty()) return -1;

        return minute;
    }
};