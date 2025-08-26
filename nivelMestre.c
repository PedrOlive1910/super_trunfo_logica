#include <stdio.h>
#include <string.h>

// Estrutura para armazenar as cartas
typedef struct {
    char nome[30];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade; // calculada: populacao / area
} Carta;

// Função para exibir os atributos disponíveis
void exibirMenu(int atributoEscolhido) {
    printf("\nEscolha um atributo para comparar:\n");

    if (atributoEscolhido != 1) printf("1 - População\n");
    if (atributoEscolhido != 2) printf("2 - Área\n");
    if (atributoEscolhido != 3) printf("3 - PIB\n");
    if (atributoEscolhido != 4) printf("4 - Pontos Turísticos\n");
    if (atributoEscolhido != 5) printf("5 - Densidade Demográfica\n");

    printf("Opção: ");
}

// Função para retornar o valor de um atributo
float obterAtributo(Carta c, int opcao) {
    switch(opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontos_turisticos;
        case 5: return c.densidade;
        default: return -1;
    }
}

// Função para exibir o nome do atributo
const char* nomeAtributo(int opcao) {
    switch(opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Inválido";
    }
}

int main() {
    // Duas cartas pré-cadastradas
    Carta carta1 = {"Brasil", 214000000, 8516000.0, 2200.0, 15, 214000000/8516000.0};
    Carta carta2 = {"Argentina", 46000000, 2780000.0, 600.0, 10, 46000000/2780000.0};

    int atributo1, atributo2;

    printf("=== SUPER TRUNFO - COMPARAÇÃO AVANÇADA ===\n");
    printf("Cartas selecionadas: %s x %s\n", carta1.nome, carta2.nome);

    // Escolha do primeiro atributo
    exibirMenu(0);
    scanf("%d", &atributo1);

    // Escolha do segundo atributo (não pode ser igual ao primeiro)
    do {
        exibirMenu(atributo1);
        scanf("%d", &atributo2);
        if (atributo1 == atributo2) {
            printf("❌ Você já escolheu esse atributo! Escolha outro.\n");
        }
    } while(atributo1 == atributo2);

    // Obter os valores dos atributos
    float valor1_c1 = obterAtributo(carta1, atributo1);
    float valor1_c2 = obterAtributo(carta2, atributo1);
    float valor2_c1 = obterAtributo(carta1, atributo2);
    float valor2_c2 = obterAtributo(carta2, atributo2);

    // Comparação do primeiro atributo
    int vencedor1;
    if (atributo1 == 5) // Densidade: vence o menor
        vencedor1 = (valor1_c1 < valor1_c2) ? 1 : (valor1_c1 > valor1_c2 ? 2 : 0);
    else
        vencedor1 = (valor1_c1 > valor1_c2) ? 1 : (valor1_c1 < valor1_c2 ? 2 : 0);

    // Comparação do segundo atributo
    int vencedor2;
    if (atributo2 == 5) // Densidade: vence o menor
        vencedor2 = (valor2_c1 < valor2_c2) ? 1 : (valor2_c1 > valor2_c2 ? 2 : 0);
    else
        vencedor2 = (valor2_c1 > valor2_c2) ? 1 : (valor2_c1 < valor2_c2 ? 2 : 0);

    // Soma dos atributos
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    int vencedorFinal = (soma_c1 > soma_c2) ? 1 : (soma_c1 < soma_c2 ? 2 : 0);

    // Exibição dos resultados
    printf("\n===== RESULTADO =====\n");
    printf("País 1: %s\n", carta1.nome);
    printf("País 2: %s\n\n", carta2.nome);

    printf("%s -> %s: %.2f | %s: %.2f\n", carta1.nome, nomeAtributo(atributo1), valor1_c1, nomeAtributo(atributo2), valor2_c1);
    printf("%s -> %s: %.2f | %s: %.2f\n\n", carta2.nome, nomeAtributo(atributo1), valor1_c2, nomeAtributo(atributo2), valor2_c2);

    printf("Soma %s: %.2f\n", carta1.nome, soma_c1);
    printf("Soma %s: %.2f\n\n", carta2.nome, soma_c2);

    if (vencedorFinal == 1) {
        printf("🏆 %s venceu a rodada!\n", carta1.nome);
    } else if (vencedorFinal == 2) {
        printf("🏆 %s venceu a rodada!\n", carta2.nome);
    } else {
        printf("🤝 Empate!\n");
    }

    return 0;
}
