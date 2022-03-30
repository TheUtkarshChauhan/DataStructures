#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*prev;
    struct node*next;
};
//For displaying the DLL
struct node* DLLdisp(struct node*head)
{
    struct node*ptr=head;
    while (ptr->next!=head)
    {
        printf("%d-> ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
    return head;
}
//For insrtion in DLL
// Case 1 insrtion at the end
struct node*DLLinsend(struct node*head,int value)
{
    struct node*ptr=head;
    struct node*NN;
    NN=(struct node*)malloc(sizeof(struct node));
    NN->data=value;
    while (ptr->next!=head)
    {
        ptr=ptr->next;
    }
    ptr->next=NN;
    NN->next=head;
    NN->prev=ptr;
    return head;
}
//case2 insertion at front
struct node*DLLinsfront(struct node*head,int value)
{
    struct node*ptr=head;
    struct node*NN;
    NN=(struct node *)malloc(sizeof(struct node));
    NN->data=value;
    NN->prev=head->prev;
    NN->next=ptr;
    ptr->prev=NN;
    return NN;
} 
// case 3 insertion at middle
struct node *DLLinsmid(struct node*head,int value)
{
    struct node*ptr=head;
    struct node*p=head->next;
    struct node*temp=head;
    int count =0;
    struct node* NN;
    NN=(struct node*)malloc(sizeof(struct node));
    NN->data =value;
    while (temp->next != head)
    {
        temp=temp->next;
        count++;
    }
    for (int i = 0; i <= count/2; i++)
    {
        ptr=ptr->next;
        p=p->next;
    }
    ptr->next=NN;
    NN->next=p;
    NN->prev=ptr;
    p->prev=NN;
    return head;
}
// Deletion operations in DLL 
// case 1: deletion from front 
struct node*DLLdelefront(struct node*head)
{
    struct node*ptr = head;
    head = head->next;
    head->prev=ptr->prev;
    free(ptr);
    return head;
}
struct node*DLLdelend(struct node*head)
{
    struct node*ptr = head;
    struct node*p=head->next;
    while (p->next!=head)
    {
        ptr=ptr->next; 
        p=p->next;
    }
    ptr->next=p->next;
    // p->next=NULL;
    free(p);
    return head;
    
}
struct node*DLLdelmiddle(struct node*head)
{
    struct node*ptr = head;
    struct node*p=head->next;
    struct node*temp=head;
    int count =0;
    while (temp->next != head)
    {
        temp=temp->next;
        count++;
    }
    for (int i = 0; i <= (count/2)-1; i++)
    {
        ptr=ptr->next;
        p=p->next;
    }
    ptr->next=p->next;
    free(p);
    return head;
}
//DLL traversal from end
struct node*DLLtraverse(struct node*head)
{
    struct node *ptr=head;
    while (ptr->next != head)
    {
        ptr=ptr->next;
    }
    while (ptr->prev!=head)
    {
        printf("%d<-",ptr->data);
        ptr=ptr->prev;
    }
    printf("%d<-",ptr->data);
    ptr=ptr->prev;
    printf("%d",ptr->data);
    
    return head;
}
int main()
{
    int value;//for taking the data input value
    int condition =0;//for do while loop continuity
    int notes=0;//for creatinf linked list
    struct node * head;
    head =(struct node *)malloc(sizeof(struct node));
    struct node * tail;
    tail =(struct node *)malloc(sizeof(struct node));
    printf("***************************************");
    printf("\n");
    int choice;
    int subchoice;
    printf("***************MENU****************\n");
        printf("Enter (1) for initializing circular doubly linked list:\n");
        printf("Enter (2) for insering elements in circular doubly linked list:\n");
        printf("Enter (3) for deleting elements from circular doubly linked list:\n");
        printf("Enter (4) for Displaying elements in circular doubly linked list:\n");
        printf("Enter (5) for traversal from end\n");
        printf("Enter (6) for Exit\n");
    do
    {
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data of the first node: ");
            scanf("%d",&(head->data));
            head->prev=tail;
            head->next=tail;
            printf("\nEnter the data of new node: ");
            scanf("%d",&(tail->data));
            tail->prev=head;
            tail->next=head;
            printf("\nEnter (-1) to stop: ");
            scanf("%d",&notes);
            while (notes!=-1)
            {
                printf("\nEnter the data of the new node: ");
                scanf("%d",&value);
                head=DLLinsend(head,value);
                printf("\nEnter (-1) to stop: ");
                scanf("%d",&notes);
            }
            
            break;
        case 2:
            printf("Enter (1) for Insertion at the front:\n");
            printf("Enter (2) for Insertion at the end:\n");
            printf("Enter (3) for Insertion at the middle:\n");
            printf("Enter the SubChoice for insertion");
            scanf("%d",&subchoice);
            printf("Enter the New Node data");
            scanf("%d",&value);
            if (subchoice==1)
                  {
                      head=DLLinsfront(head,value);
                  }
                  else if (subchoice==2)
                  {
                      head=DLLinsend(head,value);
                  }
                  else
                  {
                      head=DLLinsmid(head,value);
                  }
            break;
        case 3:
                printf("Enter (1) for deletion at the front\n:");
                printf("Enter (2) for deletion at the end:\n");
                printf("Enter (3) for deletion at the middle:\n");
                printf("Enter the SubChoice for insertion\n");
                scanf("%d",&subchoice);
                if (subchoice==1)
                {
                    head=DLLdelefront(head);
                }
                else if (subchoice==2)
                {
                    head=DLLdelend(head);
                }
                else
                {
                    head=DLLdelmiddle(head);
                }
            break;
        case 4:
         head =DLLdisp(head);
        break;
        case 5:
        head=DLLtraverse(head);
        break;

        default:
            break;
        }
        printf("\nEnter (-1) to exit from MENU: ");
        scanf("%d",&condition);
    } while (condition!=-1);
       
    return 0;
}