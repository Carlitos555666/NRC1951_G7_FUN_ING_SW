#include <iostream>
#include <string>
#include <locale>
#include <cctype> // Para validar caracteres
#include <limits> // Para limpiar el buffer de entrada
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

// Validación para que un string solo contenga letras
bool EsNombreValido(const string &nombre) {
    for (char c : nombre) {
        if (!isalpha(c) && c != ' ' && c != '.') { // Solo letras, espacios y puntos
            return false;
        }
    }
    return true;
}

// Función para validar entrada numérica
double LeerNumero(const string &mensaje) {
    double valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail()) { // Si la entrada no es válida
            cout << "Error: Solo se aceptan números.\n";
            cin.clear(); // Limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la entrada
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
    do {
        Condomino nuevo;

        // Validar entrada del nombre
        while (true) {
            cout << "\nIngrese nombre del condómino (solo letras, espacios y puntos): ";
            cin.ignore();
            getline(cin, nuevo.nombre);

            if (EsNombreValido(nuevo.nombre)) {
                break;
            } else {
                cout << "Error: El nombre solo puede contener letras, espacios y puntos.\n";
            }
        }

        // Leer y validar entradas numéricas
        nuevo.preciocasac = LeerNumero("Ingrese pago por Servicio de Casa Comunal: ");
        nuevo.preciocespeds = LeerNumero("Ingrese pago por Servicio de Cancha de Césped Sintético: ");
        nuevo.precioGuardiania = LeerNumero("Ingrese pago por Guardianía: ");
        nuevo.precioJardineria = LeerNumero("Ingrese pago por Jardinería: ");
        nuevo.precioMantenimiento = LeerNumero("Ingrese pago por Mantenimiento: ");

        Verificar_Datos(nuevo);
        V[cantidad++] = nuevo;

        cout << "\n¿Desea ingresar otro condómino? (s/n): ";
        cin >> opcion;
    } while (opcion == 's');
}

void Mostrar() {

    cout << "\n--------------------- MATRIZ: ALQUILER -----------------------" << endl;
    cout << "Nombre\t\tCasa Comunal\tCancha Césped\tTotal Alquiler" << endl;
    cout << "--------------------------------------------------------------" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << V[i].nombre << "\t\t" << V[i].preciocasac << "\t\t"
             << V[i].preciocespeds << "\t\t" << V[i].totalAlquiler << endl;
    }


    cout << "\n-------------------- MATRIZ: ALÍCUOTAS ----------------------------" << endl;
    cout << "Nombre\t\tGuardianía\tJardinería\tMantenimiento\tTotal Alícuotas" << endl;
    cout << "------------------------------------------------------------------" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << V[i].nombre << "\t\t" << V[i].precioGuardiania << "\t\t"
             << V[i].precioJardineria << "\t\t" << V[i].precioMantenimiento
             << "\t\t" << V[i].totalAlicuotas << endl;
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

    // Verificar acceso al sistema
    if (!Login()) {
        cout << "\nAcceso al sistema denegado. \nFinalizando el programa...\n";
        return 0; // Salida explícita al fallar el login
    }

    cout << "\n********** Bienvenido al Sistema de Registro de Pagos **********\n" << endl;

    Ingreso();
    Mostrar();

    return 0;
}

