#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include <array>
#include <iomanip>

// clase extraaaa
class Tablero{
    public:
    std::array<std::array<std::string,3>,3> t = {{
        {"1","2","3"},
        {"4","5","6"},
        {"7","8","9"}
    }};
};

class Jugador{
    private:
        std::string nombre_, simbolo_;
    public:
        Jugador(std::string n, std::string x){
            nombre_=n;
            simbolo_=x;
        }

        std::string getsimbolo() const{
            return simbolo_;
        }

        void turno(std::string& turno){
            std::cout<<"Jugador: "<< nombre_ <<" Ingresa que casillero deseas ocupar: "<<std::endl;
            std::cin>>turno;
        }
};

void datosjug(std::string& n, std::string& l){
    std::cout<<"Ingresa nombre del jugador:"<<std::endl;
    std::cin>>n;
    std::cout<<"Ingresa el simbolo del jugador:"<<std::endl;
    std::cin>>l; 
}

void mostrartab(std::array<std::array<std::string,3>,3> tablero){
    std::cout<<"-------------\n";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            std::cout<<"| "<<tablero[i][j]<<" ";
        }
        std::cout<<"|\n-------------\n";
    }
}

bool verificarganador(std::array<std::array<std::string,3>,3> tablero){

    for(int i=0; i<3; i++){
        if(tablero[i][0] == tablero[i][1] && tablero[i][0] == tablero[i][2]){
            return true;
        }
    }

    for(int i=0; i<3; i++){
        if(tablero[0][i] == tablero[1][i] && tablero[0][i] == tablero[2][i]){
            return true;
        }
    }

    if(tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2]){
        return true;
    }

    if(tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0]){
        return true;
    }

    return false;
}

int main(){

    Tablero tab; 
    auto& tablero = tab.t;

    std::string p1, p2,simbo1,simbo2;
    datosjug(p1,simbo1);
    datosjug(p2,simbo2);

    Jugador jug1(p1,simbo1);
    Jugador jug2(p2,simbo2);

    std::cout<<std::setw(10)<<"TIC TAC TOE"<<std::endl;

    int turnos = 0; 

    while(true){

        std::string turno1="", turno2="";

        //JUGADOR 1
        jug1.turno(turno1);

        //Validar turno
        if(turno1 < "1" or turno1 > "9"){
            std::cout<<"Entrada invalida\n";
            continue;
        }

        int pos = std::stoi(turno1);
        int fila = (pos - 1) / 3;
        int col  = (pos - 1) % 3;

        if(tablero[fila][col] != "X" && tablero[fila][col] != "O"){
            tablero[fila][col] = jug1.getsimbolo();
        } else {
            std::cout<<"Casilla ocupada\n";
            continue;
        }

        turnos++; 

        mostrartab(tablero);

        if(verificarganador(tablero)){
            std::cout<<"GANADOR JUGADOR 1"<<std::endl;
            break;
        }

        if(turnos == 9){ 
            std::cout<<"EMPATE\n";
            break;
        }

        // JUGADOR 2
        jug2.turno(turno2);

        //validar turno 
        if(turno2 < "1" or turno2 > "9"){
            std::cout<<"Entrada invalida\n";
            continue;
        }

        pos = std::stoi(turno2);
        fila = (pos - 1) / 3;
        col  = (pos - 1) % 3;

        if(tablero[fila][col] != "X" && tablero[fila][col] != "O"){
            tablero[fila][col] = jug2.getsimbolo();
        } else {
            std::cout<<"Casilla ocupada\n";
            continue;
        }

        turnos++; 

        mostrartab(tablero);

        if(verificarganador(tablero)){
            std::cout<<"GANADOR JUGADOR 2"<<std::endl;
            break;
        }

        if(turnos == 9){
            std::cout<<"EMPATE\n";
            break;
        }
    }

    return 0;
}