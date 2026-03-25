    #include <iostream>
    #include <string>
    using namespace std;

    class Aviao{
    public: 

        int vel=0;
        int velMax;
        string tipo;
        Aviao(int tp);
        void imprimir();
    };

    Aviao::Aviao(int tp){
        if(tp==1){
            tipo = "Jato";
            velMax=800;
        }else if(tp == 2){
            tipo = "Mono motor";
            velMax=350;
        }else if(tp == 3){
            tipo = "Planador";
            velMax=180;
        }
    }

    void Aviao::imprimir(){
    cout << "Tipo: " << tipo << endl;
    cout << "Velocidade maxima: " << velMax << endl;
    }

    int main(){
        Aviao av1(1);
        av1.imprimir();
        return 0;
    }

