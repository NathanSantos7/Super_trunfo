#include <stdio.h>
#include <string.h>

char estado1[3], estado2[3];
char codcarta1[10], codcarta2[10];
char nome_cidade1[50], nome_cidade2[50];
unsigned long int populacao1, populacao2;
float area1, area2;
float pib1, pib2;
float Densidade_Populacao1, Densidade_Populacao2;
float PIB_per_capita1, PIB_per_capita2;
float super_poder1, super_poder2;
int pontos_t1, pontos_t2;
int c;

void DenPopu1() { Densidade_Populacao1 = (float)populacao1 / area1; }
void DenPopu2() { Densidade_Populacao2 = (float)populacao2 / area2; }

void PIBCapita1() { PIB_per_capita1 = (float)pib1 / populacao1; }
void PIBCapita2() { PIB_per_capita2 = (float)pib2 / populacao2; }

void SuperPoder1() { super_poder1 = populacao1 + area1 + pib1 + pontos_t1 + PIB_per_capita1 + (1 / Densidade_Populacao1); }
void SuperPoder2() { super_poder2 = populacao2 + area2 + pib2 + pontos_t2 + PIB_per_capita2 + (1 / Densidade_Populacao2); }

int main() {
    // Carta 1
    printf("Insira a primeira carta\n\n");
    printf("Estado: "); scanf(" %2s", estado1);
    printf("Código: "); scanf(" %9s", codcarta1);
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Cidade: "); fgets(nome_cidade1, 50, stdin); nome_cidade1[strcspn(nome_cidade1, "\n")] = 0;
    printf("População: "); scanf("%lu", &populacao1);
    printf("Área: "); scanf("%f", &area1);
    printf("PIB: "); scanf("%f", &pib1);
    printf("Pontos Turísticos: "); scanf("%d", &pontos_t1);

    DenPopu1();
    PIBCapita1();
    SuperPoder1();

    // Carta 2
    printf("\nInsira a segunda carta\n\n");
    printf("Estado: "); scanf(" %2s", estado2);
    printf("Código: "); scanf(" %9s", codcarta2);
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Cidade: "); fgets(nome_cidade2, 50, stdin); nome_cidade2[strcspn(nome_cidade2, "\n")] = 0;
    printf("População: "); scanf("%lu", &populacao2);
    printf("Área: "); scanf("%f", &area2);
    printf("PIB: "); scanf("%f", &pib2);
    printf("Pontos Turísticos: "); scanf("%d", &pontos_t2);

    DenPopu2();
    PIBCapita2();
    SuperPoder2();

    printf("\nComparação de Cartas:\n\n");

    printf("População: Carta %d venceu (%d)\n", (populacao1 > populacao2) ? 1 : 2, (populacao1 > populacao2) ? 1 : 0);
    printf("Área: Carta %d venceu (%d)\n", (area1 > area2) ? 1 : 2, (area1 > area2) ? 1 : 0);
    printf("PIB: Carta %d venceu (%d)\n", (pib1 > pib2) ? 1 : 2, (pib1 > pib2) ? 1 : 0);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", (pontos_t1 > pontos_t2) ? 1 : 2, (pontos_t1 > pontos_t2) ? 1 : 0);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", (Densidade_Populacao1 < Densidade_Populacao2) ? 1 : 2, (Densidade_Populacao1 < Densidade_Populacao2) ? 1 : 0);
    printf("PIB per Capita: Carta %d venceu (%d)\n", (PIB_per_capita1 > PIB_per_capita2) ? 1 : 2, (PIB_per_capita1 > PIB_per_capita2) ? 1 : 0);
    printf("Super Poder: Carta %d venceu (%d)\n", (super_poder1 > super_poder2) ? 1 : 2, (super_poder1 > super_poder2) ? 1 : 0);

    return 0;
}
