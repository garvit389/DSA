#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        deque<pair<int,int>> deq;
        int total = 0;

        deq.push_front({height[0],0});
        for(int i=1; i< height.size(); i++){            
            if(height[i]<deq.front().first) {
                deq.push_front({height[i],i});
                continue;
            }
            int area = 0;

            while(deq.size()>0 && deq.front().first<height[i]){
                int bottom = deq.front().first;
                deq.pop_front();
                if(!deq.empty()) 
                    area += (min(deq.front().first, height[i])-bottom)*(i-deq.front().second-1);
            }
            
            deq.push_front({height[i],i});
            if(area>0) total+=area;
        }
        return total;
    }
};