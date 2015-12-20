#include <stdio.h>
#include <stdlib.h>
/*
	定义结构体
*/
typedef struct Node
{
	int data;
	struct Node * next;
}Node;
/*
	创建循环的单链表*/
Node * CreatLb(int large)
{
	Node * head = (Node *)malloc(1 * sizeof(Node));
	while(head == NULL)
	{
		head = (Node *)malloc(1 * sizeof(Node));
	}
	head -> data = 789;
	head -> next = NULL;

	Node * newNode;
	Node * curr = head;
	int i;
	for(i = 0;i < large;i ++)
	{
		newNode = (Node *)malloc(1 * sizeof(Node));
		while(newNode == NULL)
		{
			newNode = (Node *)malloc(1 * sizeof(Node));
		}
		newNode -> data = i + 1;
		newNode -> next = NULL;

		curr -> next = newNode;
		curr = newNode;
		newNode = NULL;
	}
	curr -> next = head;

	return head;
}
/*
打印链表*/
void PrintLb(Node * head)
{
	Node * curr;
	curr = head -> next;
	while(curr != head)
	{
		printf("%d\n",curr -> data );
		curr = curr -> next;
	}
	printf("------------------\n");
	printf("%d\n",head -> data );
}/*
释放链表*/
void FreeLb(Node * head)
{
	Node * curr;
	curr = head -> next;
	Node * tmp;
	while(curr != head)
	{
		tmp = curr;
		free(tmp);
		tmp = NULL;
		curr = curr -> next;
	}
	free(head);
	head = NULL;
}/*
删除链表中的某个值*/
void deleteNode(Node * head,int data)
{
	Node * curr = head -> next;
	Node * tmp;
	while(curr != head)
	{
		if(curr -> data == data)
		{
			tmp -> next = curr -> next;
			free(curr);
			curr = NULL;
			break;
		}
		else
		{
			tmp = curr;//承接一下
		}
		curr = curr -> next;
	}
}
//在某个位置之后插入相应的value值
void InsertAfterNode(Node * head,int pos,int value)
{
	Node * curr;
	curr = head -> next;
	Node * newNode;
	while(curr != head)
	{
		if(curr -> data == pos)
		{
			newNode = (Node *)malloc(1 * sizeof(Node));
			while(newNode == NULL)
			{
				newNode = (Node*)malloc(1 * sizeof(Node));
			}
			newNode -> data = value;
			newNode -> next = NULL;

			newNode -> next = curr	-> next;
			curr -> next = newNode;
			newNode = NULL;			
		}
		curr = curr -> next;
			

	}
}
//在某个节点的前面插入某个value值
void InsertBackNode(Node * head,int pos,int value)
{
	Node * curr;
	curr = head -> next;
	Node * tmp;
	Node * newNode;
	while(curr != head)
	{
		if(curr -> data == pos)
		{
			newNode = (Node *)malloc(1 * sizeof(Node));
			while(newNode == NULL)
			{
				newNode = (Node*)malloc(1 * sizeof(Node));
			}
			newNode -> data = value;
			newNode -> next = NULL;
			if(curr == head)
			{
				head -> next = newNode;
				newNode -> next = curr;	
				break;
			}

			tmp -> next = newNode;
			newNode -> next = curr;
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
	PrintLb(Lb);
	// FreeLb(Lb);
	// deleteNode(Lb,7);
	InsertBackNode(Lb,5,88);
	PrintLb(Lb);
	return 0;
}