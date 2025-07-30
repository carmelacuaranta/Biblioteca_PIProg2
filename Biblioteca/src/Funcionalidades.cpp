#include "Funcionalidades.h"
#include <iostream>
using namespace std;
#include "Cuota.h"
#include "Socio.h"
#include "Libro.h"
#include "ArchivoSocio.h"
#include "Prestamo.h"

Cuota cargarCuotaDesdeConsola() {
    Cuota c;
    ArchivoSocio archivoSoc;

    int id;
    int idSocio;
    int aux;
    float monto;
    bool pagada;
    Fecha fecha;

    std::cout << "Ingrese ID de la cuota: ";
    std::cin >> id;
    c.setIdCuota(id);

    std::cout << "Ingrese ID del socio: ";
    std::cin >> idSocio;

    if (archivoSoc.buscarSocioPorID(idSocio) >= 0) {
        c.setIdSocio(idSocio);
    } else {
        cout << "El socio no existe. Se asignará igual el ID (no recomendado)." << std::endl;
        c.setIdSocio(idSocio);
    }

    cout << "Ingrese monto: ";
    cin >> monto;
    c.setMonto(monto);

    cout << "¿Está pagada? (1=Si, 0=No): ";
    cin >> aux;
    c.setPagada(aux == 1);

    cout << "Ingrese fecha de pago: ";
    fecha.cargarManual();
    c.setFecha(fecha);

    c.setEstado(true);

    return c;
}

void mostrarCuotaPorConsola(Cuota c) {
    cout << "ID: " << c.getIdCuota() << endl;
    cout << "ID Socio: " << c.getIdSocio() << endl;
    cout << "Monto: " << c.getMonto() << endl;
    if (c.getPagada() == true ){
        cout << "Pagada: SI. " << endl;
    } else {
        cout << "Pagada: NO. " << endl;
    }
    cout << "Fecha de vencimiento: " << c.getFecha().toString() << endl;
}

Socio cargarSocioPorConsola() {
    Socio socio;
    int id;
    char dni[10];
    char nombre[50];
    char apellido[50];
    char telefono[20];
    char direccion[100];
    char  email[50];
    Fecha fechaNac;

    cout << "Ingrese ID: ";
    cin >> id;
    socio.setId(id);
    cin.ignore();

    cout << "Ingrese DNI: ";
    cin.getline(dni, sizeof(dni));
    socio.setDni(dni);

    cout << "Ingrese nombre: ";
    cin.getline(nombre, sizeof(nombre));
    socio.setNombre(nombre);

    cout << "Ingrese apellido: ";
    cin.getline(apellido, sizeof(apellido));
    socio.setApellido(apellido);

    cout << "Ingrese telefono: ";
    cin.getline(telefono, sizeof(telefono));
    socio.setTelefono(telefono);

    cout << "Ingrese direccion: ";
    cin.getline(direccion, sizeof(direccion));
    socio.setDireccion(direccion);

    cout << "Ingrese email: ";
    cin.getline(email, sizeof(email));
    socio.setEmail(email);

    cout << "Ingrese la fecha de nacimiento:" << endl;
    fechaNac.cargarManual();
    socio.setFechaNac(fechaNac);

    socio.setEstado(true);

    return socio;
}


void mostrarSocioPorConsola(Socio socio) {
        cout << "ID: " << socio.getId() << endl;
        cout << "DNI: " << socio.getDni() << endl;
        cout << "Nombre: " << socio.getNombre() << endl;
        cout << "Apellido: " << socio.getApellido() << endl;
        cout << "Telefono: " << socio.getTelefono() << endl;
        cout << "Direccion: " << socio.getDireccion() << endl;
        cout << "Email: " << socio.getEmail() << endl;
        cout << "Fecha de Nacimiento: " << socio.getFechaNac().toString() << endl;
}

Libro cargarLibroPorConsola() {
    Libro libro;
    int id;
    int isbn;
    int cantEjemplares;
    char titulo[100];
    char autor[50];
    char genero[30];
    Fecha fechaPub;

    cout << "Ingrese ID del libro: ";
    cin >> id;
    libro.setId(id);
    cin.ignore();

    cout << "Ingrese número de ISBN: ";
    cin >> isbn;
    libro.setIsbn(isbn);
    cin.ignore();

    cout << "Ingrese titulo: ";
    cin.getline(titulo, 100);
    libro.setTitulo(titulo);

    cout << "Ingrese autor: ";
    cin.getline(autor, 100);
    libro.setAutor(autor);

    cout << "Ingrese género: ";
    cin.getline(genero, 50);
    libro.setGenero(genero);

    cout << "Ingrese cantidad de ejemplares: ";
    cin >> cantEjemplares;
    libro.setCantEjemplares(cantEjemplares);
    cin.ignore();

    cout << "Ingrese la fecha de publicación:" << endl;
    fechaPub.cargarManual();
    libro.setFechaPublicacion(fechaPub);

    libro.setEstado(true);

    return libro;
}


void mostrarLibroPorConsola(Libro lib) {
    cout << "ID: " << lib.getId() << endl;
    cout << "ISBN: " << lib.getIsbn() << endl;
    cout << "Titulo: " << lib.getTitulo() << endl;
    cout << "Autor: " << lib.getAutor() << endl;
    cout << "Genero: " << lib.getGenero() << endl;
    cout << "Cantidad de ejemplares: " << lib.getCantEjemplares() << endl;
    cout << "Fecha de Publicacion: " << lib.getFechaPublicacion().toString() << endl;
    if (lib.getEstado() == true){
        cout << "Disponible." << endl;
    } else {
        cout << "Eliminado." << endl;
    }
}

void mostrarPrestamoPorConsola(Prestamo pres){
    cout<<"ID del prestamo: " << pres.getId() << endl;
    cout<<"ID del socio: " << pres.getIdSocio() << endl;
    cout<<"ID del libro: " << pres.getIdLibro() << endl;
    cout<< "Fecha de inicio: " << pres.getFechaPrestado().toString() << endl;
    cout << "Fecha de vencimiento: " << pres.getFechaDevolucion().toString() << endl;
}

Prestamo cargarPrestamoDesdeConsola(){
    Prestamo pres;
    int idSocio;
    int idLibro;
    Fecha fechaPrestado;
    Fecha fechaDevolucion;
    cout << "Ingrese ID del Socio: " << endl;
    cin >> idSocio;
    cout << "Ingrese ID del Libro: " << endl;
    cin >> idLibro;

    fechaPrestado.cargarFechaSistema();
    cout << "Fecha de inicio del prestamo: " << fechaPrestado.toString() << endl;
    cout << "Ingrese la fecha de finalizacion del prestamo: " << endl;
    fechaDevolucion.cargarManual();

    pres.setIdSocio(idSocio);
    pres.setIdLibro(idLibro);
    pres.setFechaPrestado(fechaPrestado);
    pres.setFechaDevolucion(fechaDevolucion);

    return pres;
}
