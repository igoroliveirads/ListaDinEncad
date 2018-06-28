#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"
int main(){
    struct aluno al, a[4] = {{2,"Igor",9.5,7.8,8.5},
                         {4,"Thiago",7.5,8.7,6.8},
                         {1,"Mateus",9.7,6.7,8.4},
                         {3,"Fred",5.7,6.1,7.4}};
    Lista* li = cria_lista(); //ponteiro para ponteiro para struct elemento
    printf("Tamanho: %d\n\n\n\n",tamanho_lista(li));

    int i;
    for(i=0; i < 4; i++)
        insere_lista_ordenada(li,a[i]);

    imprime_lista(li);
    printf("\n\n\n\n Tamanho: %d\n",tamanho_lista(li));

    for(i=0; i < 4; i++){
        remove_lista_final(li);
        imprime_lista(li);
        printf("\n Tamanho: %d\n\n\n",tamanho_lista(li));
    }

    for(i=0; i < 4; i++)
        insere_lista_ordenada(li,a[i]);
    imprime_lista(li);

    libera_lista(li);
    system("pause");
    return 0;
}

