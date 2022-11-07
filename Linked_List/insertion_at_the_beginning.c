#include <stdio.h>
#include<stdlib.h>
struct Node{
        int data;
        struct Node *ptr;
};
void linkedlisttraversal(struct Node *trav){
    while(trav!=NULL){
        printf("Element: %d\n",trav->data);
        trav=trav->ptr;
    }
}
/*struct Node * insertionatfirst(struct Node *head,int data){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->ptr=head;
    head=temp;
    return temp;
};*/
int main()
{
    int value;
    struct Node *head;
    struct Node *second;
    struct Node *third;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    head->data=7;
    head->ptr=second;
    second->data=45;
    second->ptr=third;
    third->data=63;
    third->ptr=NULL;
    printf("Enter the value to be inserted : ");
    scanf("%d",&value);
    linkedlisttraversal(head);
    //head=insertionatfirst(head,56);
    printf("After insertion at beginning\n");
    if (head==NULL){
        struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=value;
        temp->ptr=NULL;
        head=temp;
    }
    else{
        struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=value;
        temp->ptr=head;
        head=temp;
    }
    linkedlisttraversal(head);
    return 0;
}