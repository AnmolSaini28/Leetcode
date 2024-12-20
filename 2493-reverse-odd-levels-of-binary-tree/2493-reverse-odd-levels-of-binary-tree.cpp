/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>qu;
        vector<int>temp,ans;
        bool isOdd=false;
        qu.push(root);
        ans.push_back(root->val);
        while(!qu.empty()){
            int n = qu.size();
            for(int i=0;i<n;i++){
                TreeNode* tempRoot = qu.front();
                qu.pop();
                if(isOdd){
                    tempRoot->val = ans[n-i-1];
                }
                if(tempRoot->left){
                    qu.push(tempRoot->left);
                    temp.push_back(tempRoot->left->val);
                }
                if(tempRoot->right){
                    qu.push(tempRoot->right);
                    temp.push_back(tempRoot->right->val);
                }
            }
            ans = temp;
            temp.clear();
            isOdd=!isOdd;
        }
        return root;

    }
};