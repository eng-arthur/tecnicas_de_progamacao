#include <iostream>
#include <cmath>
using namespace std;

class Vetor {
private:
    float x, y, z;

public:
    void setX(float a) {x = a;}
    void setY(float b) {y = b;}
    void setZ(float c) {z = c;}
    float getX() {return x;}
    float getY() {return y;}
    float getZ() {return z;}

    float magnitude() {
        return sqrt(x * x + y * y + z * z);
    }

    Vetor soma(Vetor v) {
        Vetor r;
        r.setX(x + v.getX());
        r.setY(y + v.getY());
        r.setZ(z + v.getZ());
        return r;
    }

    Vetor subtracao(Vetor v) {
        Vetor r;
        r.setX(x - v.getX());
        r.setY(y - v.getY());
        r.setZ(z - v.getZ());
        return r;
    }

    float distancia(Vetor v) {
        float dx = x - v.getX();
        float dy = y - v.getY();
        float dz = z - v.getZ();
        return sqrt(dx * dx + dy * dy + dz * dz);
    }

    void imprimir() {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }
};

Vetor vetores[10];
int inicializado = 0;
int semente = 13;

int pseudoAleatorio() {
    semente = (semente * 1103515245 + 12345) & 0x7fffffff;
    return semente;
}

void gerarAleatorios() {
    for (int i = 0; i < 10; i++) {
        float a = (pseudoAleatorio() % 11) - 5;
        float b = (pseudoAleatorio() % 11) - 5;
        float c = (pseudoAleatorio() % 11) - 5;
        vetores[i].setX(a);
        vetores[i].setY(b);
        vetores[i].setZ(c);
    }
    inicializado = 1;
    cout << "Vetores gerados com sucesso!" << endl;
}

void receberDoUsuario() {
    float a, b, c;
    for (int i = 0; i < 10; i++) {
        cout << "Vetor " << i + 1 << ":" << endl;
        cout << "X: "; cin >> a;
        cout << "Y: "; cin >> b;
        cout << "Z: "; cin >> c;
        vetores[i].setX(a);
        vetores[i].setY(b);
        vetores[i].setZ(c);
    }
    inicializado = 1;
    cout << "Vetores recebidos com sucesso!" << endl;
}

void computarMagnitudes() {
    if (!inicializado) {
        cout << "Vetores nao inicializados!" << endl;
        return;
    }
    for (int i = 0; i < 10; i++) {
        cout << "Vetor " << i + 1 << " ";
        vetores[i].imprimir();
        cout << " -> Magnitude: " << vetores[i].magnitude() << endl;
    }
}

void imprimirOrdemCrescente() {
    if (!inicializado) {
        cout << "Vetores nao inicializados!" << endl;
        return;
    }
    Vetor copia[10];
    for (int i = 0; i < 10; i++) copia[i] = vetores[i];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (copia[j].magnitude() > copia[j + 1].magnitude()) {
                Vetor temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    cout << "Vetores em ordem crescente de magnitude:" << endl;
    for (int i = 0; i < 10; i++) {
        copia[i].imprimir();
        cout << " -> Magnitude: " << copia[i].magnitude() << endl;
    }
}

void operacoesEntreVetores() {
    if (!inicializado) {
        cout << "Vetores nao inicializados!" << endl;
        return;
    }
    int a, b;
    cout << "Digite o indice do primeiro vetor (1-10): "; cin >> a;
    cout << "Digite o indice do segundo vetor (1-10): "; cin >> b;
    a--; b--;

    Vetor s = vetores[a].soma(vetores[b]);
    Vetor sub = vetores[a].subtracao(vetores[b]);
    float dist = vetores[a].distancia(vetores[b]);

    cout << "Vetor 1: "; vetores[a].imprimir(); cout << endl;
    cout << "Vetor 2: "; vetores[b].imprimir(); cout << endl;
    cout << "Soma: "; s.imprimir(); cout << endl;
    cout << "Subtracao: "; sub.imprimir(); cout << endl;
    cout << "Distancia: " << dist << endl;
}

int main() {
    int opcao, subOpcao;

    do {
        cout << "\n=== MENU PRINCIPAL ===" << endl;
        cout << "1.   Inicializar vetores" << endl;
        cout << "2.  Computar magnitudes" << endl;
        cout << "3. Imprimir em ordem crescente" << endl;
        cout << "4.  Soma, subtracao e distancia entre vetores" << endl;
        cout << "0.   Sair" << endl;
        cout << "Escolha: "; cin >> opcao;

        if (opcao == 1) {
            cout << "1. Gerar aleatorios" << endl;
            cout << "2. Inserir manualmente" << endl;
            cout << "Escolha: "; cin >> subOpcao;
            if (subOpcao == 1) gerarAleatorios();
            else if (subOpcao == 2) receberDoUsuario();
        } else if (opcao == 2) {
            computarMagnitudes();
        } else if (opcao == 3) {
            imprimirOrdemCrescente();
        } else if (opcao == 4) {
            operacoesEntreVetores();
        }

    } while (opcao != 0);

    return 0;
}