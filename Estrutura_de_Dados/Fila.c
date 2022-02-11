#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    no_row *fila = NULL, *remover;
    FILE *arq_list;
    int cod, tamanho, valor, cheia;
    do{
        printf("\n0 - Sair\n1 - Enfileirar\n2 - Desenfileirar\n3 - Imprimir\n4 - Imprimir Final\n5 - Ver o tamanho da fila\n6 - Verificar se a fila está cheia\n"
               "7 - Escrever em arquivo texto\n8 - Ler arquivo Texto\n");
        printf("\nCom as opcoes apresentadas, o que voce deseja fazer?: ");
        scanf("%d",&cod);
        getchar();
        switch(cod){
            case 0:
                printf("\nFim do programa");
                break;
            case 1:
                printf("Informe um valor para armazenar na fila: ");
                scanf("%d",&valor);
                enfileirar(&fila, valor);
                break;
            case 2:
                remover = desenfileirar(&fila);
                if(remover != NULL){
                    printf("\nElemento removido.");
                }else{
                    printf("\nSem no para remover");
                }
                break;
            case 3:
                imprimir_Fila(fila);
                break;
            case 4:
                imprimir_fim(&fila);
                break;
            case 5:
                tamanho = tam_Fila(&fila);
                printf("\nTamanho da fila: %d",tamanho);
                break;
            case 6:
                cheia = fila_cheia(&fila);
                if(cheia == NULL){
                    printf("A fila está cheia");
                }
                else{
                    printf("Ainda possui espaço na memória");
                }
                break;
            case 7:
                arq_list = fopen("lista.txt","a");
                if (arq_list  == NULL) {
                    printf("Não foi possivel abrir o arquivo!");
                    fclose(arq_list);
                }else {
                    escrever_arq_Fila(&fila, arq_list);
                    fclose(arq_list);
                }
                    break;
            case 8:
                arq_list = fopen("lista.txt","r");
                if (arq_list == NULL) {
                    printf("Não foi possivel abrir o arquivo!");
                    fclose(arq_list);
                }else {
                    ler_arq_Fila(&fila, arq_list);
                    fclose(arq_list);
                }
                break;
            default:
                printf("Comando invalido, digite novamente!\n");
        }
    } while(cod != 0);
    return 0;
}

