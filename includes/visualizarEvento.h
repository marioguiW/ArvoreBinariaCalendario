
void listarArvore(Evento raiz) {
    if (raiz != NULL) {
        listarArvore(raiz->esq);
        printf("Data do Evento: %d/%d | Descricao: %s\n", raiz->dia, raiz->mes, raiz->desc);
        listarArvore(raiz->dir);
    }
}
