#include <stdio.h>

struct distrito { 
    int forca;
};


void EstatisticaForca(struct distrito lista[6], int *qtdmin, int *qtdmax, float *qtdmedia) {
    int soma= 0;
    *qtdmin = lista[0].forca; // força do primeiro tributo
    *qtdmax = lista[0].forca; // força do primeiro tributo



    for (int i= 0; i <6; i++) {
        if (lista [i].forca < *qtdmin) { 
            *qtdmin = lista [i].forca; //verifica se a forcaa e menor que a anterior

        }
        if (lista [i].forca > *qtdmax) { 
            *qtdmax= lista [i].forca; // verifica se a forca e maior que a anterior

        }
         soma += lista[i].forca; //soma as forcas

    }
    *qtdmedia = soma/ 6.0; //calcula a media 
}

int main() {
    struct distrito lista [6];
    int min,  max;
    float media;
    for (int i = 0; i < 6; i++) {
        printf("Digite a forca do tributo %d: ", i + 1);
        scanf("%d", &lista[i].forca);
    }


EstatisticaForca(lista, &min, &max, &media);

printf("Menor forca: %d\n", min);
printf("Maior forca: %d\n", max);
printf("Media das forcas: %.2f\n", media);

return 0; 
}

