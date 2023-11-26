#include <stdio.h>
#include <stdlib.h>
#include "marriage.h"

struct pessoa *criaPessoa(char id, int atr1, int atr2, int atr3, int atr4, int atr5, int atr6) {
	struct pessoa *tmpPessoa;
	if (!(tmpPessoa  = malloc(sizeof(struct pessoa)))) {
		printf("[-] ERRO NA ALOC. DA PESSOA!\n");
		return NULL; // aloc. da pessoa
	}
	tmpPessoa->id = id; // identificador da pessoa
	tmpPessoa->atr[0] = atr1;
	tmpPessoa->atr[1] = atr2;
	tmpPessoa->atr[2] = atr3;
	tmpPessoa->atr[3] = atr4;
	tmpPessoa->atr[4] = atr5;
	tmpPessoa->atr[5] = atr6; 
	tmpPessoa->relevancia = 0; // toda pessoa começa com 0 de relevância
	tmpPessoa->ant = NULL;
	tmpPessoa->prox = NULL;

	return tmpPessoa; // retorna uma pessoa inicializada
}

struct listaCirc *criaListaCircular() {
	struct listaCirc *tmp;
	if (!(tmp = malloc(sizeof(struct listaCirc)))) {
		printf("[-] ERRO NA ALOC. DA LISTA DE PRETENDENTES\n");
		return NULL; // aloc. da lista circular duplamente encadeada
	}
	tmp->cbc = NULL;
	tmp->cauda = NULL;
	tmp->tam = 0;

	return tmp; // retorna uma lista inicializada
}

struct pilha *criaPilha() {
	struct pilha *tmp;
	if (!(tmp = malloc(sizeof(struct pilha)))) {
		printf("[-] ERRO NA ALOC. DA PILHA DE CANDIDATOS\n");
		return NULL; // aloc. da pilha
	}
	tmp->topo = NULL;
	tmp->tam = 0;

	return tmp; // retorna uma pilha inicializada
}

int tamPilha(struct pilha *p) {
	return p->tam;
}

int tamLista(struct listaCirc *l) {
	return l->tam;
}

int pilhaVazia(struct pilha *p) {
	return tamPilha(p) == 0; // checa se a pilha está vazia pelo tamanho
}

int listaVazia(struct listaCirc *l) {
	return tamLista(l) == 0; // checa se a lista está vazia pelo tamanho
}

void push(struct pilha *p, struct pessoa *pers) {
	if (pilhaVazia(p)) {
		p->topo = pers;
		(p->tam)++;
		return; // se a pilha está vazia, define o topo como sendo a nova pessoa
	}
	pers->prox = p->topo;
	p->topo = pers; // redefinição do topo, caso a pilha não esteja vazia
	(p->tam)++;
}

void pop(struct pilha *p, int atrReturn[]) {
	if (pilhaVazia(p)) {
		printf("[-] PILHA VAZIA! IMPOSSÍVEL REALIZAR POP\n\n");
		return;
	}
	for (int i = 0; i < MAX_ATR; i++)
		atrReturn[i] = p->topo->atr[i]; // cópia dos atributos da pessoa
	struct pessoa *tmp = p->topo;
	p->topo = p->topo->prox;
	free(tmp);
	tmp = NULL; // redefinição de ponteiros e liberação da pessoa removida
	(p->tam)--;
}

void enlist(struct listaCirc *l, struct pessoa *pers) {
	if (listaVazia(l)) {
		l->cbc = pers;
		l->cauda = pers;
		pers->prox = pers;
		pers->ant = pers;
		(l->tam)++;
		return; // se a lista for vazia, todos os ponteiros apontam para a pessoa
	}
	pers->ant = l->cauda;
	pers->prox = l->cbc;
	l->cauda->prox = pers;
	l->cbc->ant = pers;
	l->cauda = pers; // redefinição de ponteiros, mantendo a circularidade
	(l->tam)++;
}

