#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string str;
        //for len 1 strings because  of the k<s.size()-1 condition
        if(s.size()<2) return s;

        for(int k = 0; k<s.size() - 1; k++){
            string strLocal;
            int l = k;
            int r = k+1;

            //handle equality case
            if(s[l] == s[r]){
                while(r+1<s.size() && s[r+1] == s[l]) r++;
            }
            if (r+1<s.size() && s[l]!=s[r]) r++; 
            if(r+1<s.size() && s[l]!=s[r]) continue;
            //breaks either due to size boundary or condition failed
            while(s[l] == s[r]){
                l--;
                r++;
                //size boundary fix for r and l
                if(l<0 || r>=s.size()){
                    l++;
                    r--;
                    break;
                }
            }
            //inequality fix 
            if(s[l]!=s[r]){
                l++;
                r--;
            }
            if(l>r){
                l=r;
            }
            strLocal = s.substr(l, r-l+1);

            str = (strLocal.size()>str.size()) ? strLocal:str;
        }
        return str;
    }
};