# Codigos-Vorazes

<h2>Descrição</h2>
Trabalho requisitado pela disciplina de Estrutura de Dados, turma 2025.1 do curso de Análise e Desenvolvimento de Sistemas no IFBAIANO – Campus Guanambi. Este projeto consiste em uma biblioteca de funções inspiradas no universo de Jogos Vorazes, desenvolvida para praticar conceitos fundamentais de estruturas de dados.

<h2>Objetivo</h2>

  Criar funções que simulem a gestão de tributos (personagens) em um torneio.

  Praticar manipulação de listas, validação de dados e operações de inserção, atualização, remoção e listagem.

  Aprender e utilizar ponteiros

<h2>Funcionalidades</h2>

  CadastrarTributo(id) – recebe os dados de nome, idade, sexo e distrito do tributo e adiciona um tributo à lista.
  
  validarNome(*nome) - verifica se o nome foi digitado, se é menor que duas letras e valida se as letras estão no alfabeto.
    
  validarIdade(idade) - verifica se o tributo segue os requisitos de idade.
  
  validarDistrito(distrito) - verifica se é um distrito válido.
  
  validarSexo(sexo) - verifica se é valido.
    
  listarTributos() – exibe todos os tributos cadastrados.

  sortearTributos(total) – sorteia tributos para participar dos jogos.

  removerTributo(id) – remove um tributo caso ele tenha morrido no jogo.

  iniciarJogos() – dá início as batalhas entre tributos.

  estatisticaForca() - faz a média de força do jogo que ocorreu, exibindo máxima, mínima e média.

  localMorte(batalha) - exibe as coordenadas do campo de batalha em que ocorreu uma morte.

  contarDistrito() - define o distrito que teve mais campeões.

<h2>Como executar o projeto:</h2>

  Vá até a pasta em que os arquivos estão localizados, abra o terminal e execute:

  ```
  gcc codigosVorazes.c main.c -o app

  ./app
```

<b>Que a sorte esteja sempre com você! </b> 🍀🏹
