#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* create(){
    struct node* head =NULL;
    return head;
}

struct node* insert(struct node* head, int val){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data= val;
    n->link= NULL;

    if(head==NULL){
        head = n;
    }
    else{
        struct node* temp=head;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=n;
}
return head;
}


void display(struct node* head){
    struct node* temp=head;
    while(temp->link!=NULL){
        printf("%d",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
int main(){
    struct node* head1 = create();

    char c1='\0';
    printf("Enter  no:  ");
    while(c1!=' ' && c1!='\n'){
        scanf("%c",&c1);
        head1=insert(head1,c1-'0');
    }
    printf("You've entered: ");
    display(head1);


}
