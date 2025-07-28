#include "Funcionalidades.h"
#include <iostream>
using namespace std;
#include "Cuota.h"
#include "Socio.h"
#include "Libro.h"
#include "ArchivoSocio.h"

Cuota cargarCuotaDesdeConsola() {
    Cuota c;
    ArchivoSocio archivoSoc;

    int id, idSocio, aux;
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
        std::cout << "El socio no existe. Se asignará igual el ID (no recomendado)." << std::endl;
        c.setIdSocio(idSocio);
    }

    std::cout << "Ingrese monto: ";
    std::cin >> monto;
    c.setMonto(monto);

    std::cout << "¿Está pagada? (1=Sí, 0=No): ";
    std::cin >> aux;
    c.setPagada(aux == 1);

    std::cout << "Ingrese fecha de pago: ";
    fecha.cargarManual();
    c.setFecha(fecha);

    c.setEstado(true);

    return c;
}

void mostrarCuotaPorConsola(const Cuota& c) {
    cout << "ID: " << c.getIdCuota() << endl;
    cout << "ID Socio: " << c.getIdSocio() << endl;
    cout << "Monto: " << c.getMonto() << endl;
    cout << "Pagada: " << (c.getPagada() ? "Sí" : "No") << endl;
    cout << "Fecha de pago: " << c.getFecha().toString() << endl;
}

Socio cargarSocioPorConsola() {
    Socio socio;
    int id;
    char dni[10], nombre[50], apellido[50], telefono[20], direccion[100], email[50];
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
    int id, isbn, cantEjemplares;
    char titulo[100], autor[50], genero[30];
    Fecha fechaPub;

    cout << "Ingrese ID del libro: ";
    cin >> id;
    libro.setId(id);
    cin.ignore();

    cout << "Ingrese número de ISBN: ";
    cin >> isbn;
    libro.setIsbn(isbn);
    cin.ignore();

    cout << "Ingrese título: ";
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
    cin.ignore();  // Limpiar el salto de línea

    cout << "Ingrese la fecha de publicación:\n";
    fechaPub.cargarManual();  // Suponiendo que esta función tiene su propio input
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
    cout << "Estado: " << (lib.getEstado() ? "disponible" : "eliminado") << endl;
}
