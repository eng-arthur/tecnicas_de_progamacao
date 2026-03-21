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

# Capítulo 2 - Algoritimo de Ordenamento

Os algoritimos de ordenamento são maneiras de ordenar dados, dentre os tipos de ordenamentos temos: **Algoritimo de bolha** e **Busca Sequêncial**.

## 2.1 - Algoritimo de Bolha

O algoritimo de bolha consiste no ordenamento

































# Capítulo 2 - Funções

Existem diversos tipos de funções: **int**, **float**, **void**, **string**, **char**. Algumas destas funções podem retornar algo, mas tambem não podem retornar nada, como por exemplo a função void.

- Exemplo de uma função:

```cpp
    void texto(){
        cout << "Arthur Lindo";
    }
```
- Exemplo de uma função num código:

```cpp
    #include <iostream>
    using namespace std;

    void texto(); //Protótipo de função

    int main(){
        texto();
    }

    void texto(){ //Função
        cout << "\nArthur é Lindo";
    }
    return 0;
```

Note que houve a necessidade de implementar um prótotipo de função antes do int main, pois é de necessidade implementar para que o código funcione, ja que função foi escrita após o int main.

- Exemplo de uma função que produz uma soma

```cpp 
    void soma(int n1, int n2){
        cout << "A soma dos dois numeros e: " << n1+n2;
    }
```

- Exemplo da função anterior num código completo:

```cpp
    #include <iostream>
    using namespace std;

    void soma(int n1, int n2);

    int main(){
        soma(3,2);
    }

    void soma(int n1, int n2){
        cout << "A soma dos dois numeros: " << n1+n2;
    }

    return 0;
```

Caso queira retornar algo, não podemos utilizar o void, já que o mesmo não retorna nada, portanto teremos que escolher entre **int**, **float**, **char** e **string**.

- Exemplo de um código que retorna um valor inteiro:

```cpp
    int soma(int n1, int n2){
        return n1+n2;
    }
```

- Exemplo da função num código completo:

```cpp
    #include <iostream>
    using namespace std;

    int soma(int n1, int n2);

    int main(){

        cout << "O valor da soma foi" << soma(15,23);

        return 0;
    }

    int soma(int n1, int n2){
        return n1+n2;
    }
```

Fazendo uma alusão do que foi visto antes, será que seria possível usar uma função com vetor ??

- Exemplo de um código que utiliza uma função para mostrar os numero guardados num vetor:

```cpp
    #include <iostream>
    using namespace std;

    void print(int n1[4]);

    int main(){

        int conjunto[4]= {1,2,3,4};

        print(conjunto);

        return 0;
    }

    void print(int n1[4]){
        for(int i=0;i<4;i++){
            cout << n1[i];
        }
    }
```

## 2.1 - Sobrecarga de Funções

A sobrecarga de funções ocorre quando há a presença de uma mais de uma função com o mesmo nome, no entando, isto não fará o código dar erro, na verdade o código continuará de maneira normal.

- Exmplode uma função sobrecarregada:

```cpp
    #include <iostream>
    using namespace std;

    void soma(int n1, int n2);

    int main(){
        soma(20,30);
        soma();
        return 0;
    }

    void soma(int n1, int n2){
        int re;
        re =n1+n2;
        cout << "Soma de " << n1 << "com" << n2 << "=" << re << "\n";
    }

    void soma(){
        int n1,n2,re;
        n1=10;
        n2=20;
        re = n1+n2;
        cout << "Soma de " << n1 << "com" << n2 << "=" << re << "\n";
    }
``` 

## 2.2 - Omissão de argumentos e argumentos padrão

Caso seja necessário omitir o argumento da função em algum momento, ou então deixar um valor default, pode ser utilizado a estratégia de argumentos padrão da seguinte maneira:

- Exemplo de código usando argumento padrão:

```cpp
    #include <iostream>
    #include <string>
    using namespace std;

    void impressao(string txt="default"); //valor "default" como padrão no protótipo da função

    int main(){

        imnpressao(); //aqui omitimos a entrada da função
                      //no entando, caso eu adicione algo dentro, será exibido oque está demntro e não o valor default.

        return 0;
    }

    void impressao(string txt){
        cout << "\n" << txt;
    }
```

## 2.3 - Funções Recursivas

As funções recursivas é quando nós chamamos a mesma função dentro dela própria, realizando assim a recursividade.

- Exemplo de uma função recursiva:

```cpp
    #include <iostream>
    using namespace std;

    void contador(int num,int cont=0);

    int main(){

        contador(20);

        return 0;
    }

    void contador(int num, int cont){
        cout << cont << "\n";
        if(cont<num>){
            contador(num,++cont); //chamando a função dentro da própria função.
        }
    }
``` 

# Capítulo 3 - Listas

