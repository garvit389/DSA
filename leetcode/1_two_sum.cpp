#include <bits/stdc++.h>
using namespace std;


//O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        unordered_multimap<int,int> map;

        int i=0;
        for(int x:nums){
            map.insert({x, i});
            i++;
        }

        int j=0;
        for(int x:nums){
            int y = target-x;
            auto it = map.find(y);
            if(x==y){
                if(map.count(y)<2){
                    j++;
                    continue;
                }
                auto range = map.equal_range(y);
                if(it->second == j){
                    ++it;
                }        
            }
            if(it!=map.end()){
                indices.push_back(j);
                indices.push_back(it->second);
                break;  
            }
            j++;
        }
        return indices;
    }
};

//O(n){not mine}
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }

            map[nums[i]] = i;
        }

        return {};
    }
};


