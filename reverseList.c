#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node* link;
};

struct node* create(){
 struct node* head= NULL;
 return head;
}

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

struct node* insert1(struct node* head, int val)
{
 struct node* new = (struct node*)malloc(sizeof(struct node));
 new->data=val;
 new->link=head;
 head=new;

return head;
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

struct node* reverse(struct node* head, struct node* deah){

 struct node* temp=head;

 while(temp->link!=NULL){
 deah=insert1(deah,temp->data);
 temp=temp->link;
}
return deah;
}

int main(){
 struct node* head= create();
 int x=0;
 printf("\n\n!!Enter -1 to get out of the loop!!\n\n");
 printf("Enter the numbers:: ");
 while(x!=-1){
// printf("Enter a number:: ");
 scanf("%d",&x);
 if(x!=-1)
 head=insert(head,x);
}
 display(head);
 struct node* deah= create();
 deah=reverse(head,deah);
 printf("\n\nReversing...\n\n");
 display(deah);
}
