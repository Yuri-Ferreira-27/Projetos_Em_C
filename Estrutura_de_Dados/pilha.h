typedef struct noPilha{
	int valor;
    struct no *prox;
} no_Stack;

/// tam_Pilha - Função que retorna o tamanho da pilha

int tam_Pilha(no_Stack **pilha){
    no_Stack *aux;
    aux = *pilha;
    int cont = 0;
    while (aux!= NULL){ // verifica se a pilha está preenchida ou vazia
        cont++; // se estiver preenchida, incrementa o contador
        aux = aux->prox; // aponta para o proximo
    }
    return cont; // retorna o valor do contador
}

///Empilhar - inserir elemento no topo

no_Stack *empilhar(no **pilha, int num){
    no *novo = malloc(sizeof(no_Stack)); //Aloca um espaço em memória para armazenar um novo elemento
    if(novo){ //Checa se o espaço foi armazenado corretamente, se sim, segue para o próximo passo
        novo->valor = num; // o nó recebe o valor informado
        novo->prox = *pilha; // o nó irá apontar para o próximo elemento
        *pilha = novo;
        return novo;// Se houver espaço, irá retornar o valor armazenado
    }else{
        printf("Erro ao alocar memoria!");
    }
    return NULL; // se não houver espaço, irá retornar NULL
}

///Desempilhar - Remove elemento do topo
no_Stack *desempilhar(no_Stack **pilha){
    if(*pilha != NULL){ //percorre a pilha até encontrar o elemento (nó) procurado
        no_Stack *remover = *pilha; // cria um ponteiro para apontar para a informação da pilha
        *pilha = remover->prox; // a pilha recebe o elemento após o elemento informado, removendo-o
        return remover; //retorna o elemento removido
    }else{
        printf("Pilha Vazia");
    }
    return NULL; // se a pilha estiver vazia, irá retornar NULL
}

/// imprimir_topo - função que retorna o elemento do topo
no_Stack *imprimir_topo(no_Stack **pilha) {
    no_Stack *aux = *pilha;
    printf("%d",aux->valor); // imprime o elemento do topo
    return aux;
}

/// imprimir_Pilha - função criada para imprimir a pilha
void imprimir_Pilha(no_Stack *pilha){
    no_Stack *aux = pilha;
        printf("[");
        while(aux != NULL){ // checa se a pilha está preenchida ou vazia
            printf("%d",aux->valor); // se estiver preenchida, imprime a pilha
            if(aux->prox != NULL){
                printf(", ");
            }
            aux = aux->prox; // aponta para o proximo elemento e imprime
        }
        printf("]");
}

/// pilha_cheia - Verifica se a pilha ainda pode alocar espaço para novo elemento
int pilha_cheia(no_Stack **pilha) {
    no_Stack *novo = malloc(sizeof(no_Stack)); //Aloca um espaço em memória para armazenar um novo elemento
    if (novo == NULL) // checa se há espaço para armazenar o elemento
        return novo; // se nao houver, retorna o elemento e informa que a pilha está cheia
}

typedef struct arq_Pilha{
    int cod_peca;
    char modelo[100];
    char marca[100];
    float preco;
}arq_Stack;

typedef struct noArq_Pilha {
    struct noArq_Pilha *prox;
}noArq_Pilha;

/// escrever_arq_Pilha - Função criada para escrever em arquivo txt
void escrever_arq_Pilha(no_Stack **pilha, FILE *arquivo){
    struct arq_Pilha aux;

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

/// ler_arq_Pilha - funçaõ para apresentar as informações registradas no arquivo txt
void ler_arq_Pilha(no_Stack **pilha, FILE *arquivo){

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