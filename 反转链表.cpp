```cpp
/*
题目地址:
https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=117&tqId=37777&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
  public:
    /*递归
	将函数看成一个黑箱操作:ReverseList(ListNode* node)表示反转以node为头结点的链表,反转之后的最后一个节点
	ListNode* ReverseList(ListNode* head) {
		if(!head || !head->next)return head;//当这个链表是空的,或者只有一个点时,直接返回pHead
		auto tail = ReverseList(head->next);//假设head后面的已经反转好了.所以,tail:就是反转之后,链表的头结点
		(head->next)->next = head;//将(head->next)这个节点的next指向head节点
		head->next = nullptr;//head的next1在指向空
		return tail;
    }*/
	//循环(更好理解一些)
	ListNode* ReverseList(ListNode* head) {
        if(!head)return nullptr;//如果是空,就直接返回空
        auto a = head , b = a->next;//a指向头节点,b指向头节点的next
        while(b){//当b不是空节点时
            auto c = b -> next;//c存一下b的next
            b -> next = a;//b的next指向a,反转
            //接下来,顺次后移a变成b,b变成c
            a = b;
            b = c;
        }
        //最后别忘了吧头节点的next指向空
        head -> next = nullptr;
        return a;//返回a就好
    }
};
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/4e09cf4f829d4fc680e4e3b54330176c.png)
关于递归的做法:
![在这里插入图片描述](https://img-blog.csdnimg.cn/20779b5ecf4a4202835224b89381c760.png)
