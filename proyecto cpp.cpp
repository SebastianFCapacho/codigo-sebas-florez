#include <iostream>
using namespace std;

int main() {
    int capacidad = 10;  
    int ocupados = 0;   
    int entradas[10] = {0}; 
    int opcion;           
    int hora;            

    while (true) {
        cout << "\n=== MENU PARQUEADERO ===\n";
        cout << "1. Registrar entrada de vehiculo\n";
        cout << "2. Registrar salida de vehiculo\n";
        cout << "3. Ver estado del parqueadero\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            if (ocupados < capacidad) {
                cout << "Ingrese la hora de entrada (solo hora en formato 24h, ejemplo: 14): ";
                cin >> hora;
                entradas[ocupados] = hora;
                ocupados++; 
                cout << "Vehiculo registrado. Espacios ocupados: " << ocupados << "/" << capacidad << "\n";
            } else {
                cout << "El parqueadero esta lleno.\n";
            }
        }
        else if (opcion == 2) {
            if (ocupados > 0) { 
                int indice;
                cout << "Ingrese el indice del vehiculo que sale (1 a " << ocupados << "): ";
                cin >> indice;

                if (indice > 0 && indice <= ocupados) {
                    cout << "Ingrese la hora de salida (solo hora en formato 24h, ejemplo: 16): ";
                    cin >> hora;
                    
                    int tiempo = hora - entradas[indice - 1]; 
                    if (tiempo < 0) tiempo += 24; 

                    cout << "El vehiculo estuvo " << tiempo << " horas en el parqueadero.\n";

                    for (int i = indice - 1; i < ocupados - 1; i++) {
                        entradas[i] = entradas[i + 1];
                    }
                    ocupados--; 
                } else {
                    cout << "Indice no valido.\n";
                }
            } else {
                cout << "No hay vehiculos en el parqueadero.\n";
            }
        }
        else if (opcion == 3) {
            cout << "Espacios ocupados: " << ocupados << "/" << capacidad << "\n";
            for (int i = 0; i < ocupados; i++) {
                cout << "Vehiculo " << i + 1 << " - Hora de entrada: " << entradas[i] << "\n";
            }
        }
        
        else if (opcion == 4) {
            cout << "Saliendo del programa...\n";
            break; 
        }
        else {
            cout << "Opcion no valida. Por favor, intente de nuevo.\n";
        }
    }

    return 0;
}

