#include<stdio.h>

#define NULL ((void *)0)

// Criando a estrutura do tipo Lista
struct TipoLista{
		int valor;
		struct TipoLista *proximo;
};

// Definindo do tipo "lista".
typedef struct TipoLista lista;

//Função que calcula o número de objetos da TipoLista.
int contaElementos(struct TipoLista *p){
	if(p == NULL){
		return 0;
	}
	return 1 + contaElementos(p->proximo);
}

//Função que calcula a altura de um objeto da TipoLista. Altura é a distância de um elemento c ao fim da TipoLista.
int altura(struct TipoLista *c){
	if(c == NULL){
		return 0;
	}return 1 + altura(c->proximo);
}

//Função que calcula a profundidade de um objeto na TipoLista. Profundidade é o número de passos que vai da primeira célula atá a célula c.
int profundidade(struct TipoLista *p, struct TipoLista *c){
	if(p == c){
		return 1;
	}return 1 + profundidade(p->proximo, c);
}

//Procedimento que adiciona elementos a minha Lista Encadeada de acordo com o numero digitado pelo usuario.
void lerCelulas(int num, struct TipoLista *p){
	int i, variavelAuxiliar;
	for(i=0; i<num; i++){
		struct TipoLista *NovoNo = malloc(sizeof(lista));
		printf("Insira um numero para a celula %d: ", i+1);
		scanf("%d", &variavelAuxiliar);
		NovoNo->valor = variavelAuxiliar;// Atribui um valor ao nó
		NovoNo->proximo = p->proximo;// Insere o novo nó no início da lista
		p->proximo = NovoNo;// Atualiza a cabeça da lista
	}
}

//Procedimento que imprime todos os elementos da TipoLista.
void imprimeLista(struct TipoLista *p){
	int i;
	struct TipoLista *temp = p->proximo;//Criando um novo ponteiro que recebe o endereço de memória do início da TipoLista, ou seja, o elemento 1.
	printf("\nElementos da Lista: ");
	while(temp != NULL){//O loop acaba no ultimo termo, já que ele irá apontar para um endereço de memória do tipo NULL.
		printf("%d ", temp->valor);
		temp = temp->proximo;
	} printf("\n");//Adiciona um quebra de linha ao fim da impressão.
}

//Procedimento que insere novas células na Lista Encadeada
void insere(int x, struct TipoLista *p){
	struct TipoLista *nova; //Declarando uma nova estrutura lista com o nome nova, de nova celula
	nova = malloc(sizeof(lista));//Alocando memória de acordo com o tamanho da estrutura.
	nova->valor = x;//Recebendo o valor da celula.
	nova->proximo = p->proximo;//Insere o novo nó no início da lista.
	p->proximo = nova;//Alterando a cabeça da lista.
}

//Função que copia a lista e retorna uma nova lista com as mesmas células.
void copiaLista(struct TipoLista *p, struct TipoLista *c){
	if(p == NULL){
		return;
	}else{
		//A estrutura abaixo é quase a mesma do procedimeno insere.
		struct TipoLista *nova; //Declarando uma nova estrutura lista com o nome nova, de nova celula
	    nova = malloc(sizeof(lista));//Alocando memória de acordo com o tamanho da estrutura.
	    nova->valor = p->valor;//Recebendo o valor da celula.
	    nova->proximo = c->proximo;//Insere o novo nó no início da lista.
	    c->proximo = nova;//Alterando a cabeça da lista.
	    copiaLista(p->proximo, c);
	}
}

//Procedimento para remover celula com valor x, mas sem cabe�a. POINTER TO POINTER FUNCTION.
void removeCelula(struct TipoLista *p, int x){
	struct TipoLista *anterior = NULL;
	struct TipoLista *atual = p;
	
	//Laço para encontrar o anterior da célula com valor x.
	while(atual != NULL && atual->valor != x){
		anterior = atual;//Atualizando o ponteiro anterior.
		atual = atual->proximo;//Atualiza o ponteiro p pra próxima célula.
	}
	//Se encontrou o valor x.
	if(atual != NULL){
		//Se o nó não é primeiro
		if(anterior !=NULL){
			anterior->proximo = atual->proximo;
		}else{ //Se o nó é o primeiro
			p = atual->proximo;
		}
	}
	free(atual);
}

