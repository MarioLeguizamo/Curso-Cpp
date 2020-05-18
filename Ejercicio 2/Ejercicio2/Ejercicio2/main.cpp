//
//  main.cpp
//  Ejercicio2
//
//  Created by Mario Leguízamo Vega on 17/05/20.
//  Copyright © 2020 Mario Leguízamo Vega. All rights reserved.
//

#include <iostream>

using namespace std;

int* cargarArreglo(int tamanoArreglo){
    int *arreglo;
    
    arreglo = new int(tamanoArreglo);
    
    for(int contador=0; contador<tamanoArreglo; contador++) {
        cout << "Ingresar el valor " << contador+1 << ": ";
        cin >> arreglo[contador];
    }
    
    return arreglo;
}

void imprimirArreglo(int *arreglo, int tamanoArreglo){
    cout << "\nArreglo : ";
    for (int contador=0; contador<tamanoArreglo; contador++) {
        cout << arreglo[contador] << " ";
    }
    cout << endl;
}

int* ordenarMayorAMenor(int* arreglo, int tamanoArreglo){
    int cambio;
    
    for (int contador1=0; contador1<tamanoArreglo; contador1++){
        for (int contador2=0; contador2<tamanoArreglo-1; contador2++){
            if (arreglo[contador2] < arreglo[contador2+1]){
                cambio = arreglo[contador2];
                arreglo[contador2] = arreglo[contador2+1];
                arreglo[contador2+1] = cambio;
            }
        }
    }
    
    return arreglo;
}

int* ordenarMenorAMayor(int* arreglo, int tamanoArreglo){
    int cambio;
    
    for (int contador1=0; contador1<tamanoArreglo; contador1++){
        for (int contador2=0; contador2<tamanoArreglo-1; contador2++){
            if (arreglo[contador2] > arreglo[contador2+1]){
                cambio = arreglo[contador2+1];
                arreglo[contador2+1] = arreglo[contador2];
                arreglo[contador2] = cambio;
            }
        }
    }
    
    return arreglo;
}

int obtenerMayor(int *arreglo, int tamanoAreglo){
    int mayor;
    
    arreglo = ordenarMayorAMenor(arreglo, tamanoAreglo);
    mayor = arreglo[0];
    
    return mayor;
}

int obtenerMenor(int *arreglo, int tamanoAreglo){
    int menor;
    
    arreglo = ordenarMenorAMayor(arreglo, tamanoAreglo);
    menor = arreglo[0];
    
    return menor;
}

float obtenerMedia(int *arreglo, int tamanoArreglo){
    float media = 0;
    
    for(int contador=0; contador<tamanoArreglo; contador++) {
        media += arreglo[contador];
    }
    media = media/tamanoArreglo;
    
    return media;
}

int obtenerModa(int *arreglo, int tamanoArreglo){
    int moda = arreglo[0];
    int contador1 = 0;
    int contador2 = 0;
    
    arreglo = ordenarMenorAMayor(arreglo, tamanoArreglo);
    for(int contador=1; contador<tamanoArreglo; contador++) {
        if (arreglo[contador] == arreglo[contador-1]) {
            contador1++;
            if (contador1<contador2) {
                contador2 = contador1;
                moda = arreglo[contador];
            }
        }
    }
    
    return moda;
}

int main(int argc, char** argv) {
    int *arreglo = nullptr;
    int tamanoArreglo = 0;
    int mayor;
    int menor;
    float media;
    int moda;
    int opcionMenu;
    
    do {
        cout << "\t\t\nMenu";
        cout << "\n1. Cargar arreglo";
        cout << "\n2. Ordenar de mayor a menor";
        cout << "\n3. Ordenar de menor a mayor";
        cout << "\n4. Obtener el numero mayor y el numero menor";
        cout << "\n5. Obtener la moda";
        cout << "\n6. Obtener la media";
        cout << "\n7. Salir";
        cout << "\nElige una opcion: ";
        cin >> opcionMenu;
            
        switch (opcionMenu) {
            case 1:
                cout << "\n¿Cual es el tamaño del arreglo?: ";
                cin >> tamanoArreglo;
                arreglo = cargarArreglo(tamanoArreglo);
                imprimirArreglo(arreglo, tamanoArreglo);
                break;
            case 2:
                arreglo = ordenarMayorAMenor(arreglo, tamanoArreglo);
                imprimirArreglo(arreglo, tamanoArreglo);
                break;
            case 3:
                arreglo = ordenarMenorAMayor(arreglo, tamanoArreglo);
                imprimirArreglo(arreglo, tamanoArreglo);
                break;
            case 4:
                mayor = obtenerMayor(arreglo, tamanoArreglo);
                menor = obtenerMenor(arreglo, tamanoArreglo);
                cout << "\nMayor: " << mayor;
                cout << "\nMenor: " << menor;
                break;
            case 5:
                moda = obtenerModa(arreglo, tamanoArreglo);
                cout << "\nModa: " << moda;
                break;
            case 6:
                media = obtenerMedia(arreglo,tamanoArreglo);
                cout << "\nMedia: " << media;
                break;
            case 7:
                cout << "\nSaliendo nadie vera este mensaje";
                break;
                
            default:
                cout << "\nOpcion no disponible\n";
                break;
        }
        //system("cls");
    }while (opcionMenu != 7);
    
    return 0;
    //system("pause");
}
