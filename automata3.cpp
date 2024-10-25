#include <string>
#include <iostream>

// Declaración e implementación de la función de validación para el autómata 3
bool validarExpresion3(const std::string & cadena) {
  char estado = 'A'; // Estado inicial

  for (char c: cadena) { // Recorrer cada carácter de la cadena
    switch (estado) {
    case 'A': // Estado A
      if (c == 'a') {
        estado = 'B'; // Transición de A a B con 'a'
      } else if (c == 'b') {
        estado = 'C'; // Transición de A a C con 'b'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'B': // Estado B
      if (c == 'a') {
        estado = 'D'; // Transición de B a D con 'a'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'C': // Estado C
      if (c == 'a') {
        estado = 'D'; // Transición de C a D con 'a'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'D': // Estado D
      if (c == 'b') {
        estado = 'E'; // Transición de D a E con 'b'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'E': // Estado E
      if (c == 'b') {
        estado = 'F'; // Transición de E a F con 'b'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'F': // Estado F
      if (c == 'a') {
        estado = 'G'; // Transición de F a G con 'a'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'G': // Estado G
      if (c == 'a') {
        estado = 'H'; // Transición de G a H con 'a'
      } else if (c == 'b') {
        estado = 'I'; // Transición de G a I con 'b'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'H': // Estado H
      if (c == 'a') {
        estado = 'J'; // Transición de H a J con 'a'
      } else if (c == 'b') {
        estado = 'K'; // Transición de H a K con 'b'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'I': // Estado I
      if (c == 'a') {
        estado = 'G'; // Transición de I a G con 'a'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'J': // Estado J
      if (c == 'a') {
        estado = 'H'; // Transición de J a H con 'a'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'K': // Estado J
      if (c == 'b') {
        estado = 'L'; // Transición de K a L con 'b'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'L': // Estado J
      if (c == 'a') {
        estado = 'H'; // Transición de L a H con 'a'
      } else {
        return false; // No hay transición válida
      }
      break;
    }
  }

  return estado == 'L'; // Acepta solo si llega al estado L
}

//bool validarArbol3(const std::string & cadena){}