//
// Created by rshum on 01/09/2017.
//

#ifndef UNTITLED1_RECETA_H
#define UNTITLED1_RECETA_H

#include <iostream>
using namespace std;

#include "Ingrediente.h"

struct Receta
{
    //------------------------------Atributos------------------------------
    string nombre;
    int cantidadDePorciones;
    //Array (Tipo[tamaño])
    Ingrediente ingredientes[100];
    int cantidadIngredientes;

    //------------------------------Constructores------------------------------
    //Por defecto
    Receta()
    {
        this->nombre = "";
        this->cantidadDePorciones = 0;

    };

    Receta(string nombreReceta , int cantidadPorciones)
    {
        this->nombre = nombreReceta;
        this->cantidadDePorciones = cantidadPorciones;
    }

    //------------------------------Métodos------------------------------

    /*D: Método para buscar un espacio vacío
     *E: El Array de Ingredientes
     *S: La posición en la cual "no hay" un Ingrediente. Si no hay espacios disponibles, retorna -1
     *R: Ninguna*
     */
    int buscarLugarVacio(Ingrediente ingredientes[100])
    {
        for (int i = 0 ; i < 100; i++)
        {
            if (ingredientes[i].cantidad == 0)
            {
                return i;
            }
        }
        return -1;
    }

    /*D: Método para validar si existen Ingredientes repetidos
     *E: El Array de Ingredientes y el nombre que se quiere validar
     *S: True si hay repetidos, False si no
     *R: Ninguna*
     */
    bool seRepiteNombre(Ingrediente ingredientes[100], string nombreIngrediente)
    {
        for (int i = 0; i < 100 ; i++)
            if (ingredientes[i].nombre == nombreIngrediente)
                return true;

        return false;
    }


    /*D: Método para buscar un ingrediente
     *E: El nombre del ingrediente (string)
     *S: La posición del ingrediente en el Array (int), si el ingrediente no existe, retorna -1
     *R: Que el número sea entero y posivito
     */
    int buscarIngrediente(string nombre)
    {
        for (int i = 0 ; i < 100; i++)
        {
            if (ingredientes[i].nombre == nombre )
            {
                return i;
            }
        }
        return -1;
    }

    /*D: Método para cambiar la cantidad de un Ingrediente
     *E: El nombre del ingrediente (string) y la cantidad nueva (int)
     *S: void
     *R: Que el número sea entero y positivo
     */
    void modificarCantidadIngrediente(string nombreIngrediente, int nuevaCantidad)
    {
        if (buscarIngrediente(nombreIngrediente) != -1)
        {
            ingredientes[buscarIngrediente(nombreIngrediente)].cambiarCantidad(nuevaCantidad);
        }
    }

    /*D: Método para agregar un Ingrediente
     *E: El nombre del ingrediente (string) ,la cantidad nueva (int) y la unidad de medidad (string)
     *S: True si el ingrediente fue agregado, False si no (bool)
     *R: Que el número sea entero y positivo
     */
    bool agregarIngrediente(string nombreIngrediente , int cantidad , string unidadDeMedida)
    {
        if (seRepiteNombre(ingredientes , nombreIngrediente) == false)
        {
            int lugar = buscarLugarVacio(ingredientes);
            Ingrediente nuevo = Ingrediente(nombreIngrediente , cantidad , unidadDeMedida);
            ingredientes[lugar] = nuevo;
            cantidadIngredientes++;
            return true;
        }
        else
            return false;
    }

    /*D: Método para imprimir los Ingredientes de una Receta
     *E: Ninguna
     *S: void
     *R: Ninguna*
     */
    void imprimirReceta()
    {
        cout <<"Nombre: "<< "---" << nombre << "---" << endl;
        cout<< "Cantidad de porciones: " << cantidadDePorciones << endl;
        cout << "Ingredientes: " << endl;

        for (int i = 0 ; i < 100 ; i++)
        {
            if (ingredientes[i].cantidad != 0)
            ingredientes[i].imprimirIngrediente();
        }
        cout << "" << endl;
    }



    //Fin de struct
};

#endif //UNTITLED1_RECETA_H
