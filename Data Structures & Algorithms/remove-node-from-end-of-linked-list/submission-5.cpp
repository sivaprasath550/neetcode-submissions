// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {

//         ListNode* prev = nullptr;
//         ListNode* curr = head;

//         while (curr != nullptr) {
//             ListNode* next = curr->next;

//             curr->next = prev;

//             prev = curr;
//             curr = next;
//         }

//         ListNode* reversedHead = prev;

//         if (n == 1) {
//             reversedHead = reversedHead->next;
//         }
//         else {
//             ListNode* current = reversedHead;

//             for (int i = 1; i < n - 1; i++) {
//                 current = current->next;
//             }

//             current->next = current->next->next;
//         }

//         prev = nullptr;
//         curr = reversedHead;

//         while (curr != nullptr) {
//             ListNode* next = curr->next;

//             curr->next = prev;

//             prev = curr;
//             curr = next;
//         }

//         return prev;
//     }
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy -> next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        for(int i = 0; i <= n; i++){
            fast = fast -> next;
        }

        while(fast != nullptr){
            slow = slow -> next;
            fast = fast -> next; 
        }

        slow -> next = slow -> next -> next;

        return dummy -> next;
    }
};