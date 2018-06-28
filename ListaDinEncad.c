#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h" //inclui os prot�tipos

struct elemento{ //define o tipo de lista
    struct aluno dados; //define o tipo de dado do elemento
    struct elemento *prox; //cria um ponteiro para o pr�ximo elemento
};
typedef struct elemento Elem; //cria um tipo elem para facilitar em algumas opera��es

Lista* cria_lista(){ //fun��o que cria a lista
    Lista* li = (Lista*) malloc(sizeof(Lista)); //reserva mem�ria para o primeiro n� da lista
    if(li != NULL) //verifica se a lista n�o � nula
        *li = NULL; //preenche o primeiro conte�do com NULL
    return li; //retorna a lista vazia
}

void libera_lista(Lista* li){ //fun��o que libera a lista
    if(li != NULL) //verifica se a lista n�o � nula
        Elem* no; //define ponteiro Elem
        while((*li) != NULL){ //enquanto n�o tiver numa lista vazia
            no = *li; //n� recebe o in�cio da lista
            *li = (*li)->prox; //in�cio da lista aponta para o pr�ximo elemento da lista
            free(no); //libera o antigo in�cio
        }
        free(li); //libera a cabe�a da lista "n� especial"
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){ //fun��o que verifica elemento pela posi��o
    if(li == NULL || pos <= 0) //verifica se a lista � v�lida e a posi��o � positiva
        return 0;
    Elem *no = *li; //declara elemento auxiliar "no" que � equivalente ao primeiro n� da lista
    int i = 1; //declara um contador, iniciado em "1"
    while(no != NULL && i < pos){ //percorre at� encontrar a posi��o desejada ou quando chegar no final da lista
        no = no->prox; //pula pro pr�ximo elemento
        i++; //adiciona "+1" no contador
    }
    if(no == NULL) //n�o encontrou a posi��o desejada ou a lista est� vazia
        return 0;
    else{
        *al = no->dados; //conte�do de al recebe o campo dados do n�
        return 1;
    }
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){ //fun��o que verifica elemento pela matricula
    if(li == NULL) //verifica se a lista � v�lida
        return 0;
    Elem *no = *li; //declara elemento auxiliar "no" que � equivalente ao primeiro n� da lista
    while(no != NULL && no->dados.matricula != mat){ //percorre at� encontrar a matricula desejada ou quando chegar no final da lista
        no = no->prox; //pula pro pr�ximo elemento
    }
    if(no == NULL) //n�o encontrou a matricula desejada ou a lista est� vazia
        return 0;
    else{
        *al = no->dados; //conte�do de al recebe o campo dados do n�
        return 1;
    }
}

int insere_lista_final(Lista* li, struct aluno al){  //fun��o que insere elemento no final da lista
    if(li == NULL) //verifica se a lista � v�lida
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem)); //reserva mem�ria para o novo n� da lista
    if(no == NULL) //verifica se o novo n� � v�lido
        return 0;
    no->dados = al; //copia os dados que foram passados por par�metro para dentro do novo n�
    no->prox = NULL; //define que o pr�ximo n� do novo n� � nulo
    if((*li) == NULL){ //verifica se a lista est� vazia
        *li = no; //define que o in�cio da lista � o novo n�
    }else{
        Elem *aux = *li; //cria ponteiro auxiliar que equivale ao in�cio da lista
        while(aux->prox != NULL){ //percorre a lista at� encontrar o �ltimo elemento da lista
            aux = aux->prox; //auxiliar recebe o n� seguinte a ele
        }
        aux->prox = no; //insere o novo n� no final
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){ //fun��o que insere elemento no in�cio da lista
    if(li == NULL) //verifica se a lista � v�lida
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem)); //reserva mem�ria para o novo n� da lista
    if(no == NULL) //verifica se o novo n� � v�lido
        return 0;
    no->dados = al; //copia os dados que foram passados por par�metro para dentro do novo n�
    no->prox = (*li); //define que o pr�ximo n� do novo n� � a pr�pria lista
    *li = no; //altera o in�cio da lista para o novo n�
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){ //fun��o que insere elemento de forma ordenada
    if(li == NULL) //verifica se a lista � v�lida
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem)); //reserva mem�ria para o novo n� da lista
    if(no == NULL) //verifica se a novo n� � v�lido
        return 0;
    no->dados = al; //copia os dados que foram passados por par�metro para dentro do novo n�
    if((*li) == NULL){ //verifica se a lista est� vazia
        no->prox = NULL; //define que o pr�ximo n� do novo n� � nulo
        *li = no; //altera o in�cio da lista para o novo n�
        return 1;
    }
    else{
        Elem *ant, *atual = *li; //declara elementos auxiliares anterior e atual, sendo o atual equivalente ao primeiro n� da lista
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual; //anterior passa para o atual
            atual = atual->prox; //atual recebe o n� seguinte a ele
        }
        if(atual == *li){ //verifica se o atual est� no in�cio da lista
            no->prox = (*li); //define que o pr�ximo n� do novo n� � a pr�pria lista
            *li = no; //altera o in�cio da lista para o novo n�
        }else{
            no->prox = atual; //define que o pr�ximo n� do novo n� � o n� atual
            ant->prox = no; //define que o pr�ximo n� do n� anterior � o novo n�
        }
        return 1;
    }
}

