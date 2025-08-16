#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

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
bool validarDistrito(int distrito){

    if(distrito > 0 && distrito <= 6)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool validarSexo(char sexo){


    if(sexo == 'F' || sexo == 'f' || sexo == 'M' || sexo == 'm')
        {
            return true;
        }

}
