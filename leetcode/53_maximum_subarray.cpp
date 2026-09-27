#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sum(nums.size());

        sum[0] = nums[0];

        for(int i=1;i<nums.size(); i++){
            sum[i] = sum[i-1] + nums[i];
        }

        int b = 0;
        int a = -1;
        int max_subarr=sum[0];
        int local_min = 0;

        while(b<sum.size()){
            int x;
            while(a<b){
                if(a<0) x = 0;
                else x = sum[a];
                
                local_min = min(local_min,x);                
                a++;
            }
            max_subarr = max(max_subarr, sum[b] - local_min);
            b++;
        }
        return max_subarr;


    }
};