#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// extra
class Maquina{
    public:
        char simbolos[4] = {'@','#','$','%'};

        void tirar(char &r1, char &r2, char &r3){
            r1 = simbolos[rand() % 4];
            r2 = simbolos[rand() % 4];
            r3 = simbolos[rand() % 4];
        }
};

class Jugador{
    private:
        std::string nombre_;
        int monedas_;
    public:
        Jugador(std::string n){
            nombre_ = n;
            monedas_ = 100;
        }

        int getMonedas(){
            return monedas_;
        }

        void apostar(int cantidad){
            monedas_ -= cantidad;
        }

        void ganar(int premio){
            monedas_ += premio;
        }

        void mostrarSaldo(){
            std::cout << "Monedas: " << monedas_ << std::endl;
        }
};

char simbolos[4] = {'@','#','$','%'};

int main(){

    srand(time(0));

    std::string nombre;
    std::cout << "Ingresa tu nombre: ";
    std::cin >> nombre;

    Jugador jug(nombre);
    Maquina maq; 

    int record = 100; 

    while(true){

        if(jug.getMonedas() < 10){
            std::cout << "No tienes suficientes monedas. Fin del juego\n";
            break;
        }

        jug.mostrarSaldo();

        char op;
        std::cout << "Tirar? (s/n): ";
        std::cin >> op;

        // validar
        if(op != 's' && op != 'n'){
            std::cout << "Entrada invalida\n";
            continue;
        }

        if(op == 'n'){
            break;
        }

        std::cout << "Suerte...\n";

        jug.apostar(10);

        char r1, r2, r3;
        maq.tirar(r1, r2, r3);

        //imprimir
        std::cout<<"====================\n";
        std::cout << "[ " << r1 << " ] [ " << r2 << " ] [ " << r3 << " ]\n";
        std::cout<<"====================\n";

        if(r1 == '@' && r2 == '@' && r3 == '@'){
            std::cout << "JACKPOT!!! Ganas 100 monedas\n";
            jug.ganar(100);
        }
        else if(r1 == r2 && r2 == r3){
            std::cout << "3 iguales! Ganas 50 monedas\n";
            jug.ganar(50);
        }
        else if(r1 == r2 or r1 == r3 or r2 == r3){
            std::cout << "2 iguales! Ganas 20 monedas\n";
            jug.ganar(20);
        }
        else{
            std::cout << "Nada, intenta otra vez\n";
        }

        if(jug.getMonedas() > record){
            record = jug.getMonedas();
        }
    }

    std::cout << "Juego terminado\n";
    jug.mostrarSaldo();

    // final
    if(jug.getMonedas() <= 0){
        std::cout<<"Te quedaste sin monedas\n";
    } else {
        std::cout<<"Saliste del juego\n";
    }

    std::cout << "Record maximo: " << record << std::endl;

    return 0;
}