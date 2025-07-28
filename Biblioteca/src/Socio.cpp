#include "Socio.h"
#include <iostream>
#include <cstring>

using namespace std;

Socio::Socio() {
    _id = 0;
    strcpy(_dni, "");
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_telefono, "");
    strcpy(_direccion, "");
    strcpy(_email, "");
    _fechaNac = Fecha();
}

Socio::Socio(int id, const char* dni, const char* nombre, const char* apellido,
             const char* telefono, const char* direccion, const char* email, Fecha fechaNac) {
    _id = id;
    strncpy(_dni, dni, sizeof(_dni));
    strncpy(_nombre, nombre, sizeof(_nombre));
    strncpy(_apellido, apellido, sizeof(_apellido));
    strncpy(_telefono, telefono, sizeof(_telefono));
    strncpy(_direccion, direccion, sizeof(_direccion));
    strncpy(_email, email, sizeof(_email));
    _fechaNac=fechaNac;
    _estado=true;

    _dni[sizeof(_dni) - 1] = '\0';
    _nombre[sizeof(_nombre) - 1] = '\0';
    _apellido[sizeof(_apellido) - 1] = '\0';
    _telefono[sizeof(_telefono) - 1] = '\0';
    _direccion[sizeof(_direccion) - 1] = '\0';
    _email[sizeof(_email) - 1] = '\0';

}

// Getters
int Socio::getId() {
    return _id;
    }
const char* Socio::getDni() {
    return _dni;
    }
const char* Socio::getNombre() {
    return _nombre;
    }
const char* Socio::getApellido() {
    return _apellido;
    }
const char* Socio::getTelefono() {
    return _telefono;
    }
const char* Socio::getDireccion() {
    return _direccion;
    }
const char* Socio::getEmail() {
    return _email;
    }
Fecha Socio::getFechaNac() {
    return _fechaNac;
    }
bool Socio::getEstado(){
    return _estado;
    }

// Setters
void Socio::setId(int idSocio) {
    _id = idSocio;
    }
void Socio::setDni(const char* dni) {
    strncpy(_dni, dni, sizeof(_dni));
    _dni[sizeof(_dni) - 1] = '\0';
    }
void Socio::setNombre(const char* nombre) {
    strncpy(_nombre, nombre, sizeof(_nombre));
    _nombre[sizeof(_nombre) - 1] = '\0';
    }
void Socio::setApellido(const char* apellido) {
    strncpy(_apellido, apellido, sizeof(_apellido));
    _apellido[sizeof(_apellido) - 1] = '\0';
    }
void Socio::setTelefono(const char* telefono) {
    strncpy(_telefono, telefono, sizeof(_telefono));
    _telefono[sizeof(_telefono) - 1] = '\0';
    }
void Socio::setDireccion(const char* direccion) {
    strncpy(_direccion, direccion, sizeof(_direccion));
    _direccion[sizeof(_direccion) - 1] = '\0';
    }
void Socio::setEmail(const char* email) {
    strncpy(_email, email, sizeof(_email));
    _email[sizeof(_email) - 1] = '\0';
    }
void Socio::setFechaNac(Fecha fechaNac) {
    _fechaNac = fechaNac;
    }
void Socio::setEstado(bool estado) {
    _estado = estado;
    }
