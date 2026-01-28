#include <iostream>
using namespace std;

int main(){

    char c;
    cout << "Digite uma letra: ";
    cin >> c;

    if(c>='a'&&c<='b' || c>='A'&&c<='Z'){
        cout << "E uma letra";
    }else if(c>='0'&&c<='9'){
        cout << "E um numero";
    }else if(c=='-'){
        cout << "Oque foi escrito e um traco";
    }else if(c=='.'){
        cout << "Vc escreveu um .";
    }

    return 0;
}