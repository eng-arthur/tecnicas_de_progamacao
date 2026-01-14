#include <iostream>
using namespace std;

    namespace maria{
        int idade = 19;
        int cra = 8;
    }

    namespace jose{
        int idade = 18;
        int cra = 4.6;
    }


int main(){

    int idade=12;

    cout << "A idade de maria e: " << maria::idade;
    cout << "\n" << idade;
    cout << "\nA idade de jose e: " << jose::idade;

    return 0;
}