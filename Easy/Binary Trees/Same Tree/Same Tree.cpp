//Link to the puzzle: https://leetcode.com/problems/same-tree/
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
    bool isSameTree(TreeNode*& a, TreeNode*& b) {
        if (a == nullptr && b == nullptr) //'nullptr' equals to 'nullptr', so return true;
            return true;
		
        //If previous condition was false, that means that this case might happen: 
		// ('a' is 'nullptr' and 'b' isn't 'nullptr') or ('a' isn't 'nullptr' and 'b' is 'nullptr');
		//If so, that means 'a' and 'b' have different values, so return false;
        if (a == nullptr || b == nullptr)
            return false;
        
		//Compare nodes using binary tree BFS traversal:
        queue<TreeNode*> q1, q2; //Declare empty queues (for 'a' tree and 'b' tree);
        q1.push(a); q2.push(b); //Push 'a' and 'b' to queues;
        
		//While both queues aren't empty, it means they have exactly same amount of nodes;
        while (!q1.empty() && !q2.empty()) {
            TreeNode* curA = q1.front(); //Get current node of 'a' tree;
            TreeNode* curB = q2.front(); //Get current node of 'b' tree;
            
            if (curA->val != curB->val) //If values of 'a' and 'b' nodes are different, return false (trees aren't same then);
                return false;

            q1.pop(); q2.pop(); //Erase 'a' and 'b' nodes from queues;
            
            //If left child of both 'a' and 'b' exists, push left children to queues;
            if (curA->left != nullptr && curB->left != nullptr) {
                q1.push(curA->left);
                q2.push(curB->left);
            }

            //Else if ONLY ONE child exists, return false;
            else if (curA->left || curB->left)
                return false;
            
            //If right child of both 'a' and 'b' exists, push right children to queues;
            if (curA->right != nullptr && curB->right != nullptr) {
                q1.push(curA->right);
                q2.push(curB->right);
            }

            //Else if ONLY ONE child exists, return false;
            else if (curA->right || curB->right)
                return false;
        }
        
        //Return true if trees are same (because function hasn't returned false);
        return true;
    }
};
