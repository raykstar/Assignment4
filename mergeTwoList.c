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

void mergesort(struct node* head1,struct node* head2){
 struct node* temp1=head1;
 struct node* temp2=head2;
 struct node* head3 = create();
 int val;
 while(temp1!=NULL && temp2!=NULL){

 if(temp1->data<temp2->data){
 val=temp1->data;
 if(temp2!=NULL)
 temp1=temp1->link;
}
 else{
 val=temp2->data;
 if(temp2!=NULL)
 temp2=temp2->link;
}
 head3=insert(head3, val);
}


while(temp1!=NULL){
 val=temp1->data;
 if(temp1!=NULL)
 temp1=temp1->link;
 head3=insert(head3, val);
}

while(temp2!=NULL){
 val=temp2->data;
 if(temp2!=NULL)
 temp2=temp2->link;
 head3=insert(head3, val);
}

 display(head3);
}

int main(){
 struct node* head1= create();
 int x=0;
 printf("\n\n!!Enter -1 to get out of the loop!!\n\n");
 printf("Enter the first sorted array:: ");
 while(x!=-1){
 scanf("%d",&x);
 if(x!=-1)
 head1=insert(head1,x);
}

display(head1);

struct node* head2= create();
  x=0;
 printf("\n\n!!Enter -1 to get out of the loop!!\n\n");
 printf("Enter the second sorted array:: ");
 while(x!=-1){
 scanf("%d",&x);
 if(x!=-1)
 head2=insert(head2,x);
 }
display(head2);
 printf("The sorted list is:: ");
 mergesort(head1,head2);
}
