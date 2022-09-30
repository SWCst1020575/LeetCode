#include <iostream>
#include <vector>

// time : pr77 space : pr93

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	auto l1current=l1;
	auto l2current=l2;
	bool longest=0;
	while(l1current != nullptr || l2current != nullptr){
		if(l1current!=nullptr && l2current != nullptr){
			int sum = l1current->val + l2current->val;
			if(sum>9){
				if(l1current->next==nullptr)
					l1current->next = new ListNode(1);
				else
					l1current->next->val++;
				sum-=10;
			}
			l1current->val = sum;
			l2current->val = sum;
		}
		if(l1current == nullptr)
			longest = 1;
		else if(l2current == nullptr)
			longest = 0;
		if(l2current != nullptr){
			if(l2current->val>9){
				if(l2current->next==nullptr)
					l2current->next = new ListNode(1);
				else
					l2current->next->val++;
				l2current->val-=10;
			}
			l2current = l2current->next;
		}
		if(l1current != nullptr){
			if(l1current->val>9){
				if(l1current->next==nullptr)
					l1current->next = new ListNode(1);
				else
					l1current->next->val++;
				l1current->val-=10;
			}
			l1current = l1current->next;
		}
	}
	if(longest)
		return l2;
	else
		return l1;
}
int main(){
	ListNode *a = new ListNode(2);
	a->next = new ListNode(4);
	a->next->next = new ListNode(3);
	ListNode *b = new ListNode(5);
	b->next = new ListNode(6);
	b->next->next = new ListNode(4);
	auto current = addTwoNumbers(new ListNode(0),new ListNode(0));
	while(current != nullptr){
		std::cout<<current->val<<" ";
		current = current->next;
	}
	std::cout<<"\n";

}
