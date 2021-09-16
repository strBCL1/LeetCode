//Link to the puzzle: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curNode = head; //Initialize node to traverse the whole linked list;
        
		//While next node is valid (is not 'nullptr'):
        while (curNode->next != nullptr) {
            if (curNode->val == curNode->next->val) //If next node's value equals to cur node's value, replace next node with next_node->next_node;
                curNode->next = curNode->next->next;
            else //Else go forward in linked list;
                curNode = curNode->next;
        }
        
        return head;
    }
};
