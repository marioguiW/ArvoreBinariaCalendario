void removerFolha(no *no_print, no *anterior){
    if(anterior->mes > no_print->mes || (anterior->mes == no_print->mes && anterior->dia > no_print->dia)){
        anterior->esq = NULL;
        free(no_print);
    }else{
        anterior->dir = NULL;
        free(no_print);
    }
}

void remover_umFilho(no *no_print, no *anterior){
    if(anterior->mes > no_print->mes || (anterior->mes == no_print->mes && anterior->dia > no_print->dia)){
        if(no_print->dir != NULL){
            anterior->esq = no_print->dir;
            free(no_print);
        }else{
            anterior->esq = no_print->esq;
            free(no_print);
        }
    }else{
        if(no_print->dir != NULL){
            anterior->dir = no_print->dir;
            free(no_print);
        }else{
            anterior->dir = no_print->esq;
            free(no_print);
        }   
    }
}

void remover_interno(no *no_print, no *anterior){
    no *atual2; 
    no *anterior2;
    atual2 = no_print->esq;
    anterior2 = no_print->esq;
    printf("passei"); 
    while(atual2->dir != NULL){
        anterior2 = atual2;
        atual2 = atual2->dir;
    }
    printf("passei2");
    anterior2->dir = NULL;
    atual2->dir = no_print->dir;
    if(atual2 == no_print->esq){
        atual2->esq = NULL;
    }else{
        atual2->esq = no_print->esq;
    }
    if(anterior->mes > no_print->mes || (anterior->mes == no_print->mes && anterior->dia > no_print->dia)){
         anterior->esq = atual2;
    }else{
        anterior->dir = atual2;
    }
    free(no_print);
    return;
}

void acha_no(no *no_print, int dia, int mes, no *anterior){
    int confirma = 0;
    if(no_print == NULL){
        return;
    }else{
        acha_no(no_print->esq, dia, mes, no_print);
        acha_no(no_print->dir, dia, mes, no_print);
        if(no_print->dia == dia && no_print->mes == mes){
            printf("Data: %d/%d - Descricao: %s\n", no_print->dia, no_print->mes, no_print->desc);
            printf("Tem certeza que deseja remover esse evento?\n[1]-SIM\n[2]-CANCELAR\n->");
            scanf("%i", &confirma);
            if (confirma == 1){
                if(no_print->esq == NULL && no_print->dir == NULL){
                    removerFolha(no_print, anterior);
                    return;
                }else if((no_print->esq == NULL && no_print->dir != NULL) || (no_print->esq != NULL && no_print->dir == NULL)){
                    remover_umFilho(no_print, anterior);
                    return;
                }else{
                    remover_interno(no_print, anterior);
                    return;
                }
                system("clear");
                printf("Elemento removido!");
            }else{
                printf("Operacao cancelada");
            }
        }
    }
}

void removerFolhaDaRaiz(no **raiz) {
    free(*raiz);
    *raiz = NULL;
}

void removerFilhoRaiz(no **raiz) {
    if ((*raiz)->esq != NULL) {
        no *temp = *raiz;
        *raiz = (*raiz)->esq;
        free(temp);
    } else {
        no *temp = *raiz;
        *raiz = (*raiz)->dir;
        free(temp);
    }
}

void removerNoInternoDaRaiz(no **raiz) {
    no *atual2 = (*raiz)->esq;
    no *anterior2 = (*raiz)->esq;

    while (atual2->dir != NULL) {
        anterior2 = atual2;
        atual2 = atual2->dir;
    }

    anterior2->dir = NULL;
    atual2->dir = (*raiz)->dir;

    if (atual2 == (*raiz)->esq) {
        atual2->esq = NULL;
    } else {
        atual2->esq = (*raiz)->esq;
    }

    free(*raiz);
    *raiz = atual2;
}


int remove_no(Evento *raiz, int dia, int mes){
    
    int confirma;
    if(raiz == NULL){
        return 0;
    }else if((*raiz)->mes == mes && (*raiz)->dia == dia){

        printf("Data: %d/%d - Descricao: %s\n", (*raiz)->dia, (*raiz)->mes, (*raiz)->desc);
        printf("Remover este evento? 1 = sim, 2 = nao\n->");
        scanf("%i", &confirma);

        if (confirma == 1){
            if ((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
                removerFolhaDaRaiz(raiz);
            } else if (((*raiz)->esq == NULL && (*raiz)->dir != NULL) ||
                    ((*raiz)->esq != NULL && (*raiz)->dir == NULL)) {
                removerFilhoRaiz(raiz);
            } else {
                removerNoInternoDaRaiz(raiz);
            }
            return 1;
        }else{
            printf("Operação cancelada");
            return 0;  
        }
    }else{
        acha_no(*raiz, dia, mes, *raiz);
    }

}