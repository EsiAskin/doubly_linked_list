#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node * next;
    struct node * prev;
};
struct node * temp;
struct node * temp2;
struct node * start;

struct node * insert_beg(struct node * start){
    int x;
    printf("Kac eklemek istiyorsun ?");
    scanf("%d", &x);
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> val = x;
    if(start==NULL){
        start = newnode;
        start->prev=NULL;
        start->next=NULL;
    }
    else{
        start->prev=newnode;
        newnode->next=start;
        newnode->prev=NULL;
        start=newnode;
    }
    return start;
}

struct node * insert_end(struct node * start){
    int x;
    printf("Kac eklemek istiyorsun ?");
    scanf("%d", &x);
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> val = x;
    if(start==NULL){
        start = newnode;
        start->prev=NULL;
        start->next=NULL;
    }
    else{
        temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=NULL;
    }

    return start;
}

struct node * insert_node(struct node * start){
    int x, y;
    printf("Kac eklemek istiyorsun ?");
    scanf("%d", &x);
    printf("Hangi sayidan sonraya eklensin");
    scanf("%d", &y);
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> val = x;
    if(start==NULL){
        start = insert_beg(start);
    }
    else{
        temp = start;
        while(temp->val!=y){
            temp=temp->next;
        }
        temp2=temp->next;
        if(temp2==NULL){
            start=insert_end(start);
        }
        else{
            temp2->prev=newnode;
            newnode->next=temp2;
            newnode->prev=temp;
            temp->next=newnode;
        }
        return start;
      
        
    }
}

struct node * del_beg(struct node * start){
    if(start==NULL) printf("Bastan silinecek eleman yok");
    else if(start->next==NULL){
        free(start);
        start=NULL;
    }
    else{
        temp = start;
        start=start->next;
        free(temp);
        start->prev=NULL;
    }
    return start;
}

struct node * del_end(struct node * start){
    if(start==NULL) printf("Sondan silinecek eleman yok.");
    else if(start->next==NULL){
        free(start);
        start=NULL;
    }
    else{
        temp=start;
        while(temp->next!=NULL){
            temp2=temp;
            temp=temp->next;
        }
        free(temp);
        temp2->next=NULL;
    }
    return start;
}

struct node * del_node(struct node * start){
    int num;
    printf("Listedeki hangi sayiyi silmek istiyorsunuz ?");
    scanf("%d", &num);
    if(start==NULL) printf("Silemem");
    else if(start->val==num){
        start=del_beg(start);
    }
    else{
        
            temp=start;
            while(temp->val!=num&&temp->next!=NULL){
                temp= temp->next;
            }
            if(temp->next!=NULL){
                struct node * onceki = temp->prev;
                struct node * sonraki = temp->next;
                free(temp);
                onceki->next=sonraki;
                sonraki->prev=onceki;
            }
            else if(temp->next==NULL&&temp->val==num){
                start=del_end(start);
            }
            else{
                printf("İstedigin sayi listede yok !!!!");
            }

    }
    return start;
}

void display(struct node * start){
    if(start==NULL) printf("Liste bos");
    else{
        temp=start;
        while(temp->next!=NULL){
        printf("%d", temp->val);
        temp=temp->next;
        }
        printf("%d", temp->val);
    }
}





int main(){
    
    start=insert_beg(start);
    start=insert_beg(start);
    start=insert_beg(start);
    display(start);
    start =del_node(start);
    display(start);
    
    
    
    
    
    
}
