typedef struct no{
    int valor;
    struct no *prox;
} no;

/// inserir_Inicio - função para inserir elemento no início da lista
int inserir_Inicio(no **lista, int num){
    no *novo = malloc(sizeof(no)); //Novo = Aloca um espaço em memória para armazenar um novo elemento
    if(novo){ //Checa se o espaço foi armazenado corretamente, se sim, segue para o próximo passo
        novo->valor = num; // o nó recebe o valor informado
        novo->prox = *lista; // o nó irá apontar para o próximo elemento
        *lista = novo;
    }else{
        return NULL; // se não houver espaço, irá retornar NULL
    }
    return novo;// Se houver, irá retornar o valor armazenado
}

/// inserir_Fim - função para inserir elemento no final da lista
int inserir_Fim(no **lista, int num){
    no *aux, *novo = malloc(sizeof(no));//Novo = Aloca um espaço em memória para armazenar um novo elemento
    if(novo){ //Checa se o espaço foi armazenado corretamente, se sim, segue para o próximo passo
        novo->valor = num; // o nó recebe o valor informado
        novo->prox = NULL; // o nó irá apontar para o ultimo elemento
        if(*lista == NULL){ // Checa se a lista está vazia ou não
            *lista = novo; //Se estiver, a lista irá receber o valor na primeira posição
        }
        else{
            aux = *lista;
            while(aux->prox != NULL){
                aux = aux->prox; //Se não, a lista irá receber o valor na última posição
            }
            aux->prox = novo;
        }
    }else{
        return NULL; // se não houver espaço, irá retornar NULL
    }
    return novo;// Se houver, irá retornar o valor armazenado
}

/// inserir_Meio - função para inserir elemento no meio da lista, após o valor de referência
int inserir_Meio(no **lista, int num, int anterior){
    no *aux, *novo = malloc(sizeof(no)); //Novo = Aloca um espaço em memória para armazenar um novo elemento
    if(novo){
        novo->valor = num; // o nó recebe o valor informado
        if(*lista == NULL){ // checa se a lista está vazia ou não
            novo->prox = NULL; // o nó irá apontar para o ultimo elemento
            *lista = novo;// a lista recebe o elemento
        }else{
            aux = *lista;
            while(aux->valor != anterior && aux->prox != NULL){ // verifica se o valor é diferente do anterior, e se o proximo não é o final da lista
                aux = aux->prox; // se sim, o aux aponta para o próximo elemento
            }
            novo->prox = aux->prox; // o novo elemento recebe o aux apontando para o próximo elemento
            aux->prox = novo; //o proximo elemento recebe o valor
        }
    }else{
        return NULL; // se não houver espaço, irá retornar NULL
    }
    return novo;// Se houver, irá retornar o valor armazenado
}

/// imprimir_Lista - função para imprimir a lista

void imprimir_Lista(no *lista){
    no *aux = lista;
    printf("[");
    while(aux != NULL){ // checa se a lista está preenchida ou vazia
        printf("%d",aux->valor); // se estiver preenchida, imprime a lista
        if(aux->prox != NULL){
            printf(", ");
        }
        aux = aux->prox; // aponta para o proximo elemento e imprime
    }
    printf("]");
}

/// remover_lista - função para remover o elemento da lista
no *remover_lista(no **lista, int num){
        no *aux, *ant;
        int encontrou=0;
        aux = *lista;
        ant = *lista;
// Percorre a lista ate encontrar o elemento (nó) procurado
        while (encontrou == 0 && aux != NULL){
            if (aux->valor == num){
                // Encontrou o elemento (nó) procurado
                encontrou = 1;
            }
            else{
                //nao encontrou o elemento(nó). Avança ao noArq
                ant = aux;
                aux =(no *) aux->prox;
            }
        }
        if (encontrou == 1){
            // Verifica se o elemento (nó) encontrado eh o primeiro da lista
            if (ant == aux
                && aux == *lista){
                *lista = aux->prox;
            }
//Caso o elemento(nó) encontrado nao seja o primeiro da lista
            else{
                ant->prox=aux->prox;
            }
            // Libera a memoria alocada
            free(aux);
            aux = NULL;
            return 1;
        }
//Retorna zero indicando que o elemento(no) nao foi encontrado
        return 0;
}

