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

float getValor(int opcao, int carta) {
    switch (opcao) {
        case 1: return carta == 1 ? (float)populacao1 : (float)populacao2;
        case 2: return carta == 1 ? area1 : area2;
        case 3: return carta == 1 ? pib1 : pib2;
        case 4: return carta == 1 ? (float)pontos_t1 : (float)pontos_t2;
        case 5: return carta == 1 ? Densidade_Populacao1 : Densidade_Populacao2;
        case 6: return carta == 1 ? PIB_per_capita1 : PIB_per_capita2;
        case 7: return carta == 1 ? super_poder1 : super_poder2;
        default: return 0;
    }
}

const char* getNomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        case 6: return "PIB per Capita";
        case 7: return "Super Poder";
        default: return "Desconhecido";
    }
}

int main() {

    int opcao1, opcao2;

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

    // Escolha dos atributos
    printf("\nEscolha o primeiro atributo:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n6 - PIB per Capita\n7 - Super Poder\n");
    printf("Opção: "); scanf("%d", &opcao1);

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 7; i++) {
        if (i != opcao1) {
            printf("%d - %s\n", i, getNomeAtributo(i));
        }
    }
    printf("Opção: "); scanf("%d", &opcao2);

    // Pegando valores dos atributos
    float valor1_c1 = getValor(opcao1, 1);
    float valor1_c2 = getValor(opcao1, 2);
    float valor2_c1 = getValor(opcao2, 1);
    float valor2_c2 = getValor(opcao2, 2);

    // Comparação individual
    printf("\nComparando cartas: %s x %s\n", nome_cidade1, nome_cidade2);

    printf("\nAtributo 1 (%s): %.2f x %.2f\n", getNomeAtributo(opcao1), valor1_c1, valor1_c2);
    int vencedor1 = (opcao1 == 5) ? (valor1_c1 < valor1_c2 ? 1 : (valor1_c1 > valor1_c2 ? 2 : 0))
                                  : (valor1_c1 > valor1_c2 ? 1 : (valor1_c1 < valor1_c2 ? 2 : 0));
    vencedor1 == 0 ? printf("Empate!\n") : printf("Carta %d venceu!\n", vencedor1);

    printf("\nAtributo 2 (%s): %.2f x %.2f\n", getNomeAtributo(opcao2), valor2_c1, valor2_c2);
    int vencedor2 = (opcao2 == 5) ? (valor2_c1 < valor2_c2 ? 1 : (valor2_c1 > valor2_c2 ? 2 : 0))
                                  : (valor2_c1 > valor2_c2 ? 1 : (valor2_c1 < valor2_c2 ? 2 : 0));
    vencedor2 == 0 ? printf("Empate!\n") : printf("Carta %d venceu!\n", vencedor2);

    // Soma dos atributos
    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    printf("\nSoma dos atributos: %.2f x %.2f\n", soma1, soma2);
    int vencedorFinal = (soma1 > soma2) ? 1 : (soma1 < soma2 ? 2 : 0);
    vencedorFinal == 0 ? printf("Resultado Final: Empate!\n") : printf("Resultado Final: Carta %d venceu!\n", vencedorFinal);

    return 0;
}