void delistCbc(struct listaCirc *l) {
	if (listaVazia(l)) {
		printf("[-] LISTA VAZIA! IMPOSSÍVEL REALIZAR DELIST\n\n");
		return;
	}
	struct pessoa *tmp = l->cbc;
	if (l->cbc == l->cauda) {
		free(l->cbc);
		l->cbc = NULL;
		(l->tam)--;
		return; // caso a lista tenha um único ponteiro, ele é apenas liberado, sem redefinição
	}
	l->cbc = l->cbc->prox;
	l->cauda->prox = l->cbc;
	l->cbc->ant = l->cauda;
	free(tmp);
	tmp = NULL; // redefinição de ponteiros e liberação da antiga cabeça da lista
	(l->tam)--;
}

void delistCauda(struct listaCirc *l) {
	if (listaVazia(l)) {
		printf("[-] LISTA VAZIA! IMPOSSÍVEL REALIZAR DELIST\n\n");
		return;
	}
	struct pessoa *tmp = l->cauda;
	if (l->cauda == l->cbc) {
		free(l->cauda);
		l->cauda = NULL;
		(l->tam)--;
		return; // caso a lista tenha um único ponteiro, ele é apenas liberado, sem redefinição
	}
	l->cauda = l->cauda->ant;
	l->cbc->ant = l->cauda;
	l->cauda->prox = l->cbc;
	free(tmp);
	tmp = NULL; // redefinição de ponteiros e liberação da antiga cauda da lista
	(l->tam)--;
}

void delist(struct listaCirc *l, int relevancia) {
	if (listaVazia(l)) {
		printf("[-] LISTA VAZIA! IMPOSSÍVEL REALIZAR DELIST\n\n");
		return;
	}
	struct pessoa *aux = l->cbc; // ponteiro auxiliar que se move pela lista
	int k = 0;
	while (k < tamLista(l)) {
		if (aux->relevancia == relevancia) {
			if (aux == l->cbc) {
				delistCbc(l);
				return; // caso especial: a pessoa está na cabeça
			}
			if (aux == l->cauda) {
				delistCauda(l);
				return; // caso especial: a pessoa está na cauda
			}
			aux->prox->ant = aux->ant;
			aux->ant->prox = aux->prox; // "ignorando" a pessoa a ser removida
			free(aux);
			aux = NULL; // liberação da pessoa
			(l -> tam)--;
			return;
		}
		aux = aux->prox; // o ponteiro anda 1 casa para a direita na lista
		k++;
	}
	printf("[-] A PESSOA NÃO EXISTE!\n");
}

void printLista(struct listaCirc *l) {
	if (listaVazia(l)) {
		printf("[-] LISTA VAZIA! IMPOSSÍVEL IMPRIMIR A LISTA\n");
		return;
	}
	struct pessoa *aux = l->cbc;
	do {
		printf("%c ", aux->id);
		aux = aux->prox;
	} while (aux != l->cbc); // impressão das pessoa da lista
	printf("\n");
}

void printAtrsPilha(struct pilha *p) {
	struct pessoa *aux = p->topo;
	for (int i = 0; i < tamPilha(p); i++) {
		printf("'%c': ", aux->id);
		for (int j = 0; j < MAX_ATR; j++)
			printf("%d ", aux->atr[j]); // impressão de cada atributo
		printf("\n");
		aux = aux->prox;
	}
}

void printAtrsLista(struct listaCirc *l) {
	struct pessoa *aux = l->cbc;
	for (int i = 0; i < tamLista(l); i++) {
		printf("'%c': ", aux->id);
		for (int j = 0; j < MAX_ATR; j++)
			printf("%d ", aux->atr[j]); // impressão de cada atributo
		printf("\n");
		aux = aux->prox;
	}
}

void printPilha(struct pilha *p) {
	if (pilhaVazia(p)) {
		printf("[-] PILHA VAZIA! IMPOSSÍVEL IMPRIMIR A PILHA\n");
		return;
	}
	struct pessoa *aux = p->topo;
	while (aux != NULL) {
		printf("%c ", aux->id);
		aux = aux->prox;
	} // impressão das pessoas da pilha 
	printf("\n");
}

