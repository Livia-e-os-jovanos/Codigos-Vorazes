#include "codigosVorazes.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

/* Variáveis globais definidas no .c */
char Nome[MAXTRIBUTOS][MAXNOME], Sexo[MAXTRIBUTOS];
int Idade[MAXTRIBUTOS], Distrito[MAXTRIBUTOS], Id[MAXTRIBUTOS];
int Tributos[6], sorteadosCopia[6];
int forca[MAXTRIBUTOS], forca2[MAXTRIBUTOS] = {0}, *ptrFatalityPlace[5];
int Campeoes[EDICOES] = {0}, edc = 0, eddc = 0, x = 0, DistritosCampeoes[EDICOES] = {0};
char CampeoesNomes[EDICOES][MAXNOME];

/*===================================CADASTRO===================================================*/
void CadastrarTributo(int id)
{
    int idade, distrito;
    char nome[MAXNOME], sexo;

    printf("Nome: ");
    scanf(" %49[^\n]", nome); // o %49 é para delimitar nomes até 49 digitos

    printf("Sexo: ");
    scanf(" %c", &sexo);

    printf("Idade: ");
    scanf("%d", &idade);

    printf("Distrito: ");
    scanf("%d", &distrito);

    if (validarDistrito(distrito) && validarIdade(idade) && validarNome(nome) && validarSexo(sexo)) // so cadastra se todas as funções forem vdd
    {
        strcpy(Nome[id], nome);
        Id[id] = id;
        Idade[id] = idade;
        Distrito[id] = distrito;
        Sexo[id] = sexo;
        forca[id] = 0;  //  isso aqui foi adicionado para resolver bug
        forca2[id] = 0; // isso tbm
        printf("\nTributo Cadastrado com Sucesso!!\n");
    }
    else
    {
        printf("\nErro ao cadastrar tributo\n");
    }
}

bool validarNome(char *nome)
{
    if (strlen(nome) < 2)
    {
        return false;
    }

    for (int i = 0; nome[i] != '\0'; i++)
    {
        if (!isalpha(nome[i]) && nome[i] != ' ') // valida se os caracteres fazem parte do alfabeto ou se são espaço
        {
            return false;
        }
    }
    return true;
}

bool validarIdade(int idade)
{
    return idade >= 12 && idade <= 18; // o tributo tem que ter entre 12 e 18 anos
}

bool validarDistrito(int distrito)
{
    return distrito > 0 && distrito <= 3; // só são válidos distritos 1-3
}

bool validarSexo(char sexo)
{
    return sexo == 'F' || sexo == 'f' || sexo == 'M' || sexo == 'm'; // Verifica se os carac. de sexo são validos
}

void listarTributos(int id)
{
    printf("\nId: %d - Nome: %s - Sexo: %c - Idade: %d - Distrito: %d\n", Id[id], Nome[id], Sexo[id], Idade[id], Distrito[id]);
}

