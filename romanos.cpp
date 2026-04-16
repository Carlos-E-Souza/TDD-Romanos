// Copyright 2026 Carlos
#include "./romanos.hpp"  // NOLINT(build/include_subdir)
#include <cstring>

namespace {

// Extrai o valor do caractere romano; retorna -1 se for invalido.
int obter_valor_algarismo(char algarismo) {
  switch (algarismo) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return -1;
  }
}

// Retorna se a entrada contem erros de tamanho ou gramaticais (repeticoes).
bool possui_erros_basicos(const char* num_romano) {
  if (num_romano == nullptr) {
    return true;
  }
  int tamanho = std::strlen(num_romano);
  if (tamanho == 0 || tamanho > 30) {
    return true;
  }
  int repeticoes = 1;
  for (int i = 0; i < tamanho; i++) {
    if (obter_valor_algarismo(num_romano[i]) == -1) {
      return true;  // Contem espacos, minusculas ou caracteres invalidos
    }
    if (i > 0) {
      if (num_romano[i] == num_romano[i - 1]) {
        repeticoes++;
        if (repeticoes == 4) {
          return true;  // Limite aditivo de 3 atingido (ex: IIII, XXXX)
        }
        if (repeticoes == 2 && (num_romano[i] == 'V' ||
            num_romano[i] == 'L' || num_romano[i] == 'D')) {
          return true;  // Bases 5 nao repetem em serie
        }
      } else {
        repeticoes = 1;
      }
    }
  }
  return false;
}

// Regra estrita de quais subtracoes sao aceitas.
bool eh_subtracao_valida(char menor, char maior) {
  if (menor == 'I') return (maior == 'V' || maior == 'X');
  if (menor == 'X') return (maior == 'L' || maior == 'C');
  if (menor == 'C') return (maior == 'D' || maior == 'M');
  return false;
}

}  // namespace

int romanos_para_decimal(char const * num_romano) {
  if (possui_erros_basicos(num_romano)) {
    return -1;
  }
  int total = 0;
  int tamanho = std::strlen(num_romano);

  for (int i = 0; i < tamanho; i++) {
    int atual = obter_valor_algarismo(num_romano[i]);
    if (i + 1 < tamanho) {
      int proximo = obter_valor_algarismo(num_romano[i + 1]);
      if (atual < proximo) {
        if (!eh_subtracao_valida(num_romano[i], num_romano[i + 1])) {
          return -1;
        }
        total += (proximo - atual);
        i++;  // Pula o proximo caractere, ja processado
        continue;
      }
    }
    total += atual;
  }
  if (total > 3000) {
    return -1;
  }

  return total;
}
