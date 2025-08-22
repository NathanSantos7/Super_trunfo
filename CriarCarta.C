#include <stdio.h>
#include <string.h>

int main() {
    char estado[3];
    char codcarta[10]; 
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_t;
    int c;

    printf("Insira as cartas de super triunfo\n\n");
    printf("Primeira Carta\n\n");

    printf("Insira Estado: ");
    scanf(" %2s", estado);

    printf("Insira código da carta: ");
    scanf(" %9s", codcarta);

    //Limpa o '\n' que veio da ultima entrada do usuario
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Insira nome da cidade: ");
    fgets(nome_cidade, 50, stdin);
    //removendo o '\n' que vem do final da entrada 
    nome_cidade[strcspn(nome_cidade, "\n")] = 0;

    printf("Insira população: ");
    scanf("%d", &populacao);

    printf("Insira área: ");
    scanf("%f", &area);

    printf("Insira PIB: ");
    scanf("%f", &pib);

    printf("Insira quantidade de pontos turisticos: ");
    scanf("%d", &pontos_t);

    printf("\nCarta Registrada:\n");
    printf("Estado: %s\nCódigo: %s\nCidade: %s\nPopulação: %d\nÁrea: %.2f\nPIB: %.2f\nPontos Turísticos: %d\n",
           estado, codcarta, nome_cidade, populacao, area, pib, pontos_t);

    return 0;
}
