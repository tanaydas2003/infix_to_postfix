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
int main()
{
    int value;
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *temp;
    struct Node *trav;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    temp=(struct Node*)malloc(sizeof(struct Node));
    trav=(struct Node*)malloc(sizeof(struct Node));
    head->data=7;
    head->ptr=second;
    second->data=45;
    second->ptr=third;
    third->data=63;
    third->ptr=NULL;
    printf("Enter the value to be inserted : ");
    scanf("%d",&value);
    linkedlisttraversal(head);
    printf("After insertion at end\n");
    temp->data=value;
    temp->ptr=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        trav=head;
        while(trav->ptr!=NULL){
            trav=trav->ptr;
        }
        trav->ptr=temp;
    }
    linkedlisttraversal(head);
    return 0;
}