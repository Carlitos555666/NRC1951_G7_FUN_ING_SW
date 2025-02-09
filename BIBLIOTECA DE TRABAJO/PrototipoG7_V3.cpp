#include <iostream>
#include <string>
#include <locale>
#include <cctype>
#include <limits>
#include <fstream>
#include <iomanip>   // Para formatear la salida
using namespace std;

struct Condomino {
    string nombre;
    double preciocasac = 0.0;
    double preciocespeds = 0.0;
    double precioGuardiania = 0.0;
    double precioJardineria = 0.0;
    double precioMantenimiento = 0.0;
    double totalAlquiler = 0.0;
    double totalAlicuotas = 0.0;
} V[100];

int cantidad = 0;

bool EsNombreValido(const string &nombre) {
    // Se permiten letras, espacios y puntos
    for (char c : nombre) {
        if (!isalpha(c) && c != ' ' && c != '.') {
            return false;
        }
    }
    return true;
}

double LeerNumero(const string &mensaje) {
    double valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail()) {
            cout << "Error: Solo se aceptan números.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return valor;
        }
    }
}

void Verificar_Datos(Condomino &d) {
    d.totalAlquiler = d.preciocasac + d.preciocespeds;
    d.totalAlicuotas = d.precioGuardiania + d.precioJardineria + d.precioMantenimiento;
}

void Ingreso() {
    char opcion;
    cantidad = 0; // Reiniciar cantidad cada vez que se reinicia el ingreso

    do {
        Condomino nuevo;

        // Se solicita el nombre sin descartar ningún carácter
        cout << "\nIngrese nombre del condómino (solo letras, espacios y puntos): ";
        getline(cin, nuevo.nombre);
        while (!EsNombreValido(nuevo.nombre) || nuevo.nombre.empty()) {
            cout << "Error: El nombre solo puede contener letras, espacios y puntos, y no puede estar vacío.\n";
            cout << "\nIngrese nombre del condómino (solo letras, espacios y puntos): ";
            getline(cin, nuevo.nombre);
        }

        // Se leen los demás valores numéricos
        nuevo.preciocasac = LeerNumero("Ingrese pago por Servicio de Casa Comunal: ");
        nuevo.preciocespeds = LeerNumero("Ingrese pago por Servicio de Cancha de Césped Sintético: ");
        nuevo.precioGuardiania = LeerNumero("Ingrese pago por Guardianía: ");
        nuevo.precioJardineria = LeerNumero("Ingrese pago por Jardinería: ");
        nuevo.precioMantenimiento = LeerNumero("Ingrese pago por Mantenimiento: ");

        Verificar_Datos(nuevo);
        V[cantidad++] = nuevo;

        cout << "\n¿Desea ingresar otro condómino? (s/n): ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el búfer de entrada
    } while (opcion == 's' || opcion == 'S');
}

bool Mostrar() {
    char sn;

    // Impresión formateada de la matriz de alquiler
    cout << "\n--------------------- PAGO ALQUILER ----------------------------\n";
    cout << left << setw(20) << "Nombre"
         << left << setw(15) << "Casa Comunal"
         << left << setw(15) << "Cancha Césped"
         << left << setw(15) << "Total Alquiler" << endl;
    cout << string(65, '-') << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << left << setw(20) << V[i].nombre
             << left << setw(15) << V[i].preciocasac
             << left << setw(15) << V[i].preciocespeds
             << left << setw(15) << V[i].totalAlquiler << endl;
    }

    // Impresión formateada de la matriz de alícuotas
    cout << "\n------------------------- PAGO ALÍCUOTAS ------------------------------------\n";
    cout << left << setw(20) << "Nombre"
         << left << setw(15) << "Guardianía"
         << left << setw(15) << "Jardinería"
         << left << setw(18) << "Mantenimiento"
         << left << setw(15) << "Total Alícuotas" << endl;
    cout << string(83, '-') << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << left << setw(20) << V[i].nombre
             << left << setw(15) << V[i].precioGuardiania
             << left << setw(15) << V[i].precioJardineria
             << left << setw(18) << V[i].precioMantenimiento
             << left << setw(15) << V[i].totalAlicuotas << endl;
    }

    cout << "\n¿La información mostrada en pantalla es correcta? (s/n): ";
    cin >> sn;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el búfer

    if (sn == 's' || sn == 'S') {
        ofstream archivo("Reporte_Pagos.txt");
        if (!archivo) {
            cout << "Error al abrir el archivo para escritura.\n";
            return false;
        }

        archivo << "---------------------------- PAGO ALQUILER ----------------------\n";
        archivo << left << setw(20) << "Nombre"
                << left << setw(15) << "Casa Comunal"
                << left << setw(15) << "Cancha Césped"
                << left << setw(15) << "Total Alquiler" << "\n";
        archivo << string(65, '-') << "\n";
        for (int i = 0; i < cantidad; i++) {
            archivo << left << setw(20) << V[i].nombre
                    << left << setw(15) << V[i].preciocasac
                    << left << setw(15) << V[i].preciocespeds
                    << left << setw(15) << V[i].totalAlquiler << "\n";
        }

        archivo << "\n------------------------------ PAGO ALÍCUOTAS -------------------------------------\n";
        archivo << left << setw(20) << "Nombre"
                << left << setw(15) << "Guardianía"
                << left << setw(15) << "Jardinería"
                << left << setw(18) << "Mantenimiento"
                << left << setw(15) << "Total Alícuotas" << "\n";
        archivo << string(83, '-') << "\n";
        for (int i = 0; i < cantidad; i++) {
            archivo << left << setw(20) << V[i].nombre
                    << left << setw(15) << V[i].precioGuardiania
                    << left << setw(15) << V[i].precioJardineria
                    << left << setw(18) << V[i].precioMantenimiento
                    << left << setw(15) << V[i].totalAlicuotas << "\n";
        }

        archivo.close();
        cout << "Datos guardados en 'Reporte_Pagos.txt'.\n";
        return true;
    } else {
        cout << "Reiniciando el ingreso de datos...\n";
        return false;
    }
}

bool Login() {
    const string User = "Tesorero";
    const string Password = "Tesorero123";
    string user, pass;
    int intentos = 0;

    while (intentos < 3) {
        system("cls");
        cout << "\n\n\n\t\t====================================" << endl;
        cout << "\t\t\tLogin del Sistema" << endl;
        cout << "\t\t====================================" << endl;

        cout << "\t\t\tIdentificación: ";
        getline(cin, user);

        cout << "\t\t\tContraseña: ";
        getline(cin, pass);

        if (pass.length() < 8) {
            cout << "\nError: La contraseña debe tener al menos 8 dígitos." << endl;
            intentos++;
            system("pause");
            continue;
        }

        if (user == User && pass == Password) {
            cout << "\nAcceso concedido. Bienvenido, Tesorero!\n";
            return true;
        } else {
            cout << "\nAcceso denegado. Intente nuevamente.\n";
            intentos++;
            system("pause");
        }
    }

    system("cls");
    cout << "\n\t\t\tUsted falló más de 3 veces." << endl;
    cout << "\n\t\t\tFinalizando programa..." << endl;
    return false;
}

int main() {
    setlocale(LC_ALL, "");

    if (!Login()) {
        cout << "\nAcceso al sistema denegado. \nFinalizando el programa...\n";
        return 0;
    }

    cout << "\n********** Bienvenido al Sistema de Registro de Pagos **********\n" << endl;

    while (true) {
        Ingreso();
        if (Mostrar()) {
            break;
        }
    }

    return 0;
}
