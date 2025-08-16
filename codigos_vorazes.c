#include "codigos_vorazes.h"
// nesse arquivo coloca toda a função

// Remove aquele que perdeu
void removerTributo (int quemPerdeu) { 
    // vou receber quem perdeu (ID)
    // aí eu tenho que colocar -1 em todas listas na parte dele
    // -1 em int, X em char
    
    // salvo elas como variáveis também no .h
    Nome[quemPerdeu][0] = 'X';// tem que fzer com q quando encontre o X, entenda que pode sobrescrever
    Nome[quemPerdeu][1] = '\0'; // \0 representa pro C que chegou no fim da string e que não vai ter mais nenhum caractere
    Sexo[quemPerdeu] = 'X';
    Idade[quemPerdeu] = -1;
}
