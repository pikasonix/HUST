#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
    char data;
    struct Node* next;
}Node;

Node* head;

Node* makeNode(char v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = v; p->next = NULL;
    return p;
}

void initStack(){
    head = NULL;
}

int stackEmpty(){
    return head == NULL;
}

void push(char x){
    Node* p = makeNode(x);
    p->next = head; head = p;
}

char pop(){
    if(stackEmpty()) return ' ';
    char x = head->data;
    Node* tmp = head; head = head->next; free(tmp);
    return x;
}

int match(char a, char b){
    if(a == '(' && b == ')') return 1;
    if(a == '[' && b == ']') return 1;
    if(a == '{' && b == '}') return 1;
    return 0;
}

int check(char* s){
    initStack();
    for(int i = 0; i < strlen(s); i++){           
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            push(s[i]);
        }else{
            if(stackEmpty()) return 0;
            char x = pop();
            if(!match(x,s[i])) return 0;
        }
    }
    return stackEmpty();
}

int main(){
    char s[1000];
    scanf("%s",s);
    printf("%d",check(s));
}