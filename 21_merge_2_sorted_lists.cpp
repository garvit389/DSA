
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* curr1;
        ListNode* curr2;

        if(!list1) return list2;
        if(!list2) return list1;
        
        if(list1->val>list2->val){
            curr1 = list2;
            curr2 = list1;
        }
        else{
            curr1 = list1;
            curr2 = list2;
        }

        ListNode *head = curr1;

        while(curr1->next&&curr2){
         
            if(curr2->val>=curr1->val && curr2->val<curr1->next->val){
                ListNode *temp = curr2;
                curr2=curr2->next;

                temp->next=curr1->next;
                curr1->next = temp;

                curr1=curr1->next;
                continue;
            }
            if(curr2->val>=curr1->next->val){
                curr1=curr1->next;
            }
        }
        if(curr2==nullptr) return head;

        curr1->next=curr2;

        return head;
    }
};