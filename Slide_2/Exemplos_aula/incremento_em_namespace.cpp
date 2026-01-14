#include <iostream>
using namespace std;

namespace maria{
    int idade = 13;
    void incremento_maria(){
        idade=idade + 1;
    }
}

namespace jose{
    int idade = 19;
    void incremento_jose(){
        idade=idade+1;
    }
}

int main(){

    cout << "A idade de maria antes era: " << maria::idade;
    maria::incremento_maria();
    cout << "\nMas a idade agora e: " << maria::idade;
    cout << "\nA idade de jose era: " << jose::idade;
    jose::incremento_jose();
    cout << "\nMas a idade de jose agora e: " << jose::idade;
    return 0;
}

