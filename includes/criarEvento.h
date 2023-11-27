int criarElemento(Evento *raiz, int dia, int mes, char descricao[100])
{
    no *novo = (no*) malloc(sizeof(no));
    if (novo == NULL )
    {
        printf("O valor é nulo");
        return 0;
    }
    else
    {
       novo->esq = NULL;
       novo->dir = NULL;
       novo->dia = dia;
       novo->mes = mes;
       strcat(descricao, "\n");
       strcpy(novo->desc, descricao);

        if(*raiz == NULL)
        {
            *raiz = novo;
            return 1;
        }
        else
        {
            no *atual  = *raiz;
            no *ant = NULL;

            while(atual != NULL)
            {
                ant = atual;
                if(atual->dia == novo->dia && atual->mes == novo->mes)
                {
                    printf("já existe um evento nesta data!");
                    free(novo);
                    return 0;
                }
                if(novo->mes > atual->mes || (novo->mes == atual->mes && novo->dia > atual->dia))
                {
                    atual = atual->dir;
                }else
                {
                    atual = atual->dir;
                }
            }
           if (novo->mes > ant->mes || (novo->mes == ant->mes && novo->dia > ant->dia))
            {
                ant->dir = novo;
            }
            else
            {
                ant->esq = novo;
            }

        }

    }
};
