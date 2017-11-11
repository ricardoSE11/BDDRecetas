//
// Created by rshum on 01/09/2017.
//

#ifndef UNTITLED1_BASEDEDATOS_H
#define UNTITLED1_BASEDEDATOS_H

#include <iostream>
using namespace std;

#include "Ingrediente.h"
#include "Receta.h"

/*D:
 *E:
 *S:
 *R:
 */

struct BaseDeDatos
{
    //------------------------------Atributos------------------------------
    Receta recetas[1000];
    int cantidadRecetas;

    //------------------------------Constructores------------------------------
    //Por defecto
    BaseDeDatos(){}

    BaseDeDatos(int cantRecetas)
    {
        this->cantidadRecetas = cantRecetas;
    }

    //------------------------------Métodos------------------------------

    /*D: Método para saber si se repite un ingrediente
     *E: El nombre de la receta (string)
     *S: True si se repite el nombre de la receta, False si no (bool)
     *R: Ninguna*
     */

    //Validaciones
    bool seRepiteReceta(string nombreReceta)
    {
        for (int i = 0; i < 1000 ; i++)
        {
            if (recetas[i].nombre == nombreReceta)
                return true;
        }
        return false;
    }

    /*D: Método para buscar un lugar vacío
     *E: Un Array de Recetas
     *S: La posición vacía, si no hay ninguna posición vacía, retorna -1
     *R: Ninguna*
     */
    int lugarVacio(Receta recetas[1000])
    {
        for (int i = 0 ; i < 1000 ; i++)
        {
            if (recetas[i].cantidadDePorciones == 0)
            {
                return i;
            }
        }
        return -1;
    }

    //Fin de Validaciones

    //------------------------------------------PENDIENTE------------------------------------------

    /*D: Método para agregar recetas a una Base de Datos
     *E: El nombre de la Receta (string) y la cantidad de porciones (int)
     *S: Retorna la posición en la que fue agregada, -1 si no fue agregada.
     *R: Ninguna*
     */

    int agregarReceta(string nombreReceta , int cantPorciones)
    {
        //Si el nombre no se repite
        if (seRepiteReceta(nombreReceta) == false)
        {
            int posicion = lugarVacio(recetas);
            Receta nueva = Receta(nombreReceta , cantPorciones);
            recetas[posicion] = nueva;
            cantidadRecetas++;

            return posicion;
        }
        return -1;

    }
    //------------------------------------------PENDIENTE------------------------------------------


    /*D: Método que busca una receta
     *E: El nombre de la receta
     *S: La posición en la cual está la Receta, si la Receta no existe, retorna -1 (int)
     *R: Ninguna*
     */
    int buscaReceta (string nombreReceta)
    {
        for (int i = 0; i < 1000; i++)
        {
            if (recetas[i].nombre == nombreReceta)
                return i;
        }
        return -1;
    }

    /*D: Método para borrar Receta
     *E: El nombre de la Receta (string)
     *S: True si fue borrada, False si no (bool)
     *R: Ninguna*
     */
    bool borrarReceta(string nombreReceta)
    {
        for (int i = 0; i < 1000; i++)
        {
            //Si la Receta existe
            if  (buscaReceta(nombreReceta) != -1)
            {
                int posicion = buscaReceta(nombreReceta);
                recetas[posicion].nombre = "";
                recetas[posicion].cantidadDePorciones = 0;
                return true;
            }
        }
        return false;
    }

    /*D: Método para modificar el nombre a una Receta
     *E: El nombre de la receta que se quiere cambiar (string) y el nombre nuevo (string)
     *S: True si el nombre fue cambiado, false si no (bool)
     *R: Ninguna*
     */
    bool modificarNombreReceta(string nombreActual , string nombreNuevo)
    {
        //Si la Receta existe
        if  (buscaReceta(nombreActual) != -1)
        {
            recetas[buscaReceta(nombreActual)].nombre = nombreNuevo;
            return true;
        }
        else
            return false;
    }

    /*D: Método para modificar la cantidad de un Ingrediente en una Receta
     *E: Nombre de la Receta (string), nombre del Ingrediente (string) y cantidad nueva (int)
     *S: True si la cantidad fue modificada, False si no (bool)
     *R: Ninguna*
     */
    bool modificarCantidadIngrediente_BDD(string nombreReceta , string nombreIngrediente , int nuevaCantidad)
    {
        //Si la Receta existe
        if (buscaReceta(nombreReceta) != -1)
        {
            int posicion = buscaReceta(nombreReceta);
            Receta recetaActual = recetas[posicion];
            recetaActual.modificarCantidadIngrediente(nombreIngrediente , nuevaCantidad);
            return true;
        }
        else
            return false;
    }

    /*D: Método para agregar un Ingrediente a una Receta
     *E: El nombre de la Receta (string), y los datos de un Ingrediente
     *S: True si el Ingrediente fue agregado, False si no (bool)
     *R: Ninguna*
     */
    bool agregarIngrediente_BDD(string nombreReceta ,string nombreIngrediente , int cantidad , string unidadDeMedida)
    {
        //Si la Receta existe
        if (buscaReceta(nombreReceta) != -1)
        {
            int posicion = buscaReceta(nombreReceta);
            Receta recetaActual = recetas[posicion];
            recetaActual.agregarIngrediente(nombreIngrediente , cantidad , unidadDeMedida);
            return true;
        }
        else
            return false;
    }


    /*D: Método para imprimir Recetas
     *E: Ninguna
     *S: Void
     *R: Ninguna*
     */
    void imprimirTodasLasRecetas()
    {
        for (int i = 0; i < 1000; i++)
        {
            if (recetas[i].cantidadDePorciones != 0)
            {
                recetas[i].imprimirReceta();
            }
        }
    }







};
#endif //UNTITLED1_BASEDEDATOS_H
