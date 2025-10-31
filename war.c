// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
// --- Estrutura de Dados ---
int totalTropas = 0;
#define MAXTROPAS 2
#define TAMANHONOME 10
// Declarações das funções utilizadas no programa.
void limparBufferEntrada();
void exibirMenu();
void inicializarTerritorios();
void alocarMapa();
void exibirMapa();
void liberarMemoria();
int jogarDado();
// Estrutura que representa um território no jogo, contendo nome, cor do exército e número de tropas.
typedef struct
{
    char nome[TAMANHONOME];
    char corExercito[TAMANHONOME];
    int numTropas[TAMANHONOME];

} War;

War *mywar;

int main()
{
exibirMenu();
    // 1. Configuração Inicial (Setup):
    // - Define o locale para português.
    // - Inicializa a semente para geração de números aleatórios com base no tempo atual.
    // - Aloca a memória para o mapa do mundo e verifica se a alocação foi bem-sucedida.
    // - Preenche os territórios com seus dados iniciais (tropas, donos, etc.).
    // - Define a cor do jogador e sorteia sua missão secreta.

    // 2. Laço Principal do Jogo (Game Loop):
    // - Roda em um loop 'do-while' que continua até o jogador sair (opção 0) ou vencer.
    // - A cada iteração, exibe o mapa, a missão e o menu de ações.
    // - Lê a escolha do jogador e usa um 'switch' para chamar a função apropriada:
    //   - Opção 1: Inicia a fase de ataque.
    //   - Opção 2: Verifica se a condição de vitória foi alcançada e informa o jogador.
    //   - Opção 0: Encerra o jogo.
    // - Pausa a execução para que o jogador possa ler os resultados antes da próxima rodada.

    // 3. Limpeza:
    // - Ao final do jogo, libera a memória alocada para o mapa para evitar vazamentos de memória.

    return 0;
}

// --- Implementação das Funções ---

// Menu de opcoes para adicionar, listar e encerrar o programa
void exibirMenu()
{   alocarMapa();
    int escolha;
    do
    {
        printf("=== Menu de Gerenciamento de Territorios ===\n");
        printf("Escolha uma das opcoes:\n");
        printf("1 - Adicionar territorio\n");
        printf("2 - listar territorios\n");
        printf("3 - Sair\n");
        printf("============================================\n");
        scanf("%d", &escolha);
        limparBufferEntrada();
        switch (escolha)
        {
        case 1:
            inicializarTerritorios();

            break;
        case 2:
            exibirMapa();
                break;
            break;
        case 3:
                liberarMemoria();
        default:
                printf("Escolha uma opcao invalida\n");
        }
    }while(escolha != 3);
}
//Adiciona territorios ao mapa do mundo
void inicializarTerritorios()
{
    if (totalTropas == MAXTROPAS)
            {
                printf("Numero maximo de territorios atingido\n");
            }
            else
            {
                while (totalTropas < MAXTROPAS)
                {   
                    
                    printf("Digite o nome do %d territorio:\n", totalTropas + 1);
                    fgets(mywar[totalTropas].nome, TAMANHONOME, stdin);

                    printf("Digite a cor do exercito:\n");
                    fgets(mywar[totalTropas].corExercito, TAMANHONOME, stdin);

                    printf("Digite o numero de tropas:\n");
                    scanf("%d",mywar[totalTropas].numTropas);
                    limparBufferEntrada();
                    mywar[totalTropas].nome[strcspn(mywar[totalTropas].nome, "\n")] = 0;
                    mywar[totalTropas].corExercito[strcspn(mywar[totalTropas].corExercito, "\n")] = 0;

                    totalTropas++;
                }
            }
    
}

// Lista os territorios cadastrados
void exibirMapa(){

if (totalTropas == 0)
            {
                printf("Nenhum territorio cadastrado\n");
            }
            else
            {
                printf("Lista de territorios:\n");
                for (int i = 0; i < totalTropas; i++)
                {
                    printf("Territorio %d:\n", i+1);
                    printf("Nome: %s \n", mywar[i].nome);
                    printf("Cor do exercito: %s\n", mywar[i].corExercito);
                    printf("Numero de tropas: %d\n", *mywar[i].numTropas);
                    printf("-----------------------\n");
                }
            }
                




}
// Limpa o buffer de entrada para evitar problemas com leituras consecutivas.
void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
// Aloca dinamicamente a memória para o mapa do mundo.
void alocarMapa()
{
    mywar = calloc(5, sizeof(War));
    if (mywar == NULL)
    {
        perror("Erro ao alocar memoria para o mapa.\n");
    };
}
//Libera a memoria alocada para o mapa do mundo
void liberarMemoria()
{
    free(mywar);
    printf("Memoria liberada com sucesso!\n");
    printf("Encerrando o programa...\n");   
}
// funcao para simular o lancamento de um dado de 6 faces
int jogarDado()
{
    return rand() % 6 + 1;
}   
// Imprime na tela o menu de ações disponíveis para o jogador.

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.

