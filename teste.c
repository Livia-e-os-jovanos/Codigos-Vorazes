#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTRIBUTOS 13
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

int main(){

    int id = 0;
    while(id < MAXTRIBUTOS)
    {
        CadastrarTributo(id);
        id++;
    }
    sortearTributos(id);
    id = 0;


    while (id < MAXTRIBUTOS)
    {
        listarTributos(id);
        id++;
    }
    
    
    return 0;
}

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


    if(validarDistrito(distrito) && validarIdade(idade) && validarNome(nome) && validarSexo(sexo))
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
bool validarNome(char *nome){ // segundo as regras do c, quando um vetor é utilizado como parametro em uma função ele automaticamente vira um ponteiro

    if(strlen(nome) < 2) return false; //verifica se o nome possui mais que 2 digitos

    for(int i = 0; nome[i] != '\0'; i++){ //lê a string
        if(!isalpha(nome[i]) && nome[i] != ' ') //verifica se são caracters validos
        {
                return false;
        }
    }
    return true;

}
bool validarIdade(int idade){

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

    if (distrito > 0 && distrito <= 6)
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
void sortearTributos(int id)
{
    bool D1_fem = false;
    bool D1_mas = false;
    bool D2_fem = false;
    bool D2_mas = false;
    bool D3_fem = false;
    bool D3_mas = false;

    int num_sorteado;
    int Tributos[6];
    int sorteados = 0;

    bool usado[id];

    for (int i = 0; i < id; i++) //verifica se uma pessoa já foi sorteada
        usado[i] = false;

    while (sorteados < 6)
    {
        num_sorteado = rand() % id; //aqui sorteia, o %id faz com que sorteie só numeros entre 0 e o ultimo "tributo"

        if (usado[num_sorteado]) // se o tributo já foi sorteado, sorteia novamente
            continue;

        if (Distrito[num_sorteado] == 1) // isso aqui nem precisa explicar, é só ler aí ;)
        {
            if (Sexo[num_sorteado] == 'm' && D1_mas == false)
            {
                Tributos[sorteados] = num_sorteado;
                D1_mas = true;
                usado[num_sorteado] = true;
                sorteados++;
            }
            else if (Sexo[num_sorteado] == 'f' && D1_fem == false)
            {
                Tributos[sorteados] = num_sorteado;
                D1_fem = true;
                usado[num_sorteado] = true;
                sorteados++;
            }
        }
        if (Distrito[num_sorteado] == 2)
        {
            if (Sexo[num_sorteado] == 'm' && D2_mas == false)
            {
                Tributos[sorteados] = num_sorteado;
                D2_mas = true;
                usado[num_sorteado] = true;
                sorteados++;
            }
            else if (Sexo[num_sorteado] == 'f' && D2_fem == false)
            {
                Tributos[sorteados] = num_sorteado;
                D2_fem = true;
                usado[num_sorteado] = true;
                sorteados++;
            }
        }
        if (Distrito[num_sorteado] == 3)
        {
            if (Sexo[num_sorteado] == 'm' && D3_mas == false)
            {
                Tributos[sorteados] = num_sorteado;
                D3_mas = true;
                usado[num_sorteado] = true;
                sorteados++;
            }
            else if (Sexo[num_sorteado] == 'f' && D3_fem == false)
            {
                Tributos[sorteados] = num_sorteado;
                D3_fem = true;
                usado[num_sorteado] = true;
                sorteados++;
            }
        }

    }
    printf("Tributos Sorteados: ");
    for (int i = 0; i < 12; i++)
    {
       listarTributos(i);
    }
    printf("\n");
}