#ifndef CODIGOSVORAZES_H
#define CODIGOSVORAZES_H

#include <stdbool.h>

#define MAXTRIBUTOS 12
#define MAXNOME 50

extern char Nome[MAXTRIBUTOS][MAXNOME], Sexo[MAXTRIBUTOS];
extern int Idade[MAXTRIBUTOS], Distrito[MAXTRIBUTOS], Id[MAXTRIBUTOS], id, Tributos[6], forca[MAXTRIBUTOS] = {0};

void CadastrarTributo(int id);
bool validarNome(char *nome);
bool validarSexo(char sexo);
bool validarIdade(int idade);
bool validarDistrito(int distrito);
void listarTributos(int id);
void sortearTributos(int id);

void removerTributo (int quemSai);

void iniciarJogos (int Tributos[], int tamanho);

void EstatisticaForca(int Tributos[6], int *qtdmin, int *qtdmax, float *qtdmedia);

#endif