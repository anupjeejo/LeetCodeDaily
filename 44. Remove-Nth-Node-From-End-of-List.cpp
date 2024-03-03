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
    
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* start=new ListNode();
        start->next=head;
        ListNode *fast=start, *slow=start;
        
        for(int i=1; i<=n; i++)
            fast=fast->next;
        
        while(fast->next != NULL){
            fast=fast->next;
            slow=slow->next;
        }
        
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return start->next;
    }

//----------------------Unoptimized----------------------//
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         if(head->next == NULL && n==1) return NULL;
        
//         ListNode* dummy=head;
        
//         int cnt=0;
        
//         while(dummy!=NULL){
//             cnt++;
//             dummy=dummy->next;
//         }
        
//         n = cnt-n;
//         dummy=head;
        
//         if(n!=0){
//             for(int i=0; i<n-1; i++){
//                 dummy=dummy->next;
//             }
//             ListNode* temp = dummy->next;
//             dummy->next=dummy->next->next;
//             delete temp;
//         }else{
//             ListNode* temp = head;
//             head=head->next;
//             delete temp;
//         }
        
//         return head;
//     }
};