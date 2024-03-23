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
        if(head==NULL || head->next==NULL) return;
        
        ListNode* s=head, *f=head, *p;
        
        while(f!=NULL && f->next!=NULL){
            p=s;
            s=s->next;
            f=f->next->next;
        }
        
        p->next=NULL;
        ListNode *l1=head;
        ListNode *l2=rev(s);
        merge(l1, l2);
    }
    
    void merge(ListNode *l1, ListNode *l2){
        while(l2!=NULL){
            ListNode *temp=l1->next;
            l1->next=l2;
            l1=l2;
            l2=temp;
        }
    }
    
    ListNode* rev(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *p=NULL, *c=head, *n=head->next;
        
        while(c!=NULL){
            c->next = p;
            p=c;
            c=n;
            if(n!=NULL) n=n->next;
        }
        
        return p;
    }
};