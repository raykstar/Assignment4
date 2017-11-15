#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node *next;
}*head,*temp,*p,*h1,*h2,*add,*t1,*t2,*temp2,f;

void append(int val){
	if(head==NULL){
		head=(struct node*)malloc(sizeof(struct node));
		head->data=val;
		head->next=NULL;
	}
	else{
		temp=head;
		while(temp->next!=NULL) temp=temp->next;
		p=(struct node*)malloc(sizeof(struct node));
		p->data=val;
		p->next=NULL;
		temp->next=p;
	}
}
void display(){
	temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

void addNo(){
	t1=h1;
	t2=h2;
	int carry=0,sum,value,a1,a2;
	while(t1!=NULL || t2!=NULL){
		a1=0;
		a2=0;
		if(t1!=NULL) a1=t1->data;
		if(t2!=NULL) a2=t2->data;
		value=a1+a2+carry;
		sum=(value)%10;
		carry=(value)/10;
		append(sum);
		if(t1!=NULL) t1=t1->next;
		if(t2!=NULL) t2=t2->next;
	}
	if (carry!=0) append(carry);
	add=head;
	head=NULL;
}

int main(){
	head=NULL;
	char s[1000];
	printf("enter the number\n");
	fflush(stdin);
	scanf("%s",s);

	int i;
	for(i=strlen(s)-1;i>=0;i--){
		append((int)s[i]-'0');
	}

	h1=head;
	head=NULL;

	fflush(stdin);
	printf("enter the second number\n");
	scanf("%s",s);
	for(i=strlen(s)-1;i>=0;i--){
		append((int)s[i]-'0');
	}

	printf("\n");
	h2=head;
	head=NULL;
	addNo();
	// have an add
	head=NULL;
	head=(struct node*)malloc(sizeof(struct node));
	head=NULL;
	temp=add;
	while(temp!=NULL){
		p=(struct node*)malloc(sizeof(struct node));
		p->data=temp->data;
		p->next=head;
		head=p;
		temp=temp->next;

	}


	display();
	return 0;
}
