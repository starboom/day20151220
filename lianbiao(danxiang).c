#include <stdio.h>
#include <stdlib.h>

/*
	链表结构体：
		存储数据类型
		指向下一个相邻链表结构体
*/
typedef struct Node
{
	int data;
	struct Node * next;
	
}Node;
/*
*	函数	：Node * CreatLb(int large)
	参数	：链表大小large
	返回值	：返回链表结构体 node*
	功能描述：创建链表
*/
Node * CreatLb(int large)
{
	Node * head;
	head = (Node *)malloc(1 * sizeof(head));
	while(head == NULL)
	{
		head = (Node *)malloc(1 * sizeof(head));
	}
	head -> data = -100;
	head -> next = NULL;
	Node * newnode;
	Node * curr;
	curr = head;

	int i;
	for(i = 0;i < large;i++)
	{
		newnode = (Node*)malloc(1 * sizeof(Node*));
		while(head == NULL)
		{
			newnode = (Node*)malloc(1 * sizeof(Node*));
		}
		newnode -> data = i + 1;
		newnode -> next = NULL;
		curr -> next = newnode;
		curr = newnode;
		newnode = NULL;
	}
	return head;
}
/*
*	函数	：void PrintLb(Node * head)
	参数	：链表结构体
	返回值	：空
	功能描述：打印链表
*/
void PrintLb(Node * head)
{
	Node * curr;
	curr = head;
	while(curr != NULL)
	{
		printf("%d\n",curr -> data );
		curr = curr -> next;
	}
}
/*
*	函数	：void FreeLb(Node * head)
	参数	：链表结构体
	返回值	：空
	功能描述：释放链表
*/
void FreeLb(Node * head)
{
	Node * curr;
	curr = head -> next;
	head -> next = NULL;
	Node * tmp;
	/*
		利用tmp变量把每一个节点独立出来释放
	*/
	while(curr != NULL)
	{
		tmp = curr;
		curr = curr -> next;
		head -> next = curr;
		free(tmp);
		tmp = NULL;
	
	}
	free(head);
	head = NULL;

}
/*
*	函数	：void InsertAfterNode(Node * head,int pos,int value)
	参数	：链表结构体，所插入的位置，所要插入的值
	返回值	：空
	功能描述：在链表某个节点之后插入数值
*/
void InsertAfterNode(Node * head,int pos,int value)
{
	Node * curr = head;

	Node * newnode;

	while(curr != NULL)
	{
		if(curr -> data == pos)
		{
			newnode = (Node*)malloc(1 * sizeof(Node));
			while(newnode == NULL)
			{
				newnode = (Node*)malloc(1*sizeof(Node));
			}
			newnode -> data = value;
			newnode -> next = NULL;
			newnode -> next = curr -> next;
			curr -> next = newnode;
		}
		curr = curr -> next;
	}

}
/*
*	函数	：void InsertBeforeNode(Node * head,int pos,int value)
	参数	：链表结构体，所插入的位置，所要插入的值
	返回值	：空
	功能描述：在链表某个节点之前插入数值
*/

void InsertBeforeNode(Node * head,int pos,int value)
{
	Node * curr = head;
	Node * tmp;
	Node * newnode;

	while(curr != NULL)
	{
		if(curr -> data == pos)
		{
			newnode = (Node*)malloc(1 * sizeof(Node));
			while(newnode == NULL)
			{
				newnode = (Node*)malloc(1 * sizeof(Node));
			}
			newnode -> data = value;
			newnode -> next = NULL;
			if(curr == head)
			{
				head -> next = newnode;
				newnode -> next = curr;
			}
			else
			{
				tmp -> next = newnode;
				newnode -> next = curr;
			}

		}
		else
			tmp = curr;
		curr = curr -> next;
	}

}
/*
*	函数	：void DeleteLb(Node * head,int pos)
	参数	：链表结构体，删除的位置
	返回值	：空
	功能描述：删除链表某个节点
*/
void DeleteLb(Node * head,int pos)
{
	Node * curr;
	curr = head;
	Node * tmp;
	while(curr != NULL)
	{


		if(curr -> data == pos)
		{
			if(curr == head)
			{
				head = head -> next;
				free(curr);
				curr = NULL;
				break;
			}
			else
			{
				tmp -> next = curr -> next;
				curr -> next = NULL;
				free(curr);
				curr = NULL;
				break;
			}

		}
		else
		{
			tmp = curr;
		}
		curr = curr -> next;
	}
}
int main(int argc, char const *argv[])
{
	Node * Lb;

	Lb = CreatLb(10);
	printf("Lb -> data = %d\n",Lb -> data );
	PrintLb(Lb);
	InsertBeforeNode(Lb,3,88);
	DeleteLb(Lb,Lb -> data);
	DeleteLb(Lb,8);
	DeleteLb(Lb,9);
	printf("\n");
	printf("Lb -> data = %d\n",Lb -> data );
	PrintLb(Lb);
	FreeLb(Lb);
	return 0;
}


