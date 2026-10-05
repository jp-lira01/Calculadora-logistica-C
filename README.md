# Calculadora de Frete em C

Projeto desenvolvido em C para simular o cálculo de frete de uma compra, considerando o peso do produto e a região de entrega.

O programa também realiza validações dos dados informados, calcula o valor total da compra e determina a data prevista de entrega de acordo com o prazo de cada região.

## Funcionalidades

* Cadastro do código, nome, peso e preço do produto
* Seleção da região de entrega
* Validação dos dados de entrada
* Cálculo do frete de acordo com peso e região
* Cálculo do valor total da compra
* Registro da data e hora da compra
* Validação de datas e horários
* Identificação de anos bissextos
* Cálculo da quantidade de dias de cada mês
* Cálculo da data prevista de entrega
* Exibição de um resumo completo da compra
* Possibilidade de realizar várias compras na mesma execução

## Regras de frete

O valor do frete é definido de acordo com a região e o peso do produto.

| Região   | Até 2 kg | Acima de 2 kg |   Prazo |
| -------- | -------: | ------------: | ------: |
| Sul      | R$ 30,00 |      R$ 50,00 |  5 dias |
| Sudeste  | R$ 25,00 |      R$ 45,00 |  3 dias |
| Norte    | R$ 35,00 |      R$ 55,00 | 10 dias |
| Nordeste | R$ 40,00 |      R$ 60,00 |  7 dias |

## Tecnologias utilizadas

* C
* GCC
* Visual Studio Code

## Conceitos utilizados

O projeto foi desenvolvido utilizando conceitos fundamentais da linguagem C, incluindo:

* Variáveis e tipos de dados
* Constantes com `#define`
* Estruturas condicionais
* Estruturas de repetição
* `switch/case`
* Funções
* Arrays
* Entrada e saída de dados
* Validação de informações
* Manipulação de datas
* Operadores aritméticos e relacionais

## Como executar

Compile o arquivo utilizando o GCC:

```bash
gcc calculadora_logistica.c -o calculadora_logistica
```

Depois execute o programa:

```bash
./calculadora_logistica
```

No Windows, também é possível executar o arquivo `.exe` gerado após a compilação.

## Objetivo

O objetivo do projeto é aplicar conceitos de programação estruturada em C na construção de uma aplicação capaz de realizar o cálculo de frete e prazo de entrega de produtos.

O projeto foi desenvolvido como atividade da disciplina de Bases de Programação - Linguagem C.
