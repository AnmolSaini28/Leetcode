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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<vector<pair<TreeNode*,int>>> level_order;//{parent,child val}
        queue<pair<TreeNode*,TreeNode*>> q;//{parent,child}
        q.push({NULL,root});
        while(!q.empty()){ // level order traversal
            int size = q.size();
            vector<pair<TreeNode*,int>> level;
            for(int i = 0;i<size;i++){
                auto nodes = q.front();
                q.pop();
                if(nodes.second->left) q.push({nodes.second,nodes.second->left});
                if(nodes.second->right) q.push({nodes.second,nodes.second->right});
                level.push_back({nodes.first,nodes.second->val});
            }
            level_order.push_back(level);
        }

        for(auto &it : level_order){
            int sumi = 0;
            int n = it.size();
            for(int i = 0;i<n;i++){//total sum of level
                sumi += it[i].second;
            }

            for(int i = 0;i<n;i++){
                int x = 0;
                if(i+1 < n && it[i].first == it[i+1].first){
                    x = it[i].second + it[i+1].second;
                    it[i].second = sumi - x;
                    it[i+1].second = sumi - x;//result node value
                    if(it[i].first){//both the child exists
                        it[i].first->left->val = it[i].second;
                        it[i].first->right->val = it[i].second;
                    }
                    i++;
                    
                }
                else{
                    x = it[i].second;
                    it[i].second = sumi - x;
                    if(it[i].first){ // single child exists
                        if(it[i].first->left) it[i].first->left->val = it[i].second;
                        else it[i].first->right->val = it[i].second;
                    }
                }                
            }
        }

        root->val = 0;//root change
        return root;
    }
};