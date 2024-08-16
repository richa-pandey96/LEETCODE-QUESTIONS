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
        if(head==nullptr || head->next==nullptr)
            return;
        
        //Finding the middle of the list
        ListNode* p1=head;
        ListNode* p2=head;
        while(p2->next!=nullptr && p2->next->next!=nullptr){
            p1=p1->next;
            p2=p2->next->next;
        }
        //Reverse the half after middle
        ListNode* prev=nullptr;
        ListNode* curr=p1->next;
        p1->next=nullptr; //cut off the first half of the list
        
        while(curr!=nullptr){
            ListNode* next=curr->next;
            curr->next=prev;
            
            
            prev=curr;
            curr=next;
        }
        
        //Start reordering
        
        ListNode* first=head;
        ListNode* second=prev;
        
        while(second!=nullptr){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            
            first->next=second;
            second->next=temp1;
            
            first=temp1;
            second=temp2;
        }
        
        
        
    }
};