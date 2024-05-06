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

    ListNode* reverseLinkedList(ListNode* head)
    {
        if(head==NULL)
            return NULL;
        
        ListNode *p=NULL, *n=head->next;
        
        while(head!=NULL){
            head->next=p;
            p=head;
            head=n;
            if(n!=NULL)n=n->next;
        }

        return p;
    }
    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        ListNode* temp = head->next;

        st.push(head->val);

        while(temp != NULL)
        {
            // if(!st.empty() && st.top() >= temp->val)
            // {
            //     st.push(temp->val);
            // }
            // else
            // {
                while(!st.empty() && temp->val > st.top())
                    st.pop();
            // }
            st.push(temp->val);
            temp = temp->next;
        }

        ListNode* headPtr = new ListNode(-1);
        ListNode* newHead = new ListNode(st.top());
        st.pop();
        headPtr->next = newHead;

        while(!st.empty())
        {
            ListNode* tempNode = new ListNode(st.top());
            newHead->next = tempNode;
            newHead = tempNode;
            st.pop();
        }

        newHead->next = NULL;

        ListNode* finalHead = reverseLinkedList(headPtr->next);
        return finalHead;
    }
};