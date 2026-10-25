#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;

        unordered_map<char,int> freq1;
        unordered_map<char,int> freq2;

        for(char c: s1){
            freq1[c]++;
        }

        int ptrA = 0;
        int ptrB = ptrA +s1.size()-1;
        int temp = ptrA;

        while(temp<=ptrB){
            freq2[s2[temp]]++;
            temp++;
        }

        while(ptrB<s2.size()){
            if(freq1 == freq2) return true;
            
            if(freq2[s2[ptrA]]>1) freq2[s2[ptrA]]--;
            else freq2.erase(s2[ptrA]);

            ptrA++;
            ptrB++;
            freq2[s2[ptrB]]++;
        }
        return false;

    }
};