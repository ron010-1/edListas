//Nesse repositória está as resoluções das questões da lista de Exercícios fornecidos na página.

#include<stdio.h>

//Definindo a minha estrutura do TipoLista
struct TipoLista{
		int valor;
		struct lista *proximo;
};

//Definindo o nome lista pra chamar minha estrutura.
typedef struct TipoLista lista;

//Procedimento que ajuda a ler os valores e ajustar os ponteiros na criação de novas células.
void lerElementos(int num, struct TipoLista *p){
	int i;
	for(i=0; i<num; i++){
		int variavelAuxiliar = i+1;
		struct TipoLista *NovoNo;
		NovoNo = malloc(sizeof(lista));
		NovoNo->valor = variavelAuxiliar;// Atribui um valor ao nó
		NovoNo->proximo = p->proximo;// Insere o novo nó no início da lista
		p->proximo = NovoNo;// Atualiza a cabeça da lista
	}
}

//Procedimento que imprime as células da lista.
void imprimeElementos(int num, struct TipoLista *p){
		int i = 0;
		struct TipoLista *temp = p->proximo;
		printf("\nElementos da Lista: ");

		do {
			printf("%d ", temp->valor);
		    temp = temp->proximo;
			i++;
		} while (i < num);

		printf("\n");
}

//Esse procedimento torna a lista Encadeada em uma lista Circular.
void listaCircular(struct TipoLista *p){
	if(p == NULL || p->proximo == NULL){
		return;
	}

	struct TipoLista *atual = p;//p � a cabe�a da lista ou seja a primeira célula.

	while(atual->proximo != NULL){//Encontrar a última célula.
		atual = atual->proximo;
	}
	//O último nó que antes apontava pro NULL, agora aponta pro endereço de memória da primeira célula.
	atual->proximo = p;
}

void permutacao(int n, int k, struct TipoLista *p) {
    if (n == 1) {
        return;
    }
    int x = k;
    struct TipoLista *inicio = p;
    
    while (k > 0 && p->proximo != NULL) {
        p = p->proximo;
        k--;
    }
    if (k == 0) {
        struct TipoLista *lixo = p->proximo;
        p->proximo = lixo->proximo;
        free(lixo);                      
    }
    permutacao(n - 1, x, inicio);
}

int main(){
	//Declarando variaveis
	int num, i;
	// Inicializar a TipoLista vazia e um ponteiro.
    struct TipoLista *le1; //Estrutura do Tipo Lista nome: le representa a HEAD da Lista Encadeada, que a um ponteiro que INDICA O INÃCIO DA LISTA.
	le1 = malloc(sizeof (lista));//A função malloc aloca a memória dinamicamente para um novo nó da LE. O sizeof informa o numero de bytes necessÃ¡rios.
	le1->proximo = NULL; //Criando a cabeça da TipoLista, que está vazia.

	//Numero de elementos que havera em minha TipoLista.
	

	imprimeElementos(num, le1);

	int n, k; //n = numero de Pessoas e k = contagem pra eliminar.
	printf("Insira, por favor, o valor n e k: ");
	scanf("%d%d", &n, &k);

	lerElementos(n, le1);

	imprimeElementos(n, le1);

	permutacao(n, k, le1);
    listaCircular(le1);


	return 0;
}
