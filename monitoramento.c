#include <stdio.h>

int main() {
    float limite;
    float temperatura;
    float soma = 0;
    float maior = 0;
    float menor = 0;
    int quantidade = 0;
    int acimaLimite = 0;
    int consecutivas = 0;
    int primeiraLeitura = 1;

    // Define e valida o limite de temperatura
    do {
        printf("Digite o limite de temperatura: ");
        scanf("%f", &limite);

        if (limite < -50 || limite > 100) {
            printf("Limite invalido! Digite um valor entre -50 e 100.\n");
        }

    } while (limite < -50 || limite > 100);

    printf("\n--- Monitoramento de Temperatura ---\n");
    printf("O programa sera encerrado apos 3 temperaturas consecutivas acima do limite.\n\n");

    // Continua o monitoramento enquanto nao houver 3 temperaturas consecutivas acima do limite
    while (consecutivas < 3) {

        // Solicita e valida cada temperatura informada
        do {
            printf("Digite a temperatura: ");
            scanf("%f", &temperatura);

            if (temperatura < -50 || temperatura > 100) {
                printf("Temperatura invalida! Digite um valor entre -50 e 100.\n");
            }

        } while (temperatura < -50 || temperatura > 100);

        // Atualiza a soma e a quantidade de temperaturas registradas
        soma += temperatura;
        quantidade++;

        // Na primeira leitura, define a temperatura como maior e menor
        if (primeiraLeitura) {
            maior = temperatura;
            menor = temperatura;
            primeiraLeitura = 0;
        } else {
            // Verifica se a temperatura atual e a maior registrada
            if (temperatura > maior) {
                maior = temperatura;
            }

            // Verifica se a temperatura atual e a menor registrada
            if (temperatura < menor) {
                menor = temperatura;
            }
        }

        // Verifica se a temperatura esta acima do limite
        if (temperatura > limite) {
            acimaLimite++;
            consecutivas++;

            printf("Temperatura acima do limite!\n");
            printf("Temperaturas consecutivas acima do limite: %d\n", consecutivas);
        } else {
            // Reinicia a contagem quando a temperatura nao esta acima do limite
            consecutivas = 0;
            printf("Temperatura dentro do limite.\n");
        }

        printf("\n");
    }

    // Exibe o relatorio final do monitoramento
    printf("====================================\n");
    printf("       MONITORAMENTO ENCERRADO\n");
    printf("====================================\n");

    printf("Quantidade de temperaturas: %d\n", quantidade);
    printf("Maior temperatura: %.2f C\n", maior);
    printf("Menor temperatura: %.2f C\n", menor);
    printf("Media das temperaturas: %.2f C\n", soma / quantidade);

    // Calcula o percentual de temperaturas acima do limite
    printf("Percentual acima do limite: %.2f%%\n",
           (acimaLimite * 100.0) / quantidade);

    printf("\nMotivo do encerramento: 3 temperaturas consecutivas acima do limite.\n");

    return 0;
}