/*===================================SORTEIO===================================================*/
void sortearTributos(int total)
{
    bool D1_fem = false, D1_mas = false;
    bool D2_fem = false, D2_mas = false;
    bool D3_fem = false, D3_mas = false;

    int sorteados = 0;
    bool usado[MAXTRIBUTOS] = {false};

    srand(time(NULL));

    while (sorteados < 6)
    {
        int num_sorteado = rand() % total; // sorteia um numero entre 0 e o ultimo indice dos jovens cadastrados
        if (usado[num_sorteado])
        { // se o numero sorteado já foi usado sorteia outros até que sorteie um valido
            continue;
        }

        if (Distrito[num_sorteado] == 1) // verifica se é do D1
        {
            if ((Sexo[num_sorteado] == 'M' || Sexo[num_sorteado] == 'm') && !D1_mas) // se for homem e nn tiver sorteado um homem do Distrito
            {
                Tributos[sorteados++] = num_sorteado; // adiciona no vetor de tributos que participarão dos jogos
                D1_mas = true;                        // atualiza para que nn armazene novamente um tributo com as msm caract.
                usado[num_sorteado] = true;
            }
            else if ((Sexo[num_sorteado] == 'F' || Sexo[num_sorteado] == 'f') && !D1_fem)
            {
                Tributos[sorteados++] = num_sorteado;
                D1_fem = true;
                usado[num_sorteado] = true;
            }
        }
        else if (Distrito[num_sorteado] == 2)
        {
            if ((Sexo[num_sorteado] == 'M' || Sexo[num_sorteado] == 'm') && !D2_mas)
            {
                Tributos[sorteados++] = num_sorteado;
                D2_mas = true;
                usado[num_sorteado] = true;
            }
            else if ((Sexo[num_sorteado] == 'F' || Sexo[num_sorteado] == 'f') && !D2_fem)
            {
                Tributos[sorteados++] = num_sorteado;
                D2_fem = true;
                usado[num_sorteado] = true;
            }
        }
        else if (Distrito[num_sorteado] == 3)
        {
            if ((Sexo[num_sorteado] == 'M' || Sexo[num_sorteado] == 'm') && !D3_mas)
            {
                Tributos[sorteados++] = num_sorteado;
                D3_mas = true;
                usado[num_sorteado] = true;
            }
            else if ((Sexo[num_sorteado] == 'F' || Sexo[num_sorteado] == 'f') && !D3_fem)
            {
                Tributos[sorteados++] = num_sorteado;
                D3_fem = true;
                usado[num_sorteado] = true;
            }
        }
    }

    printf("\n=================TRIBUTOS SORTEADOS=======================\n");
    for (int i = 0; i < 6; i++)
    {
        int idx = Tributos[i];
        printf("Id: %d - Nome: %s - Sexo: %c - Idade: %d - Distrito: %d\n",
               Id[idx], Nome[idx], Sexo[idx], Idade[idx], Distrito[idx]);
        forca2[idx] = 0; // reseta força do torneio
    }
}

/*===================================JOGOS===================================================*/
// sobrescreve os dados de quem perde a batalha
void removerTributo(int id)
{
    Nome[id][0] = 'X';
    Nome[id][1] = '\0';
    Sexo[id] = 'X';
    Idade[id] = -1;
}

