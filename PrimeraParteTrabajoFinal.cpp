#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void mostrarMenu() {
    cout << "=== Menu Principal ===" << endl;
    cout << "1. Gestionar Vehiculos" << endl;
    cout << "2. Gestionar Clientes" << endl;
    cout << "3. Gestionar Repuestos" << endl;
    cout << "4. Salir" << endl;
}

void insertarVehiculo() {
    ofstream archivo("vehiculos_temp.csv", ios::app);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo temporal de vehiculos" << endl;
        return;
    }

    string modelo, marca, placa, color, ced_cliente, fecha_entrega;
    int anio;
    double kilometraje, precio_renta;
    bool rentado;

    cout << "Ingrese modelo: ";
    cin >> modelo;
    cout << "Ingrese marca: ";
    cin >> marca;
    cout << "Ingrese placa: ";
    cin >> placa;
    cout << "Ingrese color: ";
    cin >> color;
    cout << "Ingrese año: ";
    cin >> anio;
    cout << "Ingrese kilometraje: ";
    cin >> kilometraje;
    cout << "¿Está rentado? (1: sí, 0: no): ";
    cin >> rentado;
    cout << "Ingrese motor: ";
    cin.ignore();
    string motor;
    getline(cin, motor);
    cout << "Ingrese precio de renta: ";
    cin >> precio_renta;
    cout << "Ingrese cédula del cliente: ";
    cin >> ced_cliente;
    cout << "Ingrese fecha de entrega: ";
    cin >> fecha_entrega;

    archivo << modelo << "," << marca << "," << placa << "," << color << ","
            << anio << "," << kilometraje << "," << rentado << "," << motor << ","
            << precio_renta << "," << ced_cliente << "," << fecha_entrega << endl;

    archivo.close();
}

void mostrarVehiculos() {
    ifstream archivo("vehiculos.csv");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de vehículos." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}

void gestionarVehiculos() {

    int opcion;

    do {
        cout << "=== Gestion de Vehiculos ===" << endl;
        cout << "1. Insertar vehiculo" << endl;
        cout << "2. Mostrar vehículos" << endl;
        cout << "3. Confirmar cambios" << endl;
        cout << "4. Volver al menu principal" << endl;

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                insertarVehiculo();
                break;
            case 2:
                mostrarVehiculos();
                break;
            case 3: {
                if (remove("vehiculos.csv") != 0) {
                    perror("Error al eliminar el archivo original");
                }
                if (rename("vehiculos_temp.csv", "vehiculos.csv") != 0) {
                    perror("Error al renombrar el archivo temporal");
                }
                cout << "Cambios confirmados." << endl;
                break;
            }
            case 4:
                break;
            default:
                cout << "Opción no valida." << endl;
                break;
        }
        
    } while (opcion != 4);
}

void insertarCliente() {
    ofstream archivo1("clientes_temp.csv", ios::app);
     if (!archivo1.is_open()) {
        cout << "Error al abrir el archivo temporal de clientes." << endl;
        return;
    }

    int cedula, cantveicurent;
    string nombre, lstname, email, direc, actv;

    cout<<"ingrese cedula del cliente"<<endl;
    cin>>cedula;
    cout<<"ingrese nombre del cliente"<<endl;
    cin>>nombre;
    cout<<"ingrese apellido del cliente"<<endl;
    cin>>lstname;
    cout<<"ingrese email del cliente"<<endl;
    cin>>email;
    cout<<"ingrese la cantidad de vehiculos del cliente"<<endl;
    cin>>cantveicurent;
    cout<<"ingrese la direccion del cliente"<<endl;
    cin>>direc;
    cout<<"el cliente es activo o no?"<<endl;
    cin>>actv;

    archivo1 <<cedula<<","<<nombre<<","<<lstname<<","<<email<<","<<cantveicurent<<","<<direc<<","<<actv<<","<< endl;

    archivo1.close();

}

void mostrarClientes() {
    ifstream archivo1("clientes.csv");ifstream archivo("vehiculos.csv");
    if (!archivo1.is_open()) {
        cout << "Error al abrir el archivo de clientes." << endl;
        return;
    }

    string linea;
    while (getline(archivo1, linea)) {
        cout << linea << endl;
    }

    archivo1.close();
}

void gestionarClientes() {
    int opcion;

    do {
        cout << "=== Gestión de Clientes ===" << endl;
        cout << "1. Insertar cliente" << endl;
        cout << "2. Mostrar clientes" << endl;
        cout << "3. Confirmar cambios" << endl;
        cout << "4. Volver al menú principal" << endl;

        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                insertarCliente();
                break;
            case 2:
                mostrarClientes();
                break;
            case 3: {
                
                if (remove("clientes.csv") != 0) {
                    perror("Error al eliminar el archivo original");
                }
                if (rename("clientes_temp.csv", "clientes.csv") != 0) {
                    perror("Error al renombrar el archivo temporal");
                }
                cout << "Cambios confirmados." << endl;
                break;
            }
            case 4:
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
        
    } while (opcion != 4);
}

void insertarRepuesto() {
    ofstream archivo2("repuestos_temp.csv", ios::app);
    if (!archivo2.is_open()) {
        cout << "Error al abrir el archivo temporal de repuestos." << endl;
        return;
    }

    int year, precio;
    string model, marca, nombre, model_carro, exist;

    cout<<"ingrese el modelo del repuesto: "<<endl;
    cin>>model;
    cout<<"ingrese la marca del respuesto: "<<endl;
    cin>>marca;
    cout<<"ingrese el nomnbre del repuesto: "<<endl;
    cin>>nombre;
    cout<<"ingrese modelo del carro: "<<endl;
    cin>>model_carro;
    cout<<"ingrese el año en el que salio el modelo del carro: "<<endl;
    cin>>year;
    cout<<"ingrese el precio del repuesto: "<<endl;
    cin>>precio;
    cout<<"ingrese las existencias: "<<endl;
    cin>>exist;

    archivo2 <<model<<","<<marca<<","<<nombre<<","<<model_carro<<","<<year<<","<<precio<<","<<exist<<","<< endl;

    archivo2.close();

}

void mostrarRepuestos() {
    ifstream archivo2("repuestos.csv");ifstream archivo1("clientes.csv");ifstream archivo("vehiculos.csv");
    if (!archivo2.is_open()) {
        cout << "Error al abrir el archivo de repuestos." << endl;
        return;
    }

    string linea;
    while (getline(archivo2, linea)) {
        cout << linea << endl;
    }

    archivo2.close();
}

void gestionarRepuestos() {
    int opcion;

    do {
        cout << "=== Gestión de Repuestos ===" << endl;
        cout << "1. Insertar repuesto" << endl;
        cout << "2. Mostrar repuestos" << endl;
        cout << "3. Confirmar cambios" << endl;
        cout << "4. Volver al menú principal" << endl;

        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                insertarRepuesto();
                break;
            case 2:
                mostrarRepuestos();
                break;
            case 3: {
                // Confirmar cambios
                if (remove("repuestos.csv") != 0) {
                    perror("Error al eliminar el archivo original");
                }
                if (rename("repuestos_temp.csv", "repuestos.csv") != 0) {
                    perror("Error al renombrar el archivo temporal");
                }
                cout << "Cambios confirmados." << endl;
                break;
            }
            case 4:
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
        
    } while (opcion != 4);
}

int main() {
    int opcion;

    do {
        mostrarMenu();
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                gestionarVehiculos();
                break;
            case 2:
                gestionarClientes();
                break;
            case 3:
                gestionarRepuestos();
                break;
            case 4:
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }

    } while (opcion != 4);

    return 0;
}