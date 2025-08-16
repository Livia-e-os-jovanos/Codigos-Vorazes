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
int Idade[MAXTRIBUTOS], Distrito[MAXTRIBUTOS], Id[MAXTRIBUTOS], id, Tributos[6], forca;  


/*===================================CADASTRAR===================================================*/

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

// Remove aquele que perdeu
void removerTributo (int quemSai) { 
    // vou receber quem perdeu (ID)
    // aí eu tenho que colocar -1 em todas listas na parte dele
    // -1 em int, X em char
    
    // salvo elas como variáveis também no .h
    Nome[quemSai][0] = 'X';// tem que fzer com q quando encontre o X, entenda que pode sobrescrever
    Nome[quemSai][1] = '\0'; // \0 representa pro C que chegou no fim da string e que não vai ter mais nenhum caractere
    Sexo[quemSai] = 'X';
    Idade[quemSai] = -1;

    //livia reseta a lista de quantos matou?
} 

void iniciarJogos (int Tributos[], int tamanho) {

    srand(time(NULL));
    /* a função rand não gera números aleatórios, ela usa uma semente (algum 
    valor do computador) como um ponto raíz para extrair os números.
    srand é para alterar essa semente, então para aumentar a variancia, a
    biblioteca time é incluída, com o valor NULL, que é uma constante que diz
    para o computador não apontar para nada válido */

    // preciso pegar na ordem que vem
    //int i = 0, j = i + 1, maximo = 1;
    int ganhador1, ganhador2, ganhador3, ganhador4, campeao; // rever nome dos finalistas
    int numeroRandom = rand() % 2; // só retorna 0 ou 1
    //Tributos[0] x Tributos[1]
    if (numeroRandom == 0) {
        // 0 ganhou 
        // acredito que a lista de tributos vem com os IDs
        forca[Tributos[0]]++;
        removerTributo(Tributos[1]);
        
        ganhador1 = 0; // armazena para proxima batalha
    } else {
        // 1 ganhou 
        forca[Tributos[1]]++;
        removerTributo(Tributos[0]);
        
        ganhador1 = 1; // armazena para proxima batalha
    }
    
    //Tributos[2] x Tributos[3]
        if (numeroRandom == 0) {
        // 2 ganhou 
        forca[Tributos[2]]++;
        removerTributo(Tributos[3]);
        
        ganhador2 = 2; // armazena para proxima batalha
    } else {
        // 3 ganhou 
        forca[Tributos[3]]++;
        removerTributo(Tributos[2]);
        
        ganhador2 = 3; // armazena para proxima batalha
    }

    //Tributos[4] x Tributos[5]
    if (numeroRandom == 0) {
        // 4 ganhou 
        forca[Tributos[4]]++;
        removerTributo(Tributos[5]);
        
        ganhador3 = 4; // armazena para proxima batalha
    } else {
        // 5 ganhou 
        forca[Tributos[5]]++;
        removerTributo(Tributos[4]);
        
        ganhador3 = 5; // armazena para proxima batalha
    }

    //Ganhador 1 x Ganhador 2
    if (numeroRandom == 0) {
        // ganhador 1 ganhou 
        forca[Tributos[ganhador1]]++;
        removerTributo(Tributos[ganhador2]);
        
        ganhador4 = ganhador1; // armazena para proxima batalha
    } else {
        // ganhador 2 ganhou 
        forca[Tributos[ganhador2]]++;
        removerTributo(Tributos[ganhador1]);
        
        ganhador4 = ganhador2; // armazena para proxima batalha
    }

    //ganhador 4 x ganhador 3
    if (numeroRandom == 0) {
        // ganhador 4 ganhou 
        forca[Tributos[ganhador4]]++;
        removerTributo(Tributos[ganhador3]);
        
        campeao = ganhador4; 
    } else {
        // ganhador 3 ganhou 
        forca[Tributos[ganhador3]]++;
        removerTributo(Tributos[ganhador4]);
        
        campeao = ganhador3; 
    }

    // campeao é removido?  
    // criar uma lista com os tributos que serão removidos GEOVANNI
    // removerTributo(Tributos[campeao]);

    /*
    duplicar a lista de quem foi sorteado
    a força será linkada a essa lista duplicada e livia vai usar ela
    */
}

void EstatisticaForca(int lista[6], int *qtdmin, int *qtdmax, float *qtdmedia) {
    int soma= 0;
     *qtdmin = forca[0]; // força do primeiro tributo
    *qtdmax = forca[0]; // força do primeiro tributo

    for (int i= 1; i <=6; i++) {
        if (forca[i] < *qtdmin) { 
            *qtdmin = forca[i]; //verifica se a forcaa e menor que a anterior

        }
        if (forca[i] > *qtdmax) { 
            *qtdmax= forca[i]; // verifica se a forca e maior que a anterior

        }
         soma += forca[i]; //soma as forcas

    }
    *qtdmedia = soma/ 6.0; //calcula a media 
}