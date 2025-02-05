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

// Validaci�n para que un string solo contenga letras
bool EsNombreValido(const string &nombre) {
    for (char c : nombre) {
        if (!isalpha(c) && c != ' ' && c != '.') { // Solo letras, espacios y puntos
            return false;
        }
    }
    return true;
}

// Funci�n para validar entrada num�rica
double LeerNumero(const string &mensaje) {
    double valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail()) { // Si la entrada no es v�lida
            cout << "Error: Solo se aceptan n�meros.\n";
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
            cout << "\nIngrese nombre del cond�mino (solo letras, espacios y puntos): ";
            cin.ignore();
            getline(cin, nuevo.nombre);

            if (EsNombreValido(nuevo.nombre)) {
                break;
            } else {
                cout << "Error: El nombre solo puede contener letras, espacios y puntos.\n";
            }
        }

        // Leer y validar entradas num�ricas
        nuevo.preciocasac = LeerNumero("Ingrese pago por Servicio de Casa Comunal: ");
        nuevo.preciocespeds = LeerNumero("Ingrese pago por Servicio de Cancha de C�sped Sint�tico: ");
        nuevo.precioGuardiania = LeerNumero("Ingrese pago por Guardian�a: ");
        nuevo.precioJardineria = LeerNumero("Ingrese pago por Jardiner�a: ");
        nuevo.precioMantenimiento = LeerNumero("Ingrese pago por Mantenimiento: ");

        Verificar_Datos(nuevo);
        V[cantidad++] = nuevo;

        cout << "\n�Desea ingresar otro cond�mino? (s/n): ";
        cin >> opcion;
    } while (opcion == 's');
}

void Mostrar() {

    cout << "\n--------------------- MATRIZ: ALQUILER -----------------------" << endl;
    cout << "Nombre\t\tCasa Comunal\tCancha C�sped\tTotal Alquiler" << endl;
    cout << "--------------------------------------------------------------" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << V[i].nombre << "\t\t" << V[i].preciocasac << "\t\t"
             << V[i].preciocespeds << "\t\t" << V[i].totalAlquiler << endl;
    }


    cout << "\n-------------------- MATRIZ: AL�CUOTAS ----------------------------" << endl;
    cout << "Nombre\t\tGuardian�a\tJardiner�a\tMantenimiento\tTotal Al�cuotas" << endl;
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

        cout << "\t\t\tIdentificaci�n: ";
        getline(cin, user);

        cout << "\t\t\tContrase�a: ";
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
    cout << "\n\t\t\tUsted fall� m�s de 3 veces." << endl;
    cout << "\n\t\t\tFinalizando programa..." << endl;
    return false;
}


int main() {
    setlocale(LC_ALL, "");

    // Verificar acceso al sistema
    if (!Login()) {
        cout << "\nAcceso al sistema denegado. \nFinalizando el programa...\n";
        return 0; // Salida expl�cita al fallar el login
    }

    cout << "\n********** Bienvenido al Sistema de Registro de Pagos **********\n" << endl;

    Ingreso();
    Mostrar();

    return 0;
}

