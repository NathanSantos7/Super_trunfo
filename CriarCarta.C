#include <stdio.h>
#include <string.h>


char estado[3];
char codcarta[10]; 
char nome_cidade[50];
int populacao;
float area;
float pib;
float Densidade_Populacao;
float PIB_per_capita;
int pontos_t;
int c;

void DenPopu(){

Densidade_Populacao = (float) populacao / area;

};

void PIBCapita(){

PIB_per_capita = (float) pib / populacao;

};


int main() {
 

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

    DenPopu();

    PIBCapita();

    printf("\nCarta Registrada:\n");
    printf("\nCarta Registrada:\n");
    printf("Estado: %s\n", estado);
    printf("Código: %s\n", codcarta);
    printf("Cidade: %s\n", nome_cidade);
    printf("População: %d\n", populacao);
    printf("Área: %.2f\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Pontos Turísticos: %d\n", pontos_t);
    printf("Densidade Demográfica: %.2f hab/km²\n", Densidade_Populacao);
    printf("PIB Per Capita: %.2f reais\n", PIB_per_capita);
    return 0;
}
