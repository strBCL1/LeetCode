//Link to the puzzle: https://leetcode.com/problems/symmetric-tree/
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
    bool isSymmetric(TreeNode* root) {
      	//If root is empty or has no chldren at all - return true;
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return true;
    	
		//Traverse tree using BFS;
        queue<TreeNode*> q; //Declare empty queue to store tree nodes;
        q.push(root); //Push 'root' to queue 2 times (for left and right subtrees);
        q.push(root);
        
		//Perform BFS traversal:
        while (!q.empty()) {
            TreeNode* leftNode = q.front(); //Get left node from queue and erase it from queue;
            q.pop();
            
            TreeNode* rightNode = q.front(); //Get right node from queue and erase it from queue;
            q.pop();
            
			//If nodes' values are different - the tree isn't symmetric, so return false;
            if (leftNode->val != rightNode->val)
                return false;
            
			//If left node has left child AND right node has right child, push these children to queue for further check;
            if (leftNode->left != nullptr && rightNode->right != nullptr) {
                q.push(leftNode->left);
                q.push(rightNode->right);
            }
            
			//Else if ONLY ONE child is present - return false;
            else if (leftNode->left != nullptr || rightNode->right != nullptr)
                return false;
            
            //If left node has right child AND right node has left child, push these children to queue for further check;
            if (leftNode->right != nullptr && rightNode->left != nullptr) {
                q.push(leftNode->right);
                q.push(rightNode->left);
            }
            
			//Else if ONLY ONE child is present - return false;
            else if (leftNode->right != nullptr || rightNode->left != nullptr)
                return false;            
        }
        
        return true;
    }
};
