#include <bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


 //solution 1, not optimal since int can not store numbers as big as linked lists

class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1=0, num2=0;
        int mul=1;

        while(l1){
            num1 += (l1->val)*mul;
            mul*=10;   
            l1=l1->next;
        }

        mul=1;

        while(l2){
            num2 += (l2->val)*mul;
            mul*=10;
            l2 = l2->next;
        }

        int ans = num1+num2;

        ListNode *l3 = new ListNode();
        ListNode *curr = l3;

        while(ans){
            curr->val = ans%10;
            ans = ans/10;

            if(ans){
                curr->next = new ListNode();
                curr=curr->next;
            }
        }
        return l3;
    }
};


//solution 2
class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry=0;
        ListNode *sum = new ListNode();
        ListNode *curr = sum;

        while(l1&&l2){
            int tempsum = l1->val + l2->val + carry;
            curr->val = tempsum%10;
            carry = tempsum/10;
            l1 = l1->next;
            l2 = l2->next;
            
            if(l1&&l2){
                curr->next = new ListNode();
                curr=curr->next;
            }
        }

        ListNode *remaining_list = nullptr;

        if(l1==nullptr){
            remaining_list = l2;
        }
        else{
            remaining_list = l1;
        }

        

        if(remaining_list==nullptr && carry){
            curr->next = new ListNode();
            curr=curr->next;
            curr->val = carry;
        }

        while(remaining_list){
            if(carry==0){
                curr->next=remaining_list;
                break;
            }
            curr->next = new ListNode();
            curr=curr->next;
            int tempsum = remaining_list->val + carry;
            curr->val = tempsum%10;
            carry = tempsum/10;

            remaining_list=remaining_list->next;
                
            if(carry != 0 && remaining_list==nullptr) {
                curr->next = new ListNode();
                curr=curr->next;
                curr->val = carry;
            }
        }
        return sum;         
    }
};
