#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <codigos_vorazes.h>

#define MAXTRIBUTOS 15
#define MAXNOME 50

void CadastrarTributo(int id);
bool validarNome(char *nome);
bool validarSexo(char sexo);
bool validarIdade(int idade);
bool validarDistrito(int distrito);
void listarTributos(int id);


char Nome[MAXTRIBUTOS][MAXNOME], Sexo[MAXTRIBUTOS];
int Idade[MAXTRIBUTOS], Distrito[MAXTRIBUTOS], Id[MAXTRIBUTOS], id; 

int tributosD1[MAXTRIBUTOS], tributosD2[MAXTRIBUTOS], tributosD3[MAXTRIBUTOS], tributosD4[MAXTRIBUTOS], tributosD5[MAXTRIBUTOS], tributosD6[MAXTRIBUTOS];

int main () {
    
}