  NODE *p = p_head; // headnode부터 시작
    while(p != NULL){
        printf("%d\n",p->num);
        p = p->p_next;
    }