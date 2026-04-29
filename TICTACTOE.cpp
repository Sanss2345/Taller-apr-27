#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include <array>
#include <iomanip>

class Jugador{
    private:
        std::string nombre_, simbolo_;
    public:
        std::string getname() const{
            return nombre_;
        }
        Jugador(std::string n, std::string x){
            nombre_=n;
            simbolo_=x;
        }

        std::string getsimbolo() const { //obtener simbolo 
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
    std::cout<<"\nTABLERO"<<std::endl;
     for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            std::cout<<tablero[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

bool verificarganador(std::array<std::array<std::string,3>,3> tablero){

    // filas
    for(int i=0; i<3; i++){
        if(tablero[i][0] == tablero[i][1] && tablero[i][0] == tablero[i][2]){
            return true;
        }
    }

    // columnas
    for(int i=0; i<3; i++){
        if(tablero[0][i] == tablero[1][i] && tablero[0][i] == tablero[2][i]){
            return true;
        }
    }

    // diagonales
    if(tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2]){
        return true;
    }

    if(tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0]){
        return true;
    }

    return false; 
}

int main(){

    std::array<std::array<std::string,3>,3> tablero = {{
        {"1","2","3"},
        {"4","5","6"},
        {"7","8","9"}
    }};

    std::string p1, p2,simbo1,simbo2;
    datosjug(p1,simbo1);
    datosjug(p2,simbo2);

    Jugador jug1(p1,simbo1);
    Jugador jug2(p2,simbo2);

    std::cout<<std::setw(10)<<"TIC TAC TOE"<<std::endl;
    mostrartab(tablero);
    std::cout<<std::endl;

    while(true){
        std::string turno1="", turno2="";
        //JUGADOR 1
        jug1.turno(turno1);

        int pos = std::stoi(turno1); //aqui convierto a numero la pos para con calculos mat acceder a las filas  y columnas 
        int fila = (pos - 1) / 3;
        int col  = (pos - 1) % 3;

        if(tablero[fila][col] != "X" && tablero[fila][col] != "O"){
            tablero[fila][col] = jug1.getsimbolo();
        } else {
            std::cout<<"Casilla ocupada\n";
            continue;
        }

        mostrartab(tablero);

        if(verificarganador(tablero)){
            std::cout<<"GANADOR "<<jug1.getname()<<std::endl;
            break;
        }

        //JUGADOR 2 
        jug2.turno(turno2);

        pos = std::stoi(turno2);
        fila = (pos - 1) / 3;
        col  = (pos - 1) % 3;

        if(tablero[fila][col] != "X" && tablero[fila][col] != "O"){
            tablero[fila][col] = jug2.getsimbolo();
        } else {
            std::cout<<"Casilla ocupada\n";
            continue;
        }

        mostrartab(tablero);

        if(verificarganador(tablero)){
            std::cout<<"GANADOR "<<jug2.getname()<<std::endl;
            break;
        }
    }

    return 0;
}