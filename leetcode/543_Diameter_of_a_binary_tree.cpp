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
    int MaxLength(TreeNode * root, int count, int &d){
        if(root==NULL){
            return 1;
        }

        int count1 = MaxLength(root->left, count, d);
        int count2 = MaxLength(root->right, count, d);
        d = max(count1 + count2 -1, d);
        count = max(count1,count2)+1;

        return count;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        int temp = MaxLength(root, 0, diameter);

        return diameter-1;
    }
};