#include "codigosVorazes.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


#define MAXTRIBUTOS 12
#define MAXNOME 50

void CadastrarTributo(int id);
bool validarNome(char *nome);
bool validarSexo(char sexo);
bool validarIdade(int idade);
bool validarDistrito(int distrito);
void listarTributos(int id);
void sortearTributos(int id);

char Nome[MAXTRIBUTOS][MAXNOME], Sexo[MAXTRIBUTOS];
int Idade[MAXTRIBUTOS], Distrito[MAXTRIBUTOS], Id[MAXTRIBUTOS], id;

void CadastrarTributo(int id)
{

    int idade, distrito;
    char nome[MAXNOME], sexo;

    printf("Nome: ");
    scanf(" %49[^\n]", nome);

    printf("Sexo: ");
    scanf(" %c", &sexo);

    printf("Idade: ");
    scanf("%d", &idade);

    printf("Distrito: ");
    scanf("%d", &distrito);

    if (validarDistrito(distrito) && validarIdade(idade) && validarNome(nome) && validarSexo(sexo))
    {
        int i = 0;
        while (nome[i] != '\0' && i < MAXNOME - 1) /*armazena a string digitada no vetor Nomes;
                                                Enquanto tiver caracters e estiver dentro do limite(MAXNOME), guarda dentro do vetor Nomes na posição id*/
        {
            Nome[id][i] = nome[i];
            i++;
        }

        Nome[id][i] = '\0';

        Id[id] = id;
        Idade[id] = idade;
        Distrito[id] = distrito;
        Sexo[id] = sexo;

        printf("\nTributo Cadastrado com Sucesso!!\n");
    }

    else
    {
        printf("\nerro ao cadastrar tributo\n");
    }
}

void listarTributos(int id)
{

    printf("\nId: %d - Nome: %s - Sexo: %c - Idade: %d - Distrito: %d\n", Id[id], Nome[id], Sexo[id], Idade[id], Distrito[id]);
}
bool validarNome(char *nome)
{ // segundo as regras do c, quando um vetor é utilizado como parametro em uma função ele automaticamente vira um ponteiro

    if (strlen(nome) < 2)
        return false; // verifica se o nome possui mais que 2 digitos

    for (int i = 0; nome[i] != '\0'; i++)
    {                                            // lê a string
        if (!isalpha(nome[i]) && nome[i] != ' ') // verifica se são caracters validos
        {
            return false;
        }
    }
    return true;
}
bool validarIdade(int idade)
{

    if (idade >= 12 && idade <= 18)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool validarDistrito(int distrito)
{

    if (distrito > 0 && distrito <= 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool validarSexo(char sexo)
{

    if (sexo == 'F' || sexo == 'f' || sexo == 'M' || sexo == 'm')
    {
        return true;
    }
}
void sortearTributos(int total)
{
    bool D1_fem = false, D1_mas = false;
    bool D2_fem = false, D2_mas = false;
    bool D3_fem = false, D3_mas = false;

    int Tributos[6];   
    int sorteados = 0;
    bool usado[MAXTRIBUTOS] = {false}; //nenhum tributo foi sprteado ainda

    srand(time(NULL));  // gera os num na sequencia aleatoria

    while (sorteados < 6)
    {
        int num_sorteado = rand() % total; //aqui sorteia, o %id faz com que sorteie só numeros entre 0 e o ultimo "tributo"

        if (usado[num_sorteado])
            continue;  //verifica se uma pessoa já foi sorteada

        
        if (Distrito[num_sorteado] == 1)// isso aqui nem precisa explicar, é só ler aí ;)
        {
            if ((Sexo[num_sorteado] == 'm' || Sexo[num_sorteado] == 'M') && !D1_mas)
            {
                Tributos[sorteados++] = num_sorteado;
                D1_mas = true;
                usado[num_sorteado] = true;
            }
            else if ((Sexo[num_sorteado] == 'f' || Sexo[num_sorteado] == 'F') && !D1_fem)
            {
                Tributos[sorteados++] = num_sorteado;
                D1_fem = true;
                usado[num_sorteado] = true;
            }
        }
        else if (Distrito[num_sorteado] == 2)
        {
            if ((Sexo[num_sorteado] == 'm' || Sexo[num_sorteado] == 'M') && !D2_mas)
            {
                Tributos[sorteados++] = num_sorteado;
                D2_mas = true;
                usado[num_sorteado] = true;
            }
            else if ((Sexo[num_sorteado] == 'f' || Sexo[num_sorteado] == 'F') && !D2_fem)
            {
                Tributos[sorteados++] = num_sorteado;
                D2_fem = true;
                usado[num_sorteado] = true;
            }
        }
        else if (Distrito[num_sorteado] == 3)
        {
            if ((Sexo[num_sorteado] == 'm' || Sexo[num_sorteado] == 'M') && !D3_mas)
            {
                Tributos[sorteados++] = num_sorteado;
                D3_mas = true;
                usado[num_sorteado] = true;
            }
            else if ((Sexo[num_sorteado] == 'f' || Sexo[num_sorteado] == 'F') && !D3_fem)
            {
                Tributos[sorteados++] = num_sorteado;
                D3_fem = true;
                usado[num_sorteado] = true;
            }
        }
    }

    
    printf("\nTributos Sorteados na ordem do sorteio:\n");
    for (int i = 0; i < 6; i++)
    {
        int idx = Tributos[i];
        printf("Id: %d - Nome: %s - Sexo: %c - Idade: %d - Distrito: %d\n",
               Id[idx], Nome[idx], Sexo[idx], Idade[idx], Distrito[idx]);
    }

}