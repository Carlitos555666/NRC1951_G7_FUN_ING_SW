#include<iostream>
#include<cstdio>
#include<conio.h>
#include<locale>
#include<string>
using namespace std;

struct condomino
{
    char nombre[25];
    double preciocasac;
    double preciocespeds;
    double precioGuardiania;
    double precioJardineria;
    double precioMantenimiento;
    double totalAlquiler;
    double totalAlicuotas;
} V[100];

int cantidad = 0;

void Verificar_Datos(condomino &d)
{
    d.totalAlquiler = d.preciocasac + d.preciocespeds;
    d.totalAlicuotas = d.precioGuardiania + d.precioJardineria + d.precioMantenimiento;
}

void Ingreso()
{
    char opcion;
    do
    {
        cout << "\nCondomino (Nombre.Apellido) ==> ";
        cin >> V[cantidad].nombre;
        cout << "\nIngrese pago por Servicio de Casa Comunal ==> ";
        cin >> V[cantidad].preciocasac;
        cout << "\nIngrese Pago por Servicio de Cancha de Césped Sintético ==> ";
        cin >> V[cantidad].preciocespeds;
        cout << "\nIngrese pago por Guardianía ==> ";
        cin >> V[cantidad].precioGuardiania;
        cout << "\nIngrese pago por Jardinería ==> ";
        cin >> V[cantidad].precioJardineria;
        cout << "\nIngrese pago por Mantenimiento ==> ";
        cin >> V[cantidad].precioMantenimiento;
        Verificar_Datos(V[cantidad]);
        cantidad++;
        cout << "\nDesea Ingresar Otro Condomino (s/n): ";
        cin >> opcion;
    } while (opcion == 's');
}

void Mostrar()
{
    cout << "\n-------------------------------------------------------------" << endl;
    cout << "Nombre\t\tAlquiler 1\tAlquiler 2\tTotal Alquiler\t\tGuardiania\tJardineria\tMantenimiento\tTotal Alicuotas" << endl;
    cout << "-------------------------------------------------------------" << endl;
    for (int i = 0; i < cantidad; i++)
    {
        cout << "\n" << V[i].nombre << "\t" << V[i].preciocasac << "\t\t" << V[i].preciocespeds << "\t\t"
             << V[i].totalAlquiler << "\t\t\t\t"<<V[i].precioGuardiania << "\t\t" << V[i].precioJardineria << "\t\t"
             << V[i].precioMantenimiento << "\t\t" << V[i].totalAlicuotas << endl;
    }
}

bool Login()
{
    string username, password;
    cout << "\n=============================" << endl;
    cout << "\tLogin del Sistema" << endl;
    cout << "=============================" << endl;
    cout << "Identificación: ";
    cin >> username;
    cout << "Contraseña: ";
    cin >> password;

    if (username == "Tesorero" && password == "Tesorero321")
    {
        cout << "\nAcceso Concedido. Bienvenido, Tesorero!\n";
        return true;
    }
    else
    {
        cout << "\nAcceso Denegado\n";
        return false;
    }
}

int main()
{
    setlocale(LC_ALL, "");

    if (!Login())
    {
        cout << "\nFinalizando programa..." << endl;
        return 0;
    }

    cout << "\t\tBienvenido al Sistema de Registro de Pagos\n";

    cout << "\nRegistro de Alquiler de Espacio Público y Alicuotas" << endl;
    Ingreso();
    Mostrar();

    return 0;
}

