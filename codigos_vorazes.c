#include "codigos_vorazes.h"
#include <stdlib.h>
#include <time.h>
// nesse arquivo coloca toda a função

// Remove aquele que perdeu
void removerTributo (int quemSai) { 
    // vou receber quem perdeu (ID)
    // aí eu tenho que colocar -1 em todas listas na parte dele
    // -1 em int, X em char
    
    // salvo elas como variáveis também no .h
    Nome[quemSai][0] = 'X';// tem que fzer com q quando encontre o X, entenda que pode sobrescrever
    Nome[quemSai][1] = '\0'; // \0 representa pro C que chegou no fim da string e que não vai ter mais nenhum caractere
    Sexo[quemSai] = 'X';
    Idade[quemSai] = -1;

    //livia reseta a lista de quantos matou?
} 

void iniciarJogos (int Tributos[], int tamanho) {

    srand(time(NULL));
    /* a função rand não gera números aleatórios, ela usa uma semente (algum 
    valor do computador) como um ponto raíz para extrair os números.
    srand é para alterar essa semente, então para aumentar a variancia, a
    biblioteca time é incluída, com o valor NULL, que é uma constante que diz
    para o computador não apontar para nada válido */

    // preciso pegar na ordem que vem
    //int i = 0, j = i + 1, maximo = 1;
    int ganhador1, ganhador2, ganhador3, ganhador4, campeao; // rever nome dos finalistas
    int numeroRandom = rand() % 2; // só retorna 0 ou 1
    //Tributos[0] x Tributos[1]
    if (numeroRandom == 0) {
        // 0 ganhou 
        // acredito que a lista de tributos vem com os IDs
        QuantosMatou[Tributos[0]]++;
        removerTributo(Tributos[1]);
        
        ganhador1 = 0; // armazena para proxima batalha
    } else {
        // 1 ganhou 
        QuantosMatou[Tributos[1]]++;
        removerTributo(Tributos[0]);
        
        ganhador1 = 1; // armazena para proxima batalha
    }
    
    //Tributos[2] x Tributos[3]
        if (numeroRandom == 0) {
        // 2 ganhou 
        QuantosMatou[Tributos[2]]++;
        removerTributo(Tributos[3]);
        
        ganhador2 = 2; // armazena para proxima batalha
    } else {
        // 3 ganhou 
        QuantosMatou[Tributos[3]]++;
        removerTributo(Tributos[2]);
        
        ganhador2 = 3; // armazena para proxima batalha
    }

    //Tributos[4] x Tributos[5]
    if (numeroRandom == 0) {
        // 4 ganhou 
        QuantosMatou[Tributos[4]]++;
        removerTributo(Tributos[5]);
        
        ganhador3 = 4; // armazena para proxima batalha
    } else {
        // 5 ganhou 
        QuantosMatou[Tributos[5]]++;
        removerTributo(Tributos[4]);
        
        ganhador3 = 5; // armazena para proxima batalha
    }

    //Ganhador 1 x Ganhador 2
    if (numeroRandom == 0) {
        // ganhador 1 ganhou 
        QuantosMatou[Tributos[ganhador1]]++;
        removerTributo(Tributos[ganhador2]);
        
        ganhador4 = ganhador1; // armazena para proxima batalha
    } else {
        // ganhador 2 ganhou 
        QuantosMatou[Tributos[ganhador2]]++;
        removerTributo(Tributos[ganhador1]);
        
        ganhador4 = ganhador2; // armazena para proxima batalha
    }

    //ganhador 4 x ganhador 3
    if (numeroRandom == 0) {
        // ganhador 4 ganhou 
        QuantosMatou[Tributos[ganhador4]]++;
        removerTributo(Tributos[ganhador3]);
        
        campeao = ganhador4; 
    } else {
        // ganhador 3 ganhou 
        QuantosMatou[Tributos[ganhador3]]++;
        removerTributo(Tributos[ganhador4]);
        
        campeao = ganhador3; 
    }

    // campeao é removido? 
    // removerTributo(Tributos[campeao]);

}