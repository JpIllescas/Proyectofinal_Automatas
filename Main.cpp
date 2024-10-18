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
    void cargarYValidarCadenas(const string & rutaArchivo) {
      cout << "Iniciando la validacion de cadenas..." << endl;

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
      cout << "----------------------------------------------------------------------" << endl;
      cout << "Finalizando la validacion de cadenas..." << endl;
      cout << "----------------------------------------------------------------------" << endl;
      cout << "Gracias por usar el programa :p" << endl;
      cout <<"======================================================================="<<endl;
      system("pause");
    }

  // Función para limpiar espacios en blanco de las cadenas
  void limpiarEspacios(string & cadena) {
    cadena.erase(remove(cadena.begin(), cadena.end(), ' '), cadena.end());
  }

  // Función para validar una cadena contra las expresiones regulares
  bool validarCadena(const string & cadena) {
    // Vector de pares {expresión regular, nombre de la expresión}
    vector < pair < regex, string > > expresiones = {
      {regex("(a|b)*abb(ab)+"), "1"},
      {regex("(ab)+abb(a|b)*(a|b)*"),"2"},
      {regex("(a|b)abb(ab)*(aa)+(bb)+"),"3"},
      {regex("(01)+1(0|1)*00(01)+"),"4"},
      {regex("110(0|1)*011(00)+"),"5"}
    };

    bool reconocida = false;

    // Validar contra cada expresión regular
    for (const auto & [regexExp, nombreExp]: expresiones) {
      if (regex_match(cadena, regexExp)) {
        cout << "La cadena \"" << cadena << "\" es reconocida por la Expresion " << nombreExp << endl;
        cout << "----------------------------------------------------------------------" << endl;
        reconocida = true;
      }
    }

    if (!reconocida) {
      cout << "La cadena \"" << cadena << "\" no es reconocida por ninguna expresion." << endl;
      cout << "----------------------------------------------------------------------" << endl;
    }

    return reconocida;
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

  switch (opcion) {
  case 1: {

    string rutaArchivo = "/Users/sebastianholweger/Downloads/Proyectofinal_Automatas-main/cadenas/cadenas.txt"; // Ruta relativa
    validador.cargarYValidarCadenas(rutaArchivo);
    system("pause");
    break;
  }
  case 2:
    cout <<"\n======================================================================="<<endl;
    cout << "Gracias por usar el programa :p" << endl;
    cout <<"=======================================================================\n"<<endl;
    system("pause");
    break;
  default:
    cout << "Opcion no valida. Terminando el programa.\n" << endl;
  }

  return 0;
}