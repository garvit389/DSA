#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int *a = &nums[0];
        int *b = &nums[nums.size() - 1];
        int *mid = &nums[(nums.size()-1)/2];
        int found = -1;
    
        while(a!=b && a!=mid && b!=mid){      
            if(target == *a) found = a - &nums[0];
            if(target == *b) found = b - &nums[0];
            if(target == *mid) found = mid - &nums[0];

            if(*a <= *mid){
                if(target>*a && target<*mid){
                    b = mid;
                }
                else a = mid;
            }
            else{
                if(target<*b && target>*mid){
                    a = mid;
                }
                else b = mid;
            }

            mid = a + (b - a) / 2;;
        }

        if(target == *a) found = a - &nums[0];
        if(target == *b) found = b - &nums[0];
        if(target == *mid) found = mid - &nums[0];
        
        return found;
    
    }
};