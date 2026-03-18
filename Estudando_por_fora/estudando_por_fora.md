<!-- ================= CAPA ================= -->

<p align="center">
  <h1 align="center">Técnicas de Programação</h1>
  <h3 align="center">Anotações referentes a linguagem c++</h3>
  <br>
  <p align="center">
    Autor: Arthur Emanuell de Sousa Firmino   
    <br>
    Data: 2026
  </p>
</p>

---

## Prefácio

Nesta anotação será falado um pouco sobre C++.

---

## Sumário

- [Capítulo 1 - Array e Vetor](#capítulo-1---array-e-vetor)

---

# Capítulo 1 - Array e Vetor

O vetor de 3 coisas básicas: *tipo*, *nome* e *tamanho*. 

- Exemplo:

```cpp
    int valor[5];
```

Onde em cada posição do vetor pode ser armazenado um valor, ou seja, cada valor pode ser atribuído separadamente diferenciando a localização do vetor.

```cpp
    valor[0]=1;
    valor[1]=2;
    valor[2]=3;
    valor[3]=4;
    valor[4]=5;
```

Caso formos utilizar uma variável externa para determinar o tamanho do array, é necessário que a variável de seja instanciada antes do array.

- Exemplo:

```cpp
    int tam=5;
    int vetor[tam];
```

No entando é necessário que haja a seguinte observação:

```cpp
    int tam=5;
    int vetor[tam]{10, 20 ,30, 40, 50};
```

Isso não pode, pois apartir do momento que você escolhe que o vetor é dimensionado usando uma variável externa você não pode adicionar valores manualmente.


## 1.1 Array Bidimensional - Matriz

Para criarmos o array bidimensional fazemos uso de uma tabela para nos auxiliar, já que idealizamos o mesmo como uma matriz.

- Exemplo: 

```cpp
    int matriz [3][4];
              //L  C
```
| Coluna 1 | Coluna 2 | Coluna 3 | Coluna 4 |
|----------|----------|----------|----------|
|   |  |    |   |
|   |  |    |   |
|   |  |    |   |

Para criarmos uma matriz utilizando vetor, podemos escrever da seguinte maneira.

```cpp
    int matriz[3][4];

    //Preenchendo a 1° linha
    matriz[0][0]=0;
    matriz[0][1]=1;
    matriz[0][2]=2;
    matriz[0][3]=3;

    //Preenchendo a 2° linha
    matriz[1][0]=4;
    matriz[1][1]=5;
    matriz[1][2]=6;
    matriz[1][3]=7;

    //Preenchendo a 3° linha
    matriz[2][0]=8;
    matriz[2][1]=9;
    matriz[2][2]=10;
    matriz[2][3]=11;

```

| Coluna 1 | Coluna 2 | Coluna 3 | Coluna 4 |
|----------|----------|----------|----------|
| 0  | 1 |  2  | 3  |
| 4  | 5 |  6  | 7  |
| 8  | 9 |  10  | 11  |

# Capítulo 2 - Funções



