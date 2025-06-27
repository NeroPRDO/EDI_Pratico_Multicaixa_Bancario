#ifndef CLIENTES_H
#define CLIENTES_H

#define NOME_TAM 50

typedef struct {
    char nome[NOME_TAM];
    int numero;              // Número do cliente (senha)
    int procedimentos;       // Quantidade de procedimentos
} Cliente;

// Cria um novo cliente com os dados fornecidos
Cliente criar_cliente(char nome[], int numero, int procedimentos);

#endif
