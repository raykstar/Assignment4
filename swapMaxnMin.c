#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int val){
    struct node* new = (struct node* )malloc(sizeof(struct node*));
    new->data = val;
    new->next =NULL;

    return new;
}

struct node* insert(struct node* head, int val){
    struct node* new = createNode(val);
    struct node* temp =head;
    if(head==NULL) head = new;
    else{
        while(temp->next!=NULL) temp = temp->next;
        temp->next = new;
    }

    return head;
}

int max(struct node* head){
    struct node* temp = head;
    int m = head->data;

    while(temp->next!=NULL){
        if(temp->data>m) m=temp->data;
        temp = temp->next;
    }

    if(temp->data>m) m=temp->data;

    return m;
}

int min(struct node* head){
    struct node* temp = head;
    int m = head->data;

    while(temp->next!=NULL){
        if(temp->data<m) m=temp->data;
        temp = temp->next;
    }

    if(temp->data<m) m=temp->data;

    return m;
}

struct node* swap(struct node*head,int maxm,int minm){
    struct node* temp = head;
    while(temp!=NULL){
        if(temp->data==maxm) temp->data=minm;
        else if(temp->data==minm) temp->data=maxm;
        if(temp!=NULL) temp=temp->next;
    }
    return head;
}

void display(struct node* head){
    struct node* temp = head;
    while(temp->next!=NULL){
        printf("%d-->",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}

int main(){
    struct node* head =NULL;
    int x = 0;

    while(x!=-1){
        scanf("%d",&x);
        if(x!=-1)
        head = insert(head,x);
    }
    printf("The list is::\n");
    display(head);

    int maxm = max(head);
    int minm = min(head);

    printf("%d is the maximum and %d is the minimum\n",maxm,minm);

    head = swap(head, maxm, minm);
    printf("Swapping.....\nSwapped!\n");
    display(head);
}
