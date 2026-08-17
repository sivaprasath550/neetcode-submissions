class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // 1. Reverse the linked list
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // prev is now the head of the reversed list

        // 2. Remove the Nth node from the beginning
        //    (which was the Nth node from the end originally)

        ListNode* reversedHead = prev;

        // If the node to remove is the first node
        if (n == 1) {
            reversedHead = reversedHead->next;
        }
        else {
            ListNode* current = reversedHead;

            // Move to the node just before the one we want to delete
            for (int i = 1; i < n - 1; i++) {
                current = current->next;
            }

            // Skip the Nth node
            current->next = current->next->next;
        }

        // 3. Reverse the list back to its original direction

        prev = nullptr;
        curr = reversedHead;

        while (curr != nullptr) {
            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }
};