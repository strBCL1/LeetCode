//Link to the puzzle: https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> answer = {}; //Initialize empty vector;
    
	//Function to fill 'answer' with BT values;
    void goInorder(const TreeNode* root, vector<int>& answer) {
        if (root == nullptr) //Recursion stop condition;
            return;
        
		//First visit left substree of current node;
        goInorder(root->left, answer);
		
		//Then add value of current node into 'answer';
        answer.push_back(root->val);
		
		//Visit right subtree of current node;
        goInorder(root->right, answer);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        goInorder(root, answer);
        return answer;
    }
};
