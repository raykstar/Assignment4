#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct node{

    char c;
    struct node* next;
};

struct node* insert(struct node* head, char s){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->c = s;
    new->next = NULL;

    if(head == NULL){
        head = new;
    }
    else{
        struct node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next =new;
    }
    return head;
}

void display(struct node* head){
    struct node* temp = head;
    printf("The list is:: ");
    while(temp->next!=NULL){
        printf("%c ",temp->c);
        temp = temp->next;
    }
    printf("%c \n",temp->c);

}

struct node* strcnvcl(struct node* head,char *  str){

    int i;

    for(i=0;str[i]!='\0';i++){
        head = insert(head, str[i]);
    }
    return head;
}

int strvrfyl(struct node *l1,struct node *l2){
	struct node *temp1=l1;
	struct node *temp2=l2;
	int i=1;
	while(temp1!=NULL && temp2!=NULL){
		if(temp1->c!=temp2->c) return i;
		i++;
		temp1=temp1->next;
		temp2=temp2->next;
	}
	return i;

}

char * strsbstr(struct node *l1,int i1, int i2){
	struct node* temp=l1;
	int i;
	for(i=1;i<i1;i++){
		temp=temp->next;
	}

	char s[20];
	int j=0;

    for(i=i1;i<=i2;i++){
        s[j++] = temp->c;
		temp=temp->next;
	}



    char * str =s;
   return str;
}

int strcmpl(struct node* l1, struct node* l2){
    struct node* temp1 = l1, *temp2 = l2;

    while(temp1->next!=NULL && temp2->next!=NULL){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if(temp1->next==NULL && temp2->next==NULL){
        return 0;
    }
    else if(temp1->next==NULL){
        return -1;
    }
    else if(temp2->next==NULL){
        return 1;
    }
    return -2;
}

int main(){
 while(1){
    printf("\nEnter::\n1 to convert a character string to a list\n2 to determine the first position in the 1st string that is not contained in the 2nd string\n3 to find a substring\n4 to compare two strings\n");
    printf("Your choice:: ");
    int ch;
    scanf("%d",&ch);

    char str1[20],str2[20];
    struct node* head1 =NULL, *head2=NULL;

    switch(ch){
        case 1: printf("Enter a string:: ");
                scanf("%s",str1);
                head1 = strcnvcl(head1, str1);
                display(head1);
                break;

       case 2:  printf("Enter two strings:: ");
                scanf("%s",str1);
                scanf("%s",str2);
                head1 = strcnvcl(head1, str1);
                display(head1);
                head2 = strcnvcl(head2, str2);
                display(head2);
                printf("The first position in the 1st string that is not contained in the 2nd string is:: %d\n",strvrfyl(head1,head2));
                break;

        case 3: printf("Enter a string:: ");
                scanf("%s",str1);
                head1 = strcnvcl(head1, str1);
                display(head1);
                printf("Enter two positions:: ");
                int i1, i2;
                scanf("%d %d",&i1,&i2);

                char * str = strsbstr(head1,i1,i2);

                printf("%s\n",str);
                break;

        case 4: printf("Enter two strings:: ");
                scanf("%s",str1);
                scanf("%s",str2);
                head1 = strcnvcl(head1, str1);
                display(head1);
                head2 = strcnvcl(head2, str2);
                display(head2);
                int comp = strcmpl(head1,head2);

                printf("Comparing strings....\n%d\n",comp);
                break;

        default: printf("Enter a valid option!!\n\n");
                 break;
    }
  }
}
