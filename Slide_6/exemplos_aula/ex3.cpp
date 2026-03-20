#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char lista[] = "ufpb";
    cout << lista << endl;
    //lista = "ufcg"; // Não permitido
    strcpy(lista, "UFPB");
    cout << lista << endl;
    return 0;
}