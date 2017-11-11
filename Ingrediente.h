//
// Created by rshum on 01/09/2017.
//

#ifndef UNTITLED1_INGREDIENTE_H
#define UNTITLED1_INGREDIENTE_H

#include <iostream>
using namespace std;

struct  Ingrediente
{
 //------------------------------Atributos------------------------------
    string nombre;
    int cantidad;
    string unidadDeMedida;

 //------------------------------Constructores------------------------------

    //Por defecto
    Ingrediente()
 {
     nombre = "";
     cantidad = 0;
     unidadDeMedida = "";
 }
    //Otro constructor
    Ingrediente(string nombre , int cantidad , string unidadDeMedida)
    {
        this->nombre = nombre ;
        this->cantidad = cantidad;
        this->unidadDeMedida = unidadDeMedida;
    }

 //------------------------------Métodos------------------------------
    void modificarCantidad(int cantidad_nueva)
 {
     this->cantidad = cantidad_nueva;
 }

    void cambiarCantidad (int nuevaCantidad)
    {
        this->cantidad = nuevaCantidad;
    }

    void imprimirIngrediente()
    {
        cout << "Nombre: " << nombre << "\t" ;
        cout << "Cantidad: " << cantidad << "\t" ;
        cout << "Unidad de medidad: " << unidadDeMedida << endl;
    }



};



#endif //UNTITLED1_INGREDIENTE_H