void iniciarJogos()
{
    printf("\nQue comecem os jogos e que a sorte esteja sempre ao seu favor!\n");
    int ganhador1, ganhador2, ganhador3, ganhador4, campeao;
    int eliminado1, eliminado2, eliminado3, eliminado4, eliminado5;
    int numeroRandom, batalha;

    // Jogo 1
    printf("\n======================1º CANHÃO=============================\n");

    // faz um sorteio entre 0 e 1
    numeroRandom = rand() % 2;

    // verifica e armazena o ganhador do primeiro conflito
    if (numeroRandom == 0)
    {
        ganhador1 = Tributos[0];
    }
    else
    {
        ganhador1 = Tributos[1];
    }

    // verifica e armazena o primeiro eliminado
    if (ganhador1 == Tributos[0])
    {
        eliminado1 = Tributos[1];
    }

    else
    {
        eliminado1 = Tributos[0];
    }

    batalha = 0;
    printf("\n%s(%d) matou %s(%d)\n", Nome[ganhador1], ganhador1, Nome[eliminado1], eliminado1);
    localMorte(batalha);

    if (numeroRandom == 0)
    {
        removerTributo(Tributos[1]);
    }
    else
    {
        removerTributo(Tributos[0]);
    }

    forca[ganhador1]++;
    /* é uma duplicata de força para possibilitar que os dados daqueles que morreram
    sejam utilizados para fazer a estatistica do combate atual*/
    forca2[ganhador1]++;

    // Jogo 2
    printf("\n======================2º CANHÃO=============================\n");

    // faz um sorteio entre 0 e 1
    numeroRandom = rand() % 2;

    // verifica e armazena o ganhador do segundo conflito
    if (numeroRandom == 0)
    {
        ganhador2 = Tributos[2];
    }
    else
    {
        ganhador2 = Tributos[3];
    }

    // verifica e armazena o segundo eliminado

    if (ganhador2 == Tributos[2])
    {
        eliminado2 = Tributos[3];
    }
    else
    {
        eliminado2 = Tributos[2];
    }

    batalha = 1;
    printf("\n%s(%d) matou %s(%d)\n", Nome[ganhador2], ganhador2, Nome[eliminado2], eliminado2);
    localMorte(batalha);

    // remove tributo eliminado
    if (numeroRandom == 0)
    {
        removerTributo(Tributos[3]);
    }
    else
    {
        removerTributo(Tributos[2]);
    }

    forca[ganhador2]++;
    /* é uma duplicata de força para possibilitar que os dados daqueles que morreram
    sejam utilizados para fazer a estatistica do combate atual*/
    forca2[ganhador2]++;

    // Jogo 3
    printf("\n======================3º CANHÃO=============================\n");

    // faz um sorteio entre 0 e 1
    numeroRandom = rand() % 2;

    // verifica e armazena o ganhador do terceiro conflito
    if (numeroRandom == 0)
    {
        ganhador3 = Tributos[4];
    }
    else
    {
        ganhador3 = Tributos[5];
    }

    // verifica e armazena o terceiro elimianado
    if (ganhador3 == Tributos[4])
    {
        eliminado3 = Tributos[5];
    }
    else
    {
        eliminado3 = Tributos[4];
    }

    batalha = 2;
    printf("\n%s(%d) matou %s(%d)\n", Nome[ganhador3], ganhador3, Nome[eliminado3], eliminado3);
    localMorte(batalha);

    // remove tributo eliminado
    if (numeroRandom == 0)
    {
        removerTributo(Tributos[5]);
    }
    else
    {
        removerTributo(Tributos[4]);
    }

    forca[ganhador3]++;
    /* é uma duplicata de força para possibilitar que os dados daqueles que morreram
    sejam utilizados para fazer a estatistica do combate atual*/
    forca2[ganhador3]++;

    // Semifinal
    printf("\n======================4º CANHÃO=============================\n");

    // faz um sorteio entre 0 e 1
    numeroRandom = rand() % 2;

    // verifica e armazena o ganhador do quarto conflito
    if (numeroRandom == 0)
    {
        ganhador4 = ganhador1;
    }
    else
    {
        ganhador4 = ganhador2;
    }

    // verifica e armazena o quarto eliminado
    if (ganhador4 == ganhador1)
    {
        eliminado4 = ganhador2;
    }
    else
    {
        eliminado4 = ganhador1;
    }

    batalha = 3;
    printf("\n%s(%d) matou %s(%d)\n", Nome[ganhador4], ganhador4, Nome[eliminado4], eliminado4);
    localMorte(batalha);

    // remove btributo eliminado
    if (numeroRandom == 0)
    {
        removerTributo(ganhador2);
    }
    else
    {
        removerTributo(ganhador1);
    }

    forca[ganhador4]++;
    /* é uma duplicata de força para possibilitar que os dados daqueles que morreram
    sejam utilizados para fazer a estatistica do combate atual*/
    forca2[ganhador4]++;

    // Final
    printf("\n======================5º CANHÃO=============================\n");

    // faz um sorteio entre 0 e 1
    numeroRandom = rand() % 2;

    // verifica e armazena o ganhador do último conflito
    if (numeroRandom == 0)
    {
        campeao = ganhador4;
    }
    else
    {
        campeao = ganhador3;
    }

    // verifica e armazena o último iliminado
    if (campeao == ganhador4)
    {
        eliminado5 = ganhador3;
    }
    else
    {
        eliminado5 = ganhador4;
    }

    batalha = 4;
    printf("\n%s(%d) matou %s(%d)\n", Nome[campeao], campeao, Nome[eliminado5], eliminado5);

    localMorte(batalha);

    // remove tributo eliminado
    if (numeroRandom == 0)
    {
        removerTributo(ganhador3);
    }
    else
    {
        removerTributo(ganhador4);
    }

    forca[campeao]++;
    /* é uma duplicata de força para possibilitar que os dados daqueles que morreram
    sejam utilizados para fazer a estatistica do combate atual*/
    forca2[campeao]++;

    Campeoes[edc++] = campeao;                     // guarda o id de cada campeao
    strcpy(CampeoesNomes[x++], Nome[campeao]);     // guarda o nome do campeao de cada edição
    DistritosCampeoes[eddc++] = Distrito[campeao]; // guarda o distrito  campeoes

    printf("\n======================== CAMPEÃO===========================\n");
    printf("%s, distrito %d\n", Nome[campeao], Distrito[campeao]);
}

