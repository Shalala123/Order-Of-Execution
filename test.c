#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
    struct node *next;
};

void push(int,struct node **);
void yazdir(struct node *,int);
int pop(struct node **);
int bosmu(struct node *);
int main(){
    int a=0,sonuc,i,q,y,z;
    int sayi;
    char *s1,*s2,*s3,*s4,*s5=NULL,*s6=NULL;
    char str[60];
    char main[20]="Main";
    char exec[20]="EXECUTE";
    char end[20]="END";
    char call[20]="CALL";
    char fonk[20]="fun1";
    char fun1[20]="1";
    char fun2[20]="2";
    char fun3[20]="3";
struct node *top=NULL;
FILE *ptr;
ptr=fopen("codes.txt","r");


if(ptr==NULL){
    printf("File couldn't be opened\n");
    return 1;
             }
             printf("Execution Order of Lines: \n");
 fgets(str,60,ptr);
    s1=strstr(str,main);

while(s1==NULL){
    fgets(str,60,ptr);
    s1=strstr(str,main);
}
sayi=atoi(str);
printf("%d\n",sayi);
while(a==0 || bosmu(top)!=0){
        fgets(str,60,ptr);
        s1=strstr(str,call);
        s2=strstr(str,exec);
        s3=strstr(str,end);
    if(s1!=NULL){
            a=1;
             sayi=atoi(str);
             push(sayi,&top);
             yazdir(top,sayi);
             rewind(ptr);
             str[0]='q';
             str[1]='q';
             s4=strstr(str,fun1);
             strcpy(fonk,"BEGIN Fun1");
             if(s4==NULL){
                s4=strstr(str,fun2);
                strcpy(fonk,"BEGIN Fun2");
                if(s4==NULL){
                    s4=strstr(str,fun3);
                    strcpy(fonk,"BEGIN Fun3");
                }
             }
             while(s6==NULL){
                fgets(str,60,ptr);
                s6=strstr(str,fonk);
                if(s6!=NULL){
                     sayi=atoi(str);
                    printf("%d\n",sayi);
                }
             }
             s6=NULL;
    }
    if(s2!=NULL){
            sayi=atoi(str);
        printf("%d\n",sayi);

    }
    if(s3!=NULL){
            sayi=atoi(str);
        sonuc=pop(&top);
        yazdir(top,sayi);
        rewind(ptr);
        for(q=0;q<sonuc;q++){
            fgets(str,60,ptr);
        }
    }

}
sayi=atoi(str);
printf("%d\n--END--\n",sayi+1);
system("pause");
return 0;

}


void push(int num,struct node **start){
struct node *newp=NULL;
   newp = (struct node *) malloc(sizeof(struct node));
   if(newp == NULL)
      printf("Cannot allocate memory!\n");
   else {
      newp->data = num;
      newp->next = *start;
      *start = newp;
        }
}

void yazdir(struct node *start,int num){
    printf("%d                STACK = ",num);
while(start != NULL) {
      printf("%d -> ",start->data);
      start = start -> next;
   }
   printf("\n");
   return;
}

int pop(struct node **start) {
   struct node *temp = *start;
   int value = temp->data;
   *start = (*start) -> next;
   temp -> next = NULL;
   free(temp);
   return value;
}
int bosmu(struct node *start){
    int p=1;
    if(start==NULL){
        p=0;
    }
    return p;
}
