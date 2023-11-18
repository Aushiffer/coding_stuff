# Trabalho final de Programação 1 - 90 IFs Para Casar
- Último trabalho proposto na disciplina de Programação 1 no curso de Bacharelado em Ciência da Computação da UFPR - Profº André R. Abed Grégio
- Aluno: Caio E. F. de Miranda - caio.miranda@ufpr.br

# Ferramentas usadas
- C;
- GCC;
- GDB;
- Valgrind;
- Makefile.

# Proposta
- A proposta deste trabalho é implementar um simulador de pareamentos entre candidatos e pretendentes, com base nos seus atributos.

# Estruturas
- Pessoas que têm um vetor binário (e.g. se uma pessoa tem o primeiro e o segundo atributo mas não tem os outros, seu vetor de atributos é: {1, 1, 0, 0, 0, 0}) de atributos com tamanho fixo (o tamanho foi definido em 'marriage.h' com a macro 'MAX_ATR'), um valor de 'relevância' usado para determinar se o pretendente tem chance de concorrer a um 'match', um caracter de identificação e ponteiros de 'próximo' e 'anterior' para encadeamento na lista de pretendentes e de concorrentes;
- Uma pilha de candidatos;
- Duas listas circulares duplamente encadeadas - uma com os pretendentes e uma com os concorrentes (pretendentes que podem realizar um 'match').

# Funcionamento do programa
- São colocados candidatos na pilha de candidatos e pretendentes na lista de pretendentes. Todas as pessoas são representadas pela mesma 'struct pessoa';
- São exibidos os atributos que os candidatos querem e os atributos que os pretendentes têm;
- (I) O candidato é desempilhado da pilha de pretendentes, e seus atributos são salvos;
- Inicia-se o pareamento entre o candidato atual e os pretendentes:
- - Para cada um dos pretendentes, é verificado se o candidato possui pelo menos dois atributos em comum com ele(s);
- - Se tiver, o pretendente é mandado para a lista de concorrentes, na qual pode concorrer a um 'match';
- - (II) Se, na lista de concorrentes, tiver apenas um pretendente, ele é automaticamente removido dessa lista e vai tentar realizar um 'match' com o candidato;
- - Se não existirem concorrentes, o candidato fica sem par;
- - Se tiver mais de um concorrente, eles disputam jogando 1d20 por 'relevância' (a 'relevância' representa quantos atributos eles tẽm em comum com o candidato, então é justo que quem tiver mais, tem mais chances de vencer) para saber quem vai tentar o 'match'. Quem ganhar, sai da lista de concorrentes e vai disputar pelo 'match' com o candidato. Quem perder, volta para a lista de pretendentes;
- - O que está em (II) acontece;
- Pareamento é finalizado;
- Disputa pelo 'match' inicia:
- - O candidato e o pretendente selecionado anteriormente jogam 1d20 por atributo que possuem, por 90 iterações;
- - Se o pretendente tiver mais pontos que o candidato, ocorre um 'mismatch' e o pretendente volta para a lista de pretendentes. Com isso, a disputa termina;
- - Se o candidato tiver um número de pontos maior ou igual ao do pretendente, ocorre um 'match' e a disputa termina;
- Disputa pelo 'match' termina;
- Volta para (I) até que a pilha de candidatos esteja vazia;
- Exibe quantos matches, mismatches e pessoas sem par existem ao final do programa.