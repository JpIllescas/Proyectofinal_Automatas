#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // Para usar std::remove

using namespace std;

class ValidadorDeCadenas {
public:
    // Función para cargar el archivo y validar cada cadena
    void cargarYValidarCadenas(const string & rutaArchivo) {
        cout << "Iniciando la validacion de cadenas..." << endl;

        ifstream archivo(rutaArchivo);
        if (!archivo.is_open()) {
            cerr << "Error al abrir el archivo: " << rutaArchivo << endl;
            return;
        }

        string linea;
        bool algunaCadenaValida = false;
        int numCadena = 1;  // Para depuración
        while (getline(archivo, linea)) {
            limpiarEspacios(linea); // Limpiar espacios de la cadena

            // Mostrar la cadena que estamos validando para depuración
            cout << "Validando cadena #" << numCadena++ << ": \"" << linea << "\"" << endl;

            bool reconocida = validarExpresion2(linea); // Usar la cadena leída
            if (reconocida) {
                algunaCadenaValida = true;
                cout << "--------------------------------------------------------" << endl;
                cout << "La cadena \"" << linea << "\" es reconocida por la expresion 2." << endl;
                cout << "--------------------------------------------------------" << endl;
            } else {
                cout << "--------------------------------------------------------" << endl;
                cout << "La cadena \"" << linea << "\" NO es reconocida por la expresion 2." << endl;
                cout << "--------------------------------------------------------" << endl;
            }
        }

        if (!algunaCadenaValida) {
            cout << "--------------------------------------------------------" << endl;
            cout << "Ninguna cadena fue reconocida por la expresion 2." << endl;
            cout << "--------------------------------------------------------" << endl;
        }

        archivo.close();
        cout << "----------------------------------------------------------------------" << endl;
        cout << "Finalizando la validacion de cadenas..." << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cout << "Gracias por usar el programa :p" << endl;
        cout << "=======================================================================" << endl;
        system("pause");
    }

    // Función para limpiar espacios en blanco de las cadenas
    void limpiarEspacios(string & cadena) {
        cadena.erase(remove(cadena.begin(), cadena.end(), ' '), cadena.end());
    }

    // Función para validar la cadena según los estados que has proporcionado para la expresión 2
    bool validarExpresion2(const string & cadena) {
        char estado = 'A';  // Estado inicial

        for (char c : cadena) { // Recorrer cada carácter de la cadena
            switch (estado) {
                case 'A':  // Estado A
                    if (c == 'a') {
                        estado = 'B';  // Transición de A a B con 'a'
                    } else {
                        return false;  // No hay transición válida para 'b'
                    }
                    break;

                case 'B':  // Estado B
                    if (c == 'b') {
                        estado = 'C';  // Transición de B a C con 'b'
                    } else {
                        return false;  // No hay transición válida para 'a'
                    }
                    break;

                case 'C':  // Estado C
                    if (c == 'a') {
                        estado = 'D';  // Transición de C a D con 'a'
                    } else {
                        return false;  // No hay transición válida para 'b'
                    }
                    break;

                case 'D':  // Estado D
                    if (c == 'b') {
                        estado = 'E';  // Transición de D a E con 'b'
                    } else {
                        return false;  // No hay transición válida para 'a'
                    }
                    break;

                case 'E':  // Estado E
                    if (c == 'a') {
                        estado = 'D';  // Transición de E a D con 'a'
                    } else if (c == 'b') {
                        estado = 'F';  // Transición de E a F con 'b'
                    } else {
                        return false;  // No hay transición válida para otro carácter
                    }
                    break;

                case 'F':  // Estado F
                    if (c == 'a') {
                        estado = 'G';  // Transición de F a G con 'a'
                    } else if (c == 'b') {
                        estado = 'H';  // Transición de F a H con 'b'
                    } else {
                        return false;  // No hay transición válida para otro carácter
                    }
                    break;

                case 'G':  // Estado G
                    if (c == 'a') {
                        estado = 'G';  // Transicion de G a G con 'a'
                    } else if (c == 'b') {
                        estado = 'H';  // Transicion de G a H con 'b'
                    } else {
                        return false;  // No hay transicion valida para otro caracter
                    }
                    break;

                case 'H':  // Estado H
                    if (c == 'a') {
                        estado = 'G';  // Transición de H a G con 'a'
                    } else if (c == 'b') {
                        estado = 'H';  // Transicion de H a H con 'b'
                    } else {
                        return false;  // No hay transicion valida para otro caracter
                    }
                    break;

                default:
                    return false;  // Estado no válido
            }
        }

        // El automata acepta la cadena si termina en los estados F, G o H
        return estado == 'F' || estado == 'G' || estado == 'H';
    }
};

int mostrarMenu() {
    int opcion;
    cout << "--------------------------------------------------------" << endl;
    cout << "Bienvenido al Validador de Cadenas" << endl;
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Validar cadenas desde un archivo" << endl;
    cout << "2. Salir" << endl;
    cout << "--------------------------------------------------------" << endl; 
    cout << "Ingrese su opcion: ";
    cin >> opcion;
    return opcion;
}

int main() {
    ValidadorDeCadenas validador;
    int opcion = mostrarMenu();
    string archivo;
    switch (opcion) {
    case 1: {
        cout << "Por favor ingrese el nombre del archivo:" << endl;
        cin >> archivo;
        system("pause");
        string rutaArchivo = "../cadenas/" + archivo; // Ruta relativa
        validador.cargarYValidarCadenas(rutaArchivo);
        system("pause");
        break;
    }
    case 2:
        cout << "\n=======================================================================" << endl;
        cout << "Gracias por usar el programa :p" << endl;
        cout << "=======================================================================\n" << endl;
        system("pause");
        break;
    default:
        cout << "Opción no válida. Terminando el programa.\n" << endl;
    }

    return 0;
}