/*===================================ESTATÍSTICA===================================================*/
void estatisticaForca()
{
    printf("\n=============Força dos tributos neste torneio===============\n");

    int soma = 0;
    int maior = forca2[Tributos[0]];
    int menor = forca2[Tributos[0]];

    for (int i = 0; i < 6; i++)
    {
        int id = Tributos[i];
        int *ptr = &forca2[id]; // ponteiro para a força do tributo

        printf("Tributo %d: %d\n", id, *ptr);

        soma += *ptr;

        if (*ptr > maior)
        {
            maior = *ptr;
        } // valor guardado na posiç~o da memória apontado com ponteiro

        if (*ptr < menor)
        {
            menor = *ptr;
        }
    }

    float media = (float)soma / 6;

    printf("\n=======================Estatísticas========================\n"); // Mostra os resultados de maior,menor e a média de força entre os tributos do torneio
    printf("Maior força: %d\n", maior);
    printf("Menor força: %d\n", menor);
    printf("Média das forças: %.2f\n\n", media);
}

void localMorte(int batalha) // local da morte de cada tributo definida por sorteioo
{

    int localSort;
    int localMorte1 = 0, localdaMorte2 = 1, localdaMorte3 = 2, localdaMorte4 = 3, localdaMorte5 = 4; // Esses são os cinco cenários possíveis de morte

    localSort = rand() % 5; // aqui é sorteado um número que vai definir qual será o local da morte
    if (localSort == 0)
    {
        ptrFatalityPlace[batalha] = &localMorte1; // o ponteiro ptrFatalityPlace armazena o endereço da variavel sorteada
                                                  // Que supostamente é a coordenada do local da morte
    }
    else if (localSort == 1)
    {
        ptrFatalityPlace[batalha] = &localdaMorte2;
    }
    else if (localSort == 2)
    {
        ptrFatalityPlace[batalha] = &localdaMorte3;
    }
    else if (localSort == 3)
    {
        ptrFatalityPlace[batalha] = &localdaMorte4;
    }
    else
    {
        ptrFatalityPlace[batalha] = &localdaMorte5;
    }

    printf("Coordenada da morte: %p\n\n", ptrFatalityPlace[batalha]);
}
/*===================================MAIOR DISTRITO===================================================*/
int contarDistrito() // define o distrito campeão dos jogos
{
    int i = 0;
    int D1 = 0, D2 = 0, D3 = 0;

    for (i = 0; i < eddc; i++)
    { // edcc guarda quantos tributos campeões cada distrito tem
        if (DistritosCampeoes[i] == 1)
        {
            D1++; // vai contando o ínidce do tributo que representa o seu distrito
        }
        else if (DistritosCampeoes[i] == 2)
        {
            D2++;
        }
        else
        {
            D3++;
        }
    }
    // Faz a verificação de qual é o distrito com a maior quant de venc.
    if (D1 > D2 && D1 > D3)
    {
        return D1;
    }
    else if (D2 > D3)
    {
        printf("Distrito com mais vencedores: %d", D2);
        return D2;
    }
    else if (D1 == D2 || D2 == D3 || D1 == D3)
    {
        return (-1); // mando para a main para identificar que foi empate
    }
    else
    {
        printf("Distrito com mais vencedores: %d", D3);
        return D3;
    }
}
