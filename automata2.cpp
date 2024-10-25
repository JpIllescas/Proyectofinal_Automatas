#include <string>
#include <iostream>

// Declaración e implementación de la función de validación para el autómata 2
bool validarExpresion2(const std::string & cadena) {
  char estado = 'A'; // Estado inicial

  for (char c: cadena) { // Recorrer cada carácter de la cadena
    switch (estado) {
    case 'A': // Estado A
      if (c == 'a') {
        estado = 'B'; // Transición de A a B con 'a'
      } else {
        return false; // No hay transición válida 
      }
      break;

    case 'B': // Estado B
      if (c == 'b') {
        estado = 'C'; // Transición de B a C con 'b'
      } else {
        return false; // No hay transición válida para 'a'
      }
      break;

    case 'C': // Estado C
      if (c == 'a') {
        estado = 'D'; // Transición de C a D con 'a'
      } else {
        return false; // No hay transición válida para 'b'
      }
      break;

    case 'D': // Estado D
      if (c == 'b') {
        estado = 'E'; // Transición de D a E con 'b'
      } else {
        return false; // No hay transición válida para 'a'
      }
      break;

    case 'E': // Estado E
      if (c == 'a') {
        estado = 'D'; // Transición de E a D con 'a'
      } else if (c == 'b') {
        estado = 'F'; // Transición de E a F con 'b'
      } else {
        return false; // No hay transición válida para otro carácter
      }
      break;

    case 'F': // Estado F
      if (c == 'a') {
        estado = 'G'; // Transición de F a G con 'a'
      } else if (c == 'b') {
        estado = 'H'; // Transición de F a H con 'b'
      } else {
        return false; // No hay transición válida para otro carácter
      }
      break;

    case 'G': // Estado G
      if (c == 'a') {
        estado = 'G'; // Transicion de G a G con 'a'
      } else if (c == 'b') {
        estado = 'H'; // Transicion de G a H con 'b'
      } else {
        return false; // No hay transicion valida para otro caracter
      }
      break;

    case 'H': // Estado H
      if (c == 'a') {
        estado = 'G'; // Transición de H a G con 'a'
      } else if (c == 'b') {
        estado = 'H'; // Transicion de H a H con 'b'
      } else {
        return false; // No hay transicion valida para otro caracter
      }
      break;

    default:
      return false; // Estado no válido
    }
  }

  // El automata acepta la cadena si termina en los estados F, G o H
  return estado == 'F' || estado == 'G' || estado == 'H';
}
//bool validarArbol2(const std::string & cadena){}