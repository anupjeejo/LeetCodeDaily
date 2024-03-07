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
    ListNode* middleNode(ListNode* head) 
    {
        //      Optimal solution
        
        ListNode *fast = head, *slow = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;                 
            slow = slow->next;                     
        }
        
        return slow;


//         My initial solution        
//         if(head==NULL){
//             return head;
//         }
        
//         ListNode *node = head;
//         ListNode *ans;
//         int ctr=0;
        
//         while(node != NULL){
//             ctr++;
//             node = node->next;
//         }

//         ctr = (ctr/2);
//         node=head;
        
//         for(int i=0; i<ctr+1; i++){
//             if(i == ctr){
//                ans = node;
//                break;
//             }
//             node = node->next;
//         }
        
//         return ans;

//------------------------------------------------------------------------//
    }
};