//
//  main.cpp
//  Ejercicio1
//
//  Created by Mario Leguízamo Vega on 15/05/20.
//  Copyright © 2020 Mario Leguízamo Vega. All rights reserved.
//

#include <iostream>
//#define n 100
#define pi 3.1416

using namespace std;

float calcularPerimetroPoligono(float tamañoLado, int numeroLados){
    float resultado;
    
    resultado = tamañoLado*numeroLados;
    
    return resultado;
    //return tamañoLado*numeroLados;
}

void identificarPoligono(int numeroLados){
    //comparadores == <= >= < > !=
    switch (numeroLados) {
        case 3:
            cout << "Es un Triangulo\n";
            break;
        case 4:
            cout << "Es un Cuadrado\n";
            break;
        case 5:
            cout << "Es un Pentagono\n";
            break;
        case 6:
            cout << "Es un Hexagono\n";
            break;
        case 7:
            cout << "Es un Heptagono\n";
            break;
        case 8:
            cout << "Es un Octagono\n";
            break;
    }
}

int main() {
    int numeroLados;
    float tamañoLado;
    float resultado;
    
    cout << "Cuantos lados tiene el poligono?\n";
    cin >> numeroLados;
    
    identificarPoligono(numeroLados);
    cout << "Cuanto mide cada lado?\n";
    cin >> tamañoLado;
    resultado = calcularPerimetroPoligono(tamañoLado, numeroLados);
    cout << "El perimetro es: " << resultado << endl;
    
    return 0;
}



/*
float sumarDosValores(int tamañoLado, int numeroLados){
    float resultado;
    
    
}*/
