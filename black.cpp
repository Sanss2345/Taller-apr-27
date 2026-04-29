#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Jugador{
    private:
        std::string nombre_;
        int puntos_;
    public:
        Jugador(std::string n){
            nombre_ = n;
            puntos_ = 0;
        }

        std::string getNombre(){
            return nombre_;
        }

        int getPuntos(){
            return puntos_;
        }

        void sumarPuntos(int carta){
            puntos_ += carta;
        }

        void mostrar(){
            std::cout << nombre_ << " tiene: " << puntos_ << " puntos\n";
        }
};

// mazo global 
int mazo[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

int sacarCarta(){
    int r = rand() % 13;
    return mazo[r];
}


int main(){

    srand(time(0));

    std::string nombre;
    std::cout << "Ingresa tu nombre: ";
    std::cin >> nombre;

    Jugador jug(nombre);
    Jugador dealer("dealer");

    // cartas iniciales
    int cartajug = sacarCarta();
    int cartajug2 = sacarCarta();
    jug.sumarPuntos(cartajug);
    jug.sumarPuntos(cartajug2);

    int cartcrup = sacarCarta();
    int cartcrup2 = sacarCarta();
    dealer.sumarPuntos(cartcrup);
    dealer.sumarPuntos(cartcrup);

    std::cout << "Tus cartas: " << cartajug << ", " << cartajug2 << std::endl;
    jug.mostrar();

    std::cout << "Dealer muestra: " << cartcrup << " y ?" << std::endl;

    // turno jugador
    while(true){
        if(jug.getPuntos() > 21){
            std::cout << "Te pasaste de 21. Perdiste\n";
            return 0;
        }

        char op;
        std::cout << "Pedir carta (p) o Plantarse (s): ";
        std::cin >> op;
        if(op == 'p'){
            int nueva = sacarCarta();
            std::cout << "Nueva carta: " << nueva << std::endl;
            jug.sumarPuntos(nueva);
            jug.mostrar();
        }
        else if(op == 's'){
            std::cout << "Te plantaste con " << jug.getPuntos() << "\n";
            break;
        }
    }

    // turno dealer
    std::cout << "\nTurno del dealer...\n";
    dealer.mostrar();
    while(dealer.getPuntos() < 17){
        int nueva = sacarCarta();
        std::cout << "EL Dealer agarra una nueva carta: " << nueva << std::endl;
        dealer.sumarPuntos(nueva);
        dealer.mostrar();
    }

    // resultado final
    std::cout << "\nRESULTADO FINAL\n";
    jug.mostrar();
    dealer.mostrar();
    if(dealer.getPuntos() > 21){
        std::cout << "El Dealer se paso, Ganaste!\n";
    }
    else if(jug.getPuntos() > dealer.getPuntos()){
        std::cout << "Ganaste!\n";
    }
    else if(jug.getPuntos() < dealer.getPuntos()){
        std::cout << "Perdiste\n";
    }
    else{
        std::cout << "Empate\n";
    }

    return 0;
}