void destroiPilha(struct pilha *p) {
	int aux[MAX_ATR];
	while (!pilhaVazia(p))
		pop(p, aux);
	free(p);
	p = NULL; // liberação das pessoas da pilha, assim como o espaço reservado a elas
}

void destroiLista(struct listaCirc *l) {
	while (!listaVazia(l))
		delistCbc(l);
	free(l);
	l = NULL; // liberação das pessoas da lista, assim como o espaço reservado a elas
}

int rolar1d20(int nDados) {
	int sum = 0;
	for (int i = 0; i < nDados; i++)
		sum += ((rand() % 20) + 1); // soma e definição do intervalo [1, 20] para o dado

	return sum; // retorna a soma dos valores dos dados
}

void troca(int v[], int a, int b) {
	int aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}

void insertionSort(struct pessoa *pers) {
	for (int i = 0; i < MAX_ATR; i++) {
		int k = i + 1;
		while (k > 0 && pers->atr[k] < pers->atr[k - 1]) {
			troca(pers->atr, k, k - 1);
			k--;
		}
	}
}

void iniciarMatch(struct listaCirc *listaConcorrentes, struct listaCirc *listaPretendentes, char idCand, int atrCandidato[], int *match, int *mismatch) {
	int vitoriasCandidato = 0, vitoriasPretendente = 0, totalAtrCandidato = 0, totalAtrPretendente = 0, pontosCandidato = 0, pontosPretendente = 0;
	struct pessoa *aux = listaConcorrentes->cbc;
	printf("[+] '%c' VAI CONCORRER AO MATCH!\n\n", aux->id);
	printf("-= INÍCIO DA DISPUTA CANDIDATO X PRETENDENTE =-\n\n");
	struct pessoa *conc = criaPessoa(aux->id, aux->atr[0], aux->atr[1], aux->atr[2],
						aux->atr[3], aux->atr[4], aux->atr[5]);
	delistCbc(listaConcorrentes);
	for (int i = 0; i < MAX_ATR; i++) {
		if (conc -> atr[i] == 1)
			totalAtrPretendente++;
		if (atrCandidato[i] == 1)
			totalAtrCandidato++;
	}
	for (int j = 0; j < 90; j++) {
		pontosCandidato = rolar1d20(totalAtrCandidato);
		pontosPretendente = rolar1d20(totalAtrPretendente);
		if (pontosCandidato >= pontosPretendente)
			vitoriasCandidato++;
		else
			vitoriasPretendente++;
	} // loop define a pontuação em cada iteração e incrementa as vitórias
	printf("-> VITÓRIAS DO CANDIDATO '%c': %d\n", idCand, vitoriasCandidato);
	printf("-> VITÓRIAS DO PRETENDENTE '%c': %d\n\n", conc->id, vitoriasPretendente);
	if (vitoriasCandidato >= vitoriasPretendente) {
		printf("[+] MATCH! PARABÉNS AO CASAL '%c' E '%c'!\n\n", idCand, conc->id);
		(*match)++;
		free(conc);
		conc = NULL; // liberação do ponteiro auxiliar para o concorrente
	} else {
		printf("[-] MISMATCH! SINTO MUITO '%c', MAS HOJE NÃO É SEU DIA DE SORTE!'%c' VOLTOU À LISTA DE PRETENDENTES.\n\n", idCand, conc->id);
		enlist(listaPretendentes, conc);
		(*mismatch)++; // candidato perdeu
	}
	printf("-= FIM DA DISPUTA CANDIDATO X PRETENDENTE =-\n\n");
}

