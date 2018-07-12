#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h" //inclui os protótipos

struct elemento{ //define o tipo de lista
    struct aluno dados; //define o tipo de dado do elemento
    struct elemento *prox; //cria um ponteiro para o próximo elemento
};
typedef struct elemento Elem; //cria um tipo elem para facilitar em algumas operações

Lista* cria_lista(){ //função que cria a lista
    Lista* li = (Lista*) malloc(sizeof(Lista)); //reserva memória para o primeiro nó da lista
    if(li != NULL) //verifica se a lista não é nula
        *li = NULL; //preenche o primeiro conteúdo com NULL
    return li; //retorna a lista vazia
}

void libera_lista(Lista* li){ //função que libera a lista
    if(li != NULL){ //verifica se a lista não é nula
        Elem* no; //define ponteiro Elem
        while((*li) != NULL){ //enquanto não tiver numa lista vazia
            no = *li; //nó recebe o início da lista
            *li = (*li)->prox; //início da lista aponta para o próximo elemento da lista
            free(no); //libera o antigo início
        }
        free(li); //libera a cabeça da lista "nó especial"
    }
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){ //função que verifica elemento pela posição
    if(li == NULL || pos <= 0) //verifica se a lista é válida e a posição é positiva
        return 0;
    Elem *no = *li; //declara elemento auxiliar "no" que é equivalente ao primeiro nó da lista
    int i = 1; //declara um contador, iniciado em "1"
    while(no != NULL && i < pos){ //percorre até encontrar a posição desejada ou quando chegar no final da lista
        no = no->prox; //pula pro próximo elemento
        i++; //adiciona "+1" no contador
    }
    if(no == NULL) //não encontrou a posição desejada ou a lista está vazia
        return 0;
    else{
        *al = no->dados; //conteúdo de al recebe o campo dados do nó
        return 1;
    }
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){ //função que verifica elemento pela matricula
    if(li == NULL) //verifica se a lista é válida
        return 0;
    Elem *no = *li; //declara elemento auxiliar "no" que é equivalente ao primeiro nó da lista
    while(no != NULL && no->dados.matricula != mat){ //percorre até encontrar a matricula desejada ou quando chegar no final da lista
        no = no->prox; //pula pro próximo elemento
    }
    if(no == NULL) //não encontrou a matricula desejada ou a lista está vazia
        return 0;
    else{
        *al = no->dados; //conteúdo de al recebe o campo dados do nó
        return 1;
    }
}

int insere_lista_final(Lista* li, struct aluno al){  //função que insere elemento no final da lista
    if(li == NULL) //verifica se a lista é válida
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem)); //reserva memória para o novo nó da lista
    if(no == NULL) //verifica se o novo nó é válido
        return 0;
    no->dados = al; //copia os dados que foram passados por parâmetro para dentro do novo nó
    no->prox = NULL; //define que o próximo nó do novo nó é nulo
    if((*li) == NULL){ //verifica se a lista está vazia
        *li = no; //define que o início da lista é o novo nó
    }else{
        Elem *aux = *li; //cria ponteiro auxiliar que equivale ao início da lista
        while(aux->prox != NULL){ //percorre a lista até encontrar o último elemento da lista
            aux = aux->prox; //auxiliar recebe o nó seguinte a ele
        }
        aux->prox = no; //insere o novo nó no final
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){ //função que insere elemento no início da lista
    if(li == NULL) //verifica se a lista é válida
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem)); //reserva memória para o novo nó da lista
    if(no == NULL) //verifica se o novo nó é válido
        return 0;
    no->dados = al; //copia os dados que foram passados por parâmetro para dentro do novo nó
    no->prox = (*li); //define que o próximo nó do novo nó é a própria lista
    *li = no; //altera o início da lista para o novo nó
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){ //função que insere elemento de forma ordenada
    if(li == NULL) //verifica se a lista é válida
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem)); //reserva memória para o novo nó da lista
    if(no == NULL) //verifica se a novo nó é válido
        return 0;
    no->dados = al; //copia os dados que foram passados por parâmetro para dentro do novo nó
    if((*li) == NULL){ //verifica se a lista está vazia
        no->prox = NULL; //define que o próximo nó do novo nó é nulo
        *li = no; //altera o início da lista para o novo nó
        return 1;
    }
    else{
        Elem *ant, *atual = *li; //declara elementos auxiliares anterior e atual, sendo o atual equivalente ao primeiro nó da lista
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual; //anterior passa para o atual
            atual = atual->prox; //atual recebe o nó seguinte a ele
        }
        if(atual == *li){ //verifica se o atual está no início da lista
            no->prox = (*li); //define que o próximo nó do novo nó é a própria lista
            *li = no; //altera o início da lista para o novo nó
        }else{
            no->prox = atual; //define que o próximo nó do novo nó é o nó atual
            ant->prox = no; //define que o próximo nó do nó anterior é o novo nó
        }
        return 1;
    }
}

