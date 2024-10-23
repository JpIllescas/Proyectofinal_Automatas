#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 

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
        int numCadena = 1;  // Para depuración
        while (getline(archivo, linea)) {
            limpiarEspacios(linea); // Limpiar espacios de la cadena

            // Mostrar la cadena que estamos validando para depuración
            cout << "Validando cadena #" << numCadena++ << ": \"" << linea << "\"" << endl;

            bool reconocidaPorExp1 = validarExpresion1(linea);
            bool reconocidaPorExp2 = validarExpresion2(linea);
            bool reconocidaPorExp3 = validarExpresion3(linea);
            bool reconocidaPorExp4 = validarExpresion4(linea);
            bool reconocidaPorExp5 = validarExpresion5(linea);

            if (reconocidaPorExp1) {
                cout << "\n--------------------------------------------------------" << endl;
                cout << "La cadena \"" << linea << "\" es reconocida por la expresion 1." << endl;
                cout << "--------------------------------------------------------\n" << endl;
            }
            if (reconocidaPorExp2) {
                cout << "\n--------------------------------------------------------" << endl;
                cout << "La cadena \"" << linea << "\" es reconocida por la expresion 2." << endl;
                cout << "--------------------------------------------------------\n" << endl;
            }
            if (reconocidaPorExp3) {
                cout << "\n--------------------------------------------------------" << endl;
                cout << "La cadena \"" << linea << "\" es reconocida por la expresion 3." << endl;
                cout << "--------------------------------------------------------\n" << endl;
            }
            if (reconocidaPorExp4) {
                cout << "\n--------------------------------------------------------" << endl;
                cout << "La cadena \"" << linea << "\" es reconocida por la expresion 4." << endl;
                cout << "--------------------------------------------------------\n" << endl;
            }
            if (reconocidaPorExp5) {
                cout << "\n--------------------------------------------------------" << endl;
                cout << "La cadena \"" << linea << "\" es reconocida por la expresion 5." << endl;
                cout << "--------------------------------------------------------\n" << endl;
            }
            if (!reconocidaPorExp1 && !reconocidaPorExp2 && !reconocidaPorExp3 && !reconocidaPorExp4 && !reconocidaPorExp5) { // Si no coincide con ninguna expresión
                cout << "\n--------------------------------------------------------" << endl;
                cout << "La cadena \"" << linea << "\" NO es reconocida por ninguna expresion." << endl;
                cout << "--------------------------------------------------------\n" << endl;
            }
        }

        archivo.close();
        cout << "----------------------------------------------------------------------" << endl;
        cout << "Finalizando la validacion de cadenas..." << endl;
        cout << "\n=======================================================================" << endl;
        cout << "Gracias por usar el programa :p" << endl;
        cout << "=======================================================================\n" << endl;
        system("pause");
    }

    // Función para limpiar espacios en blanco de las cadenas
    void limpiarEspacios(string & cadena) {
        cadena.erase(remove(cadena.begin(), cadena.end(), ' '), cadena.end());
    }

    // Función para validar la cadena según los estados que se han proporcionado para la expresión 1
    bool validarExpresion1(const string & cadena) {
        char estado = 'A';  // Estado inicial

        for (char c : cadena) { // Recorrer cada carácter de la cadena
            switch (estado) {
                case 'A':  // Estado A
                    if (c == 'a') {
                        estado = 'B';  // Transición de A a B con 'a'
                    } else if (c == 'b') {
                        estado = 'C';  // Transición de A a C con 'b'
                    } else {
                        return false;  // No hay transición válida para 'b'
                    }
                    break;

                case 'B':  // Estado B
                    if (c == 'a') {
                        estado = 'B';  // Transición de B a B con 'a'
                    } else if (c == 'b') {
                        estado = 'D';  // Transición de B a D con 'b'
                    } else {
                        return false;  // No hay transición válida '
                    }
                    break;

                case 'C':  // Estado C
                    if (c == 'a') {
                        estado = 'B';  // Transición de C a B con 'a'
                    } else if (c == 'b') {
                        estado = 'C';  // Transición de C a C con 'b'
                    } else {
                        return false;  // No hay transición válida '
                    }
                    break;

                case 'D':  // Estado D
                    if (c == 'a') {
                        estado = 'B';  // Transición de D a B con 'a'
                    } else if (c == 'b') {
                        estado = 'E';  // Transición de D a E con 'b'
                    } else {
                        return false;  // No hay transición válida para 'a'
                    }
                    break;

                case 'E':  // Estado E
                    if (c == 'a') {
                        estado = 'F';  // Transición de E a F con 'a'
                    } else if (c == 'b') {
                        estado = 'C';  // Transición de E a C con 'b'
                    } else {
                        return false;  // No hay transición válida para otro carácter
                    }
                    break;

                case 'F':  // Estado F
                    if (c == 'a') {
                        estado = 'B';  // Transición de F a B con 'a'
                    } else if (c == 'b') {
                        estado = 'G';  // Transición de F a G con 'b'
                    } else {
                        return false;  // No hay transición válida para otro carácter
                    }
                    break;

                case 'G':  // Estado G
                    if (c == 'a') {
                        estado = 'F';  // Transicion de G a F con 'a'
                    } else if (c == 'b') {
                        estado = 'E';  // Transicion de G a E con 'b'
                    } else {
                        return false;  // No hay transicion valida para otro caracter
                    }
                    break;
            }
        }
        
        return estado == 'G'; // El automata acepta la cadena si termina en G
    }


    // Función para validar la cadena según los estados que se han proporcionado para la expresión 2
    bool validarExpresion2(const string & cadena) {
        char estado = 'A';  // Estado inicial

        for (char c : cadena) { // Recorrer cada carácter de la cadena
            switch (estado) {
                case 'A':  // Estado A
                    if (c == 'a') {
                        estado = 'B';  // Transición de A a B con 'a'
                    } else {
                        return false;  // No hay transición válida 
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

    // Función para validar la cadena según los estados proporcionados para la expresión 3
    bool validarExpresion3(const string & cadena) {
        char estado = 'A';  // Estado inicial

        for (char c : cadena) { // Recorrer cada carácter de la cadena
            switch (estado) {
                case 'A':  // Estado A
                    if (c == 'a') {
                        estado = 'B';  // Transición de A a B con 'a'
                    } else if (c == 'b') {
                        estado = 'C';  // Transición de A a C con 'b'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'B':  // Estado B
                    if (c == 'a') {
                        estado = 'D';  // Transición de B a D con 'a'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'C':  // Estado C
                    if (c == 'a') {
                        estado = 'D';  // Transición de C a D con 'a'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'D':  // Estado D
                    if (c == 'b') {
                        estado = 'E';  // Transición de D a E con 'b'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'E':  // Estado E
                    if (c == 'b') {
                        estado = 'F';  // Transición de E a F con 'b'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'F':  // Estado F
                    if (c == 'a') {
                        estado = 'G';  // Transición de F a G con 'a'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'G':  // Estado G
                    if (c == 'a') {
                        estado = 'H';  // Transición de G a H con 'a'
                    } else if (c == 'b') {
                        estado = 'I';  // Transición de G a I con 'b'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'H':  // Estado H
                    if (c == 'a') {
                        estado = 'J';  // Transición de H a J con 'a'
                    } else if (c == 'b') {
                        estado = 'K';  // Transición de H a K con 'b'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'I':  // Estado I
                    if (c == 'a') {
                        estado = 'G';  // Transición de I a G con 'a'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'J':  // Estado J
                    if (c == 'a') {
                        estado = 'H';  // Transición de J a H con 'a'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'K':  // Estado J
                    if (c == 'b') {
                        estado = 'L';  // Transición de K a L con 'b'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'L':  // Estado J
                    if (c == 'a') {
                        estado = 'H';  // Transición de L a H con 'a'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;
            }
        }

        return estado == 'L';  // Acepta solo si llega al estado L
    }

    // Función para validar la cadena según los estados proporcionados para la expresión 4
    bool validarExpresion4(const string & cadena) {
        char estado = 'A';  // Estado inicial

        for (char c : cadena) { // Recorrer cada carácter de la cadena
            switch (estado) {
                case 'A':  // Estado A
                    if (c == '0') {
                        estado = 'B';  // Transición de A a B con '0'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'B':  // Estado B
                    if (c == '1') {
                        estado = 'C';  // Transición de B a C con '1'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'C':  // Estado C
                    if (c == '0') {
                        estado = 'B';  // Transición de C a B con '0'
                    } else if (c == '1') {
                        estado = 'D';  // Transición de C a D con '1'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'D':  // Estado D
                    if (c == '0') {
                        estado = 'E';  // Transición de D a E con '0'
                    } else if (c == '1') {
                        estado = 'F';  // Transición de D a F con '1'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'E':  // Estado E
                    if (c == '0') {
                        estado = 'G';  // Transición de E a G con '0'
                    } else if (c == '1') {
                        estado = 'F';  // Transición de E a F con '1'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'F':  // Estado F
                    if (c == '0') {
                        estado = 'E';  // Transición de F a E con '0'
                    } else if (c == '1') {
                        estado = 'F';  // Transición de F a F con '1'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'G':  // Estado G
                    if (c == '0') {
                        estado = 'H';  // Transición de G a H con '0'
                    } else if (c == '1') {
                        estado = 'F';  // Transición de G a F con '1'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'H':  // Estado H
                    if (c == '0') {
                        estado = 'H';  // Transición de H a H con '0'
                    } else if (c == '1') {
                        estado = 'I';  // Transición de H a I con '1'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'I':  // Estado I
                    if (c == '0') {
                        estado = 'J';  // Transición de I a J con '0'
                    } else if (c == '1') {
                        estado = 'F';  // Transición de I a F con '1'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'J':  // Estado J
                    if (c == '0') {
                        estado = 'G';  // Transición de J a G con '0'
                    } else if (c == '1') {
                        estado = 'I';  // Transición de J a I con '1'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;
            }
        }

        return estado == 'I';  // Acepta solo si llega al estado I
    }

    // Función para validar la cadena según los estados proporcionados para la expresión 5
    bool validarExpresion5(const string & cadena) {
        char estado = 'A';  // Estado inicial

        for (char c : cadena) { // Recorrer cada carácter de la cadena
            switch (estado) {
                case 'A':  // Estado A
                    if (c == '1') {
                        estado = 'B';  // Transición de A a B con '1'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'B':  // Estado B
                    if (c == '1') {
                        estado = 'C';  // Transición de B a C con '1'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'C':  // Estado C
                    if (c == '0') {
                        estado = 'D';  // Transición de C a D con '0'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'D':  // Estado D
                    if (c == '0') {
                        estado = 'E';  // Transición de D a E con '0'
                    } else if (c == '1') {
                        estado = 'F';  // Transición de D a F con '1'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'E':  // Estado E
                    if (c == '0') {
                        estado = 'E';  // Transición de E a E con '0'
                    } else if (c == '1') {
                        estado = 'G';  // Transición de E a G con '1'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'F':  // Estado F
                    if (c == '0') {
                        estado = 'E';  // Transición de F a E con '0'
                    } else if (c == '1') {
                        estado = 'F';  // Transición de F a F con '1'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'G':  // Estado G
                    if (c == '0') {
                        estado = 'E';  // Transición de G a E con '0'
                    } else if (c == '1') {
                        estado = 'H';  // Transición de G a H con '1'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'H':  // Estado H
                    if (c == '0') {
                        estado = 'I';  // Transición de H a I con '0'
                    } else if (c == '1') {
                        estado = 'F';  // Transición de H a F con '1'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'I':  // Estado I
                    if (c == '0') {
                        estado = 'J';  // Transición de I a J con '0'
                    } else if (c == '1') {
                        estado = 'G';  // Transición de I a G con '1'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;

                case 'J':  // Estado J
                    if (c == '0') {
                        estado = 'I';  // Transición de J a I con '0'
                    } else {
                        return false;  // No hay transición válida
                    }
                    break;
            }
        }

        return estado == 'J';  // Acepta solo si llega al estado J
    }

};

// Menú de selección
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
        cout << "Opcion no valida. Terminando el programa.\n" << endl;
    }

    return 0;
}
