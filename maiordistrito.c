#include <stdio.h>

void distritoComMaisVencedores( int lista[3], int qtd) {
    //funcao implementada
}
int main() {


int vitoriadistritos [3]= {0};
int maior= 0;
int distritomaior = 0;



for (int i=0; i < 3; i++) { // percorre o numero de vencedores por distrito
    printf("Digite o numero de vencedores nesse distrito");
    scanf ("%d", &vitoriadistritos [i]);
 if (vitoriadistritos[i]> maior) {// se a quantidade de vitorias do distrito for maior que a quantidade anterior
        maior = vitoriadistritos[i];
        distritomaior= i + 1; // guarda o distrito com mais vitórias
        } 

}
printf ("O distrito com mais vitórias é o distrito %d com %d vitorias\n", distritomaior, maior);

return 0;
}
