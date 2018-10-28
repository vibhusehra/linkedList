#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *deletei();
int main()
{
    int option;
    do
    {
        printf("\n\n *****MAIN MENU *****");
 printf("\n 1: Create a list");
 printf("\n 2: Display the list");
 printf("\n 3: Add a node at the beginning");
 printf("\n 4: Add a node at the end");
 printf("\n 5: Add a node before a given node");
 printf("\n 6: Add a node after a given node");
 printf("\n 7: Delete a node from the beginning");
 printf("\n 8: Delete a node from the end");
 printf("\n 9: Delete a given node");
 printf("\n 10: Delete a node after a given node");
 printf("\n 11: Delete the entire list");
 printf("\n 12: Sort the list");
 printf("\n 13: EXIT");
 printf("\n\n Enter your option : ");
 scanf("%d", &option);
 switch(option)
 {
    case 1: start=create_ll(start);
    printf("\n LINKED LIST CREATED");
    break;
    case 2: start=display(start);
    break;
    case 9: start=deletei();
    printf("\n The node is deleted");
    break;
 }
    }while(option!=13);
    return 0;
}
struct node *create_ll(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data");
    scanf("%d",&num);
    while(num!=-1)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node->data=num;
        if(start==NULL)
        {
            new_node->next=NULL;
            start=new_node;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
                ptr->next=new_node;
                new_node->next=NULL;
            }
        }
        printf("\n Enter the data");
        scanf("%d",&num);
    }
    return start;
};
struct node *display(struct node *start)
{
    struct node *ptr;

    while(ptr!=NULL)
    {
        printf("\t %d",ptr->data);
        ptr=ptr->next;
    }
    return start;
};
struct node *deletei()
{
    printf("Enter the data you want to delete");
    int del;
    scanf("%d",&del);
    struct node *ptr;
    while(ptr!=NULL)
    {
        if(ptr->next->data==del)
        {
            ptr=ptr->next->next;
        }
        ptr=ptr->next;
    }

};
