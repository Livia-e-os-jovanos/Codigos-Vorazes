#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "codigosVorazes.h"

int main()
{

    int escolha;

    srand(time(NULL)); // faz com que o rand nn faça sempre o mesmo sorteio
    int id = 0, rep = 1;

    while (rep < EDICOES + 1)
    { // aqui é um laço pra controlar as edições

        printf("\n====================Edicao %d=========================\n", rep); // impreime em qual edição está

        id = 0;
        while (id < MAXTRIBUTOS) //laço para cadastrar todos os jovens que seram sorteados
        {
            CadastrarTributo(id); //chama a função cadastrarTributo(que na vdd aqui são os jovens) e manda o id como parametro
            id++;
        }

        printf("Digite 1 para listar os jovens cadastrados e 2 para sortear os tributos: "); //o usuario tem dois caminhos: listar ou fazer o sorteio logo
        scanf("%d", &escolha);

        if (escolha == 1)
        {
            for (int i = 0; i < MAXTRIBUTOS; i++)
            {
                listarTributos(i); //lista tributos
            }
        }
        else //aqui vai sortear, inicar os jogos com os tributos sorteados vai mostrar a estatistica da forca e 
        //detalhes sobre os jogos;
        {
            sortearTributos(MAXTRIBUTOS);
            iniciarJogos();
            estatisticaForca();
        }
        rep++;
    }
    for (int i = 0; i < edc; i++) //edc(edição): indice utilizado para o vetor de Id dos campeoes
    {
        printf("\nCampeão da edição %d: %s\n", i, CampeoesNomes[i]); // imprime o nome dos Campeoes de cada edicao 
    }
    int maiorDist = contarDistrito(); //chama a função que verifica qual distrito teve a maior quant de vitrias

    if (maiorDist == (-1))
    {
        printf("Empate entre os distritos");
    }
    else
    {
        printf("\nParabéns ao distrito %d que acumula o maior numero de vencedores!!", maiorDist);
    }

    return 0;
}
