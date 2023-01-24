#include<iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* ans = new ListNode();
        ListNode* head = ans;
        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                ans->val = list1->val;
                list1 = list1->next;
            }
            else{
                ans->val = list2->val;
                list2 = list2->next;
            }
            ans->next = new ListNode();
            ans = ans->next;
        }
        if(list1 == NULL){
            while(list2 != NULL){
                ans->val = list2->val;
                list2 = list2->next;
                ans->next = new ListNode();
                ans = ans->next;
            }
        }
        else if(list2 == NULL){
            while(list1 != NULL){
                ans->val = list1->val;
                list1 = list1->next;
                ans->next = new ListNode();
                ans = ans->next;
            }
        }
        return head;
}

int main(){
    ListNode* list1 = new ListNode();
    ListNode* list2 = new ListNode();
    int arr[] = {1, 3, 4};
    int arr1[] = {2, 4, 5};
    for(int i = 0; i < 3;i++){
        list1->val = arr[i];
        list2->val = arr1[i];
        list1->next = new ListNode();
        list2->next = new ListNode();
        list1 = list1->next;
        list2 = list2->next;
    }
    ListNode* head = mergeTwoLists(list1, list2);
    for(;head != NULL;){
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}

