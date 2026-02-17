# Atividade Semana 02: Bubble Sort vs Selection Sort

Código em C da atividade da semana 2. A ideia do teste foi rodar os dois algoritmos no pior cenário possível: passando um vetor preenchido de ordem decrescente.

## Resultados

Rodando o código, os tempos e operações foram esses:

| Algoritmo      | Tamanho | Tempo (ms) | Comparações | Movimentações |
|----------------|---------|------------|-------------|---------------|
| Bubble Sort    | 100     | XX.XXX     | 4950        | 14850         |
| Selection Sort | 100     | XX.XXX     | 4950        | 147           |
| Bubble Sort    | 1000    | XX.XXX     | 499500      | 1498500       |
| Selection Sort | 1000    | XX.XXX     | 499500      | 1497          |
| Bubble Sort    | 10000   | XX.XXX     | 49995000    | 149985000     |
| Selection Sort | 10000   | XX.XXX     | 49995000    | 14997         |

## Qual foi o melhor?

O **Selection Sort** ganhou.

**O motivo:**
Como o vetor estava ao contrário, o Bubble Sort sofreu bastante. Ele foi obrigado a fazer trocas o tempo todo, empurrando número por número. 

Já o Selection Sort é mais eficiente com a memória: ele varre o vetor inteiro procurando o menor número e faz no máximo uma única troca por rodada. No fim das contas, os dois até fazem o mesmo tanto de comparações, mas como o Bubble Sort movimenta muito mais dados, o tempo de execução dele vai lá pra cima.

Como rodar este projeto:
1. Baixe o arquivo `atividade_semana02.c`.
2. Compile em qualquer IDE de C/C++.
3. Execute para ver a tabela de performance.