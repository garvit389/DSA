#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string MultiplyWithDigit(string num1, int d, int i){
        string ans;
        while(i!=0){
            ans.push_back('0');
            i--;
        }
        int carry = 0;
        while(!num1.empty()){
            int mul = d*(num1.back() - '0')+carry;
            num1.pop_back();
            carry = mul/10;
            char c = (mul%10) + '0';
            ans.insert(ans.begin(), c);
        }
        char carryChar = carry + '0';
        if(carry) ans.insert(ans.begin(), carryChar);

        return ans;
    }

    void addString(string &s0, string s1){
        if(s0.empty()){
            s0 = s1;
            return;
        }

        int carry = 0;
        auto it = s0.end() -1;
        while(!s1.empty()){
            int tempSum = ((*it - '0') + (s1.back() - '0') + carry);
            s1.pop_back();
            carry = tempSum/10;
            *it = (tempSum%10)+'0';
            if(it == s0.begin()) break;
            it--;
        }
        if(!s1.empty()){
            auto it2 = s1.end() -1;
            while(carry){
                int tempSum = ((*it2 - '0') + carry);
                carry = tempSum/10;
                *it2 = (tempSum%10)+'0';
                if(it2 == s1.begin()) break;
                it2--;
            }
            s0 = s1 + s0;   
        }

        if(carry){
            char carryChar = carry + '0';
            s0 = carryChar+s0;
        }

    }

    string multiply(string num1, string num2) {
        int i=0;
        string s;

        if(num2 == "0" || num1 == "0") return "0";

        while(!num2.empty()){
            int d = num2.back() - '0';
            num2.pop_back();

            string s1 = MultiplyWithDigit(num1, d, i);
            i++;

            addString(s,s1);
        }

        return s;
    }
};