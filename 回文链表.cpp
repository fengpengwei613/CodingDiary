#include<iostream>
#include<deque>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*题目让我们判断链表是否是回文链表（正向反向效果一样的链表）
首先是简单做法，直接用双向队列存储链表数据，然后依次判断首尾值是否相同。复杂度是O(n)+O(n)
然后是高效一点的办法：利用快慢指针找到链表的中点，同时反转前半部分链表，最后依次比较比较两条链表节点值。
该方法的复杂度为O(n)+O(1)
*/
//快慢指针反转链表
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //快慢指针
        ListNode* slow=head;
        ListNode* fast=head;
        //翻转链表指针
        ListNode* pre,*mid,*back;
        if(head==nullptr||head->next=nullptr){
            return true;
        }
        if(head->next->next==nullptr)
        {
            if(head->next->val==head->val){
                return true;
            }
            else{
                return false;
            }
        }
        //初始化翻转指针
        pre=head;
        mid=pre->next;
        back=mid->next;
        //两条新的链表
        ListNode* newhead1,*newhead2;
        //循环主体
        while(fast->next!=nullptr){
            fast=fast->next; 
            if(fast->next!=nullptr){
                fast=fast->next;
                newhead1=pre;
                newhead2=back;
            }
            else{
                newhead1=pre;
                newhead2=mid;
                break;
            }
            slow=slow->next;
            //翻转链表
            mid->next=pre;
            pre=mid;mid=back;back=back->next;
        }
        head->next=nullptr;
        //逐项对比
        while(newhead1!=nullptr)
        {
            if(newhead1->val!=newhead2->val){
                return false;
            }
            else{
                newhead1=newhead1->next;
                newhead2=newhead2->next;
            }
        }
        return true;
    }
};



//双向队列做法
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std:: deque<int> deq;
        while(head!=NULL)
        {
            deq.push_back(head->val);
            head=head->next;
        }
        bool res=true;
        while(!deq.empty())
        {
            if(deq.front()==deq.back())
            {
                deq.pop_back();
                if(!deq.empty())
                {
                    deq.pop_front();
                }
                else
                {
                    res=true;
                    break;
                }
            }
            else
            {
                res=false;
                break;
            }
        }
        return res;
    }
};