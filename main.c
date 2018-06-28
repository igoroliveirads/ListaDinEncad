#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"
#include <locale.h>

int main(void){
	//Declarações
	Lista* li = cria_lista(); //ponteiro para ponteiro para struct elemento
	struct aluno al,a[5] = {{2,"Igor",9.5,7.8,8.5},
                         {4,"Thiago",7.5,8.7,6.8},
                         {1,"Mateus",9.7,6.7,8.4},
                         {3,"Fred",5.7,6.1,7.4},{5,"Ab",10,9,10}};//Matriz de dados pra teste 
	int tamanho, vazia, Op;//Variaveis
	int iinicio, ifinal, iordenada;
	int rinicio, rfinal, rqualquer;
	int cposicao, cmatricula;
	int matricula_aluno, posicao;
    	int i = 0;
	int aux = 5;

	
	printf("LISTA ENCADEADA SIMPLES\n");
	
	//Cria lista
	li = cria_lista();
	
	
	while(Op != 9){//Menu
		printf("Escolha uma opção\n");
		printf("1- Inserir um dado no incio  5- Inserir um dado de acordo com num matricula\n");
		printf("2- Inserir um dado no fim    6- Remover dado a partir da matricula\n");
		printf("3- Remover dado do inicio    7- Consultar dado pela posição\n");
		printf("4- Remover dado do fim       8- Consultar dado pela matricula\n");
		printf("9- Sair\n");
		scanf("%d",&Op);	
	
		switch(Op)//switch pra trabalhar como o menu
		{
		case 1:	//Insere dado no inicio da lista
			if (i < aux){//verifica se ainda a dados a ser colocados 	
				iinicio = insere_lista_inicio(li, a[i++]);//Chama a função depois acrescenta o parametro
				imprime_lista(li);
			}
			else{printf("Acabou as palavras\n\n");}
			break;
		case 2://Insere dado no final da lista
			if (i<aux){//verifica se ainda a dados a ser colocados 
				ifinal = insere_lista_final(li, a[i++]);//Chama a função depois acrescenta o parametro
				imprime_lista(li);
			}
            		else{printf("acabou as palavras\n\n");}
			
			break;
		case 3://Remove dado do inicio da lista
			rinicio = remove_lista_inicio(li);
			imprime_lista(li);	
			break;
		case 4://Remove dado do final da lista
			rfinal = remove_lista_final(li);
			imprime_lista(li);
			break;
		case 5://Insere dado ordenado na lista
			if (i<aux){//verifica se ainda a dados a ser colocados 
				iordenada = insere_lista_ordenada(li, a[i++]);//Chama a função depois acrescenta o parametro
				imprime_lista(li);	
			}
            		else{printf("acabou as palavras\n\n");}
			
			break;
		case 6://Remove qualquer dado da lista a partir da matricula
			printf("Digite a matricula desejada\n");
			scanf("%d", &matricula_aluno);
			rqualquer = remove_lista(li, matricula_aluno);
			break;
		case 7://Consulta dado a partir da posiÃ§Ã£o
			printf("Digite a posição desejada\n");
			scanf("%d", &posicao);
			cposicao = consulta_lista_pos(li, posicao, &al);
			if (cposicao == 1){
				printf("\n\n");
				printf("Matricula");
				printf(": %d", al.matricula);
				printf("\nNome");
				printf(": %s", al.nome);
				printf("\nNotas");
				printf(" 1-%f 2-%f 3-%f\n", al.n1, al.n2, al.n3);
			}
			else if(cposicao == 0){
				printf("Essa posição não existe\n");
			}
			break;
		case 8: //Consulta dado a partir da matricula
			printf("Digite a matricula desejada\n");
			scanf("%d", &matricula_aluno);
			cmatricula = consulta_lista_mat(li, matricula_aluno, &al);
			if (cmatricula == 1){
				printf("\n\n");
				printf("Matricula");
				printf(": %d", al.matricula);
				printf("\nNome");
				printf(": %s", al.nome);
				printf("\nNotas");
				printf("1-%f 2-%f 3-%f\n", al.n1, al.n2, al.n3);
			}
			else if(cmatricula == 0){
				printf("Essa matricula não está cadastrada\n");
			}
			break;
		case 9:
			break;
		}
		//Calcula o tamanho da lista
		tamanho = tamanho_lista(li);
		printf("\n\nTamanho da lista: %d\n", tamanho);
	
		//Verifica se a lista estÃ¡ vazia
		vazia = lista_vazia(li);
		if(vazia == 1){
			printf("---------------------\nLista estão vazia\n");
		}else{
			printf("Não estão vazia\n");
		}
		printf("\n\n");
	}
	

	//Libera memoria 
	libera_lista(li);

	return 0;
}
