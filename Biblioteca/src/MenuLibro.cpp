#include <iostream>
#include "MenuLibro.h"
#include "ArchivoLibro.h"
#include "Libro.h"
#include "Cursor.h"
using namespace std;
#include "rlutil.h"

MenuLibro::MenuLibro() : Menu(6) {
}

void MenuLibro::mostrar() {
    system("cls");
    ArchivoLibro archivoLibro;
    int cantidadOpciones = 9, y = 0;
    bool salir = false;
    Cursor cursor(cantidadOpciones, y);

    do {
        //Oculta el cursor del terminal
        cursor.ocultar();

        rlutil::locate(30,10);
        cout << "MENU LIBROS" << endl;
        rlutil::locate(30,11);
        cout << "============================" << endl;
        rlutil::locate(30,12);
        cout << "Ver lista de libros" << endl;
        rlutil::locate(30,13);
        cout << "Agregar libro" << endl;
        rlutil::locate(30,14);
        cout << "Buscar libro por ID" << endl;
        rlutil::locate(30,15);
        cout << "Buscar libro por titulo" << endl;
        rlutil::locate(30,16);
        cout << "Buscar libro por genero" << endl;
        rlutil::locate(30,17);
        cout << "Cargar libros predefinidos" << endl;
        rlutil::locate(30,18);
        cout << "Eliminar libro" << endl;
        rlutil::locate(30,19);
        cout << "Modificar libro" << endl;
        rlutil::locate(30,20);
        cout << "Libros mas prestados" << endl;
        rlutil::locate(30,21);
        cout << "Volver" << endl;

        // Ubicacion inicial del puntero
        cursor.dibujar(y);

        switch (rlutil::getkey())
        {
        case 14: // ARRIBA
            y = cursor.moverArriba(y);
            break;
        case 15: // ABAJO
            y = cursor.moverAbajo(y);
            break;
        case 1: // ENTER
            switch (y)
            {
            case 0:
                {
                system("cls");
                archivoLibro.listarLibros();
                rlutil::anykey();
                system("cls");
                break;
                }
            case 1:
                {
                Libro nuevoLibro;
                system("cls");
                nuevoLibro.agregarLibro();
                archivoLibro.agregarLibro(nuevoLibro);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 2:
                {
                int id = 0;
                system("cls");
                cout << "Ingrese el ID que desea buscar: ";
                cin >> id;
                archivoLibro.buscarLibroPorID(id);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 3:
                {
                char titulo[30];
                system("cls");
                cout << "Ingrese el titulo a buscar: ";
                cin.ignore();
                cin.getline(titulo, sizeof(titulo));
                archivoLibro.buscarLibroPorTitulo(titulo);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 4:
                {
                char genero[30];
                cout << "Ingrese el genero que desea buscar: " << endl;
                cin.ignore();
                cin.getline(genero, sizeof(genero));
                archivoLibro.buscarLibroPorGenero(genero);
                break;
                }
            case 5:
                {
                system("cls");
                archivoLibro.cargaVariosAux();
                cout << "Se han cargado libros" << endl;
                rlutil::anykey();
                system("cls");
                break;
                }
            case 6:
                {
                system("cls");
                cout << "Ingrese el ID del libro que desea eliminar: " << endl;
                archivoLibro.bajaLogica();
                rlutil::anykey();
                system("cls");
                break;
                }
            case 7:
                {
                system("cls");
                int aux;
                cout << "Ingrese el ID del libro a modificar: " << endl;
                cin >> aux;
                archivoLibro.modificarLibro(aux);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 8:
                {
                system("cls");
                archivoLibro.listarLibrosMasPrestados(5);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 9:
                {
                salir = true;
                system("cls");
                break;
                }
            default:
                break;
            }
        }
    } while (!salir);
}
