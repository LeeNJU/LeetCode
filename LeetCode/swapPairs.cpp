#include<iostream>

using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


ListNode *swapPairs(ListNode *head) 
{
	if (head == nullptr || head->next == nullptr)//排除只有一个元素和空的情况
		return head;

	ListNode* p = head;
	head = head->next;  //保存返回值  head指向原链表的第二个元素
	while (p != nullptr && p->next != nullptr)
	{
		ListNode* temp = p->next;
		p->next = temp->next;
		temp->next = p;

		ListNode* next = p->next;//保存p下一个元素
		if (p->next != nullptr && p->next->next != nullptr)//检查下两个元素的情况
		{
			p->next = p->next->next;
		}
		p = next;
	}

	return head;
}

int main()
{
	ListNode one(1),two(2), three(3), four(4);
	one.next = &two;
	two.next = &three;
	three.next = &four;
	ListNode* p = swapPairs(&one);
	cout << p->val << p->next->val << p->next->next->val << p->next->next->next->val << endl;
	return 0;
}