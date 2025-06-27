# 🏦 Simulador de Atendimento Multicaixa Bancário  
**Trabalho Prático II – Estruturas de Dados: Implementação de Pilhas e Filas**  
**Disciplina**: Estrutura de Dados  
**Professor(a)**: Dr. Helcio Soares Padilha Júnior  

---

## 👥 Integrantes do Grupo

| Nome                                    | Matrícula     |
| --------------------------------------- | ------------- |
| Maria Fernanda Zandona Casagrande       | GRR20241727   |
| Pedro Eduardo Dall’ Agnol               | GRR20240844   |
| Gabriela Harres Rodrigues               | GRR20246215   |
| João Vítor Kretzschmar                  | GRR20240632   |


Link do video: https://youtu.be/yEdCJgo-4HM?si=ikVi9gAhIqydlxFL


---

## 🎯 Objetivo Geral

Desenvolver uma aplicação em C que utilize **filas lineares** (estáticas ou dinâmicas, com ou sem prioridade, e com opção circular) e **pilhas**, simulando o atendimento em duas filas de caixa (normal e rápido), com registro de histórico de atendimentos e cálculo de estatísticas ao final do dia.

---

## 🏛️ Cenário-Problema

Uma agência bancária precisa gerenciar duas filas simultâneas de atendimento:

- **Fila Comum**: qualquer cliente  
- **Fila Rápida**: clientes com até 2 procedimentos  

Os atendimentos ocorrem em paralelo, alternando entre os dois caixas. A cada atendimento, registra-se:
1. Cliente atendido  
2. Tempo estimado de atendimento  
3. Caixa utilizado (comum ou rápido)  

Ao final do dia, o sistema disponibiliza:
- Tempo médio de atendimento por tipo de fila  
- Total de clientes atendidos por caixa  

---

## 📋 Regras e Restrições Didáticas

1. **Apresentação Oral**:  
   - Cada integrante apresentará uma função implementada, explicando:  
     - Lógica da função  
     - Utilização das estruturas de dados  
     - Motivação da escolha  

2. **Comentário de Autoria**:  
   - No topo de cada função, incluir nome do responsável e descrição funcional  

---

## 📁 Estrutura de Arquivos

```text
Projeto
├── main.c                  # Menu principal e fluxo de controle
├── clientes.c / clientes.h # Cadastro e estrutura de clientes
├── fila.c / fila.h         # Implementação das filas (comum, rápida e circular)
├── atendimento.c / atendimento.h # Lógica de atendimento e cálculo de tempo
├── historico.c / historico.h     # Pilha para registro do histórico de atendimentos
├── README.md               # Documentação deste projeto
└── diario_de_bordo.pdf     # (Entregue separadamente em PDF)
```

---

## 💻 Como Compilar e Executar

### Linux / macOS
```bash
gcc main.c clientes.c fila.c atendimento.c historico.c -o simulador
./simulador
```

### Windows (Prompt de Comando)
```bat
gcc main.c clientes.c fila.c atendimento.c historico.c -o simulador.exe
simulador.exe
```

---

## ⚙️ Funcionalidades

1. **Cadastrar cliente** (nome, número, quantidade de procedimentos)  
2. **Inserir cliente** na fila adequada (rápida ou comum)  
3. **Atender clientes**, alternando entre caixas  
4. **Registrar atendimentos** em uma **pilha de histórico**  
5. **Exibir** filas atuais de cada caixa  
6. **Calcular** e exibir **tempo médio** de atendimento por tipo de fila  
7. **Listar** todos os atendimentos realizados (nome, tipo de fila, tempo)

---

## 📚 Estruturas de Dados Utilizadas

### Filas
- **Fila Comum**  
  - Tipo: Dinâmica (listas encadeadas)  
  - Operações: `enqueue`, `dequeue` em O(1)  
- **Fila Rápida**  
  - Tipo: Dinâmica com prioridade simples (≤ 2 procedimentos)  
- **Fila Circular**  
  - Tipo: Estática (vetor circular)  
  - Vantagem: Reaproveitamento de espaço e controle via ponteiros

### Pilha de Histórico
- Tipo: Dinâmica (vetor redimensionável)  
- Uso: Registro LIFO de atendimentos para relatórios finais

---

## 🔄 Fluxo Geral do Sistema

```text
                             ┌────────────┐  
   [Cadastro de Clientes] →  │ Fila Comum │  
                             └────────────┘
       │                           |
       ↓                           |
 ┌───────────┐                     |
 │Fila Rápida│                     |
 └───────────┘                     |
       │                           ↓
       └───────────────────► [Atendimento] ───► [Pilha de Histórico]  ;
```

---

## 💡 Decisões de Projeto

- **Modularização** em arquivos `.c`/`.h` para clareza e manutenção  
- **Filas Dinâmicas** garantem flexibilidade de tamanho  
- **Fila Circular** otimiza uso de memória estática  
- **Pilha Dinâmica** previne overflow fixo e facilita crescimento  
- **Comentários de Autoria** asseguram rastreabilidade de código  

---

## 🏁 Conclusão

O **Simulador de Atendimento Multicaixa Bancário** integra teoria e prática de estruturas de dados, proporcionando uma visão completa sobre o funcionamento de **filas** e **pilhas** em um cenário realista. A modularização e as escolhas de implementações (filas dinâmicas, fila circular e pilha de histórico) garantem eficiência, manutenibilidade e flexibilidade. Este projeto reforça a importância das estruturas de dados na solução de problemas computacionais e prepara os estudantes para desafios reais de programação em C.

---

## 🎥 Demonstração

Link do vídeo de demonstração (não listado):  
https:
