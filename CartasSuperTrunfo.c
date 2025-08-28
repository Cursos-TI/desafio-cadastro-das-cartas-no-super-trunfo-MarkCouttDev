#include <stdio.h>
#include <string.h>

// Função para exibir o nome do atributo
void exibirNomeAtributo(int atributo) {
    switch (atributo) {
        case 1: printf("População"); break;
        case 2: printf("Área"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos turísticos"); break;
        case 5: printf("Densidade demográfica"); break;
        case 6: printf("PIB per capita"); break;
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
    pibPerCapita1 = (pib1 * 1e9) / populacao1;

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
    pibPerCapita2 = (pib2 * 1e9) / populacao2;

    // ===== Exibição dos Dados =====
    printf("\n=== Dados da Carta 1 ===\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões R$\n", pib1);
    printf("Pontos turísticos: %d\n", pontos1);
    printf("Densidade demográfica: %.2f hab/km²\n", densidade1);
    printf("PIB per capita: %.2f R$\n", pibPerCapita1);

    printf("\n=== Dados da Carta 2 ===\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões R$\n", pib2);
    printf("Pontos turísticos: %d\n", pontos2);
    printf("Densidade demográfica: %.2f hab/km²\n", densidade2);
    printf("PIB per capita: %.2f R$\n", pibPerCapita2);

    // ===== Comparação dos Atributos =====
    int pontosCarta1 = 0, pontosCarta2 = 0;

    // População
    if (populacao1 > populacao2) pontosCarta1++;
    else if (populacao2 > populacao1) pontosCarta2++;

    // Área
    if (area1 > area2) pontosCarta1++;
    else if (area2 > area1) pontosCarta2++;

    // PIB
    if (pib1 > pib2) pontosCarta1++;
    else if (pib2 > pib1) pontosCarta2++;

    // Pontos turísticos
    if (pontos1 > pontos2) pontosCarta1++;
    else if (pontos2 > pontos1) pontosCarta2++;

    // Densidade demográfica (menor vence)
    if (densidade1 < densidade2) pontosCarta1++;
    else if (densidade2 < densidade1) pontosCarta2++;

    // PIB per capita
    if (pibPerCapita1 > pibPerCapita2) pontosCarta1++;
    else if (pibPerCapita2 > pibPerCapita1) pontosCarta2++;

    // ===== Super Poder =====
    float superPoder1 = populacao1 + area1 + pib1 + pontos1 + (1 / densidade1) + pibPerCapita1;
    float superPoder2 = populacao2 + area2 + pib2 + pontos2 + (1 / densidade2) + pibPerCapita2;

    printf("\n=== Comparação Final ===\n");
    printf("Pontos da Carta 1: %d\n", pontosCarta1);
    printf("Pontos da Carta 2: %d\n", pontosCarta2);

    printf("\nSuper Poder da Carta 1: %.2f\n", superPoder1);
    printf("Super Poder da Carta 2: %.2f\n", superPoder2);

    if (superPoder1 > superPoder2)
        printf("\n Vencedora: %s\n", cidade1);
    else if (superPoder2 > superPoder1)
        printf("\n Vencedora: %s\n", cidade2);
    else
        printf("\n Empate!\n");

    return 0;
}

