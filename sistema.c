//
// Created by hp on 19/06/2024.
//
#include "sistema.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//---------------------------- Funções para a Gestão de Utilizadores -----------------------------------

Utilizador * criar_lista (){
	return NULL;
}
Utilizador* adicionar_utilizador(Utilizador *listaUtilizadores, const char *nome, const char *senha, const char *nomeFicheiro) {
    Utilizador *novoUtilizador = (Utilizador *)malloc(sizeof(Utilizador));
    if (!novoUtilizador) {
        printf("Erro ao alocar memória para o novo utilizador.\n");
        return NULL;  
    }else{
    	strcpy(novoUtilizador->nome, nome);
    	strcpy(novoUtilizador->senha, senha);
    	strcpy(novoUtilizador->nomeFicheiro, nomeFicheiro);
    	novoUtilizador->prox = listaUtilizadores;

    	printf("Utilizador '%s' adicionado com sucesso.\n", nome);
    	return novoUtilizador;  	
	}

    
}

int autenticar_utilizador(Utilizador *listaUtilizadores, const char *nome, const char *senha) {
    Utilizador *atual = listaUtilizadores;
    while (atual) {
        if (strcmp(atual->nome, nome) == 0 && strcmp(atual->senha, senha) == 0) {
            printf("Utilizador '%s' autenticado com sucesso.\n", nome);

            // Adiciona a extensão ".txt" ao nome do arquivo se ainda não estiver presente
            char nomeFicheiroCompleto[50]; 
            if (strstr(atual->nomeFicheiro, ".txt") == NULL) {
                sprintf(nomeFicheiroCompleto, "%s.txt", atual->nomeFicheiro);
            } else {
                strcpy(nomeFicheiroCompleto, atual->nomeFicheiro);
            }

            // Verifica se o arquivo associado ao utilizador existe
            FILE *ficheiro = fopen(nomeFicheiroCompleto, "r");
            if (ficheiro) {
                fclose(ficheiro);
                printf("Ficheiro '%s' encontrado.\n", nomeFicheiroCompleto);
                return 1; 
            } else {
                printf("Ficheiro '%s' não encontrado.\n", nomeFicheiroCompleto);
                return 0;  
            }

            
        }
        atual = atual->prox;
    }
    printf("Falha na autenticação do utilizador '%s'.\n", nome);
    return 0; 
}

Utilizador* remover_utilizador(Utilizador *listaUtilizadores, const char *nome) {
    Utilizador * aux = listaUtilizadores;
    Utilizador * aux2 = NULL;

    while (aux) {
        if (strcmp(aux->nome, nome) == 0) {
            if (aux2) {
                aux2->prox = aux->prox;
            } else {
                listaUtilizadores = aux->prox;
            }
            free(aux);
            printf("\nUtilizador '%s' removido com sucesso.\n\n", nome);
            return listaUtilizadores; 
        }
        aux2 = aux;
        aux = aux->prox;
    }
    printf("\nUtilizador '%s' não encontrado.\n\n", nome);
    return NULL;  
}

