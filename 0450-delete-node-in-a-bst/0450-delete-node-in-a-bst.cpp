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
    int minValue(TreeNode* root){
        TreeNode* temp = root;
        while(temp -> left) temp = temp -> left;
        return temp -> val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;

        if(root -> val == key){
            // 0 child
            if(root -> left == NULL && root -> right == NULL){
                delete root;
                return NULL;
            }
            // 1 child
            // left child
            if(root -> left && !root -> right){
                TreeNode* temp = root -> left;
                delete root;
                return temp;
            }
            // right child
            if(!root -> left && root -> right){
                TreeNode* temp = root -> right;
                delete root;
                return temp;
            }

            // 2 child
            int mini = minValue(root -> right);
            root -> val = mini;
            root -> right = deleteNode(root -> right, mini);
            return root;
        }
        else if(root -> val > key){
            root -> left = deleteNode(root -> left, key);
            return root;
        }
        else{
            root -> right = deleteNode(root -> right, key);
            return root;
        }
        return root;
    }
};