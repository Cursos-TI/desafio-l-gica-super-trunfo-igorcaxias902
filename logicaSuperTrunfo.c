#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

#include <string.h>

// Definição da estrutura de uma carta
struct Carta {
    char estado[50];
    char codigo[20];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
};

// Função para cadastrar uma carta
struct Carta cadastrarCarta(int numero) {
    struct Carta c;

    printf("\n--- Cadastro da Carta %d ---\n", numero);
    printf("Estado: ");
    scanf(" %[^\n]", c.estado);

    printf("Código da carta: ");
    scanf(" %[^\n]", c.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", c.nome);

    printf("População: ");
    scanf("%d", &c.populacao);

    printf("Área (em km²): ");
    scanf("%f", &c.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &c.pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &c.pontosTuristicos);

    if (c.area != 0) {
        c.densidade = c.populacao / c.area;
    } else {
        c.densidade = 0;
    }

    return c;
}

// Função para exibir uma carta
void exibirCarta(struct Carta c, int numero) {
    printf("\n=== Carta %d ===\n", numero);
    printf("Estado: %s\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Nome da cidade: %s\n", c.nome);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", c.densidade);
}

// Função para comparar cartas
void compararCartas(struct Carta c1, struct Carta c2, char atributo[]) {
    printf("\nComparando cartas pelo atributo: %s\n", atributo);

    int venceu1 = 0;

    if (strcmp(atributo, "populacao") == 0) {
        venceu1 = c1.populacao > c2.populacao;
    } else if (strcmp(atributo, "area") == 0) {
        venceu1 = c1.area > c2.area;
    } else if (strcmp(atributo, "pib") == 0) {
        venceu1 = c1.pib > c2.pib;
    } else if (strcmp(atributo, "pontos") == 0) {
        venceu1 = c1.pontosTuristicos > c2.pontosTuristicos;
    } else if (strcmp(atributo, "densidade") == 0) {
        venceu1 = c1.densidade < c2.densidade;  // menor vence
    } else {
        printf("Atributo inválido!\n");
        return;
    }

    printf("\n🏆 Carta vencedora: %s (%s)\n",
           venceu1 ? c1.nome : c2.nome,
           venceu1 ? c1.estado : c2.estado);
}

// Função principal
int main() {
    struct Carta carta1, carta2;
    char atributo[20];

    printf("Desafio Logica Super Trunfo\n");

    carta1 = cadastrarCarta(1);
    carta2 = cadastrarCarta(2);

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    printf("\nAtributos disponíveis para comparação:\n");
    printf("populacao, area, pib, pontos, densidade\n");
    printf("Digite o atributo a comparar: ");
    scanf(" %s", atributo);

    compararCartas(carta1, carta2, atributo);



    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    return 0;
}
