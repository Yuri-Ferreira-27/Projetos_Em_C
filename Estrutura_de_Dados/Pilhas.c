#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    no_Stack *pilha = NULL, *remover;
    FILE *arq_list;
    int cod, tamanho, valor, cheia;
    do{
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n4 - Imprimir topo\n5 - Ver o tamanho da pilha\n"
               "6 - Verificar se a pilha está cheia\n7 - Escrever em arquivo texto\n8 - Ler arquivo Texto\n");
        printf("\nCom as opcoes apresentadas, o que voce deseja fazer?: ");
        scanf("%d",&cod);
		getchar();
        switch(cod){
            case 0:
                printf("\nFim do programa");
                break;
            case 1:
                printf("Informe um valor para armazenar na pilha: ");
                scanf("%d",&valor);
                pilha = empilhar(&pilha, valor);
                break;
            case 2:
                remover = desempilhar(&pilha);
                if(remover != NULL){
                    printf("\nElemento removido.");
                }else{
                    printf("\nSem no para remover");
                }
                break;
            case 3:
                imprimir_Pilha(pilha);
                break;
            case 4:
                imprimir_topo(&pilha);
                break;
            case 5:
               tamanho = tam_Pilha(&pilha);
               printf("\nTamanho da pilha: %d",tamanho);
               break;
            case 6:
                cheia = pilha_cheia(&pilha);
                if(cheia == NULL){
                    printf("A pilha está cheia");
                }
                else{
                    printf("Ainda possui espaço na memória");
                }
                break;
            case 7:
                arq_list = fopen("lista.txt","w");
                if (arq_list  == NULL) {
                    printf("Não foi possivel abrir o arquivo!");
                    fclose(arq_list);
                }else {
                    escrever_arq_Pilha(&pilha, arq_list);
                    fclose(arq_list);
                }
                    break;
            case 8:
                    arq_list = fopen("lista.txt","r");
                if (arq_list == NULL) {
                    printf("Não foi possivel abrir o arquivo!");
                    fclose(arq_list);
                }else {
                    ler_arq_Pilha(&pilha, arq_list);
                    fclose(arq_list);
                }
            default:
                printf("Comando invalido, digite novamente!\n");
        }
    } while(cod != 0);

    return 0;
}
