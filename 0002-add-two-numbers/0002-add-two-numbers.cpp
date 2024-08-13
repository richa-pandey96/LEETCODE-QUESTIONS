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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummynode= new ListNode(-1);
        ListNode* curr=dummynode;
        int carry=0;
        
        while(l1!=nullptr|| l2!=nullptr){
            
            int digit1=(l1!=nullptr)? l1->val:0;
            int digit2=(l2!=nullptr)? l2->val:0;
            
            int sum=digit1+digit2+carry;
             ListNode* newNode=new ListNode(sum%10);
            carry=sum/10;
            
            curr->next=newNode;
            curr=curr->next;
            
            l1=(l1!=nullptr)?l1->next:nullptr;
            l2=(l2!=nullptr)?l2->next:nullptr;
            
        }
        if(carry){
            ListNode* newNode=new ListNode(carry);
            curr->next=newNode;
        }
        
        return dummynode->next;
        
    }
};