#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Aluno {
    string nome;
    float nota1, nota2, nota3;
    int qtdNotas;
};

struct Disciplina {
    string nome;
    Aluno alunos[100];
    int qtd;
};

Disciplina disciplinas[50];
int numDisc = 0;

float media(Aluno a) {
    if (a.qtdNotas == 1) return a.nota1;
    if (a.qtdNotas == 2) return (a.nota1 + a.nota2) / 2;
    return (a.nota1 + a.nota2 + a.nota3) / 3;
}

int buscarDisc(string nome) {
    for (int i = 0; i < numDisc; i++) {
        if (disciplinas[i].nome == nome) return i;
    }
    return -1;
}

void salvar() {
    ofstream arq("dados.txt");
    for (int i = 0; i < numDisc; i++) {
        for (int j = 0; j < disciplinas[i].qtd; j++) {
            Aluno a = disciplinas[i].alunos[j];
            arq << disciplinas[i].nome << ";" << a.nome << ";" << a.qtdNotas << ";";
            arq << a.nota1 << ";" << a.nota2 << ";" << a.nota3 << "\n";
        }
    }
    arq.close();
}

void carregar() {
    ifstream arq("dados.txt");
    if (!arq.is_open()) return;

    string linha;
    while (getline(arq, linha)) {
        if (linha.empty()) continue;

        string partes[7];
        int idx = 0, ini = 0;
        for (int i = 0; i <= (int)linha.size(); i++) {
            if (i == (int)linha.size() || linha[i] == ';') {
                partes[idx++] = linha.substr(ini, i - ini);
                ini = i + 1;
            }
        }

        string nomeDisc = partes[0];
        int d = buscarDisc(nomeDisc);
        if (d == -1) {
            disciplinas[numDisc].nome = nomeDisc;
            disciplinas[numDisc].qtd = 0;
            d = numDisc++;
        }

        Aluno a;
        a.nome = partes[1];
        a.qtdNotas = stoi(partes[2]);
        a.nota1 = stof(partes[3]);
        a.nota2 = stof(partes[4]);
        a.nota3 = stof(partes[5]);
        disciplinas[d].alunos[disciplinas[d].qtd++] = a;
    }
    arq.close();
}

void cadastrar() {
    string nomeDisc, nomeAluno;
    int qtd;

    cout << "Disciplina: ";
    getline(cin, nomeDisc);
    cout << "Nome do aluno: ";
    getline(cin, nomeAluno);
    cout << "Quantas notas? (1, 2 ou 3): ";
    cin >> qtd;
    cin.ignore();

    Aluno a;
    a.nome = nomeAluno;
    a.qtdNotas = qtd;
    a.nota1 = a.nota2 = a.nota3 = 0;

    cout << "Nota 1: "; cin >> a.nota1; cin.ignore();
    if (qtd >= 2) { cout << "Nota 2: "; cin >> a.nota2; cin.ignore(); }
    if (qtd >= 3) { cout << "Nota 3: "; cin >> a.nota3; cin.ignore(); }

    int d = buscarDisc(nomeDisc);
    if (d == -1) {
        disciplinas[numDisc].nome = nomeDisc;
        disciplinas[numDisc].qtd = 0;
        d = numDisc++;
    }

    disciplinas[d].alunos[disciplinas[d].qtd++] = a;
    salvar();
    cout << "Salvo!\n";
}

void listar() {
    if (numDisc == 0) {
        cout << "Nenhuma disciplina cadastrada.\n";
        return;
    }
    for (int i = 0; i < numDisc; i++) {
        cout << "\n" << disciplinas[i].nome << ":\n";
        for (int j = 0; j < disciplinas[i].qtd; j++) {
            cout << "  - " << disciplinas[i].alunos[j].nome << "\n";
        }
    }
}

