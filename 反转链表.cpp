#include<iostream>
#include<vector>
using namespace std;
/*
题目要求实现翻转链表，这道题很简单，直接用双指针法，记录两个节点，向后遍历即可完成
还有递归做法。
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

//递归做法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(head,nullptr);
    }
    ListNode* reverse(ListNode* curr,Listnode* pre){
        if(curr=nullptr){
            return pre;
        }
        ListNode* res=reverse(curr->next,curr);
        curr->next=pre;
        return res;
    }
};





 //双指针
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr=head,*pre=nullptr;
        while(curr!=nullptr){
            ListNode* next=curr->next;
            curr->next=pre;
            pre=curr;
            curr=temp;
        }
        return pre;
    }
};
 
 
 
 
 
 
 //三指针
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre,*mid,*back;
        if(head=nullptr||head->next==nullptr){
            return head;
        }
        pre=head;mid=pre->next;back=mid->next;
        while(mid!=nullptr){
            mid->next=pre;
            pre=mid;mid=back;back=back->next;
        }
        head->next=nullptr;
        return pre;
    }
};