/// tam_Lista - função que calcula e retorna o tamanho da lista
int tam_Lista(no **lista){
    no *aux;
    aux = *lista;
    int cont = 0;
    while (aux!= NULL){ // verifica se a lista está preenchida ou vazia
        cont++; // se estiver preenchida, incrementa o contador
        aux = aux->prox; // aponta para o proximo
    }
    return cont; // retorna o valor do contador
}

/// inserir_lista - função para inserir na lista a partir de uma posição informada
int inserir_lista(no **lista, int num, int pos){
    no *novo = malloc(sizeof(no)); //Aloca um espaço em memória para armazenar um novo elemento
        no *aux = *lista;
        if(novo == NULL){ //Checa se o espaço foi armazenado corretamente, se sim, segue para o próximo passo
             return NULL; // se não houver espaço, irá retornar NULL
         }
        novo->valor = num; // o nó recebe o valor informado
        if(pos == 0){
            novo->prox = *lista; // o nó irá apontar para o próximo elemento
                *lista = novo; // a lista recebe o elemento
                  return novo; // retorna o elemento inserido
        }
        int i = 0;
            while(aux->prox != NULL && i != pos - 1){ // verifica se o proximo elemento não é NULL e checa se a posição existe na lista
             aux = aux->prox; // se sim, aponta para o proximo elemento
             i++; // e incrementa a variavel para percorrer a lista
        }
        novo->prox = aux->prox; // o novo elemento recebe o aux apontando para o próximo elemento
        aux->prox = novo; // o proximo elemento recebe o valor
        return novo; // retorna o elemento inserido
}


/// buscar_elemento - função para buscar um elemento na lista
no *buscar_elemento(no **lista, int num){
    no *aux, *no = NULL;
    aux = *lista;
    while(aux != NULL && aux->valor != num){ //verifica se a lista não está vazia, e checa se o valor existe na lista
        aux = aux->prox; // se o valor existe, aponta para o proximo
    }
    if(aux != NULL){ // verifica se a lista está vazia
        no = aux; // se não estiver, o ponteiro pra lista verifica se o valor existe na lista
    }
    return no; // retorna que o valor se encontra na lista
}

void troca(no *a, no *b){
    int temp = a->valor;
    a->valor = b->valor;
    b->valor = temp;
}

/// ordenar_lista - Função para ordernar os elementos da lista
void ordenar_lista(no *lista){
    no *aux;
    no *aux2 = NULL;

    int trocar;
    if(lista == NULL){ // verifica se a lista está vazia
        return; // se estiver, retorna NULL
    }
    do{
        trocar = 0;
        aux = lista;
        while(aux->prox != aux2){ //verifica se o elemento da lista existe
            if(aux->valor > aux->prox->valor){ //se existe, ele busca onde se encontra o valor
                troca(aux, aux->prox); //realiza a troca de posição do valor, passando o menor valor para frente
                trocar = 1;
            }
            aux = aux->prox;
        }
        aux2 = aux;
    }while (trocar);
}

/// buscar_elem_pos - função para buscar o elemento informado na posição da lista
int buscar_elem_pos(no **lista, int pos){
    int i = 0;
    no *aux = *lista;
    while(aux != NULL && i < pos){ //verifica se a lista está vazia e se a posição existe na lista
        aux = aux->prox; // se existe, aponta para o valor correspondente a posição
        i++; // incrementa a variável para percorrer
    }
    return aux; // retorna o valor encontrado na posição
}

/// lista_cheia - Verifica se a lista ainda pode alocar espaço para novo elemento
int lista_cheia(no **lista){
    no *novo = malloc(sizeof(no)); //Aloca um espaço em memória para armazenar um novo elemento
    if(novo == NULL) // checa se há espaço para armazenar o elemento
        return novo; // se nao houver, retorna o elemento e informa que a lista está cheia
}

typedef struct arq{
    int cod_peca;
    char modelo[100];
    char marca[100];
    float preco;
}arq;

typedef struct noArq{
    struct noArq *prox;
}noArq;

/// escrever_arq - Função criada para escrever em arquivo txt
void escrever_arq(no **lista, FILE *arquivo){
    struct arq aux;

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

/// ler_arq - funçao para apresentar as informações registradas no arquivo txt
void ler_arq(no **lista, FILE *arquivo){

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