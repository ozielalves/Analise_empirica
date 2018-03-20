# Análise Empírica de Algoritmos de Busca
Disciplina: Estrutura de Dados Básicas I, Universidade Federal do Rio Grande do Norte ([UFRN](http://http://www.ufrn.br))

#### Alunos envolvidos
- [Felipe Ramos](https://github.com/felipecramos/)
- [Oziel Alves](https://github.com/ozielalves/)

## Objetivos
Analisar e avaliar o comportamento **assintótico** dos algoritmos em relação ao seu tempo de execução e número de iterações. Os cenários irão simular a execução dos algoritmos para diversos tamanhos de amostras com tamanhos de elementos *n* crescentes, até atingir o limite da máquina de testes.

## Instruções de uso

### Dependências
#### Python3, python3-pip, python3-tk
É necessário para executar o script de plotagem dos dados.
```bash
# Como instalar no Ubuntu 16.04 LTS por exemplo:
 sudo apt-get install python3 python3-pip python3-tk
```
#### Matplotlib
É necessário para exibir os gráficos gerados pelo script de plotagem.
```bash
# Como instalar no Ubuntu 16.04 LTS por exemplo:
pip3 install matplotlib
```
#### G++ Compiler
É necessário para a compilação do programa, visto que ele é feito em c++.
```bash
# Como instalar no Ubuntu 16.04 LTS por exemplo:
sudo apt-get install g++
```

### Compilação
Para compilar, basta usar o seguintes comandos na raiz do repositório:
```bash
# Compilar somente
make

# Para compilar e executar o algoritmo com parâmetros pré-definidos
# ./bin/analise 10 200 6 25 1111111; python3 src/gen_plot.py
make run

# Para limpar dados residuais (objetos, executáveis e dados gerados)
make clean
```
### Execução
Feito isso, basta rodar o programa com os parametros desejados:
```bash
./bin/analise [TIC] [NT] [I] [NI] [AS]
```
+ [TIC] - **_Tamanho inicial do Conjunto_**

	Como o programa é projetado para testar e analisar algoritmos de busca, é necessário definir o número de elementos que o conjunto irá possuir para então, testar nele o algoritmo de busca.

+ [NT] - **_Número de testes_**

	Irá estipular quantas vezes o algoritmo de busca será testado para cada número de incrementos [NI], para depois gerar uma média de tempo/iterações que ele consome.

+ [I] - **_Incremento_**

	Irá definir o incremento obedecendo a seguinte função: _f_(i) = 10^i. Portando, é necessário tomar cuidado com valores acima de 6 (pois já é suficiente para travar um computador de médio porte dependendo da quantidade de incrementos).

+ [NI] - **_Numero de Incrementos_**
  	
  Esse parametro irá definir o número de incrementos que irão acontecer obedecendo os parâmetros estipulados anteriormente.

+ [AS] - **Algoritmos Selecionados**

  Esse parâmetro receberá uma string binária, que baseado nela, irá definir quais algoritmos serão selecionados para compor a bateria de testes.

  Exemplos:

  `0101011`  Irá rodar apenas os algoritmos 2, 4, 6 e 7.

  ​`1000000` ou `1` irá rodar apenas o 1• algoritmo.

  `0001000` ou `0001` irá rodar apenas o 4• algoritmo.

  Então, se rodarmos o programa com as seguintes definições:
```bash
./bin/analise 10000 100 5 25 1111111
```
Teremos um programa que irá analisar 100 vezes um conjunto constituido com:
```
10000 elementos
10000 + (1 * 10^5) elementos
10000 + (2 * 10^5) elementos
10000 + (3 * 10^5) elementos
...
10000 + (23 * 10^5) elementos
10000 + (24 * 10^5) elementos
10000 + (25 * 10^5) elementos
```

E armazenará a média de tempo e iterações das 100 vezes, gerando gráficos para interpretação posterior. 

**Obs:** Vale lembrar que o programa pode ficar **bem** pesado caso o incremento estipulado seja muito forte (acima de 6, por exemplo) dada a função crescimento.

#### Plotagem de gráficos
O programa realiza a plotagem de gráficos utilizando um script em python 3 se aproveitando da lib matplotlib.
Para utilizar o script, basta na raiz do repositório executar:
```bash
python3 src/plot.py [A] [I]
```
Caso queira fazer a plotagem individual de todos os gráficos, basta utilizar:
```bash
python3 src/gen_plot.py
```
+ [A] - **_Algoritmos_**

  É um parâmetro composto por uma string binária, que segue a regra:

  `0111011` irá um gráfico comparando os algoritmos 2, 3, 4, 6 e 7.

  `1110000`  ou `111` irá gerar um gráfico comparando os algoritmos 1, 2, 3 apenas. 

  `1000000` ou `1` irá gerar um gráfico exclusivo do primeiro algoritmo.

  `0001000` ou `0001` irá gerar um gráfico exclusivo do 4º algoritmo.

  ​

  A ordem dos algoritmos é:

  *  1º: ***Busca Sequencial Iterativa***

  *  *2º:* ***Busca Binária Iterativa***

  *  *3º:* ***Busca Binária Recurssiva***

  *  4º: ***Busca Ternária Iterativa***

  *  5º: ***Busca Ternária Iterativa***

  *  6º: ***Jump Search***

  *  7º: ***Busca Fibonacci***

+ [I] - **_Informações_**

  Este parâmetro segue a mesma regra do parametro **[A]** e define quais informações irão compor os eixos _X_ e _Y_, porem é composto por uma string binária que só pode conter 2 repetições do `1`, visto que a plotagem do gráfico é em _2D_. Exemplos:

  `1010` Irá comparar o número de elementos com o tempo médio gasto nos testes.

  `1001` Irá comparar o número de elementos com o número de iterações médias gastas nos testes. 

  ​

  A ordem das informações é:

  1º: ***Número de elementos***

  2º: ***Número de testes***

  3º: ***Tempo médio gasto***

  4º: ***Iterações gastas***

### Quanto à organização das amostras
É estipulado como parâmetro de execução o tamanho inicial do conjunto **[TIC]**, o número de incrementos **[NI]** que irão acontecer a cada caso teste e o tamanho do incremento utilizado **[TIU]**.
Após isso, o programa irá gerar um conjunto de `TIC + (NI * TIU)` elementos e preenche-lo com elementos sequenciais crescentes, visto que a grande maioria dos algoritmos testados tem como requisição básica um conjunto **ordenado** de elementos e **sem repetições**.

### Quanto às buscas
Todos os algoritmos serão testados contra seu pior caso, ou seja, quando **k** não se encontra no arranjo **A**. 

## Apresentação dos Algoritmos

### Busca Sequencial
<!--Breve explicação-->
Também conhecida como busca linear, é um algoritmo de busca que procura por um elemento dado um conjunto, iterativamente, e checa se aquele é o elemento buscado.

#### Iterativa
Dado um conjunto **L** de _**n**_ elementos, com um alvo **T**, a seguinte sub-rotina é implementada. 

1. É setado `i = 0`

2. Se `L[i] == T`, a busca termina e retorna-se `i` (que é o local do elemento no vetor). 

3. Caso seja falso,`i` é incrementado em uma unidade.

4. Se `i < n`, iremos para o passo 2, se não, a busca termina sem sucesso.

<!--Complexidade-->

Para uma lista com _**n**_ elementos, o melhor cenário possivel é quando o valor buscado está na primeira posição do conjunto, enquanto que seu pior caso é quando **T** não pertence ao conjunto **L**.

Podemos esperar que a seguinte função descreva o comportamento do algoritmo em relação ao número de elementos do conjunto.

<!--{latex equation: n if k = 0; n+1/k+1 if 1 <= k <= n}-->
<!--Gráficos exclusivos-->
##### Gráficos exclusivos
###### Tamanho x Iterações
![Alt Tamanho x Iterações](https://github.com/ozielalves/Analise_empirica/blob/master/images/1-Sequential%20Search_14.png)
###### Tamanho x Tempo médio
![Alt Tamanho x Tempo médio](https://github.com/ozielalves/Analise_empirica/blob/master/images/1-Sequential%20Search_13.png)
<!--Opnião-->


### Busca Binária
Também conhecida como busca logaritmica, é um algoritmo de busca baseado na técnica *divide and conquer* e dependente de uma ordenação, que melhora notávelmente sua performance, visto que a cada iteração, é descartado metade do conjunto.
#### Iterativa
Dado um conjunto **A** de ***n*** elementos ordenados e um alvo **T**, é seguida a sub-rotina para encontrar o elemento:

1. É setado `L = 0` e `R = n - 1`.
2. Se **L** for menor que **R**, a busca termina sem sucesso.
3. É setado a posição do meio (*m*) do elemento para o *floor* de `(L + R) / 2`.
4. Se `A[m] < T`, será setado `L = m + 1` e retorna ao passo 2.
5. Se `A[m] > T`, será setado `R = m - 1` e retorna ao passo 2.
6. Se `A[m] == T`, a busca é finalizada retornando `m`.



Pelo fato da busca binária utilizar-se do método *divide and conquer*, acaba se tornando uma função logaritma que, em seu pior caso, irá ter a complexidade de O(*log n*) comparações.

##### Gráficos exclusivos
###### Tamanho x Iterações
![Alt Tamanho x Iterações](https://github.com/ozielalves/Analise_empirica/blob/master/images/2-Iterative%20Binary_14.png)
###### Tamanho x Tempo médio
![Alt Tamanho x Tempo médio](https://github.com/ozielalves/Analise_empirica/blob/master/images/2-Iterative%20Binary_13.png)
<!--Opnião-->
#### Recursiva
<!--Complexidade-->
##### Gráficos exclusivos
###### Tamanho x Iterações
![Alt Tamanho x Iterações](https://github.com/ozielalves/Analise_empirica/blob/master/images/3-Recursive%20Binary_14.png)
###### Tamanho x Tempo médio
![Alt Tamanho x Tempo médio](https://github.com/ozielalves/Analise_empirica/blob/master/images/3-Recursive%20Binary_13.png)
<!--Opnião-->

### Busca Ternária
<!--Breve explicação-->
#### Iterativa
<!--Pseudo-Código-->
<!--Complexidade-->
##### Gráficos exclusivos
###### Tamanho x Iterações
![Alt Tamanho x Iterações](https://github.com/ozielalves/Analise_empirica/blob/master/images/4-Iterative%20Ternary_14.png)
###### Tamanho x Tempo médio
![Alt Tamanho x Tempo médio](https://github.com/ozielalves/Analise_empirica/blob/master/images/4-Iterative%20Ternary_13.png)
<!--Opnião-->
#### Recursiva
<!--Pseudo-Código-->
<!--Complexidade-->
##### Gráficos exclusivos
###### Tamanho x Iterações
![Alt Tamanho x Iterações](https://github.com/ozielalves/Analise_empirica/blob/master/images/5-Recursive%20Ternary_14.png)
###### Tamanho x Tempo médio
![Alt Tamanho x Tempo médio](https://github.com/ozielalves/Analise_empirica/blob/master/images/5-Recursive%20Ternary_14.png)
<!--Opnião-->

### Jump Search
<!--Breve explicação-->
Como a Binary Search, Jump Search é um algoritmo de pesquisa para arrays ordenados. A idéia básica é verificar menos elementos (do que a busca linear) saltando por etapas fixas ou ignorando alguns elementos no lugar de pesquisar todos os elementos.
<!--Pseudo-Código-->
<!--Complexidade-->
<!--Gráficos exclusivos-->
##### Gráficos exclusivos
###### Tamanho x Iterações
###### Tamanho x Tempo médio
<!--Opnião-->
	

### Busca Fibonacci
<!--Breve explicação-->
Fibonacci Search é uma técnica baseada em comparação que usa números Fibonacci para pesquisar um elemento em um vetor ordenado.

<!--Pseudo-Código-->
1. Encontra o menor número de Fibonacci maior ou igual ao valor passado para a busca (`value`). Deixe que este número seja `fibM` [número Mth Fibonacci]. Deixe que os dois números de Fibonacci que precedem sejam `fib1` [(m-1) 'th Fibonacci Number] e `fib2` [(m-2)' th Fibonacci Number].

2. Enquanto o vetor possui elementos a serem inspecionados:
	1. Compara `value` com o último elemento da gama coberta por `fib2`
	2. Se `value` corresponder, retorna endereço.
	3. Se for menor do que `value`, mova as três variáveis Fibonacci duas "Fibonacci" para baixo, indicando a eliminação de cerca de dois terços do vetor restante.
	4. Se `value` for maior do que o elemento, mova as três variáveis Fibonacci um "Fibonacci" para baixo. Redefina o deslocamento para o endereço. Juntos, estes indicam a eliminação de cerca de um terço do vetor restante.

3. Uma vez que pode haver um único elemento restante para comparação, verifica se `fib1` é 1. Se sim, compara `value` com o vetor restante. Se coincidir, retorna o endereço.
<!--Complexidade-->
##### Gráficos exclusivos
###### Tamanho x Iterações
###### Tamanho x Tempo médio
<!--Opnião-->
	
## Comparações Gerais
<!--Breve explicação-->

### Recursivos x Iterativos
<!--Breve explicação-->
#### Busca Binária
<!--Breve explicação-->
<!--Gráfico-->
<!--Gráfico2-->
#### Busca Ternária
<!--Breve explicação-->
<!--Gráfico-->
<!--Gráfico2-->

### Recursivos x Busca Fibonacci
#### Tamanho x Iterações
<!--Gráfico Binary x Fib-->
<!--Gráfico Ternary x Fib-->
#### Tamanho x Tempo
<!--Gráfico Binary x Fib-->
<!--Gráfico Ternary x Fib-->

### Recursivos x Jump Search
#### Tamanho x Iterações
<!--Gráfico Binary x Jump-->
<!--Gráfico Ternary x Jump-->
#### Tamanho x Tempo
<!--Gráfico Binary x Jump-->
<!--Gráfico Ternary x Jump-->

### Geral
<!-- Grafico Geral -->
<!-- Gráfico Geral2 -->

<!--Conclusões finais-->

## Condições de Testes
### Informações sobre a maquina utilizada
<!--Maquina utilizada-->
+ **Macbook Pro** (13-inch, 2017)

+ **Processador** 2,3 GHz Intel Core i5

+ **Memória** 8 GB 2133 MHz LPDDR3

+ **Sistema** macOS High Sierra 10.13.3

### Informações sobre os parametros utilizados
Todos as informações interpretadas neste documento foram obtidas utilizando o seguinte comando::
```bash
# Irá compilar e executar o arquivo binário, em seguida o script gerador de gráficos (src/gen_plot.py)
make run
```
### Softwares utilizados
```bash
$> g++ --version
Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 9.0.0 (clang-900.0.39.2)
Target: x86_64-apple-darwin17.4.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

```bash
$> python3 --version
Python 3.6.4
```

```bash
$> pip3 --version
pip 9.0.1 from /usr/local/lib/python3.6/site-packages (python 3.6)
```
