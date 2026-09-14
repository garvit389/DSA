#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> maxSum;
        maxSum.push_back(nums[0]);

        for(int i=1; i<nums.size(); i++){
            int sum;

            int third;
            if(i-2<0) third = 0;
            else third = maxSum[i-2];

            int second;
            if(i-1<0) second = 0;
            else second = maxSum[i-1];

            if(nums[i]+third>second) sum = nums[i]+third;
            else sum = second;

            maxSum.push_back(sum);
        }

        return maxSum[maxSum.size()-1];
    }
};