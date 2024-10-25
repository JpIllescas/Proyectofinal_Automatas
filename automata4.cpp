#include <string>
#include <iostream>

// Declaración e implementación de la función de validación para el autómata 4
bool validarExpresion4(const std::string & cadena) {
  char estado = 'A'; // Estado inicial

  for (char c: cadena) { // Recorrer cada carácter de la cadena
    switch (estado) {
    case 'A': // Estado A
      if (c == '0') {
        estado = 'B'; // Transición de A a B con '0'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'B': // Estado B
      if (c == '1') {
        estado = 'C'; // Transición de B a C con '1'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'C': // Estado C
      if (c == '0') {
        estado = 'B'; // Transición de C a B con '0'
      } else if (c == '1') {
        estado = 'D'; // Transición de C a D con '1'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'D': // Estado D
      if (c == '0') {
        estado = 'E'; // Transición de D a E con '0'
      } else if (c == '1') {
        estado = 'F'; // Transición de D a F con '1'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'E': // Estado E
      if (c == '0') {
        estado = 'G'; // Transición de E a G con '0'
      } else if (c == '1') {
        estado = 'F'; // Transición de E a F con '1'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'F': // Estado F
      if (c == '0') {
        estado = 'E'; // Transición de F a E con '0'
      } else if (c == '1') {
        estado = 'F'; // Transición de F a F con '1'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'G': // Estado G
      if (c == '0') {
        estado = 'H'; // Transición de G a H con '0'
      } else if (c == '1') {
        estado = 'F'; // Transición de G a F con '1'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'H': // Estado H
      if (c == '0') {
        estado = 'H'; // Transición de H a H con '0'
      } else if (c == '1') {
        estado = 'I'; // Transición de H a I con '1'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'I': // Estado I
      if (c == '0') {
        estado = 'J'; // Transición de I a J con '0'
      } else if (c == '1') {
        estado = 'F'; // Transición de I a F con '1'
      } else {
        return false; // No hay transición válida
      }
      break;

    case 'J': // Estado J
      if (c == '0') {
        estado = 'G'; // Transición de J a G con '0'
      } else if (c == '1') {
        estado = 'I'; // Transición de J a I con '1'
      } else {
        return false; // No hay transición válida
      }
      break;
    }
  }

  return estado == 'I'; // Acepta solo si llega al estado I
}

//bool validarArbol4(const std::string & cadena){}