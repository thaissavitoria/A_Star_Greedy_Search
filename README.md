# Analisando a utilização dos algoritmos BFS e DFS

Os algoritmos analisados neste trabalho pertencem à categoria de buscas informadas, ou seja, utilizam heurísticas para estimar a proximidade de um estado ao objetivo, orientando a busca de forma mais eficiente.

## Greedy Search:
A busca gulosa (Greedy Search) é um algoritmo de busca informada utilizado para encontrar um caminho em uma estrutura de dados que pode ser representada como um grafo ou uma árvore. Nesse algoritmo, a exploração começa em um nó inicial e é guiada por uma função heurística h(n), que estima a "proximidade" do nó atual em relação ao objetivo. Diferentemente de outros algoritmos como A*, a busca gulosa considera apenas o valor heurístico para decidir qual nó explorar a seguir, ignorando o custo acumulado do caminho. O processo utiliza uma fila de prioridade para organizar os nós a serem explorados com base na heurística, e um conjunto de nós visitados para garantir que cada nó seja processado apenas uma vez. 
> **OBS:** a implementação está no arquivo 
Astar.cpp
.

## A*:
A busca A* (A Star Search) é um algoritmo utilizado para encontrar o caminho mais curto em um grafo, combinando estratégias de busca informada e custo acumulado. Nesse algoritmo, cada nó é avaliado com base em uma função custo f(n)=g(n)+h(n), onde g(n) representa o custo acumulado do nó inicial até o nó atual e h(n) é a heurística que estima o custo restante do nó atual até o destino. O algoritmo utiliza uma fila de prioridade para explorar os nós com menor custo total estimado f(n), garantindo que a exploração seja guiada para a solução de forma eficiente.
> **OBS:** a implementação está no arquivo 
greedySearch.cpp
.

## Heurística
A heurística é o cálculo feito que diz o custo estimado do caminho mínimo a partir do estado do vértice n até o estado meta. Para resolução do problema do labirinto foi utilizada a heurística com base na distância de Manhattan, que diz:

Dada a posição de dois pontos no espaço bidimensional, A(x1,y1) e B(x2,y2), a distância de Manhattan entre eles é calculada como: $$|x1-x2| + |y1-y2|$$.


## Implementação do Labirinto
O labirinto é representado como um grafo não direcionado, implementado na classe ```grafo.cpp```

- Inicialização do grafo criando 25 vértices, estes que são instanciados com o seu valor representativo do labirinto e sua coordenada cartesiana.
- Realizado o cálculo da distância de manhattan para cada vértice do grafo a partir de suas coordenadas.
- Arestas são adicionadas bidirecionalmente usando o método ```addAresta(u, v)```.
- Nós são conectados para criar caminhos potenciais.
- Algoritmos de busca (Busca Gulosa e A*) percorrem este grafo para encontrar um caminho entre nós de início e fim.

#### Abordagem de Medição de Desempenho
Ambos algoritmos medem:

- Tempo de execução usando ```chrono::high_resolution_clock```

- Uso de memória através de rastreamento personalizado.

Registro e Saída

- ```caminhoBuscaGulosa.txt```
 para a busca gulosa.
- ```caminhoAestrela.txt```
 para a busca A estrela.

Estes arquivos contêm, detalhes passo a passo da exploração, ordem de visitação dos nós, caminho para a solução e estatísticas de execução

## Medições e desempenho

### Discussão 

Como base para discussão feita, é preciso compreender alguns conceitos. Um algoritmo completo deve ser capaz de explorar sistematicamente todos os estados que podem ser alcançados desde o estado inicial. Em espaços de estados finitos, que é o caso deste trabalho, é garantido que poderá ser atingido, nas duas implementações, qualquer estado que esteja conectado ao estado inicial. 