void pesquisar() {
    string termo;
    cout << "Nome do aluno ou disciplina: ";
    getline(cin, termo);

    bool achou = false;
    for (int i = 0; i < numDisc; i++) {
        if (disciplinas[i].nome.find(termo) != string::npos) {
            cout << "Disciplina encontrada: " << disciplinas[i].nome << "\n";
            achou = true;
        }
        for (int j = 0; j < disciplinas[i].qtd; j++) {
            if (disciplinas[i].alunos[j].nome.find(termo) != string::npos) {
                cout << "Aluno encontrado: " << disciplinas[i].alunos[j].nome
                     << " | Disciplina: " << disciplinas[i].nome << "\n";
                achou = true;
            }
        }
    }

    if (!achou) cout << "Nao encontrado.\n";
}

void notasDisciplina() {
    string nome;
    cout << "Nome da disciplina: ";
    getline(cin, nome);

    int d = buscarDisc(nome);
    if (d == -1) {
        cout << "Disciplina nao encontrada.\n";
        return;
    }

    float somaMedias = 0;
    cout << "\n" << disciplinas[d].nome << "\n";
    for (int j = 0; j < disciplinas[d].qtd; j++) {
        Aluno a = disciplinas[d].alunos[j];
        float m = media(a);
        somaMedias += m;
        cout << a.nome << " | N1: " << a.nota1;
        if (a.qtdNotas >= 2) cout << " N2: " << a.nota2;
        if (a.qtdNotas >= 3) cout << " N3: " << a.nota3;
        cout << " | Media: " << fixed << setprecision(1) << m;
        cout << " | " << (m >= 7 ? "Aprovado" : "Reprovado") << "\n";
    }

    if (disciplinas[d].qtd > 0)
        cout << "Media da turma: " << fixed << setprecision(1) << somaMedias / disciplinas[d].qtd << "\n";
}

void notasAluno() {
    string nome;
    cout << "Nome do aluno: ";
    getline(cin, nome);

    bool achou = false;
    for (int i = 0; i < numDisc; i++) {
        for (int j = 0; j < disciplinas[i].qtd; j++) {
            Aluno a = disciplinas[i].alunos[j];
            if (a.nome.find(nome) != string::npos) {
                float m = media(a);
                cout << disciplinas[i].nome << " | N1: " << a.nota1;
                if (a.qtdNotas >= 2) cout << " N2: " << a.nota2;
                if (a.qtdNotas >= 3) cout << " N3: " << a.nota3;
                cout << " | Media: " << fixed << setprecision(1) << m;
                cout << " | " << (m >= 7 ? "Aprovado" : "Reprovado") << "\n";
                achou = true;
            }
        }
    }

    if (!achou) cout << "Aluno nao encontrado.\n";
}

int main(int argc, char* argv[]) {
    carregar();

    if (argc > 1) {
        string cmd = argv[1];
        if (cmd == "add" && argc >= 5) {
            Aluno a;
            a.nome = argv[3];
            a.qtdNotas = argc - 4;
            a.nota1 = a.nota2 = a.nota3 = 0;
            if (argc >= 5) a.nota1 = stof(argv[4]);
            if (argc >= 6) a.nota2 = stof(argv[5]);
            if (argc >= 7) a.nota3 = stof(argv[6]);

            int d = buscarDisc(argv[2]);
            if (d == -1) {
                disciplinas[numDisc].nome = argv[2];
                disciplinas[numDisc].qtd = 0;
                d = numDisc++;
            }
            disciplinas[d].alunos[disciplinas[d].qtd++] = a;
            salvar();
            cout << "Salvo!\n";
        }
        return 0;
    }

    int op;
    do {
        cout << "\n1. Cadastrar\n2. Listar\n3. Pesquisar\n4. Notas por disciplina\n5. Notas por aluno\n0. Sair\nOpcao: ";
        cin >> op;
        cin.ignore();

        if (op == 1) cadastrar();
        else if (op == 2) listar();
        else if (op == 3) pesquisar();
        else if (op == 4) notasDisciplina();
        else if (op == 5) notasAluno();

    } while (op != 0);

    return 0;
}