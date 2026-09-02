#include <bits/stdc++.h>
using namespace std;


//my solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest=0;
        vector<bool> canReach(nums.size(), false);

       for(int i=0; i<nums.size(); i++){
            if(i<=furthest) canReach[i] = true;
            if(nums[i]+i>furthest && canReach[i]) furthest = i+nums[i];
       }
    
        if(furthest>=nums.size()-1) return true;

        return false;
    }
};

//cleaner version
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest=0;

       for(int i=0; i<nums.size(); i++){
            if(nums[i]+i>furthest && i<=furthest) furthest = i+nums[i];
       }
    
        if(furthest>=nums.size()-1) return true;

        return false;
    }
};