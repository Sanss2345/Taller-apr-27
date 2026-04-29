#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

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

// Simbolos glob
char simbolos[4] = {'@','#','$','%'};

int main(){

    srand(time(0));

    std::string nombre;
    std::cout << "Ingresa tu nombre: ";
    std::cin >> nombre;

    Jugador jug(nombre);

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

        if(op == 'n'){
            break;
        }

        std::cout << "Suerte...\n";

        jug.apostar(10);

        // tirar 3 simbo aleato
        char r1 = simbolos[rand() % 4];
        char r2 = simbolos[rand() % 4];
        char r3 = simbolos[rand() % 4];

        std::cout << "[ " << r1 << " ] [ " << r2 << " ] [ " << r3 << " ]\n";

        //Resultados
        if(r1 == '@' && r2 == '@' && r3 == '@'){
            std::cout << "JACKPOT!!! Ganas 100 monedas\n";
            jug.ganar(100);
        }
        else if(r1 == r2 && r2 == r3){
            std::cout << "3 iguales! Ganas 50 monedas\n";
            jug.ganar(50);
        }
        else if(r1 == r2 || r1 == r3 || r2 == r3){
            std::cout << "2 iguales! Ganas 20 monedas\n";
            jug.ganar(20);
        }
        else{
            std::cout << "Nada, intenta otra vez\n";
        }

        //actualizar record
        if(jug.getMonedas() > record){
            record = jug.getMonedas();
        }
    }

    std::cout << "Juego terminado\n";
    jug.mostrarSaldo();
    std::cout << "Record maximo: " << record << std::endl; //nuevo record
    return 0;
}