void iniciarPareamento(struct pilha *pilhaCandidatos, struct listaCirc *listaPretendentes, struct listaCirc *listaConcorrentes, int *match, int *mismatch, int *noPair) {
	while (!pilhaVazia(pilhaCandidatos)) {
		printf("--= NOVO PAREAMENTO =--\n\n");
		int atrCandidato[MAX_ATR]; // vetor que salva os atributos do candidato
		char idCand = pilhaCandidatos->topo->id;
		pop(pilhaCandidatos, atrCandidato);
		struct pessoa *aux = listaPretendentes->cbc;
		int j = tamLista(listaPretendentes);
		for (int k = 0; k < j; k++) {
			int relevanciaPretendente = 0;
			for (int i = 0; i < MAX_ATR; i++)
				if (aux->atr[i] == 1 && atrCandidato[i] == 1)
					relevanciaPretendente++; // verifica atributos em comum
			aux->relevancia = relevanciaPretendente; // define a relevância do pretendente atual p/ o número de atributos em comum
			if (relevanciaPretendente > 1) {
				printf("[+] O PRETENDENTE '%c' TEM ALGUNS ATRIBUTOS EM COMUM COM O CANDIDATO '%c'! ELE VAI CONCORRER AO MATCH!\n\n", aux->id, idCand);
				struct pessoa *conc = criaPessoa(aux->id, aux->atr[0], aux->atr[1], aux->atr[2], 
									aux->atr[3], aux->atr[4], aux->atr[5]); 
				conc->relevancia = aux->relevancia; // vai ser usado nas disputas entre concorrentes
				aux = aux->prox;
        			delist(listaPretendentes, relevanciaPretendente);
				enlist(listaConcorrentes, conc); // tira da lista de pretendentes e coloca na de concorrentes
			} else {
				printf("[-] O PRETENDENTE '%c' NÃO COMBINOU COM O CANDIDATO '%c'! CONTINUA NA LISTA DE PRETENDENTES...\n\n", aux->id, idCand);
				aux = aux->prox;
			}
		}
		if (tamLista(listaConcorrentes) > 1) {
			printf("[=] EXISTE MAIS DE UM CONCORRENTE! ELES IRÃO DISPUTAR ENTRE SI PARA VER QUEM VAI TENTAR CONSEGUIR UM MATCH!\n\n");
			printf("-= INÍCIO DA DISPUTA ENTRE CONCORRENTES =-\n\n");
			int j = tamLista(listaConcorrentes), minRelevancia;
			aux = listaConcorrentes->cbc;
			for (int i = 0; i < j; i++) {
				aux->relevancia = rolar1d20(aux->relevancia);
				printf("-> PONTUAÇÃO DE '%c': %d\n", aux->id, aux->relevancia);
				aux = aux->prox;
			} // loop define a pontuação de cada concorrente
			printf("\n");
			for (int n = 0; n < j - 1; n++) {
				aux = listaConcorrentes->cbc->prox;
				minRelevancia = listaConcorrentes->cbc->relevancia;
				for (int k = 0; k < j - 1; k++) {
					if (aux->relevancia <= minRelevancia)
						minRelevancia = aux->relevancia;
					aux = aux->prox;
				} // acha a pessoa com menor relevância dentre os concorrentes
				aux = listaConcorrentes->cbc;
				int achouMenor = 0;
				while (!achouMenor) {
					if (aux->relevancia == minRelevancia)
						achouMenor = 1;
					aux = aux->prox;
					if (achouMenor)
						aux = aux->ant;
				} // coloca o ptr. auxiliar na pessoa com menor relevância
				struct pessoa *perdedor = criaPessoa(aux->id, aux->atr[0], aux->atr[1], aux->atr[2], 
									aux->atr[3], aux->atr[4], aux->atr[5]);
				delist(listaConcorrentes, minRelevancia); // delistagem da pessoa com menor relevância
				enlist(listaPretendentes, perdedor); // coloca a pessoa com menor relevância na lista de pretendentes
			}
			// a lista de concorrentes só tem uma pessoa
			iniciarMatch(listaConcorrentes, listaPretendentes, idCand, atrCandidato, match, mismatch);
		} else if (tamLista(listaConcorrentes) == 1) {
			iniciarMatch(listaConcorrentes, listaPretendentes, idCand, atrCandidato, match, mismatch);
		} else {
			printf("[-] QUE PENA, NENHUM DOS PRETENDENTES COMBINOU COM O CANDIDATO... TCHAU, '%c'!\n\n", idCand);
			(*noPair)++; // candidato sem par
		}
		printf("--= FIM DO PAREAMENTO =--\n\n");
	}
	(*noPair) += tamLista(listaPretendentes);
}
