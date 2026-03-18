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