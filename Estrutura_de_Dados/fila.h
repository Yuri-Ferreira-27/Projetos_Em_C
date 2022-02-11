
typedef struct noFila{
    int valor;
    struct noFila *prox;
} no_row;

/// tam_Fila - Função que retorna o tamanho da fila
int tam_Fila(no_row **fila){
    no_row *aux;
    aux = *fila;
    int cont = 0;
    while (aux!= NULL){ // verifica se a fila está preenchida ou vazia
        cont++; // se estiver preenchida, incrementa o contador
        aux = aux->prox; // aponta para o proximo
    }
    return cont; // retorna o valor do contador
}

///Enfileirar - inserir elemento no final
void enfileirar(no_row **fila, int num){
    no_row *aux, *novo = malloc(sizeof(no_row)); //Aloca um espaço em memória para armazenar um novo elemento
    if(novo){ //Checa se o espaço foi armazenado corretamente, se sim, segue para o próximo passo
        novo->valor = num; // o nó recebe o valor informado
        novo->prox = NULL; // o nó irá apontar para o próximo elemento
        if(*fila == NULL){ // checa se a fila é igual ao último elemento (NULL)
            *fila = novo; // se for, recebe o elemento informado
        }else{
            aux = *fila;
            while(aux->prox != NULL){ //checa se o proximo elemento da fila é igual ao último elemento (NULL)
                aux = aux->prox; // aponta para o proximo
            }
        aux->prox = novo; // o proximo recebe o elemento informado
        }
    }else{
        printf("Erro ao alocar memoria!");
    }
}

///Desenfileirar - Remove elemento do inicio
no_row *desenfileirar(no_row **fila){
     no_row *remover = NULL;
    if(*fila != NULL){ //percorre a fila até encontrar o elemento (nó) procurado
        remover = *fila; // cria um ponteiro para apontar para a informação da fila
        *fila = remover->prox; // a fila recebe o elemento após o elemento informado, removendo-o
    }else{
        printf("Fila Vazia");
    }
    return remover; //retorna o elemento removido
}

/// imprimir_fim - função que retorna o elemento do final da fila
no_row *imprimir_fim(no_row **fila) {
    no_row *aux = *fila;
    printf("%d",aux->valor); // imprime o elemento do final da fila
    return aux;
}

/// imprimir_Fila - função criada para imprimir a fila
void imprimir_Fila(no_row *fila){
    no_row *aux = fila;
    printf("[");
    while(aux != NULL){ // checa se a fila está preenchida ou vazia
        printf("%d",aux->valor); // se estiver preenchida, imprime a fila
        if(aux->prox != NULL){
            printf(", ");
        }
        aux = aux->prox; // aponta para o proximo elemento e imprime
    }
    printf("]");
}

/// fila_cheia - Verifica se a fila ainda pode alocar espaço para novo elemento
int fila_cheia(no_row **fila){
    no_row *novo = malloc(sizeof(no_row)); //Aloca um espaço em memória para armazenar um novo elemento
    if (novo == NULL) // checa se há espaço para armazenar o elemento
        return novo; // se nao houver, retorna o elemento e informa que a fila está cheia
}

typedef struct arq_Fila{
    int cod_peca;
    char modelo[100];
    char marca[100];
    float preco;
}arq_Fila;

typedef struct no_rowArq{
    struct no_rowArq *prox;
}no_rowArq;

/// escrever_arq_Fila - Função criada para escrever em arquivo txt
void escrever_arq_Fila(no_row **fila, FILE *arquivo){
    struct arq_Fila aux;

    // Leitura e gravação das informações no arquivo.txt
    printf("Informe o codigo da peca: ");
    scanf("%d",&aux.cod_peca);
    printf("Informe o modelo: ");
    scanf("%s",aux.modelo);
    printf("Informe a marca: ");
    scanf("%s",aux.marca);
    printf("Informe o preco: ");
    scanf("%f",&aux.preco);

    fprintf(arquivo,"%d %s %s %f",aux.cod_peca, aux.modelo, aux.marca, aux.preco);
}

/// ler_arq_Fila - funçaõ para apresentar as informações registradas no arquivo txt
void ler_arq_Fila(no_row **fila, FILE *arquivo){

    struct arq aux;
    char arq_aux;
    printf("Informe o codigo da peca: "); // recebe o código da peça a ser lida
    scanf("%d",&aux.cod_peca);

    arq_aux = fscanf(arquivo,"%s %s %f", aux.modelo, aux.marca, &aux.preco);
    while (arq_aux != EOF) { //verifica se o arquivo é diferente de EOF, se sim, mostra as informações dele na tela
        printf("\nModelo: %s", aux.modelo);
        printf("\nMarca: %s", aux.marca);
        printf("\nPreco: R$%.2f", aux.preco);
    }
}
