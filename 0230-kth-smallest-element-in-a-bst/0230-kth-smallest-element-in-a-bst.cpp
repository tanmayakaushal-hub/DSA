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
private:
    void solve(TreeNode* root, int k, int& ans, int &i){
        if(root == NULL) return;

        solve(root -> left, k, ans, i);

        i++;
        if(k == i){
            ans = root -> val;
            return;
        }

        solve(root -> right, k, ans, i);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        int i = 0;
        solve(root, k, ans, i);
        return ans;
    }
};