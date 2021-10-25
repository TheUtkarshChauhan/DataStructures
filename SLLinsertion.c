#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void lltrans(struct Node * ptr)
{
    while (ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    
}
struct Node * insertfist(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct Node * inseratindex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p =head;
    int i =0;
    while(i!=(index-1))
    {
        p =p->next;
        i++;

    }
    ptr->data = data;
    ptr->next = p->next;
    p->next =ptr;
    return head;
}
struct Node * insertatend(struct Node *head, int data)
{
    struct Node * ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p =head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
struct Node* insertafterNOde(struct Node* prevenode, int data)
{
    struct Node * ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next=prevenode->next;
    prevenode->next = ptr;
    
}
int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    
    // linking first node
    head->data = 7;
    head->next = second;
    //linking second node
    second ->data =8;
    second->next = third;
    //linking third node
    third->data =66;
    third->next =NULL;
    lltrans(head);
    head = insertfist(head,56);
    printf("\n");
    lltrans(head);
    head =inseratindex(head,44,2);
    printf("\n");
    lltrans(head);
    head =insertatend(head,117);
    printf("\n");
    lltrans(head);
    insertafterNOde(second, 45);
    printf("\n");
    lltrans(head);
    return 0;
}