void listar_utilizadores(Utilizador *listaUtilizadores) {
    Utilizador * aux = listaUtilizadores;
    if(aux != NULL){
    	while (aux) {
        printf("Utilizador: %s, Ficheiro: %s\n\n", aux->nome, aux->nomeFicheiro);
        aux = aux->prox;
    	}	
	}else{
		printf("Não há ultilizadores registrados. \n\n");
	}
    
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

const char* pesquisar_nome_ficheiro(Utilizador *listaUtilizadores, const char *nomeUtilizador) {
    Utilizador *atual = listaUtilizadores;

    while (atual != NULL) {
        if (strcmp(atual->nome, nomeUtilizador) == 0) {
            
            char *nomeFicheiroCompleto = (char *) malloc(50 * sizeof(char)); 
            if (nomeFicheiroCompleto == NULL) {
                printf("Erro ao alocar memória para nomeFicheiroCompleto.\n");
                return NULL;
            }

            // Adiciona a extensão ".txt" ao nome do arquivo se ainda não estiver presente
            if (strstr(atual->nomeFicheiro, ".txt") == NULL) {
                sprintf(nomeFicheiroCompleto, "%s.txt", atual->nomeFicheiro);
            } else {
                strcpy(nomeFicheiroCompleto, atual->nomeFicheiro);
            }

            return nomeFicheiroCompleto;
        }
        atual = atual->prox;
    }

    return NULL;
}


//---------------------------- Funções para a Simulação -----------------------------------


Grafo * criar_grafo(){
	return NULL;
}
// Função para criar uma localidade 

Grafo* criar_localidade(int numPostes) {
    Grafo *novo = (Grafo*)malloc(sizeof(Grafo));

    if (!novo) {
        printf("Erro na alocação de memória.\n");
        return NULL;
    }

    novo->poste = numPostes;
    novo->prox = (noLista*)malloc(numPostes * sizeof(noLista));

    // Inicializando a nossa lista de Adjacência
    for (int count = 0; count < numPostes; count++) {
        novo->prox[count].rotulo = NULL;
    }
    return novo;
}

// Função para adicionar uma nova rua ao grafo
Grafo* adicionar_nova_rua(Grafo* grafo, int inicio, int destino, int distancia) {
    if (grafo == NULL) {
        printf("Erro de Alocação.\n");
        return NULL;
    }

    Aresta *novaRua = (Aresta*)malloc(sizeof(Aresta));
    if (!novaRua) {
        printf("Erro na alocação de memória.\n");
        return NULL;
    }else{
    	novaRua->destino = destino;
    	novaRua->distancia = distancia;
    	novaRua->iluminada = 0;
    	novaRua->prox = grafo->prox[inicio].rotulo;
    	grafo->prox[inicio].rotulo = novaRua;
    	
	
    	return grafo;
	}

    
}


// Função para imprimir o grafo
void imprimir(Grafo* grafo) {
    if (grafo == NULL) {
        printf("Grafo não inicializado.\n");
        
    }else{
    	for (int count = 0; count < grafo->poste; count++) {
       		Aresta* aux = grafo->prox[count].rotulo;
       	 	printf("Poste %d: ", count + 1);
       		while (aux) {
            	printf(" -> %d (Distância: %d) ", aux->destino + 1, aux->distancia);
           		aux = aux->prox;
        	}
        printf("\n");
    }	
	}

  
}

// Função para adicionar um novo poste ao grafo
Grafo* adicionar_novo_poste(Grafo *grafo) {
    if (grafo == NULL) {
        printf("Grafo não inicializado.\n");
        return grafo;
    }

    int numPostes = grafo->poste + 1;

    // Realocar a memória para a nova lista de adjacência
    noLista *novaLista = (noLista*)realloc(grafo->prox, numPostes * sizeof(noLista));
    if (novaLista == NULL) {
        printf("Erro na realocação de memória.\n");
        return grafo;
    }

    grafo->prox = novaLista;
    grafo->prox[numPostes - 1].rotulo = NULL;
    grafo->poste = numPostes;

    printf("\n\nPoste %d adicionado com sucesso. Total de postes: %d\n\n\n", numPostes, grafo->poste);
    return grafo;
}


// Função para remover um Poste
Grafo* remover_poste(Grafo *grafo, int poste) {
    if (grafo == NULL || poste < 0 || poste >= grafo->poste) {
        printf("Poste inválido.\n");
        return grafo;
    }

    // Libera todas as ruas do poste a ser removido
    Aresta *aux = grafo->prox[poste].rotulo;
    Aresta *aux2 = NULL;

    while (aux != NULL) {
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }

    // Remove o poste ajustando a lista de adjacência
    grafo->prox[poste].rotulo = NULL;

    for (int i = poste; i < grafo->poste - 1; i++) {
        grafo->prox[i] = grafo->prox[i + 1];
    }
    
    grafo->poste--;

    noLista *novaLista = (noLista*)realloc(grafo->prox, grafo->poste * sizeof(noLista));
    if (novaLista == NULL && grafo->poste > 0) {
        printf("Erro na realocação da memória.\n");
        return grafo;
    }

    grafo->prox = novaLista;

    printf("Poste %d removido com sucesso.\n", poste + 1);
    return grafo;
}

// Função para remover uma Rua
Grafo* eliminar_rua(Grafo *grafo, int inicio, int destino) {
    if (grafo == NULL || inicio < 0 || inicio >= grafo->poste || destino < 0 || destino >= grafo->poste) {
        printf("Postes inválidos.\n");
        return grafo;
    }

    // Procura a rua que deve ser removida
    Aresta *aux = grafo->prox[inicio].rotulo;
    Aresta *aux2 = NULL;

    while (aux != NULL && aux->destino != destino) {
        aux2 = aux;
        aux = aux->prox;
    }

    // Se não encontrou a rua
    if (aux == NULL) {
        printf("Rua entre o poste %d e o poste %d não encontrada.\n", inicio + 1, destino + 1);
        return grafo;
    }

    // Remove a rua da lista de adjacência
    if (aux2 == NULL) {
        // A rua a ser removida é a primeira da lista
        grafo->prox[inicio].rotulo = aux->prox;
    } else {
        aux2->prox = aux->prox;
    }

    free(aux);
    printf("Rua entre o poste %d e o poste %d removida com sucesso.\n", inicio + 1, destino + 1);

    // Verifica se o poste destino ficou sem ligações e remove se necessário
    if (!exite_rua(grafo, destino)) {
        grafo = remover_poste(grafo, destino);
    }

    return grafo;
}

// Função para verificar se existe uma rua
int exite_rua(Grafo *grafo, int poste) {
    if (grafo == NULL || poste < 0 || poste >= grafo->poste) {
        return 0;
    }

    // Verifica se há pelo menos uma rua na lista de adjacência do poste
    return (grafo->prox[poste].rotulo != NULL);
}


void destruir_simulacao(Grafo **grafo, int *numPoste) {
    if (*grafo == NULL) {
        printf("\nGrafo não inicializado. Nada a destruir.\n");
        return;
    }

    // Liberar memória das ruas  de cada poste 
    for (int count = 0; count < (*grafo)->poste; ++count) {
        Aresta *aux = (*grafo)->prox[count].rotulo;
        while (aux) {
            Aresta *temp = aux;
            aux = aux->prox;
            free(temp);
        }
    }

    // Liberar memória das listas de adjacência
    free((*grafo)->prox);

    // Liberar memória da lista de postes 
    free(*grafo);

    // Resetar o ponteiro de grafo para NULL
    *grafo = NULL;

    // Resetar o número de poste para 0
    *numPoste = 0;

    printf("\nSimulação destruída com sucesso.\n");
}


// Função para atualizar a distância entre dois postes
void atualizar_distancia(Grafo *grafo, int poste_origem, int poste_destino, int nova_distancia) {
    Aresta *aux = grafo->prox[poste_origem].rotulo;

    // Percorre a lista de adjacência do poste_origem procurando pela aresta para o poste_destino
    while (aux) {
        if (aux->destino == poste_destino) {
            aux->distancia = nova_distancia; // Atualiza a distância
            printf("Distância entre o poste %d e o poste %d atualizada para %d.\n", poste_origem + 1, poste_destino + 1, nova_distancia);
            return;
        }
        aux = aux->prox;
    }

    // Se não encontrou a aresta
    printf("Rua entre o poste %d e o poste %d não encontrada.\n", poste_origem + 1, poste_destino + 1);
}
// Função para encontrar a melhor ligação entre dois postes
void melhor_Ligacao(Grafo* grafo, int origem, int destino) {
	
    if (grafo == NULL || origem < 0 || origem >= grafo->poste || destino < 0 || destino >= grafo->poste) {
        
		printf("Postes inválidos.\n");
        
    }else{
  	
	int distancia[grafo->poste];
    int visitado[grafo->poste];
    int anterior[grafo->poste];
    
    
    for (int count = 0; count < grafo->poste; count++) {
        distancia[count] = INT_MAX;
        visitado[count] = 0;
        anterior[count] = -1;
    }

    distancia[origem] = 0;

    // Algoritmo de Dijkstra
    for (int count = 0; count < grafo->poste - 1; count++) {
        int minDist = INT_MAX;
        int counter1 = -1;

        // Encontrar o vértice com a menor distância
        for (int counter = 0; counter < grafo->poste; counter++) {
            if (!visitado[counter] && distancia[counter] < minDist) {
                minDist = distancia[counter];
                counter1 = counter;
            }
        }

        if (counter1 == -1) {
            break; // Nenhum vértice acessível encontrado
        }

        visitado[counter1] = 1;

        // Atualizar distâncias dos vértices adjacentes
        Aresta * aux = grafo->prox[counter1].rotulo;
        
        while (aux != NULL) {
            int counter2 = aux->destino;
            int peso = aux->distancia;

            if (!visitado[counter2] && distancia[counter1] != INT_MAX && distancia[counter1] + peso < distancia[counter2]) {
                distancia[counter2] = distancia[counter1] + peso;
                anterior[counter2] = counter1;
            }

            aux = aux->prox;
        }
    }

    // Verificar se há caminho até o destino
    if (distancia[destino] == INT_MAX) {
        printf("\nNão existe caminho entre os postes %d e %d.\n", origem + 1, destino + 1);
        return;
    }

    // Construir o caminho mais curto
    int caminho[grafo->poste];
    int comprimento = 0;
    int atual = destino;

    while (atual != -1) {
        caminho[comprimento++] = atual;
        atual = anterior[atual];
    }

    // Imprimir o caminho mais curto e a distância
    printf("O caminho mais curto entre os postes %d e %d é: ", origem + 1, destino + 1);
    for (int count = comprimento - 1; count >= 0; count--) {
        printf("%d ", caminho[count] + 1);
        if (count > 0) {
            printf("-> ");
        }
    }
    
    printf("\nCusto total: %d KZ\n", distancia[destino]*1600);
	}

   
}

void iluminar_ruas_adjacentes(Grafo *grafo, int poste){
	if(grafo == NULL || poste < 0 || poste >= grafo->poste){
		printf("\nPoste inválido. \n");
	}else{
		
		Aresta * aux = grafo->prox[poste].rotulo;
		while(aux != NULL){
			aux->iluminada = 1;
			aux = aux->prox;
		}
		printf("\nTodas as ruas adjacentes ao poste %d foram iluminadas. \n", poste + 1);
	}
}

// Função de comparação para qsort
int compare(const void *a, const void *b) {
    ArestaAux *arestaA = (ArestaAux *)a;
    ArestaAux *arestaB = (ArestaAux *)b;
    return arestaA->distancia - arestaB->distancia;
}

// Função para encontrar o representante do conjunto
int procurar(GrupoDePostes grupodeposte[], int i) {
    if (grupodeposte[i].pai != i) {
        grupodeposte[i].pai = procurar(grupodeposte, grupodeposte[i].pai);
    }
    return grupodeposte[i].pai;
}

// Função para unir dois conjuntos
void uniao_de_postes(GrupoDePostes grupodeposte[], int x, int y) {
    int raizX = procurar(grupodeposte, x);
    int raizY = procurar(grupodeposte, y);

    if (grupodeposte[raizX].profundidade < grupodeposte[raizY].profundidade) {
        grupodeposte[raizX].pai = raizY;
    } else if (grupodeposte[raizX].profundidade > grupodeposte[raizY].profundidade) {
        grupodeposte[raizY].pai = raizX;
    } else {
        grupodeposte[raizY].pai = raizX;
        grupodeposte[raizX].profundidade++;
    }
}

// Função para calcular o custo total das arestas iluminadas
int calcularCustoTotalArestasIluminadas(Grafo *grafo) {
    int total = 0;
    for (int count = 0; count < grafo->poste; count++) {
        Aresta *aux = grafo->prox[count].rotulo;
        while (aux) {
            total += aux->distancia * 1600;
            aux = aux->prox;
        }
    }
    return total / 2; // Cada aresta é contada duas vezes
}

// Função para encontrar a melhor solução de iluminação (MST)
void melhor_solucao(Grafo *grafo) {
    if (grafo == NULL) {
        printf("Grafo não inicializado.\n");
        return;
    }

    int numPostes = grafo->poste;
    ArestaAux *arestas = NULL;
    int numArestas = 0;

    // Contar o número de arestas no grafo
    for (int count = 0; count < numPostes; count++) {
        Aresta *aux = grafo->prox[count].rotulo;
        while (aux) {
            numArestas++;
            aux = aux->prox;
        }
    }

    // Alocar memória para as arestas
    arestas = (ArestaAux *)malloc(numArestas * sizeof(ArestaAux));
    if (arestas == NULL) {
        printf("Erro ao alocar memória para as arestas.\n");
        return;
    }

    // Preencher o array de arestas
    int index = 0;
    for (int count = 0; count < numPostes; count++) {
        Aresta *aux = grafo->prox[count].rotulo;
        while (aux) {
            arestas[index].origem = count;
            arestas[index].destino = aux->destino;
            arestas[index].distancia = aux->distancia;
            index++;
            aux = aux->prox;
        }
    }

    // Ordenar as arestas pela distância
    qsort(arestas, numArestas, sizeof(ArestaAux), compare);

    // Inicializar GrupoDePostes
    GrupoDePostes *grupodeposte = (GrupoDePostes *)malloc(numPostes * sizeof(GrupoDePostes));
    if (grupodeposte == NULL) {
        printf("Erro ao alocar memória para os grupodeposte.\n");
        free(arestas);
        return;
    }

    for (int count = 0; count < numPostes; count++) {
        grupodeposte[count].pai = count;
        grupodeposte[count].profundidade = 0;
    }

    // Construir a MST
    ArestaAux *mst = (ArestaAux *)malloc((numPostes - 1) * sizeof(ArestaAux));
    if (mst == NULL) {
        printf("Erro ao alocar memória para a MST.\n");
        free(arestas);
        free(grupodeposte);
        return;
    }
    int mstIndex = 0;
    int count = 0;
    while (mstIndex < numPostes - 1 && count < numArestas) {
        ArestaAux margem = arestas[count++];

        int rotaX = procurar(grupodeposte, margem.origem);
        int rotaY = procurar(grupodeposte, margem.destino);

        if (rotaX != rotaY) {
            mst[mstIndex++] = margem;
            uniao_de_postes(grupodeposte, rotaX, rotaY);
        }
    }

    // Imprimir a MST e calcular o custo total
    int custoTotal = 0;
    printf("A melhor solução de iluminação  é:\n");
    for (int count = 0; count < mstIndex; count++) {
        printf("%d -> %d (Distância: %d)\n", mst[count].origem + 1, mst[count].destino + 1, mst[count].distancia);
        custoTotal += mst[count].distancia;
    }

    printf("Custo total: %d KZ\n", custoTotal * 1600);
    printf("Quantidade poupada: %d KZ\n", calcularCustoTotalArestasIluminadas(grafo) - custoTotal * 1600);

    free(arestas);
    free(grupodeposte);
    free(mst);
}
// Função para Imprime todas as ligações possíveis e custo total da ligação
void iluminacao_total(Grafo *grafo) {
    if (grafo == NULL) {
        printf("Grafo não inicializado.\n");
        return;
    }

    int custoTotal = 0;
    int numPostes = grafo->poste;

    printf("Todas as ligações possíveis:\n");
    for (int i = 0; i < numPostes; i++) {
        Aresta *aux = grafo->prox[i].rotulo;
        while (aux) {
            printf("Poste %d -> Poste %d (Distância: %d metros, Iluminada: %s)\n", 
        i + 1, aux->destino + 1, aux->distancia, aux->iluminada == 1 ? "Sim" : "Não");
            custoTotal += aux->distancia * 1600; // Somar o custo desta aresta
            aux = aux->prox;
        }
    }

	printf("\nCusto total de todos as ligações: %d Kz \n", custoTotal);
}


// Função para ler dados de um ficheiro
void ler_ficheiro(const char *nome_ficheiro, Grafo **grafo, int *numPoste) {
    
	FILE * ficheiro = fopen(nome_ficheiro, "r");
    if (ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        
    }else{
    	int numRuas;
    	fscanf(ficheiro, "%d %d", numPoste, &numRuas);

    	*grafo = criar_localidade(*numPoste);

    	int inicio, fim, distancia;
    	
    	for (int count = 0; count < numRuas; count++) {
        	fscanf(ficheiro, "%d %d %d", &inicio, &fim, &distancia);
        	adicionar_nova_rua(*grafo, inicio - 1, fim - 1, distancia);
    	}

   		fclose(ficheiro);
	}

    
}
