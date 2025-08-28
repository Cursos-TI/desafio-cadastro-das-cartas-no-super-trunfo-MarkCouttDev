#include <stdio.h>
#include <string.h>

// Função para obter o valor de um atributo
float getValor(int atributo, unsigned long int pop, float area, float pib, int pontos, float densidade) {
    switch (atributo) {
        case 1: return (float)pop;
        case 2: return area;
        case 3: return pib;
        case 4: return (float)pontos;
        case 5: return densidade;
        default: return 0;
    }
}

// Função para exibir o nome do atributo
void exibirNomeAtributo(int atributo) {
    switch (atributo) {
        case 1: printf("População"); break;
        case 2: printf("Área"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos turísticos"); break;
        case 5: printf("Densidade demográfica"); break;
    }
}

int main() {
    // ===== Dados para Carta 1 =====
    char estado1, codigo1[4], cidade1[50];
    unsigned long int populacao1;
    float area1, pib1;
    int pontos1;
    float densidade1, pibPerCapita1;

    // ===== Dados para Carta 2 =====
    char estado2, codigo2[4], cidade2[50];
    unsigned long int populacao2;
    float area2, pib2;
    int pontos2;
    float densidade2, pibPerCapita2;

    // ===== Cadastro Carta 1 =====
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (letra A a H): ");
    scanf(" %c", &estado1);
    printf("Código da carta: ");
    scanf(" %s", codigo1);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", cidade1);
    printf("População: ");
    scanf(" %lu", &populacao1);
    printf("Área (km²): ");
    scanf(" %f", &area1);
    printf("PIB (bilhões R$): ");
    scanf(" %f", &pib1);
    printf("Pontos turísticos: ");
    scanf(" %d", &pontos1);

    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;

    // ===== Cadastro Carta 2 =====
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (letra A a H): ");
    scanf(" %c", &estado2);
    printf("Código da carta: ");
    scanf(" %s", codigo2);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", cidade2);
    printf("População: ");
    scanf(" %lu", &populacao2);
    printf("Área (km²): ");
    scanf(" %f", &area2);
    printf("PIB (bilhões R$): ");
    scanf(" %f", &pib2);
    printf("Pontos turísticos: ");
    scanf(" %d", &pontos2);

    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // ===== Escolha dos Atributos =====
    int atributo1, atributo2;

    printf("\n=== Escolha o Primeiro Atributo ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("Opção: ");
    scanf(" %d", &atributo1);

    // Menu dinâmico para o segundo atributo
    printf("\n=== Escolha o Segundo Atributo ===\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos turísticos\n"); break;
                case 5: printf("5 - Densidade demográfica\n"); break;
            }
        }
    }
    printf("Opção: ");
    scanf(" %d", &atributo2);

    // ===== Comparação dos Atributos =====
    float valor1A = getValor(atributo1, populacao1, area1, pib1, pontos1, densidade1);
    float valor2A = getValor(atributo1, populacao2, area2, pib2, pontos2, densidade2);

    float valor1B = getValor(atributo2, populacao1, area1, pib1, pontos1, densidade1);
    float valor2B = getValor(atributo2, populacao2, area2, pib2, pontos2, densidade2);

    int pontosCarta1 = 0, pontosCarta2 = 0;

    // Comparação do primeiro atributo
    if (atributo1 == 5)
        valor1A < valor2A ? pontosCarta1++ : (valor2A < valor1A ? pontosCarta2++ : 0);
    else
        valor1A > valor2A ? pontosCarta1++ : (valor2A > valor1A ? pontosCarta2++ : 0);

    // Comparação do segundo atributo
    if (atributo2 == 5)
        valor1B < valor2B ? pontosCarta1++ : (valor2B < valor1B ? pontosCarta2++ : 0);
    else
        valor1B > valor2B ? pontosCarta1++ : (valor2B > valor1B ? pontosCarta2++ : 0);

    // Soma dos atributos
    float soma1 = valor1A + valor1B;
    float soma2 = valor2A + valor2B;

    // ===== Exibição dos Resultados =====
    printf("\n=== Resultado Final ===\n");
    printf("Carta 1: %s\n", cidade1);
    printf("Carta 2: %s\n", cidade2);

    printf("\nAtributo 1: ");
    exibirNomeAtributo(atributo1);
    printf("\n%s: %.2f\n%s: %.2f\n", cidade1, valor1A, cidade2, valor2A);

    printf("\nAtributo 2: ");
    exibirNomeAtributo(atributo2);
    printf("\n%s: %.2f\n%s: %.2f\n", cidade1, valor1B, cidade2, valor2B);

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", cidade1, soma1);
    printf("%s: %.2f\n", cidade2, soma2);

    if (soma1 > soma2)
        printf("\n Vencedora: %s\n", cidade1);
    else if (soma2 > soma1)
        printf("\n Vencedora: %s\n", cidade2);
    else
        printf("\n Empate!\n");

    return 0;
}