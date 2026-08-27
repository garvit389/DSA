#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int hashPair(int a, int b){
        a/=3;
        b/=3;
        return 3*a + b;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>> countRow;
        unordered_map<int,unordered_set<int>> countCol;
        unordered_map<int,unordered_set<int>> countBox;

        for(int i =0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == '.') continue;

                auto check = countRow[i].insert(board[i][j] - '0');
                if(!check.second) return false;

                check = countCol[j].insert(board[i][j] - '0');
                if(!check.second) return false;

                check = countBox[hashPair(i,j)].insert(board[i][j] - '0');
                if(!check.second) return false;
            }
        }
        return true;
    }
};