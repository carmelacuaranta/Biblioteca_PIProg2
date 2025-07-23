#include <iostream>
#include "ArchivoPrestamo.h"
#include "ArchivoSocio.h"
#include "ArchivoLibro.h"
using namespace std;

int ArchivoPrestamo::agregarPrestamo(Prestamo pres){
    ArchivoLibro lib;
    ArchivoSocio soc;

    int idSocioValido = soc.buscarSocioPorID(pres.getIdSocio());
    int idLibroValido = lib.buscarLibroPorID(pres.getIdLibro());

    if (idSocioValido < 0 || idLibroValido < 0) {
        cout << "No se puede realizar el prestamo. ID invalido." << endl;
        return -1;
    }

    FILE *pPrestamo = fopen("prestamos.dat", "ab");
    if(pPrestamo == nullptr) {
        cout << "Error de archivo." << endl;
        return -1;
    }

    int nuevoID = obtenerUltimoID() + 1;
    pres.setIdPrestamo(nuevoID);      // ID autoincremental
    pres.setEstado(true);     // Estado activo

    fwrite(&pres, sizeof(Prestamo), 1, pPrestamo);
    fclose(pPrestamo);

    cout << "Prestamo registrado con ID: " << nuevoID << endl;
    return nuevoID;
}

bool ArchivoPrestamo::listarPrestamos() {
    FILE* p = fopen("prestamos.dat", "rb");
    if (p == nullptr) {
        cout << "Error de archivo." << endl;
        return -1;
    }

    Prestamo pres;
    cout << "LISTADO DE PRESTAMOS:" << endl;
    cout << "--------------------" << endl;

    while (fread(&pres, sizeof(Prestamo), 1, p) == 1) {
        if(pres.getEstado()==true && pres.getFinalizado()==false){
            pres.mostrarPrestamo();
            cout << "-------------------" << endl;
        }
    }

    fclose(p);
    return 0;
}

int ArchivoPrestamo::buscarPrestamoPorId(int idBuscado){
    FILE* p = fopen("prestamos.dat", "rb");
    if (p == nullptr) {
        cout << "Error de archivo.";
        return false;
    }

    Prestamo pres;
    int pos=0;
    while (fread(&pres, sizeof(Prestamo), 1, p) == 1) {
        if (pres.getIdPrestamo() == idBuscado) {
            cout << "Prestamo encontrado: " << endl;
            pres.mostrarPrestamo();
            fclose(p);
            return pos;
        }
        pos++;
    }
    cout << "No se encontro un prestamo con ese ID." << endl;
    fclose(p);
    return -1;
}

void ArchivoPrestamo::listarPrestamosPorIdLibro(int idBuscado){
    FILE* p = fopen("prestamos.dat", "rb");
    if (p == nullptr) {
        cout << "Error al abrir el archivo de prestamos." << endl;
        return;
    }

    Prestamo pres;
    bool encontrado = false;

    while (fread(&pres, sizeof(Prestamo), 1, p) == 1) {
        if (pres.getIdLibro() == idBuscado && pres.getEstado()) {
            pres.mostrarPrestamo();
            encontrado = true;
        }
    }

    fclose(p);

    if (!encontrado) {
        cout << "No se encontraron prestamos activos con ese ID de libro." << endl;
    }
}

void ArchivoPrestamo::listarPrestamosPorIdSocio(int idBuscado){
    FILE* p = fopen("prestamos.dat", "rb");
    if (p == nullptr) {
        cout << "Error de archivo." << endl;
        return;
    }

    Prestamo pres;
    bool encontrado = false;

    while (fread(&pres, sizeof(Prestamo), 1, p) == 1) {
        if (pres.getIdSocio() == idBuscado && pres.getEstado()) {
            pres.mostrarPrestamo();
            encontrado = true;
        }
    }

    fclose(p);

    if (!encontrado) {
        cout << "No se encontraron prestamos activos con ese ID de socio." << endl;
    }
}

int ArchivoPrestamo::obtenerUltimoID() {
    FILE* p = fopen("prestamos.dat", "rb");
    if (p == nullptr) return 0;

    Prestamo pres;
    fseek(p, -sizeof(Prestamo), SEEK_END);  // SEEK_END posicion al final
    if (fread(&pres, sizeof(Prestamo), 1, p) == 1) {
        fclose(p);
        return pres.getIdPrestamo();
    }

    fclose(p);
    return 0;
}

Prestamo ArchivoPrestamo::leerRegistro(int pos){
    Prestamo pres;
    FILE *pPrestamo;
    pPrestamo = fopen("prestamos.dat","rb");
    if(pPrestamo==nullptr){
        cout << "Eror de archivo." << endl;
        return pres;
    }
    fseek(pPrestamo,pos*sizeof(Prestamo),0);
    fread(&pres, sizeof(Prestamo), 1, pPrestamo);
    fclose(pPrestamo);
    return pres;
}

bool ArchivoPrestamo::bajaLogica(){
    Prestamo pres;
    ArchivoPrestamo archiPrestamo("prestamos.dat");
    int id;
    cout << "Ingresar id del prestamo a eliminar: ";
    cin >> id;
    int encontro = archiPrestamo.buscarPrestamoPorId(id);
    if (encontro < 0){
        cout << "No hay prestamos con ese id." << endl;
        return false;
    }
    pres=archiPrestamo.leerRegistro(encontro);
    if (pres.getEstado()==false){
        cout << "Ya estaba eliminado. " << endl;
        return false;
    } else {
        pres.setEstado(false);
        if(archiPrestamo.modificarRegistro(pres,encontro)==1){
            cout << "Eliminado con exito. " << endl;
           return true;
        } else { return false;}
    }
}

