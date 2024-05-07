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

    ListNode* reverseLL(ListNode* head)
    {
        if(head == NULL)
            return head;

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = head->next;

        while(curr != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if(nxt != NULL) nxt = nxt->next;
        }

        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        ListNode *revHead = reverseLL(head);

        ListNode *tempHead = revHead;
        int doubleVal = tempHead->val * 2;
        ListNode *headPtr = new ListNode(-1);
        ListNode *newHead = new ListNode(doubleVal%10);
        
        headPtr->next = newHead;
        tempHead = tempHead->next;

        int carry = doubleVal/10;
        while(tempHead != NULL)
        {
            doubleVal = (tempHead->val * 2) + carry;
            int sum = doubleVal%10;
            carry = doubleVal/10;
            
            ListNode *temp = new ListNode(sum);
            newHead->next = temp;
            newHead = temp;
            tempHead = tempHead->next;
        }

        if(carry > 0)
        {
            ListNode *temp = new ListNode(carry);
            newHead->next = temp;
            newHead = temp;
        }

        newHead->next = NULL;

        reverseLL(revHead);
        newHead = reverseLL(headPtr->next);
        return newHead;
    }
};