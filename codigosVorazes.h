#ifndef CODIGOSVORAZES_H
#define CODIGOSVORAZES_H

#include <stdbool.h>

#define MAXTRIBUTOS 12
#define MAXNOME 50

extern char Nome[MAXTRIBUTOS][MAXNOME], Sexo[MAXTRIBUTOS];
extern int Idade[MAXTRIBUTOS], Distrito[MAXTRIBUTOS], Id[MAXTRIBUTOS], id;

void CadastrarTributo(int id);
bool validarNome(char *nome);
bool validarSexo(char sexo);
bool validarIdade(int idade);
bool validarDistrito(int distrito);
void listarTributos(int id);
void sortearTributos(int id);



#endif