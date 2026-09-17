#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        
        for(int k=0; k<nums.size(); k++){
            int i = 0;
            int j = nums.size() -1;
            
            if(k>0 && nums[k]==nums[k-1]) continue;

            while(i!=j){
                if(i==k){
                    i++;
                    continue;
                }
                if(j==k){
                    j--;
                    continue;
                }

                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    vector<int> temp{nums[i],nums[j],nums[k]};
                    sort(temp.begin(), temp.end());
                    int a = temp[0];
                    int b = temp[1];
                    int c = temp[2];

                    s.insert({a,b,c});
                    i++;
                }

                if(sum>0) j--;
                if(sum<0) i++;
            }
        }
        auto it = s.begin();

        while(it!=s.end()){
            ans.push_back(*it);
            it++;
        }
        return ans;
    }
};