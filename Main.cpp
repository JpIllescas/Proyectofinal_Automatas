#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // Incluir para std::remove
#include "Automata1.cpp"
#include "Automata2.cpp"
#include "Automata3.cpp"
#include "Automata4.cpp"
#include "Automata5.cpp"

using namespace std;

class ValidadorDeCadenas {
public:
    void cargarYValidarCadenas(const std::string & rutaArchivo) {
        cout << "Iniciando la validacion de cadenas..." << endl;

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

            if (reconocidaPorExp1) cout << "La cadena \"" << linea << "\" es reconocida por la expresion 1." << endl;
            if (reconocidaPorExp2) cout << "La cadena \"" << linea << "\" es reconocida por la expresion 2." << endl;
            if (reconocidaPorExp3) cout << "La cadena \"" << linea << "\" es reconocida por la expresion 3." << endl;
            if (reconocidaPorExp4) cout << "La cadena \"" << linea << "\" es reconocida por la expresion 4." << endl;
            if (reconocidaPorExp5) cout << "La cadena \"" << linea << "\" es reconocida por la expresion 5." << endl;

        }

        archivo.close();
        cout << "Finalizando la validacion de cadenas..." << endl;
    }

    void limpiarEspacios(string & cadena) {
        cadena.erase(std::remove(cadena.begin(), cadena.end(), ' '), cadena.end());
    }
};

int main() {
    ValidadorDeCadenas validador;
    string archivo;
    cout << "Por favor ingrese el nombre del archivo:" << endl;
    cin >> archivo;
    string rutaArchivo = "../cadenas/" + archivo;
    validador.cargarYValidarCadenas(rutaArchivo);

    cout << "Presione Enter para salir..." << endl;
    cin.ignore();
    cin.get();

    return 0;
}
