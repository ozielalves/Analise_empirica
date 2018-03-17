# Análise Empírica de Algoritmos de Busca
#### Disciplina: Estrutura de Dados Básicas I / Universidade Federal do Rio Grande do Norte ~ [UFRN](http://http://www.ufrn.br)

#### Alunos
- [Felipe Ramos](https://github.com/felipecramos/)
- [Oziel Alves](https://github.com/ozielalves/)

#### Implementações
  ###### Buscas
  - [x] Busca Binária (Iterativa / Recursiva)
  - [x] Busca Sequencial (Iterativa)
  - [ ] Busca Ternária (Iterativa / Recursiva)
  - [x] Jump Search
  - [ ] Busca Fibonacci

  ###### Código
  - [x] Códigos comentados
  - [x] Implementação de function pointers
  - [x] Modularização
  - [x] Makefile
  - [x] Realce de cores nos outputs
  - [x] Plotagem de gráficos
  - [x] Outputs .dat com dados gerados


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
./bin/analise $tamanho_inicial_array $numero_de_testes $incremento $numero_de_variacoes
```
+ **_Tamanho inicial do Array_**

    Como o programa é projetado para testar e analisar algoritmos de busca, é necessário definir o número de elementos que o array irá possuir para então, testar nele o algoritmo de busca. Vale lembrar que irão acontecer 25 incrementos no array (número estipulado dentro do `src/main.cpp`) e será um array já ordenado em ordem crescente.
+ **_Número de testes_**

    Esse parametro estipula quantas vezes o algoritmo de busca será testado, para depois obtermos uma média de tempo/passos que ele consome e assim gerar os gráficos.

+ **_Incremento_**
    Esse parametro irá definir o incremento obedecendo a seguinte função: _f_(incremento) = 10^incremento. Portando, é necessário tomar cuidado com valores acima de 6 (pois já é suficiente para travar um computador de médio porte dependendo da quantidade de incrementos).

+ **_Numero de Variações_**
	Esse parametro irá definir o número de variações obedecendo ao incremento que irão existir
	
Ou seja, se rodarmos o programa com as seguintes definições:
```bash
./bin/analise 10000 100 5 25
```
Teremos um programa que irá analisar 100 vezes um array de `long int` com:
```
10000 elementos
10000 + 1 * 10^5 elementos
10000 + 2 * 10^5 elementos
10000 + 3 * 10^5 elementos
...
10000 + 23 * 10^5 elementos
10000 + 24 * 10^5 elementos
10000 + 25 * 10^5 elementos
```

E armazenará a média de tempo e iterações das 100 vezes, gerando gráficos para interpretação posterior. 

_Obs:_ Vale lembrar que o programa pode ficar **bem** pesado caso dê um incremento muito forte (acima de 6, por exemplo) dada a função exponencial de crescimento.

## Apresentação dos Algoritmos

### Busca Sequencial
<!--Breve explicação-->
	#### Iterativa
	<!--Pseudo-Código-->
	<!--Complexidade-->
	<!--Gráficos exclusivos-->
		<!--Tempo x Iterações-->
		<!--Tempo x Tamanho-->
		<!--Iterações x Tamanho-->
	<!--Opnião-->


### Busca Binária
<!--Breve explicação-->
	#### Iterativa
	<!--Pseudo-Código-->
	<!--Complexidade-->
	<!--Gráficos exclusivos-->
		<!--Tempo x Iterações-->
		<!--Tempo x Tamanho-->
		<!--Iterações x Tamanho-->
	<!--Opnião-->
	#### Recursiva
	<!--Pseudo-Código-->
	<!--Complexidade-->
	<!--Gráficos exclusivos-->
		<!--Tempo x Iterações-->
		<!--Tempo x Tamanho-->
		<!--Iterações x Tamanho-->
	<!--Opnião-->

### Busca Ternária
<!--Breve explicação-->
	#### Iterativa
	<!--Pseudo-Código-->
	<!--Complexidade-->
	<!--Gráficos exclusivos-->
		<!--Tempo x Iterações-->
		<!--Tempo x Tamanho-->
		<!--Iterações x Tamanho-->
	<!--Opnião-->
	#### Recursiva
	<!--Pseudo-Código-->
	<!--Complexidade-->
	<!--Gráficos exclusivos-->
		<!--Tempo x Iterações-->
		<!--Tempo x Tamanho-->
		<!--Iterações x Tamanho-->
	<!--Opnião-->

### Jump Search
<!--Breve explicação-->
	<!--Pseudo-Código-->
	<!--Complexidade-->
	<!--Gráficos exclusivos-->
		<!--Tempo x Iterações-->
		<!--Tempo x Tamanho-->
		<!--Iterações x Tamanho-->
	<!--Opnião-->
	

### Busca Fibonacci
<!--Breve explicação-->
	<!--Pseudo-Código-->
	<!--Complexidade-->
	<!--Gráficos exclusivos-->
		<!--Tempo x Iterações-->
		<!--Tempo x Tamanho-->
		<!--Iterações x Tamanho-->
	<!--Opnião-->
	
### Comparações Gerais
<!--Breve explicação-->
	#### Tempo x Iterações
	#### Tempo x Tamanho
	#### Iterações x Tamanho

<!--Conclusões finais-->

## Condições de Testes
### Informações sobre a maquina utilizada
	<!--Maquina utilizada-->
### Informações sobre os parametros utilizados
	<!--Parametros utilizados-->
### Softwares utilizados
	<!--Softwares utilizados-->
### Dependências necessárias
	<!--Dependências-->
