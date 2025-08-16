#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "codigosVorazes.h"

int main() {

    srand(time(NULL));
    int id = 0;

    while (id < MAXTRIBUTOS) {
        CadastrarTributo(id);
        id++;
    }

    int escolha;
    printf("Digite 1 para listar os jovens cadastrados e 2 para sortear os tributos: ");
    scanf("%d", &escolha);

    if (escolha == 1) {
        for (int i = 0; i < MAXTRIBUTOS; i++) {
            listarTributos(i);
        }
    } else {
        sortearTributos(MAXTRIBUTOS);
    }

    return 0;
}
