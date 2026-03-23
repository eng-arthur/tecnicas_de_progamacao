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

O algoritimo de bolha consiste no ordenamento por meio de analises entre dois elementos do array.

- Exemplo do código para analise através do algoritimo bolha.

```cpp
    #include <iostream>
    using namespace std;

    void ordenamento(float x[], int k);
    void intercambio (float& x, float& y);
    void imprimir(float x[], int n);

    int main(){

        float x[10]={25.5, 34.1, 27.6, 15.24, 3.27, 5.14, 6.21, 7.57, 4.61, 5.4};
        imprimir(x,10);
        cout << endl;

        ordenamento(x,10);

        imprimir(x,10);

        return 0;
    }

    void imprimir(float x[], int n){
        for(int i=0;i<n;i++){
            cout << x[i] << " ";
        }
    }

    void intercambio (float& x, float& y){
        float temp;
        temp=x;
        x=y;
        y=temp;
    }

    void ordenamento(float x[], int k){
        for(int i=k;i>0;i--)
            for(int j=0;j<i-1;j++)
                if(x[j] > x[j+1]) intercambio(x[j], x[j+1]); //caso queira que fique decrescente, basta mudar o (>) para (<).
    }
```

## 2.2 - Busca Sequêncial

A busca sequêncial fará uma leitura do array através de um valor digitado e buscara dentro do array o valor igual ao digitado, caso encontre retornará o indice do array.

- Exemplo de um código utilizando a busca sequêncial:

```cpp
    #include <iostream>
    using namespace std;

    int busca(int x[], int n, int TAM);

    int main(){

        int x[10]={15, 41, 76, 64, 97, 33, 82, 18, 9, 48};
        int n=0;
        int r;

        cout << "Digite o valor que deseja procurar dentro do array: ";
        cin >> n;

        r = busca(x,n,10);

        if(r== -1) cout << "\nNao foi encontrado o valor digitado dentro do array";
        else cout << "\n O valor digitado foi encontrado e estava no indice: " << r << " do vetor.";

        return 0;
    }

    int busca(int x[], int n, int TAM){
        enum retorno{FALSE, TRUE}; // NESTE ENUM NOS CRIAMOS QUE O FALSE == 0 E O TRUE == 1 OBS: NÃO HAVIA A NECESSIDADE DE USAR O ENUM, FOI UTILIZADO APENAS COMO CUNHO EDUCATIVO.
        int encontrada = FALSE; //ESPECIFICAMOS QUE O ENCONTRADA == 0.
        int i=0;

        while(!encontrada && i<TAM){
            if(x[i]==n) encontrada=TRUE; //CASO ENCONTREMOS DENTRO DO VETOR NA POSIÇÃO I O VALOR IGUAL A N, O ENCONTRADA RECEBERÁ TRUE QUE EQUIVALE A 1;
            else        i++;
        }

        if(encontrada==TRUE) return i;
        else                 return -1;
    }
```

## 2.3 - Funções que usam strings (Determinadas por array)

Todas as strings são um conjunto de arrays do tipo char, na qual podemos trabalhar com elas de diferentes maneiras.

### 2.3.1 - STRCPY

Este tipo de função copia o que seja escrito ou atribuido para dentro da string.

- Exemplo:

```cpp
    #include <iostream>
    #include <string>
    using namespace std;

    int main(){
        char str1[]="Sample string";
        char str2[40];
        char str3[40];

        strcpy(str2,str1);
        strcpy(str3,"copy successfull");
        cout << str1 << str2 << str3;
    }
```

### 2.3.2 - STRLEN

Retorna o tamnho de uma string.

- Exemplo de uso:

```cpp
    #include <iostream>
    #include <string>
    using namespace std;

    int main(){
        char Input[256];
        cout << "Enter a sentence: ";
        cin.getline(Input,256);
        cout << "The sentece entered is" << strlen(Input) << " characters long";
        return 0;
    }
```

### 2.3.3 - STRCMP

Compara duas strings com a seguinte sintaxe:

```cpp
    int strcmp(char*str1, char*str2);
```

Caso str1 == str2 ele retornará 0, caso str1 > str2 ele retornará +1, mas se caso str1 < str2 então ele retornará -1.

Esta função procura até encontrar o primeiro caractere diferente. Se este for maior, em valor ASCII, então a string é considerada maior, caso contrário menor.

### 2.3.4 - STRCAT

Concatena o conteúdo de uma string em outra.

```cpp
    strcat(char*destination,char*source);
```

- Exemplo aplicado de utilização desta função:

```cpp
    #include <iostream>
    #include <string>
    using namespace std;

    int main(){

        char str[80];
        strcpy(str,"oi ");
        strcat(str,"meu ");
        strcat(str,"nome ");
        strcat(str,"e ");
        strcat(str,"arthur");
        cout << str;

        return 0;
    }
```

# Capítulo 3 - ENUM

O enum é o conjunto de constantes inteiras que especificam valores que uma variável deste tipo podem ter. Que podem ser verificadas através de strings, onde você cria uma lista e define os dados nesta lista.

- Exemplo de código usando o enum:

```cpp
    #include <iostream>
    using namespace std;

    int main(){
        enum armas{fuzil=100, revolver=8, rifle=12, escopeta=1};
        armas armaSel;

        armaSel = rifle;
        cout << armaSel;

        return 0;
    }
```

# Capítulo 4 - Funções

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

# Capítulo 5 - Classes

Uma classe é um modelo que define atributos e métodos, permitindo a criação de objetos organizados segundo os princípios da programação orientada a objetos.

Dentro das classes temos divisões entre públicos e privados, na qual a parte privada é encapsulada cujo que o usuário não pode mexer nela.

Para a utilização de uma classe é necessário que haja a contrução de um objeto, isso se torna bem parecido com a declaração de uma variável.

- Exemplo de criação de um objeto:

```cpp
    #include <iostream>
    using namepace std;

    class Aviao{
    private:

    public:
    int vel=0; //Criamos uma variável "vel" publica na classe aviao;
    }

    int main(){
        Aviao av1; //Criamos um objeto av1 referente a classe Aviao.

        cout << av1.vel; //Imprimimos a variável "vel" referente ao objeto av1. 
    }
``` 

Na maior parte dos casos as classes são usadas em conjunto com funções, dito isso é importante treinar esse tipo de utilização, segue um exemplo de uso de funções em classes.

- Exemplo:

```cpp
    #include <iostream>
    #include <string>
    using namespace std;

    class Aviao{
    public:
        int vel=0;
        int velMax;
        void init(int n);
        string modelo;
    };

    void Aviao::init(int n){
        if(n==1){
            modelo="Jato";
            velMax=800;
        }else if(n==2){
            modelo="Mono motor";
            velMax=500;
        }else if(n==3){
            modelo="Planador";
            velMax=180;
        }
    }

    int main(){
        Aviao av1;
        av1.init(1);
        cout << "O modelo e: " << av1.modelo << " e a velocidade maxima: " << av1.velMax;
    }
```