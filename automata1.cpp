#include <string>
#include <iostream>

// Declaración e implementación de la función de validación para el autómata 1
using namespace std;
bool validarExpresion1(const string & cadena) {
  char estado = 'A'; // Estado inicial

  for (char c: cadena) { // Recorrer cada carácter de la cadena
    switch (estado) {
    case 'A': // Estado A
      if (c == 'a') {
        estado = 'B'; // Transición de A a B con 'a'
      } else if (c == 'b') {
        estado = 'C'; // Transición de A a C con 'b'
      } else {
        return false; // No hay transición válida para 'b'
      }
      break;

    case 'B': // Estado B
      if (c == 'a') {
        estado = 'B'; // Transición de B a B con 'a'
      } else if (c == 'b') {
        estado = 'D'; // Transición de B a D con 'b'
      } else {
        return false; // No hay transición válida '
      }
      break;

    case 'C': // Estado C
      if (c == 'a') {
        estado = 'B'; // Transición de C a B con 'a'
      } else if (c == 'b') {
        estado = 'C'; // Transición de C a C con 'b'
      } else {
        return false; // No hay transición válida '
      }
      break;

    case 'D': // Estado D
      if (c == 'a') {
        estado = 'B'; // Transición de D a B con 'a'
      } else if (c == 'b') {
        estado = 'E'; // Transición de D a E con 'b'
      } else {
        return false; // No hay transición válida para 'a'
      }
      break;

    case 'E': // Estado E
      if (c == 'a') {
        estado = 'F'; // Transición de E a F con 'a'
      } else if (c == 'b') {
        estado = 'C'; // Transición de E a C con 'b'
      } else {
        return false; // No hay transición válida para otro carácter
      }
      break;

    case 'F': // Estado F
      if (c == 'a') {
        estado = 'B'; // Transición de F a B con 'a'
      } else if (c == 'b') {
        estado = 'G'; // Transición de F a G con 'b'
      } else {
        return false; // No hay transición válida para otro carácter
      }
      break;

    case 'G': // Estado G
      if (c == 'a') {
        estado = 'F'; // Transicion de G a F con 'a'
      } else if (c == 'b') {
        estado = 'E'; // Transicion de G a E con 'b'
      } else {
        return false; // No hay transicion valida para otro caracter
      }
      break;
    }
  }

  return estado == 'G'; // El automata acepta la cadena si termina en G
}

/*
bool validarArbol1(const std::string & cadena){
     char estado = 'S0'; // Estado inicial

  for (char c: cadena) { // Recorrer cada carácter de la cadena
    switch (estado) {
    case 'S0': // Estado A
      if (c == 'a') {
        estado = 'S1'; // Transición de A a B con 'a'
      } else if (c == 'b') {
        estado = 'S0'; // Transición de A a C con 'b'
      } else {
        return false; // No hay transición válida para 'b'
      }
      break;

    case 'S1': // Estado B
      if (c == 'a') {
        estado = 'S1'; // Transición de B a B con 'a'
      } else if (c == 'b') {
        estado = 'S2'; // Transición de B a D con 'b'
      } else {
        return false; // No hay transición válida '
      }
      break;
    case 'S2': // Estado B
      if (c == 'a') {
        estado = 'S1'; // Transición de B a B con 'a'
      } else if (c == 'b') {
        estado = 'S3'; // Transición de B a D con 'b'
      } else {
        return false; // No hay transición válida '
      }
      break;
    case 'S3': // Estado B
      if (c == 'a') {
        estado = 'S4'; // Transición de B a B con 'a'
      } else if (c == 'b') {
        estado = 'S0'; // Transición de B a D con 'b'
      } else {
        return false; // No hay transición válida '
      }
      break;
    case 'S4': // Estado B
      if (c == 'a') {
        estado = 'S1'; // Transición de B a B con 'a'
      } else if (c == 'b') {
        estado = 'S5'; // Transición de B a D con 'b'
      } else {
        return false; // No hay transición válida '
      }
      break;
    case 'S5': // Estado B
      if (c == 'a') {
        estado = 'S4'; // Transición de B a B con 'a'
      } else if (c == 'b') {
        estado = 'S3'; // Transición de B a D con 'b'
      } else {
        return false; // No hay transición válida '
      }
      break;
    return estado == 'S5'; // El automata acepta la cadena si termina en G
  }
*/