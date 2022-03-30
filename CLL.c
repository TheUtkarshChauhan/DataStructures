// circular linked list menu driven
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
// CLL display function to transverse the linked list
struct node *CLLdisp(struct node *head)
{
    struct node * p = head;
    do
    {
        printf("%d-> ",p->data);
        p=p->next;
    } while (p->next != head);
    printf("%d-> ",p->data);
    return head;
}
//CLL insertion at the end 
struct node * CLLindend(struct node*head, int value)
{
    struct node*ptr =head;
    struct node * NN;
    NN=(struct node*)malloc(sizeof(struct node));
    NN->data=value;
    while (ptr->next !=head)
    {
        ptr = ptr->next;
    }
    ptr->next =NN;
    NN->next=head;
    return head;
}
//CLL insertion at front
struct node* CLLinstfront(struct node*head, int value)
{
    struct node*ptr =head;
    struct node* NN;
    NN=(struct node*)malloc(sizeof(struct node));
    NN->data=value;
    NN->next=head;
    while (ptr->next !=head)
    {
        ptr = ptr->next;
    }
    ptr->next = NN;
    return NN;
}
//CLL insertion at mid
struct node* CLLinstatmid(struct node*head,int value)
{
    struct node*ptr =head;
    struct node* p =head->next;
    struct node* temp =head;
    int count = 0;
    struct node* NN;
    NN=(struct node*)malloc(sizeof(struct node));
    NN->data =value;
    while (temp->next!=head)
    {
        temp=temp->next;
        count++;
    }
    for (int i = 0; i < (count/2)-1; i++)
    {
        ptr=ptr->next;
        p=p->next;
    }
    ptr->next=NN;
    NN->next=p;
    return head;
    
}
// CLL deletion operations 
// Case 1 CLL delete from front of list
struct node* CLLdelefront(struct node*head)
{
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;

}
//case 2 CLL delete from end of list
struct node* CLLdeleend(struct node*head)
{
    struct node *ptr=head;
    struct node*q =head->next;
    while (q->next != head)
    {
        ptr=ptr->next;
        q=q->next;
    }
    ptr->next=q->next;
    free(q);
    return head;
}
//case 3 CLL delete from middle
struct node* CLLdelemid(struct node*head)
{
    struct node*ptr =head;
    struct node* p =head->next;
    struct node* temp =head;
    int count = 0;
    
    while (temp->next!=head)
    {
        temp=temp->next;
        count++;
    }
    for (int i = 0; i < (count/2)-1; i++)
    {
        ptr= ptr->next;
        p= p->next;
    }
    ptr->next = p->next;
    free(p);
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
        printf("Enter (1) for initializing circular linked list:\n");
        printf("Enter (2) for insering elements in linked list:\n");
        printf("Enter (3) for deleting elements from linked list:\n");
        printf("Enter (4) for Displaying elements in linked list:\n");
        printf("Enter (5) for Exit\n");    
    do
    {
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data of first element: ");
            scanf("%d",&(head->data));
            head->next =tail;
            printf("\nEnter the data of New element: ");
            scanf("%d",&(tail->data));
            tail->next =head;
            printf("Enter (-1) to exit:");
            scanf("%d",&notes);
            while (notes!=-1)
            {
                printf("\nEnter the data of New element: ");
                scanf("%d",&value);
                head =CLLindend(head,value);
                printf("Enter (-1) to exit:");
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
                      head=CLLinstfront(head,value);
                  }
                  else if (subchoice==2)
                  {
                      head=CLLindend(head,value);
                  }
                  else
                  {
                      head=CLLinstatmid(head,value);
                  }
                  
                  break;
        case 3:
                printf("Enter (1) for deletion at the front\n:");
                printf("Enter (2) for deletion at the end\n:");
                printf("Enter (3) for deletion at the middle:\n");
                printf("Enter the SubChoice for insertion\n");
                scanf("%d",&subchoice);
                if (subchoice==1)
                {
                    head=CLLdelefront(head);
                }
                else if (subchoice==2)
                {
                    head=CLLdeleend(head);
                }
                else
                {
                    head=CLLdelemid(head);
                }
                break;
        case 4:
            head = CLLdisp(head);
            break;
        default:
            break;
        }
        printf("\nEnter (-1) to exit the MENU:");
        scanf("%d",&condition);
    } while (condition!=-1);
    
    return 0;
}