int ArchivoPrestamo::modificarRegistro(Prestamo pres, int pos){
    FILE *p;
    p = fopen("prestamos.dat","rb+");
    if (p == nullptr){
        return -1;
    }
    fseek(p,pos*sizeof(Prestamo),0);
    int escribio=fwrite(&pres, sizeof(Prestamo), 1, p);
    fclose(p);
    return escribio;
}


int ArchivoPrestamo::modificarPrestamo(int idPrestamo){
    ArchivoPrestamo archiPrestamo("prestamos.dat");

    int pos = archiPrestamo.buscarPrestamoPorId(idPrestamo);
    if (pos == -1) {
        cout << "No se encontro socio con ese ID." << endl;
        return -1;
    }

    Prestamo pres = archiPrestamo.leerRegistro(pos);
    if (pres.getEstado()==false) {
        cout << "Prestamo eliminado, no se puede modificar." << endl;
        return -2;
    }

    int idNuevo=pres.getIdPrestamo();
    Fecha fechaP = pres.getFechaPrestado();
    Fecha fechaD=pres.getFechaDevolucion();
    bool ven=pres.getVencido();
    bool fin=pres.getFinalizado();


    cout << "Ingrese los nuevos datos:" << endl;
    int idLibroNuevo;
    int idSocioNuevo;

    cout << "ID SOCIO: ";
    cin>> idSocioNuevo;
    cout << "ID LIBRO: ";
    cin>> idLibroNuevo;

    Prestamo nuevoPrestamo(idNuevo,idLibroNuevo, idSocioNuevo, fechaP, fechaD, ven, ven);

    if (archiPrestamo.modificarRegistro(nuevoPrestamo, pos) == 1){
        cout << "Se actualizo correctamente." << endl;
        return 1;
    } else {
        cout << "Error al modificar el prestamo." << endl;
        return 0;
    }
}

int ArchivoPrestamo::extenderFechaDevolucion(int idPrestamo){

    ArchivoPrestamo archiPrestamo("prestamos.dat");
    int pos = archiPrestamo.buscarPrestamoPorId(idPrestamo);
    if (pos == -1) {
        cout << "No se encontro prestamo con ese ID." << endl;
        return -1;
    }

    Prestamo pres = archiPrestamo.leerRegistro(pos);
    if (pres.getEstado()==false) {
        cout << "Prestamo eliminado, no se puede modificar." << endl;
        return -2;
    }

    int idNuevo=pres.getIdPrestamo();
    int idLibroNuevo=pres.getIdLibro();
    int idSocioNuevo=pres.getIdSocio();
    Fecha fechaP = pres.getFechaPrestado();
    bool ven=false;
    bool fin=false;

    Fecha fechaD;
    fechaD.cargarManual();

    Prestamo nuevoPrestamo(idNuevo,idLibroNuevo, idSocioNuevo, fechaP, fechaD, ven, ven);

    if (archiPrestamo.modificarRegistro(nuevoPrestamo, pos) == 1){
        cout << "Se actualizo correctamente." << endl;
        return 1;
    } else {
        cout << "Error al modificar el prestamo." << endl;
        return 0;
    }
}

int ArchivoPrestamo::registrarDevolucion(int idPrestamo){
    ArchivoPrestamo archiPrestamo("prestamos.dat");
    int pos = archiPrestamo.buscarPrestamoPorId(idPrestamo);
    if (pos == -1) {
        cout << "No se encontro prestamo con ese ID." << endl;
        return -1;
    }

    Prestamo pres = archiPrestamo.leerRegistro(pos);
    if (pres.getEstado()==false) {
        cout << "Prestamo eliminado, no se puede modificar." << endl;
        return -2;
    }

    int idNuevo=pres.getIdPrestamo();
    int idLibroNuevo=pres.getIdLibro();
    int idSocioNuevo=pres.getIdSocio();
    Fecha fechaP = pres.getFechaPrestado();
    Fecha fechaD = pres.getFechaDevolucion();
    bool ven=pres.getVencido();
    bool fin=true;

    Prestamo nuevoPrestamo(idNuevo,idLibroNuevo, idSocioNuevo, fechaP, fechaD, ven, fin);

    if (archiPrestamo.modificarRegistro(nuevoPrestamo, pos) == 1){
        cout << "Devolucion registrada." << endl;
        return 1;
    } else {
        cout << "Error al registrar devolucion." << endl;
        return 0;
    }
}

void ArchivoPrestamo::listarPrestamosVencidos() {
    FILE* p = fopen("prestamos.dat", "rb");
    if (p == nullptr) {
        cout << "Error al abrir el archivo de prestamos." << endl;
        return;
    }

    Prestamo pres;
    Fecha hoy;
    hoy.cargarFechaSistema();

    bool hayVencidos = false;
    cout << "PRESTAMOS VENCIDOS:" << endl;
    cout << "-------------------" << endl;

    while (fread(&pres, sizeof(Prestamo), 1, p) == 1) {
        // Solo prestamos activos y no finalizados
        if (pres.getEstado() && !pres.getFinalizado()) {
            Fecha fechaLimite = pres.getFechaDevolucion();

            if (hoy.esMayorQue(fechaLimite)) {
                // Esta vencido
                pres.mostrarPrestamo();
                cout << "-------------------" << endl;
                hayVencidos = true;
            }
        }
    }

    if (!hayVencidos) {
        cout << "No hay prestamos vencidos." << endl;
    }

    fclose(p);
}