int remove_lista(Lista* li, int mat){  //fun��o que remove elemento da lista pela matricula
    if(li == NULL) //verifica se a lista � v�lida
        return 0;
    if((*li) == NULL) //verifica se a lista est� vazia
        return 0;
    Elem *ant, *no = *li; //declara elementos auxiliares anterior e n�, sendo n� equivalente ao primeiro n� da lista 
    while(no != NULL && no->dados.matricula != mat){
        ant = no; //anterior passa para o n�
        no = no->prox; //n� recebe o n� seguinte a ele
    }
    if(no == NULL) //verifica se o n� � v�lido e se a matr�cula existe
        return 0;

    if(no == *li) //verifica se o n� est� no in�cio da lista
        *li = no->prox; //in�cio da lista aponta para o elemento seguinte ao n�
    else
        ant->prox = no->prox; //anterior aponta para onde aponta o n� 
    free(no); //libera a mem�ria do n�
    return 1;
}

int remove_lista_inicio(Lista* li){ //fun��o que remove elemento do in�cio da lista
    if(li == NULL) //verifica se a lista � v�lida
        return 0;
    if((*li) == NULL) //verifica se a lista est� vazia
        return 0;
		
    Elem *no = *li; //declara elemento auxiliar "no" que � equivalente ao primeiro n� da lista
    *li = no->prox; //in�cio da lista aponta para o elemento seguinte ao n�
    free(no); //libera a mem�ria do n�
    return 1;
}

int remove_lista_final(Lista* li){ //fun��o que remove elemento do final da lista
    if(li == NULL) //verifica se a lista � v�lida
        return 0;
    if((*li) == NULL) //verifica se a lista est� vazia
        return 0;

    Elem *ant, *no = *li; //declara elementos auxiliares anterior e n�, sendo n� equivalente ao primeiro n� da lista 
    while(no->prox != NULL){ //percorre a lista at� encontrar o �ltimo elemento da lista
        ant = no; //anterior passa para o n�
        no = no->prox; //n� recebe o n� seguinte a ele
    }

    if(no == (*li)) //verifica se o n� est� no in�cio da lista
        *li = no->prox; //in�cio da lista aponta para o elemento seguinte ao n�
    else
        ant->prox = no->prox; //anterior aponta para onde aponta o n�
    free(no); //libera a mem�ria do n�
    return 1;
}

int tamanho_lista(Lista* li){ //fun��o que verifica o tamanho da lista
    if(li == NULL) //verifica se a lista � v�lida
        return 0;
    int cont = 0; //cria um contador
    Elem* no = *li; //cria "n�" auxiliar que receber� o primeiro elemento da lista
    while(no != NULL){ //percorre a lista elemento por elemento
        cont++; //conta mais "1" no contador
        no = no->prox; //pula pro pr�ximo elemento
    }
    return cont; //retorna o tamanho da lista
}

int lista_cheia(Lista* li){ //fun��o que verifica se a lista est� cheia
    return 0;
}

int lista_vazia(Lista* li){ //fun��o que verifica se a lista est� vazia
    if(li == NULL) //verifica se a lista � v�lida
        return 1;
    if(*li == NULL) //verifica se o in�cio da lista aponta para nulo
        return 1;
    return 0;
}

void imprime_lista(Lista* li){ //fun��o que exibe a lista 
    if(li == NULL) //verifica se a lista � v�lida
        return 0;
    Elem* no = *li; //declara elemento auxiliar "no" que � equivalente ao primeiro n� da lista
    while(no != NULL){ //percorre a lista elemento por elemento
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox; //pula pro pr�ximo elemento
    }
}
