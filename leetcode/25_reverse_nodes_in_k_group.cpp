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
    //checks if k-1 Nodes exist ahead of curr, ie, k including curr
    bool kExist(ListNode *curr, int *tempK){
        if(*tempK == 1 && curr!=NULL) return true;
        if(*tempK == 1 || curr==NULL) return false;

        (*tempK)--;

        return kExist(curr->next, tempK);
    }

    //after rev, head is the last node, which points to the head of the next set, prev is the new first node, and curr is the node after, if any

    ListNode* reverseKGroup(ListNode* head, int k) {
        int tempK = k;
        if(!(kExist(head, &tempK))) return head;

        ListNode* prev = NULL;
        ListNode * curr = head;
        ListNode* nxt =  NULL;

        for(int i=0; i<k; i++){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        head->next = reverseKGroup(curr, k);

        return prev;
    }
};