int main(){
	//Declarando variaveis
	int num, i, contador=0;
	// Inicializar a TipoLista vazia e um ponteiro.
    struct TipoLista *le; //Estrutura do Tipo Lista nome: le representa a HEAD da Lista Encadeada, que é um ponteiro que INDICA O INÍCIO DA LISTA.
	le = malloc(sizeof (lista));//A função malloc aloca a memória dinamicamente para um novo nó da LE. O sizeof informa o numero de bytes necessários.
	le->proximo = NULL; //Criando a head da TipoLista, que está vazia.

	//Numero de elementos que havera em minha TipoLista.
	printf("Insira o numero de celulas que havera na TipoLista: (0 encerra o programa): ");
	scanf("%d", &num);

	//Chamando procedimento adicionar Elementos
	lerCelulas(num, le);

	//Chamando procedimento imprimir Elementos
	imprimeLista(le);
	
	printf("\n\n\n");

	char letra;//Declarandi variavel de controle do laço.
	while(letra != 'z'){
		printf("\nAgora voce pode fazer algumas operacoes com a TipoLista e ver como funciona as funcoes pelo codigo e o que cada um faz.\n");
	    printf("a - Inserir uma nova celula na lista.\n");
	    printf("b - Remove uma celula da lista.\n");
	    printf("c - Calcula a altura de um elemento x da TipoLista.\n");
	    printf("d - Calcula a profundidade de um elemento x da TipoLista.\n");
		printf("e - Copia a lista.\n");
		printf("f - Procurar um valor x na Lista.\n");
		printf("z - Encerra o programa.\n");
		fflush(stdin);//Limpar buffer do teclado.
		scanf("%c", &letra);
		//Condições de acordo com a escolha do usuário.
        
		//Apenas as configurações iniciais para caso o usuário solicitar a opção de Copiar a lista.
		struct TipoLista *novaLista;
		novaLista = malloc(sizeof(lista));
		novaLista->proximo = NULL;

		switch (letra) {
        case 'a':
            printf("Insira, por favor, o valor da nova celula: ");
			scanf("%d", &num);
			printf("Antes de inserir a nova celula - ");
			imprimeLista(le);
			printf("Depois da insercao da celula: ");
			insere(num, le);
			imprimeLista(le);
            break;
        case 'b':
            printf("Insira, por favor, o valor da celula que voce deseja remover: ");
			scanf("%d", &num);
			printf("\nEssa eh a lista antes da remocao: ");
			imprimeLista(le);
			removeCelula(le, num);
			printf("Essa eh a lista apos a remocao: ");
			imprimeLista(le);
            break;
        case 'c':
            printf("Insira, por favor, o valor da celula que voce deseja saber a altura: ");
			scanf("%d", &num);
			while(le != NULL && le->valor != num){
				contador++;
				le = le->proximo;
			}
			int h = altura(le);
			printf("A altura da celula %d eh %d\n", contador, h);
            break;
        case 'd':
            //PROFUNDIDADE DE UM ELEMENTO NA LISTA
            break;
        case 'e':
		    //A função le já é enviada para a posição 0 pra evitar que pegue algum lixo de memória.
            copiaLista(le->proximo, novaLista);
			printf("Lista 'le' : ");
			imprimeLista(le);
			printf("\n");
			printf("Lista 'novaLista' : ");
			imprimeLista(novaLista);
            break;
		case 'f':
            //BUSCA E INSERE
            break;
		case 'z':
		    printf("Muito obrigado por participar dos meus estudos em C.\nGratidao, pequeno gafanhoto. GG.\n");
        default:
		if(letra != 'z'){
			printf("\nVoce inseriu uma tecla que nao apresenta funcao.\n");
		}
            break;
    }
		
	}
	
	
	//IMPLEMENTAR BUSCA DE UM ELEMENTO X, INSER��O EM UMA LISTA J� CRIADA, REMO��O EM UMA LISTA J� CRIADA, BUSCA E REMOVE, BUSCA E INSERE. 
	return 0;
}
