/* 爬楼梯，给定楼层层数，求上楼梯的方法种数，并打印出来，其本质是斐波那契数列穿了一层马甲 */

#include <iostream>
#include <string>

using namespace std;

typedef struct Node
{
	Node *parent;
	Node *left;
	Node *right;
	int value;
} Node;

int n;

int climbStairs(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else
	{
		return climbStairs(n - 1) + climbStairs(n - 2);
	}
}

int func(Node *root, int layer)
{
	string start = "\n";
	for (int i = 0; i < layer; i++)
	{
		start += "   |";
	}
	start += "\n";
	for (int i = 0; i < layer; i++)
	{
		start += "    ";
	}
	start += "————";
	
	int sum = 0;
	if (n == root->value)
	{
		sum += 1;
	}
	else
	{
		if (n - root->value > 0 && root->left == nullptr)
		{
			Node leftNode;
			leftNode = {root, nullptr, nullptr, root->value + 1};
			root->left = &leftNode;
			cout << start << "走1层";
			sum += func(&leftNode, layer + 1);
		}
		if (n - root->value > 1 && root->right == nullptr)
		{
			Node rightNode;
			rightNode = {root, nullptr, nullptr, root->value + 2};
			root->right = &rightNode;
			cout << start << "走2层";
			sum += func(&rightNode, layer + 1);
		}
	}
	return sum;
}

int test(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else
	{
		int num1 = 1, num2 = 2;
		for (int i = 3; i <= n; i++)
		{
			int temp = num1 + num2;
			num1 = num2;
			num2 = temp;
		}
		return num2;
	}
}

int main()
{
	//cin >> n;
	n = 45;
	cout << "走" << n << "层楼梯，一次只能走1层或2层，有如下方法：\n";
	Node root = {nullptr, nullptr, nullptr, 0};
	//int res = func(&root, 0);
	//int res = climbStairs(n); //也可使用此函数得到方法种数，该算法来自力扣
	int res = test(n); //计算斐波那契数列
	cout << "\n\n共" << res << "种走法\n";
	system("pause");
}
