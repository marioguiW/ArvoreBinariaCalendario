lista* criaLista(){
    lista *inicio = (lista*) malloc(sizeof(lista));
    if (inicio != NULL){
        *inicio = NULL;
    }else{
        printf("Erro na alocaçãooo");
    }
    return inicio;
}

int InsereNoFinal(lista* inicio, Evento nodeArv) {
    node* novo = (node*)malloc(sizeof(node));
    if (novo == NULL) {
        printf("Erro na alocação\n");
        return 0;
    } else {
        if ((*inicio) == NULL) {
            novo->prox = NULL;
            *inicio = novo;
        } else {
            node* temp;
            temp = (*inicio);
            while (temp->prox != NULL) {
                temp = temp->prox;
            }
            temp->prox = novo;
            novo->prox = NULL;
        }
        novo->evento = nodeArv;
        return 1;
    }
}

void exibelista(lista*inicio){

    if(*inicio == NULL){
        printf("Lista vazia");
    }else{
        node *temp;
        temp = (*inicio);

        while (temp != NULL){
            printf("%s\n", temp->evento->desc);
            temp = temp->prox;
        }
    }
}

int construirLista(Evento nodeArv, lista* list) {
    if (nodeArv == NULL) {
        return 1;
    }
    printf("aqui passou");
    construirLista(nodeArv->esq, list);
    printf("aqui passou2");
    InsereNoFinal(list, nodeArv);
    printf("aqui passou3");
    construirLista(nodeArv->dir, list);
    printf("passou aqui tambem PORRA");
}


no *criarNo(int mes, int dia, const char *desc) {

    // cria novo no

    no *novoNo = (no *)malloc(sizeof(no));

    // coloca o mes e dia correspondente

    novoNo->mes = mes;
    novoNo->dia = dia;

    // copia descricao

    strcpy(novoNo->desc, desc);

    //aponta para nullo o novo elemento

    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

no *listaParaArvore(lista *head, int tamanho) {
    if (tamanho <= 0) {
        return NULL;
    }

    // Encontrar o meio da lista
    int meio = tamanho / 2;

    // Avançar até o meio da lista
    lista *atual = head;
    int i;
    for (i = 0; i < meio; i++) {
        atual = &((*atual)->prox);
    }

    // Criar o nó correspondente ao meio
    no *raiz = criarNo((*atual)->evento->mes, (*atual)->evento->dia, (*atual)->evento->desc);

    // Recursivamente construir as subárvores
    raiz->esq = listaParaArvore(head, meio);
    raiz->dir = listaParaArvore(&((*atual)->prox), tamanho - meio - 1);

    return raiz;
}

void contador(no *no_print, int*cont){
    if(no_print == NULL){
        return;
    }else{
        contador(no_print->esq, cont);
        contador(no_print->dir, cont);
        *cont += 1;
    }
}

int contar_nos(Evento * raiz){
    if(raiz == NULL){
        return 0;
    }else{
        int cont = 0;
        contador(*raiz, &cont);
        return cont;
    }
}
