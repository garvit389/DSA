#include <bits/stdc++.h>
using namespace std;

// o(n^2)
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        vector<int> best_index;
        int max_jmp=0;        
        

        for(int i=0; i<nums.size() -1; i++){
            max_jmp = i+nums[i];
           if(max_jmp>=nums.size()-1){ 
                best_index.push_back(nums.size() - 1); 
                break;
           }
            int target_index = i;

            int farthest = 0;
            while(i<=max_jmp){
                 
                if(i+nums[i]>nums.size()-1) {
                    target_index = i;
                    farthest = i+nums[i];
                    break;
                };

                if(i+nums[i]>farthest) target_index = i;

                farthest = max(farthest, i+nums[i]);
                i++;
            }
            best_index.push_back(target_index);
           
            if(target_index >= nums.size()-1) best_index.push_back(nums.size()-1);

            i = target_index-1;
            if(i<0) i++;
        }

        return best_index.size();
    }
};
