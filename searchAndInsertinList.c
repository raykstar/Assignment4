#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node* link;
};

//struct node* create(){
// struct node* head= NULL;
 //return head;
//}

struct node* insert(struct node* head, int val)
{
 struct node* new = (struct node*)malloc(sizeof(struct node));
 new->data=val;
 new->link=NULL;

 if(head==NULL){
 head=new;
}
else{
 struct node* temp=head;
 while(temp->link!=NULL){
 temp=temp->link;
}
 temp->link=new;
}
return head;
}

struct node* search(struct node* head, int x){
 struct node* temp = head;
 while(temp!=NULL){
 if(temp->data==x)
 return temp;
 else
 if(temp!=NULL)
 temp=temp->link;
}
return NULL;
}

struct node* srchinsrt(struct node* head, int val){
 head = insert(head,val);
 struct node* pos = search(head,val);
 return pos;
}

void display(struct node* head){
struct node* temp= head;

temp=head;
printf("The list is:: \n\n");
while(temp->link!=NULL){
 printf("%d  ",temp->data);
 temp=temp->link;
}
printf("%d  \n",temp->data);

}

int main(){
    struct node* head = NULL;
    int x=0;
    printf("Enter -1 to indicate the end of input string!!\n\n");
    printf("Enter the list:: ");
    while(x!=-1){
     scanf("%d",&x);
     if(x!=-1)
     head=insert(head,x);
    }
    display(head);

    int val;
    printf("Enter the value to search:: ");
    scanf("%d",&val);
    struct node* pos=search(head, val);
    if(pos==NULL){
     printf("NOT FOUND!\n");
     printf("\nAdding element to the list\n\n");
     pos = srchinsrt(head,val);
     display(head);
    }
    else{
     printf("FOUND!\n");
    }
}
