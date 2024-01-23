//Nesse repositória está as resoluções das questões da lista de Exercícios fornecidos na página.

#include<stdio.h>

//Definindo a minha estrutura do TipoLista
struct TipoLista{
		int valor;
		struct lista *proximo;
};

//Definindo o nome lista pra chamar minha estrutura.
typedef struct TipoLista lista;


//Função que conta o número de células de uma lista
int contaCelulas(struct TipoLista *p){
	if(p == NULL){
		return 0;
	}
	return 1 + contaCelulas(p->proximo);
}

//Função que calcula a altura de uma célula dentro da lista.
int altura(struct TipoLista *c){
	if(c == NULL){
		return 0;
	}return 1 + altura(c->proximo);
}

//Função que calcula a profundidade de um célula x dentro da lista.
int profundidade(struct TipoLista *p, struct lista *c){
	if(p == c){
		return 1;
	}return 1 + profundidade(p->proximo, c);
}

//Procedimento que ajuda a ler os valores e ajustar os ponteiros na criação de novas células.
void lerElementos(int num, struct TipoLista *p){
	int i, variavelAuxiliar;
	for(i=0; i<num; i++){
		struct TipoLista *NovoNo = malloc(sizeof(lista));
		printf("Insira um numero para a celula %d: ", i+1);
		scanf("%d", &variavelAuxiliar);
		NovoNo->valor = variavelAuxiliar;// Atribui um valor ao nÃ³
		NovoNo->proximo = p->proximo;// Insere o novo nÃ³ no inÃ­cio da lista
		p->proximo = NovoNo;// Atualiza a cabeÃ§a da lista
	}
}

//Procedimento que imprime as células da lista.
void imprimeElementos(struct TipoLista *p){
	struct TipoLista *temp = p->proximo;//Criando um novo ponteiro que recebe o endereÃ§o de memÃ³ria do inÃ­cio da TipoLista, ou seja, o elemento 1.
	printf("\nElementos da Lista: ");
	while(temp != NULL){//O loop acaba no ultimo termo, jÃ¡ que ele irÃ¡ apontar para um endereÃ§o de memÃ³ria do tipo NULL.
		printf("%d ", temp->valor);
		temp = temp->proximo;
	} printf("\n");//Adiciona um quebra de linha ao fim da impressÃ£o.
}

//Engata uma lista no final da Outra. RECURSIVA.
void engateLista(struct TipoLista *p, struct TipoLista *c){
	if(p->proximo == NULL){
		p->proximo = c->proximo;
		return;
	}engateLista(p->proximo, c);
}

//Insere uma cÃ©lula com valor x apÃ³s o k-Ã©sima cÃ©lula da lista. RECURSIVA.
void insereAposK(struct TipoLista *p, int x, int k){
	if(k==0){
		struct TipoLista *nova = malloc(sizeof(lista));
	    nova->valor = x;
		nova->proximo = p->proximo;
     	p->proximo = nova;
		return;
	}else{
		insereAposK(p->proximo, x, k-1);
	}	
}

//Procedimento que troca duas células pelo seu valor, x e y.
void trocaCelulas(struct TipoLista *p, int x, int y){
	struct TipoLista *celulaX = NULL;
	struct TipoLista *celulaY = NULL;

	while(p!=NULL){
		if(p->valor == x){
			celulaX = p;
		}else if(p->valor == y){
			celulaY = p;
		}
		p = p->proximo;
	}

	int variavelAuxiliar = celulaX->valor;
	celulaX->valor = celulaY->valor;
	celulaY->valor = variavelAuxiliar;
}

//Procedimento que inverte a lista, o primeiro se torna o último, o segundo o penúltimo...
void inverteLista(struct TipoLista *p){
	if(p == NULL){
		return;
	}else{
		//A estrutura abaixo é quase a mesma do procedimeno insere.
		struct TipoLista *nova; //Declarando uma nova estrutura lista com o nome nova, de nova celula
	    nova = malloc(sizeof(lista));//Alocando memória de acordo com o tamanho da estrutura.
	    nova->valor = p->valor;//Recebendo o valor da celula.
	    nova->proximo = p->proximo;//Insere o novo nó no início da lista.
	    p->proximo = nova;//Alterando a cabeça da lista.
	    copiaLista(p->proximo);
	}
}

//Procedimento para remover celula com valor x, mas sem cabe�a. POINTER TO POINTER FUNCTION.
void removeCelula(struct TipoLista **p, int x){
	struct TipoLista *anterior = NULL;
	struct TipoLista *atual = *p;
	
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
			*p = atual->proximo;
		}
	}
	free(atual);
}

int main(){
	//Declarando variaveis
	int num, i;
	// Inicializar a TipoLista vazia e um ponteiro.
    struct TipoLista *le1; //Estrutura do Tipo Lista nome: le representa a HEAD da Lista Encadeada, que a um ponteiro que INDICA O INÃCIO DA LISTA.
	le1 = malloc(sizeof (lista));//A função malloc aloca a memória dinamicamente para um novo nó da LE. O sizeof informa o numero de bytes necessÃ¡rios.
	le1->proximo = NULL; //Criando a cabeça da TipoLista, que está vazia.

	struct TipoLista *le2;
	le2 = malloc(sizeof(lista));
	le2->proximo = NULL;

	//Numero de elementos que havera em minha TipoLista.
	printf("Insira o numero de celulas que havera na TipoLista: (0 encerra o programa): ");
	scanf("%d", &num);

	//Chamando procedimento adicionar Elementos
	lerElementos(num, le1);

	printf("Chamando a funcao Remove celula: \n");
	removeCelula(le1, 4);

	imprimeElementos(le1);

	return 0;
}
