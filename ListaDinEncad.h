struct aluno{ //define os tipos de dados armazenados na lista
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Lista; //cria o ponteiro "Lista", sendo o "struct elemento" definido no "ListaDinEncad.c"

Lista* cria_lista(); //função que cria a lista
void libera_lista(Lista* li); //função que libera a lista
int insere_lista_final(Lista* li, struct aluno al); //função que insere elemento no final da lista
int insere_lista_inicio(Lista* li, struct aluno al); //função que insere elemento no inicio da lista
int insere_lista_ordenada(Lista* li, struct aluno al); //função que insere elemento de forma ordenada
int remove_lista(Lista* li, int mat); //função que remove elemento da lista pela matricula
int remove_lista_inicio(Lista* li); //função que remove elemento do início da lista
int remove_lista_final(Lista* li); //função que remove elemento do final da lista
int tamanho_lista(Lista* li); //função que verifica o tamanho da lista
int lista_vazia(Lista* li); //função que verifica se a lista está vazia
int lista_cheia(Lista* li); //função que verifica se a lista está cheia
void imprime_lista(Lista* li); //função que exibe a lista
int consulta_lista_mat(Lista* li, int mat, struct aluno *al); //função que verifica elemento pela matricula
int consulta_lista_pos(Lista* li, int pos, struct aluno *al); //função que verifica elemento pela posição
