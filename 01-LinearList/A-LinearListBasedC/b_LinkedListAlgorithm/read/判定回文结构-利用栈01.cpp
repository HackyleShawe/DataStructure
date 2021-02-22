#include <cstdio>
#include <list>
#include <stack>
using namespace std;

/*
 * 函数功能：判断链表是否为回文
 * 输出：链表
 * 输出：1：是回文；0：不是回文
 * 算法：
 *  1.使用栈，遍历一遍链表把每个节点都压入栈中，这样在弹出栈的时候，所有的节点就逆序了。
 *  2.依次对比原链表的每个节点即可。
 */
bool IsPalindromw(list<int>& MyList)
{
	if (MyList.empty())
	{
		return false;
	}

	stack<int> MyStack;
	list<int> AssistList = MyList;
	for (list<int>::iterator it = AssistList.begin(); it != AssistList.end(); *it++)
	{
		MyStack.push(*it);
	}
	list<int>::iterator it = MyList.begin();
	while (!MyStack.empty() && it != MyList.end())
	{
		if (MyStack.top() != *it)
		{
			return false;
		}
		MyStack.pop();
		*it++;
	}
	return true;
}
int main()
{
	//创建列表
	list<int> MyList;
	MyList.push_back(1);
	MyList.push_back(2);
	MyList.push_back(3);
	MyList.push_back(2);
	MyList.push_back(1);

	printf("是否回文？ %d", IsPalindromw(MyList));
	return 0;
}
