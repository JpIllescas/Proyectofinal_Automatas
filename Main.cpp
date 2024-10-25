#include <iostream>
#include <fstream>
#include <string>
#include "Automata1.cpp"
#include "Automata2.cpp"
#include "Automata3.cpp"
#include "Automata4.cpp"
#include "Automata5.cpp"

using namespace std;

// Clase encargada de validar cadenas
class ValidadorDeCadenas {
public:
    // Cargar archivo y validar cada cadena
    void cargarYValidarCadenas(const std::string & rutaArchivo) {
        cout << "-----------------------------------------" << endl;
        cout << "Iniciando la validacion de cadenas..." << endl;
        cout << "=========================================\n" << endl;

        ifstream archivo(rutaArchivo);
        if (!archivo.is_open()) {
            cerr << "Error al abrir el archivo: " << rutaArchivo << endl;
            return;
        }

        string linea;
        int numCadena = 1;
        while (getline(archivo, linea)) {
            limpiarEspacios(linea); // Limpiar espacios de la cadena
            cout << "Validando cadena #" << numCadena++ << ": \"" << linea << "\"" << endl;

            bool reconocidaPorExp1 = validarExpresion1(linea);
            bool reconocidaPorExp2 = validarExpresion2(linea);
            bool reconocidaPorExp3 = validarExpresion3(linea);
            bool reconocidaPorExp4 = validarExpresion4(linea);
            bool reconocidaPorExp5 = validarExpresion5(linea);

            cout << "------------------------------------------------------------------------------" << endl;
            if (reconocidaPorExp1) cout << "La cadena \"" << linea << "\" es reconocida por la expresion 1." << endl;
            if (reconocidaPorExp2) cout << "La cadena \"" << linea << "\" es reconocida por la expresion 2." << endl;
            if (reconocidaPorExp3) cout << "La cadena \"" << linea << "\" es reconocida por la expresion 3." << endl;
            if (reconocidaPorExp4) cout << "La cadena \"" << linea << "\" es reconocida por la expresion 4." << endl;
            if (reconocidaPorExp5) cout << "La cadena \"" << linea << "\" es reconocida por la expresion 5." << endl;
            cout << "------------------------------------------------------------------------------" << endl;

            if (!reconocidaPorExp1 && !reconocidaPorExp2 && !reconocidaPorExp3 && !reconocidaPorExp4 && !reconocidaPorExp5) {
                cout << "La cadena \"" << linea << "\" NO es reconocida por ninguna expresion." << endl;
                cout << "------------------------------------------------------------------------------" << endl;
            }
        }

        archivo.close();
        cout << "Finalizando la validacion de cadenas..." << endl;
    }

    // Limpiar espacios en blanco de una cadena
    void limpiarEspacios(string & cadena) {
        cadena.erase(remove(cadena.begin(), cadena.end(), ' '), cadena.end());
    }
};

// Menú de opciones
int mostrarMenu() {
    int opcion;
    cout << "=========================================" << endl;
    cout << "Bienvenido al Validador de Cadenas" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "1. Metodo de la cadena Vacia" << endl;
    cout << "2. Metodo del arbol" << endl;
    cout << "3. Salir" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Ingrese su opcion: ";
    cin >> opcion;
    cout << "-----------------------------------------" << endl;
    return opcion;
}

// Función principal (fuera de la clase)
int main() {
    ValidadorDeCadenas validador;
    int opcion = mostrarMenu();
    string archivo;

    switch (opcion) {
    case 1: {
        cout << "Por favor ingrese el nombre del archivo:" << endl;
        cin >> archivo;
        string rutaArchivo = "../cadenas/" + archivo;
        validador.cargarYValidarCadenas(rutaArchivo);
        break;
    }
    case 2: {
        cout << "Por favor ingrese el nombre del archivo:" << endl;
        cin >> archivo;
        string rutaArchivo = "../cadenas/" + archivo;
        // Aquí puedes implementar otro tipo de validación si aplica
        // validador.cargarYValidarCadenas(rutaArchivo);
        break;
    }
    case 3:
        cout << "Gracias por usar el programa :p" << endl;
        cout << "=========================================" << endl;
        break;
    default:
        cout << "Opcion no valida." << endl;
    }

    return 0;
}
