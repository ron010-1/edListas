#include<stdio.h>

#define NULL ((void *)0)

// Criando a estrutura do tipo Lista
typedef struct TipoLista{
		int valor;
		struct TipoLista *proximo;
}lista;

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
void lerElementos(int num, struct TipoLista *p){
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
void imprimeElementos(struct TipoLista *p){
	int i;
	struct TipoLista *temp = p->proximo;//Criando um novo ponteiro que recebe o endereço de memória do início da TipoLista, ou seja, o elemento 1.
	printf("Elementos da Lista: ");
	while(temp != NULL){//O loop acaba no ultimo termo, já que ele irá apontar para um endereço de memória do tipo NULL.
		printf("%d ", temp->valor);
		temp = temp->proximo;
	}
}

//Procedimento que insere novas células na Lista Encadeada
void insere(int x, struct TipoLista *p){
	struct TipoLista *nova; //Declarando uma nova estrutura lista com o nome nova, de nova celula
	nova = malloc(sizeof(lista));//Alocando memória de acordo com o tamanho da estrutura.
	nova->valor = x;//Recebendo o valor da celula.
	nova->proximo = p->proximo;//Insere o novo nó no início da lista.
	p->proximo = nova;//Alterando a cabeça da lista.
}
int main(){
	//Declarando variaveis
	int num, i;
	// Inicializar a TipoLista vazia e um ponteiro.
    struct TipoLista *le; //Estrutura do Tipo Lista nome: le representa a HEAD da Lista Encadeada, que é um ponteiro que INDICA O INÍCIO DA LISTA.
	le = malloc(sizeof (lista));//A função malloc aloca a memória dinamicamente para um novo nó da LE. O sizeof informa o numero de bytes necessários.
	le->proximo = NULL; //Criando a head da TipoLista, que está vazia.

	//Numero de elementos que havera em minha TipoLista.
	printf("Insira o numero de celulas que havera na TipoLista: (0 encerra o programa): ");
	scanf("%d", &num);

	//Chamando procedimento adicionar Elementos
	adicionaElementos(num, le);

	//Chamando procedimento imprimir Elementos
	lerElementos(num, le);
	
	printf("\n\n\n");
	printf("Agora voce pode fazer algumas operacoes com a TipoLista e ver como funciona as funcoes pelo codigo e o que cada um faz.\n");
	printf("A - Calcula a altura de um elemento x da TipoLista.\n B - Calcula a profundidade de um elemento x da TipoLista.\n");
	
	//IMPLEMENTAR BUSCA DE UM ELEMENTO X, INSER��O EM UMA LISTA J� CRIADA, REMO��O EM UMA LISTA J� CRIADA, BUSCA E REMOVE, BUSCA E INSERE. 
	return 0;
}
