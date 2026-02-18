#include <iostream>
using namespace std;

class Retangulo{
    private:
        int x,y,area;
    public:
        void setX(); //Prototipagem da função
        void setY();
        int getX();
        int getY();
        int getArea();
        void Area();
};

void Retangulo::setX(){
    cout << "\nDigite o valor da base: ";
    cin >> x;
}

void Retangulo::setY(){
    cout << "\nDigite o valor da altura: ";
    cin >> y;
}

void Retangulo::Area(){
    area=x*y;
}

int Retangulo::getArea(){
    return area;
}

int main(){

    Retangulo ret1;

    ret1.setX();
    ret1.setY();
    ret1.Area();
    cout << "\n" << ret1.getArea();


return 0;
}