#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int i=0;
        int maxArea = 0;
        s.push(i);
        i++;

        while(i<heights.size()){
            int localArea = 0;
            while(!s.empty() && heights[i]<heights[s.top()]){
                int h = s.top();
                s.pop();
                int l = -1;
                if(!s.empty()) l = s.top();
                localArea = heights[h]*(i-l-1);
                maxArea = max(maxArea, localArea);
            }
            s.push(i);
            i++;
        }

        while(!s.empty()){
            int h = s.top();
            s.pop();
            int l = -1;
            if(!s.empty()) l = s.top();
            int localArea = heights[h]*(heights.size()-l-1);
            maxArea = max(maxArea, localArea);
        }
        
        return maxArea;
    }
};