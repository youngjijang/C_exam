#include <stdio.h>
#include <stdlib.h>

/*노드 구조체*/
typedef struct node
{
    int num;
    struct node *p_next;

}NODE;

/*큐 자료구조에 데이터 추가*/
void append(NODE **p_head, int num){
    
    NODE *p_tail = *p_head;
    while (NULL != p_tail->p_next)  p_tail = p_tail->p_next;
    
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->num = num;
    newNode->p_next = NULL;

    p_tail->p_next = newNode;
}

/* leftpop 큐 자료구조 가장 오랜된 데이터를 반환하고 삭제*/
int leftpop(NODE *p_head){
    // if(p_head == NULL)
    //     return 0;
    
    NODE *tmp = p_head->p_next;
    int result = tmp->num;
    p_head->p_next = tmp->p_next;
    free(tmp);

    return result;
}

int main(){
    NODE *p_head = (NODE*)malloc(sizeof(NODE));
    p_head->p_next = NULL;

    append(&p_head,100);
    append(&p_head,200);
    append(&p_head,300);

    int result = leftpop(p_head);
    printf("%d\n",result);


    // NODE *p = p_head; // headnode부터 시작
    // while (p != NULL){
    //     printf("%d\n",p->num);
    //     p = p->p_next;
    // }

}