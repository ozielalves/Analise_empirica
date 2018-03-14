# Projeto de Análise Empírica
#### Disciplina: Estrutura de Dados Básicas I / Universidade Federal do Rio Grande do Norte ~ [UFRN](http://http://www.ufrn.br)

#### Alunos
- [Felipe Ramos](https://github.com/felipecramos/)
- [Oziel Alves](https://github.com/ozielalves/)

#### Implementações
  ###### Buscas
  - [ ] Busca Binária (Iterativa / Recursiva)
  - [x] Busca Sequencial (Iterativa)
  - [ ] Busca Ternária (Iterativa / Recursiva)
  - [x] Jump Search
  - [ ] Busca Fibonacci

  ###### Código
  - [x] Function pointers
  - [x] Modularização / Makefile
  - [x] Custom outputs


#### Objetivos
Analisar e avaliar o comportamento **assintótico** dos algoritmos em relação ao seu tempo de execução, os cenários deverão simular a execução dos algoritmos para diversos tamanhos de amostras com valores de *n* crescentes, até atingir o limite da máquina de testes. Por esta razão iremos gerar pelo menos 25 variações no tamanho das amostras dos elementos.

##### Organização das amostras
Iremos assumir que os arranjos já se encontram ordenados e sem repetições.

##### Sobre as buscas
Todos os algoritmos serão testados contra seu pior caso, ou seja, quando *k* não se encontra no arranjo **A**. 

#### Como usar
Para compilar, basta usar o seguintes comandos:
```bash
# Via git
git clone https://github.com/ozielalves/Analise_empirica.git; cd Analise_empirica; make

# Caso já tenha o diretório, basta estar dentro dele e usar
make
```

Depois, basta rodar o programa com os parametros desejados:
```bash
./bin/analise $(tamanho_inicial_array) $(numero_de_testes)
```
+ **_Tamanho inicial do Array_**

    Como o programa é projetado para testar e analisar algoritmos de busca, é necessário definir o número de elementos que o array irá possuir para então, testar nele o algoritmo de busca. Vale lembrar que irão acontecer 25 incrementos no array (número estipulado dentro do `src/main.cpp`) e será um array já ordenado em ordem crescente.
+ **_Número de testes_**

    Esse parametro estipula quantas vezes o algoritmo de busca será testado, para depois obtermos uma média de tempo/passos que ele consome e assim gerar os gráficos.
