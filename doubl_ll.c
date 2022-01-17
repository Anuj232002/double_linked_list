#include <stdio.h>
#include <stdlib.h>
struct double_ll
{
 int data;
 struct double_ll *prev, *next;
};
void create(int n, struct double_ll* head)
{
 struct double_ll *temp;
 for(int i=0;i<n;i++)
 {
 temp = (struct double_ll*)malloc(sizeof(struct double_ll));
 printf("Enter data: ");
 scanf("%d",&temp->data);
 head->next = temp;
 temp->next = NULL;
 temp->prev = head;
 head = head->next;
 }
}
void display(struct double_ll *head)
{
 printf("\nElements of the list are: ");
 while(head!=NULL)
 {
 printf("%d ",head->data);
 head = head->next;
 printf("\n");
}
}
void insert_middle(int e, struct double_ll *head)
{
 struct double_ll *temp, *p, *q;
 q = head;
 temp = (struct double_ll*)malloc(sizeof(struct double_ll));
 printf("\nEnter data: ");
 scanf("%d",&temp->data);
 temp->next = NULL;
 temp->prev = NULL;
 while(e != head->data)
 {
 head = head->next;
 }
 p = head->next;
 p->prev = temp;
 temp->next = p;
 head->next = temp;
 temp->prev = head;
 display(q);
}
void display_rev(struct double_ll *head)
{
 while(head->next != NULL)
 {
 head = head->next;
 }
 while(head!=NULL)
 {
 printf("%d\n",head->data);
 head = head->prev;
 }
}
void insert_end(struct double_ll *head)
{
 struct double_ll *temp;
 temp = (struct double_ll*)malloc(sizeof(struct double_ll));
 printf("Enter data: ");
 scanf("%d",&temp->data);
 temp->next = NULL;
 temp->prev = NULL;
 while(head->next != NULL)
 {
 head = head->next;
 }
 temp->prev = head;
 head->next = temp;
}
struct double_ll* insert_first(struct double_ll *head)
{
 struct double_ll *temp;
 temp = (struct double_ll*)malloc(sizeof(struct double_ll));
 printf("Enter data: ");
 scanf("%d",&temp->data);
 temp->prev = NULL;
 temp->next = head;
 head->prev = temp;
 return temp;
}
struct double_ll* deleteHead(struct double_ll *head)
{
 struct double_ll *p;
 p = head;
 head = head->next;
 head->prev = NULL;
 free(p);
 return head;
}
void delete(struct double_ll *head, int data)
{
 while(head->data != data)
 {
 head = head->next;
 }
 struct double_ll *p, *q;
 p = head->prev;
 q = head->next;
 p->next = q;
 q->prev = p;
 free(head);
}
void display(struct double_ll *head)
{
 printf("Elements of the list are: \n");
 while(head!=NULL)
 {
 printf("%d ",head->data);
 head = head->next;
 printf("\n");
}
}
void deleteLast(struct double_ll *head)
{
 struct double_ll *p;
 while(head->next != NULL)
 {
 head = head->next;
 }
 p = head->prev;
 p->next = NULL;
 free(head);
}

int main(void)
{
 struct double_ll *head;
 head = (struct double_ll*)malloc(sizeof(struct double_ll));
 int choice,n,e;
 
 do
 {
printf("\n****************************************\n");
 printf("\n1. Create ");
 printf("\n2. Insert at first");
 printf("\n3. Insert at middle");
 printf("\n4. Insert at end");
 printf("\n5. Delete head");
 printf("\n6. Delete middle node");
 printf("\n7. Delete last node");
 printf("\n8. Display list forward");
 printf("\n9. Display backward");
 printf("\n10. Exit");
 printf("\nEnter choice: ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 printf("\nEnter data for head node");
 scanf("%d",&head->data);
 head->next = NULL;
 head->prev = NULL;
 printf("\nEnter number of nodes");
 scanf("%d",&n);
 create(n,head);
 case 2:
 head = insert_first(head);
 display(head);
 break;
 case 3:
 printf("\nEnter element after which want to insert: ");
 scanf("%d",&e);
 insert_middle(e, head);
 break;
 case 4:
 insert_end(head);
 display(head);
 break;
 case 5:
 head = deleteHead(head);
 display(head);
 break;
 case 6:
 printf("\nEnter node which want to delete: ");
 scanf("%d",&e);
 delete(head,e);
 display(head);
 break;
 case 7:
 deleteLast(head);
 display(head);
 break;
 case 8:
 display(head);
 break;
 case 9:
 display_rev(head);
 break;
 case 10:
 
 break;
 default:
 printf("\nPlease enter correct choice");
}}while(choice != 10);

 return 0;
}
