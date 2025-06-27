#include <stdio.h>
#include <string.h>
#include "clientes.h"

// Autor: Maria Fernanda Zandona Casagrande GRR20241727
// Descrição: Cria e retorna uma struct Cliente com os dados fornecidos.
Cliente criar_cliente(char nome[], int numero, int procedimentos) {
    Cliente c;
    strncpy(c.nome, nome, NOME_TAM);
    c.nome[NOME_TAM - 1] = '\0'; // Garante terminação
    c.numero = numero;
    c.procedimentos = procedimentos;
    return c;
}
