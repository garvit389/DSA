#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int goodNodes(TreeNode* root) {

        stack<pair<TreeNode*,int>> st;
        int max = root->val;
        int count = 0;
        st.push({root, max});

        while(!st.empty()){
            TreeNode *curr = st.top().first;
            max = st.top().second;

            if(curr->val>=max){
                max = curr->val;
                count++;
            }
            st.pop();

            if(curr->right) st.push({curr->right,max});
            if(curr->left) st.push({curr->left,max});
        }

        return count;
    }
};