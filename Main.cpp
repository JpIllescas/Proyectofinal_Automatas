#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm> // Para usar std::remove

using namespace std;

class ValidadorDeCadenas {
public:
    // Función para cargar el archivo y validar cada cadena
    void cargarYValidarCadenas(const string& rutaArchivo) {
        // Mostrar la ruta que se va a usar para abrir el archivo
        cout << "Intentando abrir el archivo en la ruta: " << rutaArchivo << endl;

        ifstream archivo(rutaArchivo);
        if (!archivo.is_open()) {
            cerr << "Error al abrir el archivo: " << rutaArchivo << endl;
            return;
        }

        string linea;
        bool algunaCadenaValida = false;
        while (getline(archivo, linea)) {
            limpiarEspacios(linea); // Limpiar espacios de la cadena
            bool reconocida = validarCadena(linea);
            if (reconocida) {
                algunaCadenaValida = true;
            }
        }

        if (!algunaCadenaValida) {
            cout << "Ninguna cadena fue reconocida por las expresiones regulares." << endl;
        }

        archivo.close();
    }

    // Función para limpiar espacios en blanco de las cadenas
    void limpiarEspacios(string& cadena) {
        cadena.erase(remove(cadena.begin(), cadena.end(), ' '), cadena.end());
    }

    // Función para validar una cadena contra las expresiones regulares
    bool validarCadena(const string& cadena) {
        // Vector de pares {expresión regular, nombre de la expresión}
        vector<pair<regex, string>> expresiones = {
            {regex("(a|b)*abb(ab)+"), "1"},
            {regex("(ab)+abb(a|b)*(a|b)*"), "2"},
            {regex("(a|b)abb(ab)*(aa)+(bb)+"), "3"},
            {regex("(01)+1(0|1)*00(01)+"), "4"},
            {regex("110(0|1)*011(00)+"), "5"}
        };

        bool reconocida = false;

        // Validar contra cada expresión regular
        for (const auto& [regexExp, nombreExp] : expresiones) {
            if (regex_match(cadena, regexExp)) {
                cout << "------------------------------------------" << endl;
                cout << "La cadena \"" << cadena << "\" es reconocida por la Expresion " << nombreExp << endl;
                reconocida = true;
            }
        }

        if (!reconocida) {
            cout << "------------------------------------------" << endl;
            cout << "La cadena \"" << cadena << "\" no es reconocida por ninguna expresion." << endl;
        }

        return reconocida;
    }
};

int main() {
    ValidadorDeCadenas validador;
    string rutaArchivo = "../cadenas/cadenas.txt";  // Ruta relativa
    validador.cargarYValidarCadenas(rutaArchivo);

    return 0;
}
