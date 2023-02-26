#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
单链表的节点分为数据域和指针域，可以将它们视为一个整体，称之为节点，会用结构体来表示节点。
数据域，顾名思义，就是存放数据的地方。
指针域，是用来存放指针变量的地方，指针指向下一个节点的地址。
	struct node {
    struct node *next;//后继节点 
	int data;//值
	};
	
	
*/  
typedef struct node {
	/* 后继节点 */
	struct node *next;
	/* 值 */
	int data;
}list;
//typedef  truct node list 取别名
// 创建链表
list * create_list()
{
	/* 创建一个新的节点，由于使用了typedef关键字，此处 list *head与struct node *head等价    */
	list *head = (list *)malloc(sizeof(list));
	if(head==NULL) return NULL;
	/* 初始化节点 */
	head->data = 0; // 头结点数据域，我们用来表示链表长度
	head->next = NULL; 
	return head;
}
/* 打印链表数据，但不包括头结点的数据*/
void print_list(list *head)
{
	list *curr = head->next;
	while (curr)
	{
		printf("%d \t", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

//链表插入节点
/*
	list_insert_node插入函数接受三个参数，
	被插入节点的链表的指针head，新结点的数据data，和要插入的位置pos
*/

list * list_insert_node(list *head, int data, int pos)
{   
	int i;
	list *curr = head; //当前位置
	
	/* 如果要插入的位置比链表长，则属于非法操作 */
	if(pos > curr->data) return NULL;
	
	/* 遍历链表，找到要插入的位置 */
	for(i=0;i<pos;i++){
		curr = curr->next;
	}
	
	/* 查找成功，生成一个空节点node,并初始化 */
	list *node = (list *)malloc(sizeof(list));
	if(node==NULL) return NULL;
	node->data = data; 	//把新结点的数据data赋值给node->data
	node->next = NULL;
	
	/* 单链表插入标准语句 */
	node->next = curr->next;
	curr->next = node;
	
	/* 链表长度+1 */
	head->data++;
	
	return head;
}
//删除节点
list *list_delete_data(list *head, int pos)
{
	int i;
	list *curr = head; //记录当前位置
	
	/* 如果要删除的位置比链表长，则属于非法操作 */
	if(pos > curr->data) return NULL;
	
	/* 遍历链表，找到要删除的节点的前一个节点的指针 */
	for(i=0;i<pos;i++){
		curr = curr->next;
	}
	
	// 临时记录将被删除的节点
	list *temp = curr->next;
	// 删除节点
	curr->next = curr->next->next;
	
	//释放掉被删除节点的内存
	free(temp);
	head->data--;
	return head;
}


int main()
{
	int i;
	list *l = create_list();
	// 多次插入数据
	for(i=0;i<5;i++)
	{
		list_insert_node(l, i, 0);
		print_list(l);
	}
	list_delete_data(l, 0);
	print_list(l);
	return 0;
}

