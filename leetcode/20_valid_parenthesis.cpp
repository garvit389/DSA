#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ismatching(char c1, char c2){
        if(c1=='(' && c2==')') return true;
        if(c1=='[' && c2==']') return true;
        if(c1=='{' && c2=='}') return true;
        return false;
    }
    
    bool isValid(string s) {
        stack<char> stack;

        for(char c:s){

            if(c == '(' || c == '[' || c == '{') stack.push(c);
            if(c == ')' || c == ']' || c == '}'){

                if(stack.empty()) return false;

                bool match = ismatching(stack.top(), c);
                if(!(match)) return false;
                stack.pop();
            }
        }
        if(stack.empty()) return true;
        return false;
    }
};