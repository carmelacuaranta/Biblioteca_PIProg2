#include "Socio.h"
#include <iostream>
#include <cstring>

using namespace std;

Socio::Socio() {
    id = 0;
    numSocio = 0;
    strcpy(dni, "");
    strcpy(nombre, "");
    strcpy(apellido, "");
    strcpy(telefono, "");
    strcpy(direccion, "");
    strcpy(email, "");
    fechaNac = Fecha();
}

Socio::Socio(int id, int numSocio, const char* dni, const char* nombre, const char* apellido,
             const char* telefono, const char* direccion, const char* email, Fecha fechaNac) {
    this->id = id;
    this->numSocio = numSocio;
    strncpy(this->dni, dni, sizeof(this->dni));
    strncpy(this->nombre, nombre, sizeof(this->nombre));
    strncpy(this->apellido, apellido, sizeof(this->apellido));
    strncpy(this->telefono, telefono, sizeof(this->telefono));
    strncpy(this->direccion, direccion, sizeof(this->direccion));
    strncpy(this->email, email, sizeof(this->email));
    this->fechaNac=fechaNac;

    this->dni[sizeof(this->dni) - 1] = '\0';
    this->nombre[sizeof(this->nombre) - 1] = '\0';
    this->apellido[sizeof(this->apellido) - 1] = '\0';
    this->telefono[sizeof(this->telefono) - 1] = '\0';
    this->direccion[sizeof(this->direccion) - 1] = '\0';
    this->email[sizeof(this->email) - 1] = '\0';

}

// Getters
int Socio::getId() { return id; }
int Socio::getNumSocio() { return numSocio; }
const char* Socio::getDni() { return dni; }
const char* Socio::getNombre() { return nombre; }
const char* Socio::getApellido() { return apellido; }
const char* Socio::getTelefono() { return telefono; }
const char* Socio::getDireccion() { return direccion; }
const char* Socio::getEmail() { return email; }
Fecha Socio::getFechaNac() { return fechaNac; }

// Setters
void Socio::setId(int idSocio) { id = idSocio; }
void Socio::setNumSocio(int numS) { numSocio = numS; }
void Socio::setDni(const char* documento) { strncpy(dni, documento, sizeof(dni)); dni[sizeof(dni) - 1] = '\0'; }
void Socio::setNombre(const char* nombreSocio) { strncpy(nombre, nombreSocio, sizeof(nombre)); nombre[sizeof(nombre) - 1] = '\0'; }
void Socio::setApellido(const char* apellidoSocio) { strncpy(apellido, apellidoSocio, sizeof(apellido)); apellido[sizeof(apellido) - 1] = '\0'; }
void Socio::setTelefono(const char* telSocio) { strncpy(telefono, telSocio, sizeof(telefono)); telefono[sizeof(telefono) - 1] = '\0'; }
void Socio::setDireccion(const char* direccionSocio) { strncpy(direccion, direccionSocio, sizeof(direccion)); direccion[sizeof(direccion) - 1] = '\0'; }
void Socio::setEmail(const char* emailSocio) { strncpy(email, emailSocio, sizeof(email)); email[sizeof(email) - 1] = '\0'; }
void Socio::setFechaNac(Fecha fechaSocio) { fechaNac = fechaSocio; }

void Socio::agregarSocio() {
    int aux = 0;
    cout << "Ingrese ID: ";
    cin >> id;
    cin.ignore();

    cout << "Ingrese numero de socio: ";
    cin >> numSocio;
    cin.ignore();

    cout << "Ingrese DNI: ";
    cin.getline(dni, sizeof(dni));

    cout << "Ingrese nombre: ";
    cin.getline(nombre, sizeof(nombre));

    cout << "Ingrese apellido: ";
    cin.getline(apellido, sizeof(apellido));

    cout << "Ingrese telefono: ";
    cin.getline(telefono, sizeof(telefono));

    cout << "Ingrese direccion: ";
    cin.getline(direccion, sizeof(direccion));

    cout << "Ingrese email: ";
    cin.getline(email, sizeof(email));

    cout << "Ingrese anio de nacimiento: ";
    cin >> aux;
    this->fechaNac.setAnio(aux);
    cout << "Ingrese mes de nacimiento: ";
    cin >> aux;
    this->fechaNac.setMes(aux);
    cout << "Ingrese dia de nacimiento: ";
    cin >> aux;
    this->fechaNac.setDia(aux);
}

void Socio::mostrarSocio() {
    cout << "ID: " << id << endl;
    cout << "Numero de Socio: " << numSocio << endl;
    cout << "DNI: " << dni << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Email: " << email << endl;
    cout << "Fecha de Nacimiento: " << fechaNac.toString() << endl;
}

