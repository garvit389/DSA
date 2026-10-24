#include<bits/stdc++.h>
using namespace std;


//   if(c1 == n){
//      place ')'
//      c2++;
//      continue;
//   }
//   if(c2<c1){
//      either place '(' or ')'
//      c1++ or c2++
//   }
//   place '('
//   c1++; 


class Solution {
public:
    void generateString(vector<char> str, int c1, int c2, char c, vector<string> &v, int n){
        str.push_back(c);
        
        if(c1==n && c2==n){
            string s1(str.begin(), str.end());
            v.push_back(s1);
            return;
        }

        if(c1==n){
            generateString(str, c1, c2+1, ')', v, n); 
        }
        else if(c2<c1){
            generateString(str, c1+1, c2, '(', v, n);
            generateString(str, c1, c2+1, ')', v, n);
        }
        else if(c1==c2){
            generateString(str, c1+1, c2, '(', v, n);
        }


    }
    vector<string> generateParenthesis(int n) {
        vector<char> str;
        vector<string> vec;
        int c1=0;
        int c2=0;

        generateString(str, c1+1, c2, '(', vec, n);

        return vec;
    }
};

//runtime is so high because i pass a copy of the string every time, 
//a better solution to do rather is to pop after each recursive call and pass the vecotr by reference
