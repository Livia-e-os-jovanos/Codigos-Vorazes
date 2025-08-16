#ifndef CODIGOS_VORAZES_H
#define CODIGOS_VORAZES_H

// aqui ficam as constantes, que vão conseguir ser interpretadas de todos arquivos
#define MAXTRIBUTOS 15
#define MAXNOME 50

extern char Nome[MAXTRIBUTOS][MAXNOME], Sexo[MAXTRIBUTOS];
extern int Idade[MAXTRIBUTOS], Distrito[MAXTRIBUTOS], Id[MAXTRIBUTOS];

// aqui ficam os protótipos
void removerTributo (int quemSai);

#endif