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
        if(head == NULL || head ->next == NULL){
            return head;
        }
        if(head -> val == head ->next ->val){
            int value = head -> val;

            while(head != NULL && head ->val == value){
                head = head -> next;
            }
            return deleteDuplicates(head);
        }
        head -> next = deleteDuplicates(head->next);

        return head;
    }
};