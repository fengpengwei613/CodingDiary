#include<iostream>
#include<unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 /* 题目给了两个链表头，要我们找出两条的链表交点，我第一想到的解决方法是暴力枚举或者利用hash
    暴力枚举不过多赘述，直接介绍hash做法：
    选中第一条链表作为基链，unordered_set（底层利用hash原理实现，当然你也可以手搓一个哈希表）存储该链的所有节点的指针，
    然后遍历第二条链，每个节点进行查询当前节点的指针set中是否存在，若存在返回该指针，否则继续遍历。
    时间复杂度在O(m+n),空间复杂度为O(n)
    !!!除了以上方法，在leecode上还发现了第三种，不禁让我感觉人和人的脑子还是有差距的
    我来简单介绍一下第三种算法：将两条链表拼接，成新的两条新链，即A+B和B+A(这样说好理解，实际你只需要A遍历完
    再遍历B就行)，然后同时遍历这两条链，逐一比较两条链相同位置的节点地址是否相同即可，若有相同就则说明该节点就是焦点，
    否则无交点。
    原理：假如两个链有交点，公共段为c，则A=a+c,B=b+c，a和b为各自独属段。第一条新链：遍历完A链；遍历b链的独属段，
    则总共遍历了(a+c)+b个节点，第二条新链遍历完B链再遍历A链独属段，总共遍历了(b+c)+a个交点，两个值是相同的！
    并且两条新链要遍历的下一个节点都将是公共段的第一个节点！当我们同时遍历两个新链，他们会在a+b+c的位置重合。
    如果遍历完两条新链发现没有重合的点，说明没又交点。它的复杂度为O(m+n),O(1)！
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == headB) {
            return headA;
        }
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        std::unordered_set<ListNode*> linkA{};
        while (headA != NULL) {
            linkA.insert(headA);
            headA = headA->next;
        }

        while (linkA.find(headB) == linkA.end()) {
            headB = headB->next;
            if (headB->next == NULL) {
                break;
            }
        }
        return headB;
        
    }
};