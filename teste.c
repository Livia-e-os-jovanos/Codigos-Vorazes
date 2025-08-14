#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


#define MAXTRIBUTOS 1
#define MAXNOME 50

void CadastrarTributo(int id);
bool validarNome(char *nome);
bool validarSexo(char sexo);
bool validarIdade(int idade);
bool validarDistrito(int distrito);

char Nome[MAXTRIBUTOS][MAXNOME], Sexo[MAXTRIBUTOS];
int Idade[MAXTRIBUTOS], Distrito[MAXTRIBUTOS], id; 
bool dadosValidos = true;


int main(){

    int id = 0;
    while(id <= MAXTRIBUTOS)
    {
        CadastrarTributo(id);
        id++;
    }
    
    return 0;
}

void CadastrarTributo(int id){ 

    int idade, distrito;
    char nome[MAXNOME], sexo;


    printf("\nNome: ");
    scanf(" %49[^\n]", nome);
    validarNome(nome);


    printf("Sexo: ");
    scanf(" %c", &sexo);
    validarSexo(sexo);

    printf("Idade: ");
    scanf("%d", &idade);
    validarIdade(idade);


    printf("Distrito: ");
    scanf("%d", &distrito);

    validarDistrito(distrito);
    

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

        

        Idade[id] = idade;
        Distrito[id] = distrito;
        Sexo[id] = sexo;

        
        printf("\nTributo Cadastrado com Sucesso!!");
        //printf("\nNome: %s\nSexo: %c\nIdade: %d\nDistrito: %d\n", nome, sexo, Idade[id], Distrito[id]);
    }

    else
    {
        printf("\nerro ao cadastrar tributo\n");
    }


    
}
bool validarNome(char *nome){ // segundo as regras do c, quando um vetor é utilizado como parametro em uma função ele automaticamente vira um ponteiro

    if(strlen(nome) > 1){
        for(int i = 0; i != '\0'; i++){
            if(isalpha(nome[i]) || nome[i] == ' ')
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
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

    if(distrito > 0 && distrito <= 12)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool validarSexo(char sexo){

    if(isalpha(sexo))
    {
        if(sexo == 'F' || sexo == 'f' || sexo == 'M' || sexo == 'm')
        {
            return true;
        }
    }
    else{
        return false;
    }
}
    