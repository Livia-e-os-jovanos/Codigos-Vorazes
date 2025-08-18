#ifndef CODIGOSVORAZES_H
#define CODIGOSVORAZES_H

#include <stdbool.h>

#define MAXTRIBUTOS 6
#define MAXNOME 50
#define EDICOES 2

// Variáveis globais definidas no .c
extern char Nome[MAXTRIBUTOS][MAXNOME];
extern char Sexo[MAXTRIBUTOS];
extern int Idade[MAXTRIBUTOS];
extern int Distrito[MAXTRIBUTOS];
extern int Id[MAXTRIBUTOS];
extern int Tributos[6];
extern int sorteadosCopia[6];
extern int forca[MAXTRIBUTOS];
extern int forca2[MAXTRIBUTOS];
extern int *ptrFatalityPlace[5];
extern int Campeoes[EDICOES];
extern int edc, eddc;
extern char CampeoesNomes[EDICOES][MAXNOME];


/* Funções */
void CadastrarTributo(int id);
void listarTributos(int id);
bool validarNome(char *nome);
bool validarIdade(int idade);
bool validarDistrito(int distrito);
bool validarSexo(char sexo);
void sortearTributos(int total);
void removerTributo(int id);
void iniciarJogos(void);
void estatisticaForca(void);
void localMorte(int batalha);
int contarDistrito();

#endif
