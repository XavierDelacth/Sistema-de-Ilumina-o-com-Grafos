//
// Created by hp on 18/06/2024.
//
#ifndef SISTEMA_H
#define SISTEMA_H

//---------------------------- Estrutura para a Gestão de Utilizadores -----------------------------------

typedef struct Utilizador {
    char nome[50];
    char senha[50];
    char nomeFicheiro[100];  
    struct Utilizador * prox;
} Utilizador;


Utilizador * criar_lista ();  // check
Utilizador* adicionar_utilizador(Utilizador *listaUtilizadores, const char *nome, const char *senha, const char *nomeFicheiro); // check
int autenticar_utilizador(Utilizador *listaUtilizadores, const char *nome, const char *senha); // check
Utilizador* remover_utilizador(Utilizador *listaUtilizadores, const char *nome); // check
void listar_utilizadores(Utilizador *listaUtilizadores); // check
char* pesquisar_nome_ficheiro(Utilizador *listaUtilizadores, const char *nomeUtilizador);// check


//---------------------------- Estrutura para a Simulação -----------------------------------

// Estrutura para uma rua na lista de adjacência
typedef struct aresta {
    int destino;
    int distancia;
    int iluminada;
    struct aresta* prox;
} Aresta;

// Estrutura para representar um poste na lista de adjacência
typedef struct no_lista {
    Aresta* rotulo;
} noLista;

// Estrutura para representar o grafo
typedef struct grafo {
    int poste;
    noLista * prox;
} Grafo;


// Início das funções:

Grafo * criar_grafo();// check
Grafo* criar_localidade(int numPostes); // check
Grafo* adicionar_nova_rua(Grafo* grafo, int inicio, int destino, int distancia);// check
Grafo* adicionar_novo_poste(Grafo *grafo); // check
Grafo* remover_poste(Grafo *grafo, int poste);// check
Grafo* eliminar_rua(Grafo *grafo, int inicio, int destino);
void destruir_simulacao(Grafo **grafo, int *numPoste);// check
void atualizar_distancia(Grafo *grafo, int poste_origem, int poste_destino, int nova_distancia);// check
void melhor_Ligacao(Grafo* grafo, int origem, int destino);// check
void iluminar_ruas_adjacentes(Grafo *grafo, int poste);// check
int exite_rua(Grafo *grafo, int poste);// check
void iluminacao_total(Grafo *grafo);

// Melhor solução

// Estrutura auxiliar para armazenar ruas com origem
typedef struct aresta_aux {
    int origem;
    int destino;
    int distancia;
    int iluminada;
} ArestaAux;

typedef struct grupodeposte{
    int pai;
    int profundidade;
} GrupoDePostes;

void melhor_solucao(Grafo *grafo);
int procurar(GrupoDePostes grupodeposte[], int count);
void uniao_de_postes(GrupoDePostes grupodeposte[], int counter1, int counter2);
int compare(const void * a, const void* b);
int calcularCustoTotalTodasRuas(Grafo *grafo);

void imprimir(Grafo* grafo); // check
void ler_ficheiro(const char *nome_ficheiro, Grafo **grafo, int *numPoste); // check

void limpar_buffer();

#endif // SISTEMA_H
