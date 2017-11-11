#include <iostream>
#include <string>

using namespace std;

#include "Ingrediente.h"
#include "Receta.h"
#include "BaseDeDatos.h"

BaseDeDatos BDD = BaseDeDatos(0);

int main() {
    //declaración de métodos
    void menu ();
    void cincoRecetas();
    void printMenu();

    cincoRecetas();
    while (true)
    {
        printMenu();
        menu();
    }

    std::cout << "Hello " << std::endl;
    return 0;

    //End of main
}

    /*D: Método para imprimir el menú
     *E: Ninguna
     *S: Ninguna
     *R: Ninguna
     */
    void printMenu()
    {
        cout << "--- Bienvenido a la Base de Datos de Recetas ---" << endl;
        cout << "1. Agregar receta" << endl;
        cout << "2. Buscar receta" << endl;
        cout << "3. Borrar receta" << endl;
        cout << "4. Imprimir todas las recetas" << endl;
        cout << "5. Modificar nombre de una receta" << endl;
        cout << "6. Modificar cantidad de un ingrediente" << endl;
        cout << "7. Agregar ingrediente a una receta" << endl;
        cout << "8. Salir" << endl;
        cout << " " << endl;

    }

    /*D: Método para ejecutar el menú
     *E: Ninguna (contiene un cin adentro que se encarga de la entrada.)
     *S: El resultado correspondiente a la opción escogida
     *R: Ninguna
     */
    void menu () {
        int opcion;

        cout << "Por favor eliga una opción: ";
        cin >> opcion;

        //Evaluación de casos
        switch (opcion) {
            case 1: {
                string nombreReceta;
                int cantPorciones;
                string SiNo = "Si";

                string nombreIngrediente;
                int cantidad;
                string unidadDeMedida;

                cout << "Ingrese el nombre de la nueva receta: ";
                cin.ignore();
                getline(cin , nombreReceta);
                if (BDD.seRepiteReceta(nombreReceta) == true)
                {
                    cout << "ERROR. Ya existe una receta con ese nombre. " << endl;
                }
                else
                {
                    cout << "Ingrese la cantidad de porciones: ";
                    cin >> cantPorciones;
                    cout << "--Ingredientes--";
                    cout << "" << endl;
                }


                if (BDD.seRepiteReceta(nombreReceta) == false)
                {
                    int place = BDD.agregarReceta(nombreReceta, cantPorciones);
                    Receta * nueva = & BDD.recetas[place];

                    while (SiNo == "Si" )
                    {
                        cout << "Ingrese el nombre del ingrediente: ";
                        cin.ignore();
                        getline(cin , nombreIngrediente);

                        cout << "Ingrese la cantidad: ";
                        cin >> cantidad;

                        cout << "Ingrese la unidad de medidad: ";
                        cin.ignore();
                        getline(cin , unidadDeMedida);

                        nueva->agregarIngrediente(nombreIngrediente , cantidad , unidadDeMedida);

                        cout << "¿Desea continuar agregando ingredientes?";
                        cin >> SiNo;
                        cout << "";

                    }
                }





            }
                break;


            case 2: {
                string nombreReceta;
                cout << "Ingrese el nombre de la receta que busca: ";
                cin.ignore();
                getline(cin , nombreReceta);
                int posicion = BDD.buscaReceta(nombreReceta);
                if (posicion != -1) {
                    Receta encontrada = BDD.recetas[posicion];
                    encontrada.imprimirReceta();

                } else
                    cout << "No se encontró la receta." << endl;



            }break;

            case 3: {
                string nombreReceta;
                cout << "Ingrese el nombre de la receta que desea borrar: ";
                cin.ignore();
                getline(cin , nombreReceta);

                int posicion = BDD.buscaReceta(nombreReceta);
                if (posicion != -1) {
                    BDD.borrarReceta(nombreReceta);
                    cout << "La Receta" << "  " << nombreReceta << " " << "fue borrada" << endl;
                    cout << "";
                } else
                    cout << "No se encontró la receta." << endl;
                    cout << "";

            }
                break;

            case 4: {
                BDD.imprimirTodasLasRecetas();
            }
                break;

            case 5: {
                string nombreActual;
                string nombreNuevo;

                cout << "Ingrese el nombre de la receta a la cual le desea modificar el nombre: ";
                cin.ignore();
                getline(cin , nombreActual);
                cout << "" << endl;
                cout << "Ingrese el nombre nuevo para su receta: ";
                getline(cin , nombreNuevo);
                cout << "" << endl;

                if (BDD.buscaReceta(nombreActual) != -1) {
                    BDD.modificarNombreReceta(nombreActual, nombreNuevo);
                    cout << "El nombre fue modificado con éxito." << endl;
                } else
                    cout << "No se pudo realizar la modificación." << endl;


            }
                break;

            case 6: {
                string nombreReceta;
                string nombreIngrediente;
                int cantidadNueva;

                cout << "Ingrese el nombre de la receta: ";
                cin.ignore();
                getline(cin , nombreReceta);
                cout << "Ingrese el nombre del ingrediente: ";
                getline(cin , nombreIngrediente);
                cout << "Ingrese la nueva cantidad: ";
                cin >> cantidadNueva;

                int posicion = BDD.buscaReceta(nombreReceta);
                if (posicion != -1) {
                    BDD.recetas[posicion].modificarCantidadIngrediente(nombreIngrediente, cantidadNueva);
                    cout << "Cantidad modificada con éxito" << endl;
                } else
                    cout << "No se pudo modificar la cantidad." << endl;
            }
                break;

            case 7: {
                string nombreReceta;

                string nombreIngrediente;
                int cantidad;
                string unidadDeMedida;

                cout << "Ingrese el nombre de la receta: ";
                cin.ignore();
                getline(cin , nombreReceta);

                int receta = BDD.buscaReceta(nombreReceta);

                cout << "Ingrese el nombre del ingrediente: ";
                getline(cin , nombreIngrediente);

                if (BDD.recetas[receta].seRepiteNombre(BDD.recetas[receta].ingredientes , nombreIngrediente) == true)
                {
                    cout <<"ERROR. Ya exite un ingrediente con ese nombre." << endl;
                }
                else
                {
                    cout << "Ingrese la cantidad: ";
                    cin >> cantidad;


                    cout << "Ingrese la unidad de medida: ";
                    cin >> unidadDeMedida;
                    cout << "" << endl;
                }

                if (BDD.recetas[receta].seRepiteNombre(BDD.recetas[receta].ingredientes , nombreIngrediente) == false)
                {
                    int posicion = BDD.buscaReceta(nombreReceta);
                    if (posicion != -1) {
                        Receta * encontrada = & BDD.recetas[posicion];
                        if (encontrada->seRepiteNombre(encontrada->ingredientes, nombreIngrediente) == false) {
                            encontrada->agregarIngrediente(nombreIngrediente, cantidad, unidadDeMedida);
                            cout << "Se agregó el ingrediente con éxito" << endl;
                        } else
                            cout << "Ya existe un ingrediente con ese nombre" << endl;
                    } else
                        cout << "No se pudo agregar el ingrediente" << endl;
                }
            }
                break;
            case 8: {
                cout << "Hasta luego, que tenga buen día.";
                exit(EXIT_SUCCESS);
            }
            default: {
                cout << "Por favor ingrese una opción dentro del rango.";
            }
        }
    }

    /*D: Método para insertar 5 recetas
     *E: Ninguna
     *S: Ninguna
     *R: Ninguna
     */
    void cincoRecetas()
    {
        Receta receta1 = Receta("Arroz con pollo" , 12);
        receta1.agregarIngrediente("Arroz" , 20 , "g");
        receta1.agregarIngrediente("Maíz" , 10 , "g");
        receta1.agregarIngrediente("Sal" , 15, "g");
        receta1.agregarIngrediente("Pollo" , 1, "kg");

        Receta receta2 = Receta("Huevos con jamón" , 1);
        receta2.agregarIngrediente("Huevos" , 10, "g");
        receta2.agregarIngrediente("Jamón" , 7, "g");
        receta2.agregarIngrediente("Cebolla" , 2, "g");
        receta2.agregarIngrediente("Chile Dulce" , 1, "g");

        Receta receta3 = Receta("Pancakes" , 5);
        receta3.agregarIngrediente("Huevos" , 5 , "g");
        receta3.agregarIngrediente("Harina" , 5, "g");
        receta3.agregarIngrediente("Azúcar" , 10 , "g");
        receta3.agregarIngrediente("Vainilla", 12, "ml");
        receta3.agregarIngrediente("Polvo para hornear" , 8 , "g");

        Receta receta4 = Receta("Spaghetti a la bolognesa" , 5);
        receta4.agregarIngrediente("Pasta" , 10 , "g");
        receta4.agregarIngrediente("Salsa de tomate" , 20 , "ml");
        receta4.agregarIngrediente("Carne" , 50 , "g");

        Receta receta5 = Receta("Pinto" , 15);
        receta5.agregarIngrediente("Arroz" , 50 , "g");
        receta5.agregarIngrediente("Frijoles" , 45 , "g");
        receta5.agregarIngrediente("Salsa inglesa (Lizano)" , 20 , "ml");
        receta5.agregarIngrediente("Cebolla" , 20 , "g");
        receta5.agregarIngrediente("Chile dulce" , 20 , "g");

        BDD.recetas[0] = receta1;
        BDD.recetas[1] = receta2;
        BDD.recetas[2] = receta3;
        BDD.recetas[3] = receta4;
        BDD.recetas[4] = receta5;
    }







