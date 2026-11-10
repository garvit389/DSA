#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int tempSum = digits[digits.size()-1]+1;
        digits[digits.size()-1] = tempSum%10;
        int carry = tempSum/10;

        for(int i = digits.size()-2; i>=0; i--){
            if(!carry) break;

            tempSum = digits[i]+carry;
            digits[i] = tempSum%10;
            carry = tempSum/10;
         }

         if(carry){
            digits[0] = 0;
            digits.insert(digits.begin(), carry);
         }

         return digits;
    }
};