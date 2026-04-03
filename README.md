# 💡 Sistema de Iluminação — Trabalho Final

> Sistema de simulação e gestão de iluminação pública desenvolvido em **C**, com suporte a grafos, algoritmos de caminho mínimo e árvore geradora mínima.

---

## 📋 Descrição

Este projeto implementa um sistema de simulação de iluminação pública baseado em grafos. Permite gerir utilizadores, carregar localidades a partir de ficheiros, e realizar operações avançadas sobre a rede de postes e ruas, como encontrar a melhor ligação entre postes, calcular o custo total de iluminação e obter a solução mais eficiente (MST).

---

## 🗂️ Estrutura do Projeto

```
.
├── main.c           # Ponto de entrada do programa e interface de menus
├── sistema.c        # Implementação de todas as funções
├── sistema.h        # Definições de estruturas e declarações de funções
├── ficheiro.txt     # Localidade de exemplo com 8 postes e 18 ruas
├── ficheiro1.txt    # Localidade de exemplo com 6 postes e 18 ruas
├── ficheiro2.txt    # Localidade de exemplo com 7 postes e 18 ruas
└── ficheiro3.txt    # Localidade de exemplo com 8 postes e 25 ruas
```

---

## ⚙️ Funcionalidades

### 👤 Gestão de Utilizadores
- Adicionar utilizador (nome, senha e ficheiro associado)
- Autenticar utilizador
- Listar todos os utilizadores registados
- Remover utilizador

### 🗺️ Simulação de Iluminação
| Opção | Descrição |
|-------|-----------|
| Criar Localidade | Carrega uma localidade a partir de um ficheiro `.txt` |
| Adicionar Poste | Insere um novo poste na rede |
| Remover Poste | Remove um poste e as suas ligações |
| Adicionar Rua | Cria uma ligação entre dois postes com distância definida |
| Eliminar Rua | Remove a ligação entre dois postes |
| Atualizar Distância | Modifica a distância entre dois postes existentes |
| Melhor Ligação | Algoritmo de **Dijkstra** para encontrar o caminho mais curto |
| Iluminação Total | Lista todas as ligações e calcula o custo total |
| Melhor Solução | Algoritmo de **Kruskal** (MST) para minimizar o custo de iluminação |
| Iluminar Adjacentes | Ilumina todas as ruas adjacentes a um poste |
| Destruir Simulação | Liberta a memória e reinicia a simulação |

---

## 📄 Formato dos Ficheiros de Localidade

Os ficheiros de entrada seguem o seguinte formato:

```
<nº de postes> <nº de ruas>
<poste origem> <poste destino> <distância>
...
0 0
```

**Exemplo (`ficheiro.txt`):**
```
8 18
1 2 8
1 3 9
1 4 7
...
0 0
```

---

## 🔬 Algoritmos Implementados

### Dijkstra — Melhor Ligação
Encontra o caminho de menor custo entre dois postes. O resultado inclui o trajeto completo e o custo em **Kwanzas (KZ)**.

### Kruskal — Melhor Solução (MST)
Calcula a **Árvore Geradora Mínima** do grafo, determinando a solução de iluminação com menor custo total, e mostra quanto é poupado em relação à iluminação de todas as ligações.

---

## 🛠️ Compilação e Execução

### Pré-requisitos
- Compilador C (GCC recomendado)
- Sistema operativo Windows (usa `system("pause")`) ou adaptação para Linux/macOS

### Compilar

```bash
gcc main.c -o sistema_iluminacao
```

### Executar

```bash
./sistema_iluminacao
```

> ⚠️ Os ficheiros `.txt` devem estar na **mesma pasta** que o executável.

---

## 🚀 Como Usar

1. Execute o programa.
2. No menu principal, selecione **1. Entrar na Simulação**.
3. **Adicione um utilizador** com nome, senha e o nome do ficheiro de localidade (ex: `ficheiro`).
4. **Autentique-se** com as credenciais criadas.
5. Dentro da simulação, selecione **1. Criar Localidade** para carregar o grafo.
6. Explore as restantes opções de gestão e análise da rede.

---

## 📊 Representação Interna

O grafo é representado com uma **lista de adjacência**:

```
Poste 1: -> 2 (Dist: 8) -> 3 (Dist: 9) -> 4 (Dist: 7)
Poste 2: -> 3 (Dist: 8) -> 5 (Dist: 11) -> 6 (Dist: 5)
...
```

Cada rua (aresta) contém:
- **Destino** — índice do poste de chegada
- **Distância** — peso em metros
- **Iluminada** — estado de iluminação (`0` = Não, `1` = Sim)

---

## 👨‍💻 Tecnologias

- **Linguagem:** C (C99/C11)
- **Estruturas de dados:** Lista ligada, Lista de adjacência, Arrays dinâmicos
- **Algoritmos:** Dijkstra, Kruskal, Union-Find
- **Gestão de memória:** `malloc`, `realloc`, `free`

---

## 📝 Notas

- O custo de iluminação é calculado com base na distância multiplicada por **1600 KZ/metro**.
- A função `system("pause")` é específica para Windows — em Linux/macOS pode ser substituída por `getchar()`.
- O programa suporta localidades de qualquer dimensão, limitadas apenas pela memória disponível.