int remove_lista(Lista* li, int mat){  //função que remove elemento da lista pela matricula
    if(li == NULL) //verifica se a lista é válida
        return 0;
    if((*li) == NULL) //verifica se a lista está vazia
        return 0;
    Elem *ant, *no = *li; //declara elementos auxiliares anterior e nó, sendo nó equivalente ao primeiro nó da lista 
    while(no != NULL && no->dados.matricula != mat){
        ant = no; //anterior passa para o nó
        no = no->prox; //nó recebe o nó seguinte a ele
    }
    if(no == NULL) //verifica se o nó é válido e se a matrícula existe
        return 0;

    if(no == *li) //verifica se o nó está no início da lista
        *li = no->prox; //início da lista aponta para o elemento seguinte ao nó
    else
        ant->prox = no->prox; //anterior aponta para onde aponta o nó 
    free(no); //libera a memória do nó
    return 1;
}

int remove_lista_inicio(Lista* li){ //função que remove elemento do início da lista
    if(li == NULL) //verifica se a lista é válida
        return 0;
    if((*li) == NULL) //verifica se a lista está vazia
        return 0;
		
    Elem *no = *li; //declara elemento auxiliar "no" que é equivalente ao primeiro nó da lista
    *li = no->prox; //início da lista aponta para o elemento seguinte ao nó
    free(no); //libera a memória do nó
    return 1;
}

int remove_lista_final(Lista* li){ //função que remove elemento do final da lista
    if(li == NULL) //verifica se a lista é válida
        return 0;
    if((*li) == NULL) //verifica se a lista está vazia
        return 0;

    Elem *ant, *no = *li; //declara elementos auxiliares anterior e nó, sendo nó equivalente ao primeiro nó da lista 
    while(no->prox != NULL){ //percorre a lista até encontrar o último elemento da lista
        ant = no; //anterior passa para o nó
        no = no->prox; //nó recebe o nó seguinte a ele
    }

    if(no == (*li)) //verifica se o nó está no início da lista
        *li = no->prox; //início da lista aponta para o elemento seguinte ao nó
    else
        ant->prox = no->prox; //anterior aponta para onde aponta o nó
    free(no); //libera a memória do nó
    return 1;
}

int tamanho_lista(Lista* li){ //função que verifica o tamanho da lista
    if(li == NULL) //verifica se a lista é válida
        return 0;
    int cont = 0; //cria um contador
    Elem* no = *li; //cria "nó" auxiliar que receberá o primeiro elemento da lista
    while(no != NULL){ //percorre a lista elemento por elemento
        cont++; //conta mais "1" no contador
        no = no->prox; //pula pro próximo elemento
    }
    return cont; //retorna o tamanho da lista
}

int lista_cheia(Lista* li){ //função que verifica se a lista está cheia
    return 0;
}

int lista_vazia(Lista* li){ //função que verifica se a lista está vazia
    if(li == NULL) //verifica se a lista é válida
        return 1;
    if(*li == NULL) //verifica se o início da lista aponta para nulo
        return 1;
    return 0;
}

void imprime_lista(Lista* li){ //função que exibe a lista 
    if(li == NULL) //verifica se a lista é válida
        return;
    Elem* no = *li; //declara elemento auxiliar "no" que é equivalente ao primeiro nó da lista
    while(no != NULL){ //percorre a lista elemento por elemento
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox; //pula pro próximo elemento
    }
}
