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
    ListNode* mergeTwoLists(ListNode*& l1, ListNode*& l2) {
        ListNode* ansHead = new ListNode(-101); //Create empty result linked list (nodes' values should be in range -100 ... 100; -101 won't be in count in answer);
        ListNode* traverseAns = ansHead; //Create traversal pointer to add new nodes to ansHead (ansHead and traverseAns have same addresses in the beginning, so changing traverseAns also changes ansHead);
        
        //While both l1 and l2 haven't reached their ends:
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) { //If l1 node's value is smaller than l2 node's value, add l1 node to traverseAns; else add l2 node;
                traverseAns->next = l1;
                l1 = l1->next;
            }
            else {
                traverseAns->next = l2;
                l2 = l2->next;
            }
            traverseAns = traverseAns->next; //Move traverseAnd to newly created next node;
        }
        
        //Add remaining nodes of l1 or l2 to traverseAns;
        while (l1 != nullptr) {
            traverseAns->next = l1;
            l1 = l1->next;
            traverseAns = traverseAns->next;
        }
        
        while (l2 != nullptr) {
            traverseAns->next = l2;
            l2 = l2->next;
            traverseAns = traverseAns->next;
        }
        
        //Return answer list without '-101' node;
        return ansHead->next;
    }
};
