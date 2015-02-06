/********************************************************************************** 
*
*问题：给出一个有序的链表，要求返回一个没有相同数字的链表。
*方法一：开一个新的链表ans，ans->val等于head->next->val就不添加到ans->next。
*
*
**********************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//方法一
//23MS
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
		if(head == NULL) return NULL;
		ListNode* Newhead;
		ListNode* ans;
		ListNode* temp;
		ans = new ListNode(head->val);
		Newhead = ans;
		temp = head;
		while(temp->next != NULL)
		{
			if(ans->val != temp->next->val)
			{
				ans->next = new ListNode(temp->next->val);
				ans = ans->next;
			}
			temp = temp->next;
		}
		return Newhead;
    }
};