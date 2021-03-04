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
    
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prevNode = head;
        ListNode* curNode = head->next;
        head->next = nullptr;
        
        while(curNode) {
            ListNode* nextNode = curNode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
        }
        
        return prevNode;
    }
    
    void reorderList(ListNode* head) {
        
        if(!head || !head->next) {
            return;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Determining the midpoint of the list, stored in slow
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reversing the second half of the list
        // secondHalf points to the head of the reversed second half
        ListNode* secondHalf = reverseList(slow);
        
        ListNode* firstHalf = head;
        ListNode* newList = nullptr;
        
        // Reordering the list
        while(firstHalf != slow) {
            
            if(newList) {
                newList->next = firstHalf;
            }
            
            ListNode* nextInFirstHalf = firstHalf->next;
            firstHalf->next = secondHalf;
            newList = secondHalf;
            firstHalf = nextInFirstHalf;
            secondHalf = secondHalf->next;
        }
        
        if(secondHalf) {
            newList->next = secondHalf;
        }
    }
};