#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
题目要求我们判断一个链表是否是环形链表，有两个思路，一个是直接用unorderset保存已经访问过的节点
然后每访问一个节点进行判断是否访问过。
另外一个思路就是快慢指针，如果存在环，那么快指针一定会再次追上慢指针。
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr){
            return false;
        }
        ListNode* slow=head,*fast =head->next;
        while(fast!=nullptr){
            if(fast==slow){
                return true;
            }
            slow=slow->next;
            fast=fast->next
            if(fast==nullptr){
                return false;
            }
            fast=fast->next;
        }
        return false;
    }
};







class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> record;
        while(head!=nullptr){
            if(record.find(head)!=record.end()){
                return true;
            }else{
                record.insert(head);
                head=head->next;
            }
        }
        return false;
    }
};