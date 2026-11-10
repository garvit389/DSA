#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void DFS(vector<vector<int>> &v, vector<int>& nums, int i, vector<int> &temp){
        if(i == nums.size()){
            v.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        DFS(v,nums,i+1,temp);

        temp.pop_back();
        DFS(v,nums,i+1,temp);


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int> temp;

        DFS(vec,nums,0,temp);

        return vec;
        
    }
};