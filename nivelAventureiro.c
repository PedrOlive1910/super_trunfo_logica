#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char pais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
} Carta;

int main() {
    // Cadastro de duas cartas pré-definidas
    Carta carta1 = {"Brasil", 213000000, 8515767.0, 14400.0, 20};
    Carta carta2 = {"Argentina", 45300000, 2780400.0, 520.0, 10};

    // Cálculo de atributos derivados
    carta1.densidade = (float)carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib * 1000000000 / carta1.populacao; // PIB em bilhões
    carta2.densidade = (float)carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib * 1000000000 / carta2.populacao;

    int opcao;
    printf("===== SUPER TRUNFO - MENU =====\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("6 - PIB per Capita\n");
    printf("Escolha um atributo para comparar: ");
    scanf("%d", &opcao);

    printf("\nComparacao entre %s e %s\n", carta1.pais, carta2.pais);

    switch(opcao) {
        case 1: // População
            printf("Populacao %s: %d\n", carta1.pais, carta1.populacao);
            printf("Populacao %s: %d\n", carta2.pais, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2: // Área
            printf("Area %s: %.2f km²\n", carta1.pais, carta1.area);
            printf("Area %s: %.2f km²\n", carta2.pais, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3: // PIB
            printf("PIB %s: %.2f bilhões\n", carta1.pais, carta1.pib);
            printf("PIB %s: %.2f bilhões\n", carta2.pais, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4: // Pontos turísticos
            printf("Pontos Turisticos %s: %d\n", carta1.pais, carta1.pontosTuristicos);
            printf("Pontos Turisticos %s: %d\n", carta2.pais, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5: // Densidade (regra invertida: menor vence)
            printf("Densidade %s: %.6f hab/km²\n", carta1.pais, carta1.densidade);
            printf("Densidade %s: %.6f hab/km²\n", carta2.pais, carta2.densidade);
            if (carta1.densidade < carta2.densidade) {
                printf("Resultado: %s venceu! (menor densidade)\n", carta1.pais);
            } else if (carta2.densidade < carta1.densidade) {
                printf("Resultado: %s venceu! (menor densidade)\n", carta2.pais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 6: // PIB per capita
            printf("PIB per Capita %s: %.2f USD\n", carta1.pais, carta1.pibPerCapita);
            printf("PIB per Capita %s: %.2f USD\n", carta2.pais, carta2.pibPerCapita);
            if (carta1.pibPerCapita > carta2.pibPerCapita) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            printf("Opcao invalida! Escolha entre 1 e 6.\n");
            break;
    }

    return 0;
}
