#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char estado[3];
    char codigo[5];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
} Carta;

int main() {
    // Cadastro de duas cartas pré-definidas
    Carta carta1 = {"SP", "A01", "São Paulo", 12300000, 1521.0, 699000.0, 15};
    Carta carta2 = {"RJ", "A02", "Rio de Janeiro", 6000000, 1200.0, 450000.0, 10};

    // Cálculo de atributos derivados
    carta1.densidade = (float)carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    carta2.densidade = (float)carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // -------------------------------
    // Escolha do atributo para comparação
    // Troque aqui para comparar: populacao, area, pib, densidade, pibPerCapita
    // -------------------------------
    char atributoEscolhido[] = "populacao";  

    printf("Comparacao de cartas (Atributo: %s):\n\n", atributoEscolhido);

    // Variáveis auxiliares para guardar valores
    float valor1, valor2;

    if (strcmp(atributoEscolhido, "populacao") == 0) {
        valor1 = carta1.populacao;
        valor2 = carta2.populacao;
    } else if (strcmp(atributoEscolhido, "area") == 0) {
        valor1 = carta1.area;
        valor2 = carta2.area;
    } else if (strcmp(atributoEscolhido, "pib") == 0) {
        valor1 = carta1.pib;
        valor2 = carta2.pib;
    } else if (strcmp(atributoEscolhido, "densidade") == 0) {
        valor1 = carta1.densidade;
        valor2 = carta2.densidade;
    } else if (strcmp(atributoEscolhido, "pibPerCapita") == 0) {
        valor1 = carta1.pibPerCapita;
        valor2 = carta2.pibPerCapita;
    } else {
        printf("Atributo invalido!\n");
        return 0;
    }

    // Mostra valores das cartas
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n\n", carta2.nomeCidade, carta2.estado, valor2);

    // Regras de comparação
    if (strcmp(atributoEscolhido, "densidade") == 0) {
        // Na densidade, vence quem tiver MENOR valor
        if (valor1 < valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valor2 < valor1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
        // Nos demais atributos, vence quem tiver MAIOR valor
        if (valor1 > valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valor2 > valor1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }

    return 0;
}
