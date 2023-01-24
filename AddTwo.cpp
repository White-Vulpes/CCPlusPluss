#include <bits/stdc++.h>

using namespace std;

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode *getNext(){
        return next;
    }
};
bool IsRemainder = false;
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    l2->val = l1->val + l2-> val;
    if(IsRemainder){
        l2->val++;
        IsRemainder = false;
    }
    if(l2->val >= 10){
        IsRemainder = true;
        l2->val -= 10;
    }
    if(l1->next == nullptr && l2->next == nullptr){
        return l2;
    }
    else if(l1->next == nullptr){
        l1->next = new ListNode(0);
        l1 = l1->next;
        l2 = l2->next;
    }
    else if(l2->next == nullptr){
        l2->next = new ListNode(0);
        l2 = l2->next;
        l1 = l1->next;
    }
    else{
        l2 = l2->next;
        l1 = l1->next;
    }
    addTwoNumbers(l1,l2);
}
int main(){
    vector<int> a = {9, 9, 9, 9, 9, 9, 9};
    vector<int> b = {9, 9, 9, 9};
    ListNode *l1,*start1,*start2,*l2 = new ListNode();
    l1 = new ListNode();
    start1 = l1;
    start2 = l2;
    for (int i = 0; i < a.size(); i++) {
        l1->val = a[i];
        l1->next = new ListNode();
        l1 = l1->getNext();
    }

    for (int i = 0; i < b.size(); i++) {
        l2->val = b[i];
        l2->next = new ListNode();
        l2 = l2->getNext();
    }

    ListNode *ans = addTwoNumbers(start1, start2);
    cout << start2->val << " ";
    for(;start2->next != NULL;){
        start2 = start2->next;
        cout << start2->val << " ";
        
    }
}