void editar_no(no *no_print, int dia, int mes, char desc[100], no *ant){
    int confirma = 0;
    if(no_print == NULL){
        return;
    }else{
        editar_no(no_print->esq, dia, mes, desc, no_print);
        editar_no(no_print->dir, dia, mes, desc, no_print);
        if(no_print->dia == dia && no_print->mes == mes){
            strcat(desc, "\n");
            strcpy(no_print->desc, desc);
        }
    }
}