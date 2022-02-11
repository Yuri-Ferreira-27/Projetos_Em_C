#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main() {
    no *lista = NULL, *busca_pos;
    int cod, tamanho, valor, pos, busca, cheia;
    FILE *arq_list;
    do{
        printf("\n0 - Sair\n1 - Inserir com posicao\n2 - Remover elemento\n3 - Imprimir lista\n4 - Tamanho da lista\n5 - Buscar elemento\n"
               "6 - Buscar elemento por posicao\n7 - Verificar se a lista esta cheia\n8 - Ordenar lista\n9 - Escrever em Arquivo\n10 - Ler Arquivo\n");
        printf("\nCom as opcoes apresentadas, o que voce deseja fazer?: ");
        scanf("%d",&cod);
        getchar();
        switch(cod){
            case 0:
                printf("\nFim do programa");
            break;
            case 1:
                printf("Informe um valor para inserir na lista: ");
                scanf("%d",&valor);
                printf("Informe a posicao: ");
                scanf("%d",&pos);
                inserir_lista(&lista, valor, pos);
                printf("\nElemento inserido com sucesso!");
                break;
            case 2:
                printf("Informe um valor para remover da lista: ");
                scanf("%d",&valor);
                remover_lista(&lista, valor);
                printf("O valor %d foi removido com sucesso",valor);
                break;
            case 3:
                imprimir_Lista(lista);
                printf("\n");
                break;
            case 4:
                tamanho = tam_Lista(&lista);
                printf("\nTamanho da lista: %d",tamanho);
                break;
            case 5:
                printf("Informe o valor que deseja buscar na lista: ");
                scanf("%d",&valor);
                busca = buscar_elemento(&lista, valor);
                if(busca != NULL){
                    printf("\nO valor %d existe na lista.",valor);
                }
                else{
                    printf("Valor nao encontrado");
                }
                break;
            case 6:
                printf("Informe a posicao deseja: ");
                scanf("%d",&pos);
                busca_pos = buscar_elem_pos(&lista, pos);
                printf("O elemento da posicao %d e: %d",pos, busca_pos->valor);
                break;
            case 7:
                cheia = lista_cheia(&lista);
                if(cheia == NULL){
                    printf("A lista está cheia");
                }
                else{
                    printf("Ainda possui espaco na memoria");
                }
                break;
            case 8:
                ordenar_lista(lista);
                imprimir_Lista(lista);
                printf("\n");
                break;
            case 9:
                arq_list = fopen("lista.txt","w");
                if (arq_list  == NULL) {
                    printf("Não foi possivel abrir o arquivo!");
                    fclose(arq_list);
                }else {
                    escrever_arq(&lista, arq_list);
                    fclose(arq_list);
                }
                break;
            case 10:
                arq_list = fopen("lista.txt","r");
                if (arq_list == NULL) {
                    printf("Não foi possivel abrir o arquivo!");
                    fclose(arq_list);
                }else {
                    ler_arq(&lista, arq_list);
                    fclose(arq_list);
                }
                break;
            default:
                printf("Comando invalido, digite novamente!\n");
        }
    } while(cod != 0);
    return 0;
}