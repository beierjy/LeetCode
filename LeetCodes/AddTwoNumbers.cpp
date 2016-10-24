/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//未优化前的代码
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* head = NULL;
	ListNode *pLast = NULL;
	if (l1 != NULL&&l2 != NULL){
		ListNode* pNode1 = l1;
		ListNode* pNode2 = l2;
		int cal = 0;
		while (pNode1 != NULL || pNode2 != NULL || cal != 0){
			ListNode* pNode = new ListNode(0);
			int tval = 0;
			if (pNode1 != NULL && pNode2 != NULL)
				tval = pNode1->val + pNode2->val + cal;
			else if (pNode1 != NULL)
				tval = pNode1->val + cal;
			else if (pNode2 != NULL)
				tval = pNode2->val + cal;
			else
				tval = cal;
			cal = 0;
			int rval = tval;
			while (tval / 10 != 0){
				rval = tval % 10;
				cal++;
				tval /= 10;
			}
			pNode->val = rval;
			pNode->next = NULL;
			
			if (pNode1 == l1 && pNode2 == l2){
				head = pNode;
				pLast = pNode;
				if (pNode1 != NULL)
					pNode1 = pNode1->next;
				if (pNode2 != NULL)
					pNode2 = pNode2->next;
				continue;
			}
			pLast->next = pNode;
			pLast = pNode;
			if (pNode1 != NULL)
				pNode1 = pNode1->next;
			if (pNode2 != NULL)
				pNode2 = pNode2->next;
		}

	}
	return head;
}

//优化代码
ListNode* addTwoNumbers_1(ListNode* l1, ListNode* l2) {
	ListNode* head = NULL;
	ListNode *pLast = NULL;
	if (l1 != NULL&&l2 != NULL){
		ListNode* pNode1 = l1;
		ListNode* pNode2 = l2;
		int carry = 0;
		while (pNode1 != NULL || pNode2 != NULL){
			int x = (pNode1 == NULL) ? 0 : pNode1->val;
			int y = (pNode2 == NULL) ? 0 : pNode2->val;
			int rval = x + y + carry;
			ListNode *pNode = new ListNode(rval%10);
			carry = rval / 10;
			if (pNode1 == l1 && pNode2 == l2){
				head = pNode;
				pLast = pNode;
				pNode1 = (pNode1 == NULL) ? NULL : pNode1->next;
				pNode2 = (pNode2 == NULL) ? NULL : pNode2->next;
				continue;
			}
			pLast->next = pNode;
			pLast = pNode;
			pNode1 = (pNode1 == NULL) ? NULL : pNode1->next;
			pNode2 = (pNode2 == NULL) ? NULL : pNode2->next;
		}
		if (carry > 0){
			ListNode *pNode = new ListNode(0);
			pNode->val = carry;
			pLast->next = pNode;
			pLast = pNode;
		}
	}
	return head;
}

int main(){
	ListNode root1(5);
	//ListNode a(4);
	//ListNode b(3);
	//root1.next = &a;
	//a.next = &b;
	ListNode root2(5);
	//ListNode c(6);
	//ListNode d(4);
	//root2.next = &c;
	//c.next = &d;
	ListNode* res = addTwoNumbers_1(&root1, &root2);
	system("pause");
	return 0;
}