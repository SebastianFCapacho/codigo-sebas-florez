#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Estructura para representar un veh�culo
struct Vehiculo {
    string placa;
    int horaEntrada;
};

// Variables globales
const int MAX_ESPACIOS = 10;
vector<Vehiculo> parqueadero;

// Funci�n para registrar un veh�culo (entrada o salida)
void registrarVehiculo(bool entrada) {
    if (entrada) { // Registrar entrada
        if (parqueadero.size() >= MAX_ESPACIOS) {
            cout << "El parqueadero est� lleno.\n";
            return;
        }
        Vehiculo nuevo;
        cout << "Ingrese la placa: ";
        cin >> nuevo.placa;
        cout << "Ingrese la hora de entrada (0-23): ";
        cin >> nuevo.horaEntrada;
        if (nuevo.horaEntrada < 0 || nuevo.horaEntrada > 23) {
            cout << "Hora inv�lida.\n";
            return;
        }
        parqueadero.push_back(nuevo);
        cout << "Entrada registrada.\n";
    } else { // Registrar salida
        string placa;
        int horaSalida;
        cout << "Ingrese la placa: ";
        cin >> placa;

        auto it = find_if(parqueadero.begin(), parqueadero.end(), [&placa](Vehiculo& v) {
            return v.placa == placa;
        }

        if (it == parqueadero.end()) {
            cout << "Veh�culo no encontrado.\n";
            return;
        }

        cout << "Ingrese la hora de salida (0-23): ";
        cin >> horaSalida;
        if (horaSalida < 0 || horaSalida > 23) {
            cout << "Hora inv�lida.\n";
            return;
        }

        int tiempo = (horaSalida >= it->horaEntrada) ? 
                     (horaSalida - it->horaEntrada) : 
                     (24 - it->horaEntrada + horaSalida);
        cout << "Tiempo estacionado: " << tiempo << " horas.\n";
        parqueadero.erase(it);
    }
}

// Funci�n para mostrar el estado del parqueadero
void consultarEstado() {
    if (parqueadero.empty()) {
        cout << "El parqueadero est� vac�o.\n";
        return;
    }
    cout << "Veh�culos en el parqueadero:\n";
    for (const auto& v : parqueadero) {
        cout << "Placa: " << v.placa << ", Hora de entrada: " << v.horaEntrada << "\n";
    }
}

// Funci�n principal
int main() {
    int opcion;
    do {
        cout << "\n=== SISTEMA DE PARQUEADERO ===\n";
        cout << "1. Registrar entrada\n2. Registrar salida\n3. Consultar estado\n4. Salir\nOpci�n: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarVehiculo(true);
                break;
            case 2:
                registrarVehiculo(false);
                break;
            case 3:
                consultarEstado();
                break;
            case 4:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opci�n inv�lida.\n";
        }
    } while (opcion != 4);

    return 0;
}

