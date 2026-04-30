#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// clase extra
class Mazo{
    public:
        int cartas[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

        int sacar(){
            return cartas[rand() % 13];
        }
};

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

int main(){

    srand(time(0));

    std::string nombre;
    std::cout << "Ingresa tu nombre: ";
    std::cin >> nombre;

    Jugador jug(nombre);
    Jugador crupier("Crupier");

    Mazo mazo; 

    // cartas iniciales
    int carta1 = mazo.sacar();
    int carta2 = mazo.sacar();

    jug.sumarPuntos(carta1);
    jug.sumarPuntos(carta2);

    int carta3 = mazo.sacar();
    int carta4 = mazo.sacar();

    crupier.sumarPuntos(carta3);
    crupier.sumarPuntos(carta4);

    std::cout << "Tus cartas: " << carta1 << ", " << carta2 << std::endl;
    jug.mostrar();

    std::cout << "Crupier muestra: " << carta3 << " y ?" << std::endl;

    while(true){

        std::cout<<"====================\n";
        jug.mostrar();
        std::cout<<"====================\n";

        if(jug.getPuntos() > 21){
            std::cout << "Te pasaste de 21. Perdiste\n";
            break;
        }

        char op;
        std::cout << "Pedir carta (p) o Plantarse (s): ";
        std::cin >> op;

        // validar 
        if(op != 'p' && op != 's'){
            std::cout<<"Opcion invalida\n";
            continue;
        }

        if(op == 'p'){
            int nueva = mazo.sacar();
            std::cout << "Nueva carta: " << nueva << std::endl;

            jug.sumarPuntos(nueva);
        }
        else if(op == 's'){
            std::cout << "Te plantaste con " << jug.getPuntos() << std::endl;
            break;
        }
    }

    // turno crupier
    std::cout << "\nTurno del crupier...\n";
    crupier.mostrar();

    while(crupier.getPuntos() < 17){
        int nueva = mazo.sacar();
        std::cout << "Crupier roba: " << nueva << std::endl;
        crupier.sumarPuntos(nueva);
    }

    // resultados
    std::cout << "\nRESULTADO FINAL\n";
    jug.mostrar();
    crupier.mostrar();

    if(jug.getPuntos() > 21){
        std::cout<<"Perdiste\n";
    }
    else if(crupier.getPuntos() > 21){
        std::cout<<"Ganaste\n";
    }
    else if(jug.getPuntos() > crupier.getPuntos()){
        std::cout<<"Ganaste\n";
    }
    else if(jug.getPuntos() < crupier.getPuntos()){
        std::cout<<"Perdiste\n";
    }
    else{
        std::cout<<"Empate\n";
    }

    return 0;
}