#include <stdio.h>

// Função que descobre o distrito com mais vencedores
void distritoComMaisVencedores(int lista[], int qtd) {
    int maior = 0;
    int distritomaior = 0;

    for (int i = 0; i < qtd; i++) {
        if (lista[i] > maior) {
            maior = lista[i];
            distritomaior = i + 1; // +1 pq distrito começa em 1
        }
    }

    printf("O distrito com mais vitórias é o distrito %d com %d vitórias\n", distritomaior, maior);
}

int main() {
    int vitoriadistritos[3]; // guarda as vitórias de 3 distritos

    for (int i = 0; i < 3; i++) {
        printf("Digite o numero de vencedores no distrito %d: ", i + 1);
        scanf("%d", &vitoriadistritos[i]);
    }

    // chama pra descobrir o distrito com mais tributos vencedores
    distritoComMaisVencedores(vitoriadistritos, 3);

    return 0;
}
   
