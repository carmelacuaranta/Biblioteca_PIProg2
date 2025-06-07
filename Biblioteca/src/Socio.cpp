#include "Socio.h"
#include <iostream>
using namespace std;

Socio::Socio(){
    this->id = 0;
    this->numSocio = 0;
    this->dni = "";
    this->nombre = "";
    this->apellido = "";
    this->telefono = "";
    this->direccion = "";
    this->email = "";
    this->fechaNac = "";
}

Socio::Socio(int id, int numSocio, string dni, string nombre, string apellido, string telefono, string direccion, string email, string fechaNac) {
    this->id = id;
    this->numSocio = numSocio;
    this->dni = dni;
    this->nombre = nombre;
    this->apellido = apellido;
    this->telefono = telefono;
    this->direccion = direccion;
    this->email = email;
    this->fechaNac = fechaNac;
}

// Getters
int Socio::getId() { return id; }
int Socio::getNumSocio() { return numSocio; }
string Socio::getDni() { return dni; }
string Socio::getNombre() { return nombre; }
string Socio::getApellido() { return apellido; }
string Socio::getTelefono() { return telefono; }
string Socio::getDireccion() { return direccion; }
string Socio::getEmail() { return email; }
string Socio::getFechaNac() { return fechaNac; }

// Setters
void Socio::setId(int idSocio) { id = idSocio; }
void Socio::setNumSocio(int numS) { numSocio = numS; }
void Socio::setDni(string documento) { dni = documento; }
void Socio::setNombre(string nombreSocio) { nombre = nombreSocio; }
void Socio::setApellido(string apellidoSocio) { apellido = apellidoSocio; }
void Socio::setTelefono(string telSocio) { telefono = telSocio; }
void Socio::setDireccion(string direccionSocio) { direccion = direccionSocio; }
void Socio::setEmail(string emailSocio) { email = emailSocio; }
void Socio::setFechaNac(string fechaSocio) { fechaNac = fechaSocio; }

void Socio::CrearSocio(){
    cout << "Ingrese ID: ";
    cin >> id;
    cin.ignore(); // limpia el salto de línea

    cout << "Ingrese número de socio: ";
    cin >> numSocio;
    cin.ignore();

    cout << "Ingrese DNI: ";
    getline(cin, dni);

    cout << "Ingrese nombre: ";
    getline(cin, nombre);

    cout << "Ingrese apellido: ";
    getline(cin, apellido);

    cout << "Ingrese teléfono: ";
    getline(cin, telefono);

    cout << "Ingrese dirección: ";
    getline(cin, direccion);

    cout << "Ingrese email: ";
    getline(cin, email);

    cout << "Ingrese fecha de nacimiento: ";
    getline(cin, fechaNac);
}

void Socio::MostrarSocio(){
    //van a faltar las comprobaciones
    cout<<"ID: "<<id<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Apellido: "<<apellido<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Direccion: "<<direccion<<endl;
    cout<<"Fecha de Nacimiento: "<<fechaNac<<endl;
}
