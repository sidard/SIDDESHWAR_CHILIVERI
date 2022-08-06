#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};

int main()
{
	struct Node *ptr= NULL,*baseAddress=NULL;
	/**First Node Creation*/
	ptr = (struct Node*)malloc(sizeof(struct Node));
	/**Assign the baseAddress*/
	baseAddress = ptr;

	ptr->data = 1;
	printf("First Node :%d ",ptr->data);printf("First Node Address:%x\n",ptr);
	/**Second Node Creation*/
	ptr->next = (struct Node*)malloc(sizeof(struct Node));

	struct Node *ptr2 = ptr->next;
	ptr2->data = 2;
	printf("Second Node :%d",ptr2->data);printf(" Second Node Address:%x ",ptr2);
	ptr2->next = NULL;
}
