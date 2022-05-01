#include <stdio.h>
#include <stdlib.h> //malloc,free

/*노드 구조체*/
typedef struct node
{
    int data;
    struct node *p_next;

}NODE;

/*노드 추가*/
void addNode(NODE *target, int data){ //target뒤에 추가
    if (target == NULL)
        return;
    NODE *newNode = malloc(sizeof(NODE));
    newNode->p_next = target->p_next; //nuwNode가 taget뒤로 들어감 > target의 next주소를 가져오고
    newNode->data = data;

    target->p_next = newNode; //target의 next주소는 newnode의 주소가됨
}
/*노드 삭제*/
void removeNode(NODE *target){ //target다음 노드 삭제하기
    if (target == NULL)
        return;  

    NODE *temp = target->p_next; //taget의 다음 노드 가져오기(주소 저장)
    target->p_next = temp->p_next; 
    free(temp); // 해당 주소 NODE 삭제
}

void main(){
   NODE *p_head = NULL; //처음시작 > headnode는 NULL

   p_head = (NODE*)malloc(sizeof(NODE));
   p_head->p_next = NULL;

   addNode(p_head,100);
   addNode(p_head,200);
   addNode(p_head,300);

   removeNode(p_head);

   /*순회*/
   NODE *p = p_head; // headnode부터 시작
   while(p != NULL){
       printf("%d\n",p->data);
       p = p->p_next;
   }
}