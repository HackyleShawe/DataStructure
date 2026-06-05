#include <iostream>
#include <list>
#include <stack>
using namespace std;

/*
 * 函数功能：判断链表是否为回文
 * 输出：链表
 * 输出：1：是回文；0：不是回文
 * 算法：
 *  1.使用栈，但是这次只将链表的后半部分压入栈中，这样在弹出栈的时候，后半部分的节点就逆序了。
 *  2.依次对比链表的前半部分和栈中的每个节点即可。
 */
bool IsPalindromw(list<int>& head)
{
	if (head.empty())
	{
		return false;
	}
	stack<int> my_stack;
	//设置一个快指针和一个慢指针，快指针比慢指针快两倍；
	//当快指针到到末尾时，慢指针刚好在链表的中央；
	list<int> list_fast_point;
	list<int> list_slow_point;

	list<int>::iterator fast = list_fast_point.begin();
	list<int>::iterator slow = list_slow_point.begin();
	for (; fast != list_fast_point.end(); *fast += 2)
	{
		*slow++;
	}
	for (; slow != list_slow_point.end(); *slow++)
	{
		my_stack.push(*slow);
	}

	list<int>::iterator it = head.begin();
	while (!my_stack.empty() && it != head.end())
	{
		if (my_stack.top() != *it)
		{
			return false;
		}
		my_stack.pop();
		*it++;
	}
	return true;
}

int main()
{
	list<int> my_list;
	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	my_list.push_back(2);
	my_list.push_back(1);

	cout << IsPalindromw(my_list) << endl;
	return 0;
}