Em relação a heurística temos propriedades que determinam sua otimabilidade, uma propriedade fundamental é a admissibilidade que diz que uma heurística admissível é a que nunca superestima o custo de atingir a meta. Isso significa que ela sempre fornece uma estimativa igual ou menor ao custo real mínimo necessário para atingir o destino. Outra propriedade importante da heurística é a consistência, onde uma heurística é consistente se, para cada nó n e para todo sucessor n' de n gerado por uma ação a, tivermos que: $$h(n) ≤ c(n,a,n') + h(n')$$.

Com uma heurística consistente na primeira vez que um estado for atingido ele estará em um caminho ótimo, portanto, nunca teremos que adicionar novamente um estado à fronteira e nunca teremos que alterar uma entrada em alcançado. Porém, com uma heurística inconsistente, podemos acabar com vários caminhos atingindo o mesmo estado, e se cada novo caminho tiver um custo menor do que o anterior, então acabaremos com vários nós para aquele estado na fronteira, custando tempo e espaço.

A distância de Manhattan assume um caminho direto. Se houver obstáculos que forcem desvios, ela ainda será admissível (não superestima o custo), mas poderá ser menos eficiente.

Analisando a busca gulosa pela melhor escolha temos que ela é completa em espaços de estados finitos, mas não nos infinitos. Além disso, não é um algoritmo ótimo devido a sua lógica gulosa, uma vez que a cada passo ele tenta chegar o mais próximo da meta que puder, porém ser guloso pode levar a resultados piores do que ser cauteloso.

Já a análise da busca A* mostra que, para espaços de estados finitos é completa. Porém, a otimabilidade dela depende das propriedades citadas acima, se a heurística aplicada cumprir essas propriedades o algoritmo A* tem custo ótimo.

#### Análisando as complexidades
Temporal e Memória
- No pior caso, a busca gulosa apresenta complexidade de tempo e de espaço $$O(|V|)$$. Com uma boa função heurística, no entanto, a complexidade pode ser reduzida substancialmente, chegando a alcançar $$O(B*M)$$.
- Na A*, no seu pior caso a complexidade de espaço e tempo é de $$O(b^d)$$, com uma heurística ideal o número de nós explorados diminui, tornando mais eficiente. A memória nesse algoritmo pode ser um problema quando tem um alto fator de ramificação ou profundidade.

#### Tempo de execução e Consumo de memória

Nesta etapa será visualizado o tempo gasto por cada algoritmo pra completar o objetivo e a memoria utilizada.

#### Gulosa

| Execução | Tempo de Execução (ms) | Memória Usada (bytes) |
|----------|-------------------------|-----------------------|
| 1        | 13.3859                | 64                    |
| 2        | 14.0311                | 64                    |
| 3        | 13.6689                | 64                    |
| 4        | 13.0686                | 64                    |
| 5        | 13.0047                | 64                    |
| 6        | 12.7345                | 64                    |
| 7        | 13.6245                | 64                    |
| 8        | 14.0786                | 64                    |
| 9        | 14.2533                | 64                    |
| 10       | 11.8527                | 64                    |
| **Média**| **13.3703**            | **64**                |

---

#### A*

| Execução | Tempo de Execução (ms) | Memória Usada (bytes) |
|----------|-------------------------|-----------------------|
| 1        | 11.4827                | 64                    |
| 2        | 11.9939                | 64                    |
| 3        | 12.467                | 64                    |
| 4        | 10.8914                | 64                    |
| 5        | 10.4026                | 64                    |
| 6        | 10.6629                | 64                    |
| 7        | 10.7598                | 64                    |
| 8        | 12.8035                | 64                    |
| 9        | 11.9997                | 64                    |
| 10       | 13.1197                | 64                    |
| **Média**| **11.66**            | **64**                |

---


## Possíveis melhorias

Como possíveis melhorias para ambos os algoritmos seria a utilização de uma heurística mais eficiente. Podem ser utilizadas tambem estruturas de dados mais eficientes como por exemplo o binaryHeap, para otimizar o tempo na busca gulosa. Para melhor o uso de memoria pode ser usada a implementação de algumas técnicas, por exemplo o iterative deepening no A*, que reduz o uso de memoria ao explorar os nós de maneira iterativa.

## Conclusão

Neste trabalho, foram analisados dois algoritmos fundamentais de busca informada: Busca Gulosa (Greedy Search) e A* (A Star). Ambos demonstraram ser eficientes para encontrar o caminho até a meta no labirinto, utilizando heurística baseada na distância de Manhattan. A Busca Gulosa oferece uma solução rápida e simples, porém pode ser que não garanta o melhor caminho, já que a sua estratégia se baseia apenas na estimativa heurística, sem considerar o custo acumulado do caminho. Em contrapartida, o A*, com a combinação de custo acumulado e heurística, garante encontrar o caminho ótimo, desde que a heurística seja admissível e consistente, o que o torna mais robusto e eficiente.

## Compilação e Execução

<div align="justify">
O algoritmo disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:
</div>
<p></p>
<div align="center">

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  make clean          | Apaga a última compilação realizada contida na pasta build                                        |
|  make                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  make run            | Executa o programa da pasta build após a realização da compilação                                 |
</div>
