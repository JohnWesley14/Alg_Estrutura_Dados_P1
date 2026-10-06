# 🏛️ Universidade Federal do Maranhão (UFMA)

| Informação | Detalhe |
| :--- | :--- |
| **Curso** | Bacharelado Interdisciplinar em Ciência e Tecnologia (BICT) |
| **Disciplina** | Algoritmos e Estruturas de Dados |
| **Data de Entrega** | 06 de Outubro de 2026 |
| **Autores** | [John Wesley Rabelo Vaz] e [Ivaldo] |

---

## 📌 Título do Projeto: Sistema de Gerenciamento de [INSERIR TEMA AQUI]

> ⚠️ **Atenção [Nome do Seu Amigo]:**  
> Substitua `[INSERIR TEMA AQUI]` acima pelo tema escolhido (ex.: *Acervo de Biblioteca*, *Controle de Estoque*, *Cadastro de Alunos*) e preencha a seção abaixo descrevendo o contexto do sistema. Lembre-se de realizar o **commit** e **push** dessas alterações no repositório!

### 📝 Contexto do Tema
*[ESPAÇO RESERVADO PARA O SEU AMIGO: Explique aqui o que os números armazenados no vetor representam no contexto do tema escolhido, como códigos de identificação de livros, IDs de produtos ou números de matrícula].*

---

## 💻 Sobre o Projeto

Este projeto foi desenvolvido como requisito avaliativo para a disciplina de **Algoritmos e Estruturas de Dados** da **UFMA (BICT)**. O objetivo é implementar um sistema interativo em linguagem C capaz de realizar as operações fundamentais de manipulação de dados (**CRUD**) em uma estrutura de vetor unidimensional.

### 🛑 Restrições Pedagógicas
Atendendo estritamente às diretrizes da disciplina, o código **não utiliza recursos avançados**, tais como:
* ❌ `structs` (Registros)
* ❌ Ponteiros ou Alocação Dinâmica (`malloc`, `free`)
* ❌ Funções externas ou bibliotecas adicionais (toda a lógica é processada no fluxo da função `main`)

Toda a solução utiliza exclusivamente os conceitos fundamentais: **estruturas de controle condicionais (`if`, `else`), laços de repetição (`for`, `while`) e vetores estáticos**.

---

## ⚙️ Arquitetura e Lógica do Sistema

### 1. Separação de Capacidade Máxima vs. Tamanho Efetivo
Em C, ao declarar um vetor estático `int array[capacity]`, a memória alocada pode conter valores residuais ("lixo de memória"). Para contornar isso e garantir iterações precisas, o sistema utiliza duas variáveis distintas:

* `capacity`: Representa o limite máximo teórico de elementos que o vetor suporta armazenar na memória.
* `size`: Representa a **quantidade real e ativa** de elementos presentes. Todas as operações de busca, listagem e atualização iteram estritamente até `size`, evitando a leitura de posições vazias ou desatualizadas.

### 2. O Loop Interativo (`while`)
Para que o usuário consiga navegar pelo sistema livremente sem que o programa finalize após uma única ação, o menu principal é envelopado em uma estrutura `while`:

```c
while (menu_option != 0) {
    // Exibição do menu e leitura da opção escolhida
}
```

A variável `menu_option` controla o fluxo de execução. O laço executa indefinidamente exibindo as opções do menu até que o usuário digite `0`. Nesse momento, a condição do `while` torna-se falsa e a aplicação é encerrada com segurança.

### 3. Remoção de Elementos por Deslocamento (*Shift*)
Como o vetor possui tamanho fixo em memória e não podemos utilizar estruturas encadeadas ou alocação dinâmica, a deleção de um elemento na posição `delete_index` é feita reorganizando os elementos à direita:

```c
for (int i = delete_index; i < size - 1; i++) {
    array[i] = array[i + 1];
}
size--;
```

O algoritmo puxa todos os elementos subsequentes uma posição para a esquerda (sobrescrevendo o elemento excluído) e decrementa a variável `size`. Assim, o elemento é removido logicamente sem deixar "buracos" no array.

---

## 🛡️ Tratamento de Erros e Validações

O código prevê falhas de entrada e previne travamentos (*segfaults*) por meio de validações preventivas:

1. **Validação de Vetor Vazio:** Antes de executar buscas, deleções ou atualizações, o sistema verifica se `size == 0`. Caso o vetor esteja sem dados ativos, a operação é interrompida com uma mensagem informativa.
2. **Checagem de Limites de Índice (*Out-of-Bounds*):** Para evitar o acesso a posições de memória inválidas ou não inicializadas, todas as entradas de índices numéricos para consulta, deleção ou edição passam por verificação de intervalo:

```c
if (index < 0 || index >= size) {
    // Exibe mensagem de erro e interrompe a operação inválida
}
```

---

## 🚀 Como Compilar e Executar

### Pré-requisitos
* Um compilador C instalado no sistema (ex.: `gcc` ou `clang`).

### Passos para Execução

1. **Clonar ou Baixar o Repositório:**
   ```bash
   git clone <URL_DO_REPOSITORIO>
   cd <NOME_DA_PASTA>
   ```

2. **Compilação via Terminal:**  
   Utilizando o GCC, compile o arquivo fonte `main.c`:
   ```bash
   gcc main.c -o sistema_array
   ```

3. **Execução:**
   * **Linux / macOS:**
     ```bash
     ./sistema_array
     ```
   * **Windows (Prompt de Comando / PowerShell):**
     ```cmd
     sistema_array.exe
     ```