#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* head = NULL;

Node* makeNode(int v){
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=v; p->next =NULL;
    return p;
}

Node* find(Node* head, int v){
    for(Node*p=head;p!=NULL;p=p->next)
        if(p->data == v) return p;
    return NULL;
}

Node* addFirst(Node* head, int v){
    Node* p = makeNode(v);
    p->next = head;
    return p;
}

Node* addLast(Node* head, int v){
    if(head == NULL) return makeNode(v);
    head->next = addLast(head->next, v);
    return head;
}

Node* addBefore(Node* head, int u, int v){
    if(head == NULL) return NULL;
    if(head->data == v){
        Node* q = makeNode(u);
        q->next = head; 
	  return q;
    }
    head->next=addBefore(head->next,u,v);
    return head;
}

Node* addAfter(Node* head, int u, int v){
    if(head == NULL) return NULL;
    if(head->data == v){
        Node* q = makeNode(u);
        q->next = head->next;
        head->next = q; 
	  return head;
    }
    head->next=addAfter(head->next,u,v);
    return head;
}

Node* remove(Node* head, int v){
    if(head == NULL) return NULL;
    if(head->data == v){
        Node* tmp = head; 
        head = head->next; 
        free(tmp); return head;
    }
    head->next = remove(head->next, v);
    return head;
}

Node* reverse(Node *head){
    Node* p = head;
    Node* prevp = NULL;
    Node* nextp = NULL;
    while(p != NULL){
        nextp = p->next;
        p->next = prevp;
        prevp = p;
        p = nextp;
    }
    return prevp;
}

int main(){
    int n,u,v;
    scanf("%d",&n);
    for (int i=0;i<n;i++) {scanf("%d",&v); head=addLast(head,v);}
    while(1){
        char s[100];
        scanf("%s",s);
        if(strcmp(s,"#") == 0) break;
        if(strcmp(s,"addlast") == 0){
            scanf("%d",&v);
            if(find(head,v) == NULL)    head = addLast(head,v);
        }
        if(strcmp(s,"addfirst") == 0){
            scanf("%d",&v);
            if(find(head,v) == NULL)    head = addFirst(head,v);
        }
        if(strcmp(s,"addafter") == 0){
            scanf("%d %d",&u,&v);
            if(find(head,u) == NULL)    head = addAfter(head,u,v);
        }
        if(strcmp(s,"addbefore") == 0){
            scanf("%d %d",&u,&v);
            if(find(head,u) == NULL)    head = addBefore(head,u,v);
        }
        if(strcmp(s,"remove") == 0){
            scanf("%d",&v);             head = remove(head,v);
        }
        if(strcmp(s,"reverse") == 0){   head = reverse(head);
        }
        for(Node* p = head; p != NULL; p = p->next)
        printf("%d ",p->data);
    }
    for(Node* p = head; p != NULL; p = p->next)
        printf("%d ",p->data);
}
