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
    int postOrderIdx;
    unordered_map<int, int> inorderIdx;

    TreeNode* solve(vector<int>& postorder, int s, int e){
        if(s > e) return NULL;

        int val = postorder[postOrderIdx--];
        TreeNode* root = new TreeNode(val);
        int mid = inorderIdx[val];

        root -> right = solve(postorder, mid + 1, e);
        root -> left = solve(postorder, s, mid - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postOrderIdx = postorder.size() - 1;
        for(int i = 0; i < inorder.size(); i++){
            inorderIdx[inorder[i]] = i;
        }

        return solve(postorder, 0, postorder.size() - 1);
    }
};