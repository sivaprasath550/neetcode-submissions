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
    void reorderList(ListNode* head) {

        if(head == nullptr || head -> next == nullptr){
            return;
        }
        
        //part-1
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        //part-2
        ListNode* prev = nullptr;
        ListNode* curr = slow;
    
        while(curr != nullptr){
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        //part-3

        ListNode* first = head;
        ListNode* second = prev;

        while(second -> next != nullptr){
            ListNode* firstNext = first -> next;
            ListNode* secondNext = second -> next;

            first -> next = second;
            second -> next = firstNext;

            first = firstNext;
            second = secondNext;
        }

    }
};
