#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getArea(int i, int j, const vector<int> &height){
        if(height[i]>height[j]) return (j-i)*height[j];
        else return (j-i)*height[i];
    }
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;

        int Area_max = 0;

        while(i!=j){
            Area_max = max(Area_max, getArea(i, j, height));
            if(height[i]<height[j]) i++;
            else j--;
        }

        return Area_max;
    }
};