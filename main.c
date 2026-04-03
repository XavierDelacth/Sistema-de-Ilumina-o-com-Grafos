#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "sistema.c"


int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	
	
	while(1){
		printf("\n------------------------------------ Seja Bem-vindo ao nosso Sistema de Iluminação -----------------------------------\n");
		printf("1. Entrar na Simulação\n");
		printf("2. Ajuda\n");
		printf("3. Sair\n");
		
		int escolhaEntrada;
        char linhaEntrada[100]; 
        printf("Escolha uma opção: ");
        
        // Lê a linha de entrada usando fgets
        if (fgets(linhaEntrada, sizeof(linhaEntrada), stdin)) {
        	
            // Converte a entrada para um número inteiro
            if (sscanf(linhaEntrada, "%d", &escolhaEntrada) != 1) {
                printf("Opção inválida. Tente novamente.\n");
                limpar_buffer();  
                continue;  
            }
            
            switch (escolhaEntrada){
            	
            	case 1:{
				    Utilizador * listaUtilizadores = criar_lista();
				    int autenticado = 0;
					int escolha; 
				    do{
				    	
				        printf("\n-------------------------------------------- Gestão de Utilizadores ---------------------------------------------------\n");
				        printf("1. Adicionar Utilizador\n");
				        printf("2. Autenticar Utilizador\n");
				        printf("3. Listar Utilizadores\n");
				        printf("4. Remover Utilizador\n");
				        printf("5. Sair\n");
				
				        
				        char linha[100]; 
				        printf("Escolha uma opção: ");
				        
				        // Lê a linha de entrada usando fgets
				        if (fgets(linha, sizeof(linha), stdin)) {
				        	
				            // Converte a entrada para um número inteiro
				            if (sscanf(linha, "%d", &escolha) != 1) {
				                printf("Opção inválida. Tente novamente.\n");
				                			                  
				            }else{
				            	if(escolha < 1 || escolha > 5){
				            	printf("Opção inválida. Tente novamente.\n");
				                 
							}else{
								if( escolha == 1){
									printf("\n\n------------------------------------------------- Adicionar Utilizador ------------------------------------------------\n\n");
									char nome[50], senha[50], nomeFicheiro[100];
				                    
				                    printf("Nome de utilizador: ");
				                    fgets(nome, sizeof(nome), stdin);
				                    nome[strcspn(nome, "\n")] = '\0';  // Remove o caractere de nova linha
				                    
				                    printf("Senha: ");
				                    fgets(senha, sizeof(senha), stdin);
				                    senha[strcspn(senha, "\n")] = '\0'; 
				                    
				                    printf("Nome do ficheiro: ");
				                    fgets(nomeFicheiro, sizeof(nomeFicheiro), stdin);
				                    nomeFicheiro[strcspn(nomeFicheiro, "\n")] = '\0';  
				                    
				                    listaUtilizadores = adicionar_utilizador(listaUtilizadores, nome, senha, nomeFicheiro);
				                    system("pause");
								}
								if( escolha == 2){
									printf("\n\n------------------------------------------------ Autenticar Utilizador -------------------------------------------------\n\n");
									 char nome[50], senha[50];
				                    
				                    printf("Nome de utilizador: ");
				                    fgets(nome, sizeof(nome), stdin);
				                    nome[strcspn(nome, "\n")] = '\0';  
				                   
								    printf("Senha: ");
				                    fgets(senha, sizeof(senha), stdin);
				                    senha[strcspn(senha, "\n")] = '\0';  
				                    
				                    autenticado = autenticar_utilizador(listaUtilizadores, nome, senha);
				                    if(autenticado == 1){
				                    	   
				                    	     Grafo * grafo = NULL;
				    						 int numPostes = 0;
				   							 int opcao;
										   
										    do {
											        printf("\n\n------------------------------------------------------ Simulador ------------------------------------------------------\n\n");
											        printf("1. Criar Localidade \n");
											        printf("2. Adicionar Novo Poste\n");
											        printf("3. Remover Poste\n");
											        printf("4. Adicionar Nova Rua\n");
											        printf("5. Eliminar Rua\n");
											        printf("6. Atualizar Distância Entre Dois Postes\n");
											        printf("7. Melhor Ligação Entre Dois Postes\n");
											        printf("8. Iluminação Total\n");
											        printf("9. Melhor Solução\n");
											        printf("10. Iluminar Ruas Adjacentes\n");
											        printf("11. Destruir a Simulação\n");
											        printf("12. Sair\n");
											        printf("Escolha uma opção: ");
											        
											        if (scanf("%d", &opcao) != 1) {
											            printf("Opção inválida.\n");
											            limpar_buffer();
											            continue;
											        }
											
											        switch (opcao) {
											            case 1:
											            	printf("\n\n--------------------------------------------------- Criar Localidade ---------------------------------------------------\n\n");
											                if (grafo) {
				                    							printf("Localidade já criada.\n");
				                    							system("pause");
				               								 } else {
											                    char nome_ficheiro[100];
											                    
											                    strcpy(nome_ficheiro, pesquisar_nome_ficheiro(listaUtilizadores, nome));
											                    ler_ficheiro(nome_ficheiro, &grafo, &numPostes);
											                    if (!grafo) {
											                        printf("\nFalha ao criar a localidade a partir do ficheiro.\n");
											                       	system("pause");
											                    }else{
											                    	printf("Localidade criada com sucesso.\n");
											                    	system("pause");
																	}
											                    
											                }
											                break;
											            case 2:
											            		printf("\n\n------------------------------------------------- Adicionar Novo Poste -------------------------------------------------\n\n");
											                    adicionar_novo_poste(grafo);
											                    system("pause");
											                break;
											            case 3:
											            	printf("\n\n---------------------------------------------------- Remover Poste ------------------------------------------------------\n\n");
											                if (grafo) {
											                    int poste;
											                    printf("Informe o poste a ser removido: ");
											                    if (scanf("%d", &poste) != 1 || poste < 1 || poste > grafo->poste) {
											                        printf("Poste inválido.\n");
											                        limpar_buffer();
											                        system("pause");
											                        break;
											                    }
											                    remover_poste(grafo, poste - 1);
											                    system("pause");
											                } else {
											                    printf("Grafo não inicializado.\n");
											                    system("pause");
											                }
											                break;
											            case 4:
											            	printf("\n\n------------------------------------------------- Adicionar Nova Rua ----------------------------------------------------\n\n");
											                if (grafo) {
											                    int inicio, destino, distancia;
											                    printf("Informe o poste de início, destino e a distância: ");
											                    if (scanf("%d %d %d", &inicio, &destino, &distancia) != 3) {
											                        printf("Dados inválidos.\n");
											                        limpar_buffer();
											                        system("pause");
											                        break;
											                    }
											                    adicionar_nova_rua(grafo, inicio - 1, destino - 1, distancia);
											                    system("pause");
											                } else {
											                    printf("Grafo não inicializado.\n");
											                    system("pause");
											                }
											                break;
											            case 5:
											            	printf("\n\n---------------------------------------------------- Eliminar Rua ------------------------------------------------------\n\n");
											                if (grafo) {
											                    int inicio, destino;
											                    printf("\nInforme o poste de início e destino para eliminar a rua: ");
											                    if (scanf("%d %d", &inicio, &destino) != 2) {
											                        printf("\nDados inválidos.\n");
											                        limpar_buffer();
											                        system("pause");
											                        break;
											                    }
											                    eliminar_rua(grafo, inicio - 1, destino - 1);
											                    system("pause");
											                } else {
											                    printf("\nGrafo não inicializado.\n");
											                    system("pause");
											                }
											                break;
											            case 6:
											            	printf("\n\n------------------------------------------ Atualizar Distância Entre Dois Postes --------------------------------------\n\n");
											                if (grafo) {
											                    int poste_origem, poste_destino, nova_distancia;
											                    printf("Informe os postes de origem e destino e a nova distância: ");
											                    if (scanf("%d %d %d", &poste_origem, &poste_destino, &nova_distancia) != 3) {
											                        printf("Dados inválidos.\n");
											                        limpar_buffer();
											                        system("pause");
											                        break;
											                    }
											                    atualizar_distancia(grafo, poste_origem - 1, poste_destino - 1, nova_distancia);
											                    system("pause");
											                } else {
											                    printf("\nGrafo não inicializado.\n");
											                    system("pause");
											                }
											                break;
											            case 7:
											            	printf("\n\n-------------------------------------------- Melhor Ligação Entre Dois Postes ---------------------------------------\n\n");
											            	if(grafo){
											            		int inicio, destino;
											            		printf("\nPoste de origem e de destino: ");
											                 	if (scanf("%d %d", &inicio, &destino) != 2) {
											                        printf("\nDados inválidos.\n");
											                        limpar_buffer();
											                        system("pause");
											                        break;
											                	}	
											                	melhor_Ligacao(grafo, inicio - 1, destino - 1);
											                	system("pause");
															}else{
																printf("\nGrafo não inicializado.\n");
																system("pause");
															}						                
				                						               							
				                							break;
											            case 8:
											            	printf("\n\n------------------------------------------------ Iluminação Total ----------------------------------------------------\n\n");
											                if(grafo){
											                	iluminacao_total(grafo);
															}else{
																printf("\nGrafo não inicializado.\n");
											                    system("pause");
															}
											                system("pause");
											                break;
											            case 9:
											            	printf("\n\n--------------------------------------------- Melhor Solução ----------------------------------------------------\n\n");
											                if(grafo){
											                	melhor_solucao(grafo);
															}else{
																printf("\nGrafo não inicializado.\n");
											                    system("pause");
															}
											                system("pause");
											                break;
											            case 10:
											                printf("\n\n--------------------------------------------- Iluminar Ruas Adjacentes ------------------------------------------------\n\n");						                
											                // Iluminar ruas adjacentes
											                if (grafo) {
											                    int poste;
											                    printf("Informe o poste a partir do qual deseja iluminar as ruas: ");
											                    if (scanf("%d", &poste) != 1 || poste < 1 || poste > grafo->poste) {
											                        printf("Poste inválido.\n");
											                        limpar_buffer();
											                        system("pause");
											                        break;
											                    }
											                    iluminar_ruas_adjacentes(grafo, poste - 1);
											                    system("pause");
											                } else {
											                    printf("\nGrafo não inicializado.\n");
											                    system("pause");
											                }
											                break;
											            case 11:
											            	printf("\n\n--------------------------------------------- Destruir a Simulação ------------------------------------------------\n\n");
											                destruir_simulacao(&grafo, &numPostes);
											                printf("\n * Se deseja utilizar o ficheiro na sua forma original não é necessário sair da Simulação,\n é só criar uma nova localidade.");
											                
											                system("pause");
											                break;
											            case 12:
											            	destruir_simulacao(&grafo, &numPostes);
											                printf("\nSaindo da Simulação...\n");
											                limpar_buffer();
											                break;
											            default:
											                printf("\n\nOpção inválida. Escolha novamente.\n");
											                system("pause");
											                break;
											        }
				
				    					} while (opcao != 12);
									}
								}
								if( escolha == 3){
									printf("\n\n------------------------------------------------- Listar Utilizadores --------------------------------------------------\n\n");
									listar_utilizadores(listaUtilizadores);
				                    system("pause");
								}
								
								if( escolha == 4){
									printf("\n\n------------------------------------------------- Remover Utilizador ---------------------------------------------------\n\n");
									 char nome[50];
				                    
				                    printf("Nome de utilizador a remover: ");
				                    fgets(nome, sizeof(nome), stdin);
				                    nome[strcspn(nome, "\n")] = '\0'; 
									 
				                    listaUtilizadores = remover_utilizador(listaUtilizadores, nome);
				                    system("pause");
								}
								
								if( escolha == 5){
									 while (listaUtilizadores) {
				                    	
				                        Utilizador *aux = listaUtilizadores;
				                        listaUtilizadores = listaUtilizadores->prox;
				                        free(aux);
				                    }
				                  printf("\nSaindo da Gestão de Utilizadores...\n");  
								}
								
							}	
				        					                    
				               
				       }
				        } else {
				            printf("Erro ao ler a entrada.\n");
				            return 1;
				        }
				    }while(escolha != 5);
						
					break;
				}
					
				case 2:{
					printf("\n\n----------------------------------------------------- Ajuda -----------------------------------------------------------\n\n");
					
					printf("Opção 1 - Entrar na Simulação: Permite acessar o sistema de iluminação.\n");
					    printf("Opção 2 - Ajuda: Mostra este menu de ajuda.\n");
					    printf("Opção 3 - Sair: Encerra o programa.\n\n");
					    
					    printf("Opção 1 na Simulação - Adicionar Utilizador:\n");
					    printf("    Permite adicionar um novo utilizador ao sistema.\n");
					    printf("    Você deve fornecer um nome de utilizador, senha e o nome do ficheiro associado (o ficheiro deve estar na mesma pasta do programa).\n\n");
					    
					    printf("Opção 2 na Simulação - Autenticar Utilizador:\n");
					    printf("    Permite verificar se um utilizador está cadastrado no sistema.\n");
					    printf("    Você deve fornecer o nome de utilizador e a senha para autenticação.\n\n");
					    
					    printf("Opção 3 na Simulação - Listar Utilizadores:\n");
					    printf("    Mostra todos os utilizadores cadastrados no sistema.\n\n");
					    
					    printf("Opção 4 na Simulação - Remover Utilizador:\n");
					    printf("    Permite remover um utilizador do sistema.\n");
					    printf("    Você deve fornecer o nome de utilizador a ser removido.\n\n");
					    
					    printf("Opção 5 na Simulação - Sair da Gestão de Utilizadores:\n");
					    printf("    Encerra a gestão de utilizadores e retorna ao menu principal.\n\n");
					    
					    printf("Dentro da simulação, você pode realizar operações avançadas relacionadas à gestão de postes e iluminação:\n");
					    printf("Opção 1 - Criar Localidade:\n");
					    printf("    Cria uma nova localidade a partir de um ficheiro.\n");
					    printf("    Se nenhum ficheiro foi carregado, essa opção permite carregar um ficheiro com os dados da localidade.\n\n");
					    
					    printf("Opção 2 - Adicionar Novo Poste:\n");
					    printf("    Adiciona um novo poste à localidade existente.\n\n");
					    
					    printf("Opção 3 - Remover Poste:\n");
					    printf("    Remove um poste específico da localidade.\n\n");
					    
					    printf("Opção 4 - Adicionar Nova Rua:\n");
					    printf("    Adiciona uma nova rua entre dois postes da localidade.\n\n");
					    
					    printf("Opção 5 - Eliminar Rua:\n");
					    printf("    Remove uma rua existente entre dois postes da localidade.\n\n");
					    
					    printf("Opção 6 - Atualizar Distância Entre Dois Postes:\n");
					    printf("    Atualiza a distância entre dois postes na localidade.\n\n");
					    
					    printf("Opção 7 - Melhor Ligação Entre Dois Postes:\n");
					    printf("    Encontra a melhor ligação entre dois postes na localidade, otimizando o trajeto.\n\n");
					    
					    printf("Opção 8 - Iluminação Total:\n");
					    printf("    Calcula a iluminação total de toda a localidade.\n\n");
					    
					    printf("Opção 9 - Melhor Solução:\n");
					    printf("    Encontra a melhor solução para a iluminação da localidade, considerando diversos fatores.\n\n");
					    
					    printf("Opção 10 - Iluminar Ruas Adjacentes:\n");
					    printf("    Ilumina as ruas adjacentes a partir de um poste específico na localidade.\n\n");
					    
				    printf("Opção 11 - Destruir a Simulação:\n");
				    printf("    Limpa todos os dados da simulação, permitindo iniciar uma nova simulação com o ficheiro na sua forma original.\n\n");
				    
				    printf("Opção 12 - Sair da Simulação:\n");
				    printf("    Encerra a simulação e volta ao menu principal.\n\n");
				    
				    printf("Cada opção oferece funcionalidades específicas para gerenciar a iluminação da localidade de forma eficiente.\n\n");
				    
				    system("pause");
	    
					
					
					break;
				}
				
				case 3:{
					printf("\n\nSaindo.....\n");
					return 0;
					break;
				}
				
				default:{
				    printf("Opção inválida. Tente novamente.\n");
				      
					break;
				}
							}
				
				            
			
    	} else {
            printf("Erro ao ler a entrada.\n");
            return 1;
        }
    	
	}
	
	
 
    return 0;
}
