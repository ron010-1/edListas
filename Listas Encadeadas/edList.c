#include<stdio.h>

#define NULL ((void *)0)

// Criando a estrutura do tipo Lista
typedef struct TipoLista{
		int valor;
		struct TipoLista *proximo;
}TipoLista;

//Função que calcula o número de objetos da TipoLista.
int contaElementos(struct TipoLista*p){
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
void adicionaElementos(int num, struct TipoLista *p){
	int i, variavelAuxiliar;
	for(i=0; i<num; i++){
		struct TipoLista *NovoNo = malloc(sizeof(TipoLista));
		printf("Insira um numero para a celula %d: ", i+1);
		scanf("%d", &variavelAuxiliar);
		NovoNo->valor = variavelAuxiliar;
		NovoNo->proximo = p->proximo;
		p->proximo = NovoNo;
	}
}

//Procedimento que imprime todos os elementos da TipoLista.
void imprimeElementos(struct TipoLista *p){
	int i;
	struct TipoLista *temp = p->proximo;//Criando um novo ponteiro que recebe o endereço de memória do início da lista, ou seja, o elemento 1.
	printf("Elementos da Lista: ");
	while(temp != NULL){//O loop acaba no ultimo termo, já que ele irá apontar para um endereço de memória do tipo NULL.
		printf("%d ", temp->valor);
		temp = temp->proximo;
	}
}
int main(){
	//Declarando variaveis
	int num, i;
	// Inicializar a TipoLista vazia e um ponteiro.
    struct TipoLista *le; //Estrutura do Tipo Lista nome: le representa a HEAD da Lista Encadeada, que é um ponteiro que INDICA O INÍCIO DA LISTA.
	le = malloc(sizeof (TipoLista));//A função malloc aloca a memória dinamicamente para um novo nó da LE. O sizeof informa o numero de bytes necessários.
	le->proximo = NULL; //Criando a head da TipoLista, que está vazia.

	//Numero de elementos que havera em minha TipoLista.
	printf("Insira o numero que havera na TipoLista: (0 encerra o programa): ");
	scanf("%d", &num);

	//Chamando procedimento adicionar Elementos
	adicionaElementos(num, le);

	//Chamando procedimento imprimir Elementos
	imprimeElementos(le);
	
	printf("\n\n\n");
	printf("Agora voce pode fazer algumas operacoes com a lista e ver como funciona as funcoes pelo codigo e o que cada um faz.\n");
	printf("A - Calcula a altura de um elemento x da lista.\n B - Calcula a profundidade de um elemento x da lista.\n");

	return 0;
}
