#include <iostream>
#include <string>
#include <locale>
#include <cctype> // Para validar caracteres
#include <limits> // Para limpiar el buffer de entrada
using namespace std;




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



    return 0;
}

