# Trabalho final de Programação 1 - 90 IFs Para Casar
- Último trabalho proposto na disciplina de Programação 1 no curso de Bacharelado em Ciência da Computação da UFPR - Profº André R. Abed Grégio
- Aluno: Caio E. F. de Miranda - caio.miranda@ufpr.br

- # Proposta
- - A proposta deste trabalho é implementar um simulador de pareamentos entre candidatos e pretendentes, com base nos seus atributos.

- # Estruturas
> Pessoas que têm um vetor binário (e.g. se uma pessoa tem o primeiro atributo mas não tem os outros, seu vetor de atributos é: {1, 0, 0, 0, 0, 0}) de atributos com tamanho fixo (o tamanho foi definido em 'marriage.h' com a macro 'MAX_ATR'), um valor de 'relevância' usado para determinar se o pretendente tem chance de concorrer a um 'match', um caracter de identificação e ponteiros de 'próximo' e 'anterior' para encadeamento na lista de pretendentes e de concorrentes;
- - Uma pilha de candidatos;
- - Duas listas circulares duplamente encadeadas - uma com os pretendentes e uma com os concorrentes (pretendentes que podem realizar um 'match');
