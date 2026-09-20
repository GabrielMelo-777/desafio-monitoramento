# Desafio de Monitoramento de Temperatura

## 1. Identificação

**Nome do aluno:** Gabriel Cardozo de Melo
**Disciplina:** Algoritmos e Pensamento Computacional
**Professora:** Profa. Karla Sartin
**Título do projeto:** Sistema de Monitoramento de Temperatura

---

## 2. Objetivo

O objetivo deste projeto é desenvolver um programa em linguagem C para realizar o monitoramento de temperaturas informadas pelo usuário.

O programa verifica se as temperaturas estão acima de um limite definido, controla a quantidade de temperaturas consecutivas acima desse limite e encerra automaticamente o monitoramento quando são registradas três temperaturas consecutivas acima do limite.

Ao final, o programa apresenta um relatório com as principais informações das temperaturas registradas.

---

## 3. Funcionamento do programa

Inicialmente, o usuário informa o limite de temperatura que será utilizado durante o monitoramento.

O programa considera válidos valores entre **-50 °C e 100 °C**. Caso seja informado um valor fora dessa faixa, o programa apresenta uma mensagem de erro e solicita uma nova entrada.

Após definir o limite, o usuário informa as temperaturas uma por vez. Cada temperatura também é validada para garantir que esteja dentro da faixa permitida.

Para cada temperatura válida, o programa:

* adiciona o valor à soma das temperaturas;
* aumenta a quantidade de temperaturas registradas;
* verifica se é a maior ou a menor temperatura registrada;
* verifica se está acima do limite definido;
* contabiliza a quantidade de temperaturas acima do limite;
* controla a quantidade de temperaturas consecutivas acima do limite.

Quando uma temperatura está acima do limite, o contador de temperaturas consecutivas é aumentado.

Quando uma temperatura está dentro ou igual ao limite, o contador de temperaturas consecutivas é reiniciado para zero.

O monitoramento é encerrado automaticamente quando são registradas **três temperaturas consecutivas acima do limite**.

Ao final, o programa apresenta:

* quantidade de temperaturas registradas;
* maior temperatura;
* menor temperatura;
* média das temperaturas;
* percentual de temperaturas acima do limite;
* motivo do encerramento do monitoramento.

---

## 4. Estruturas de repetição utilizadas

### while

A estrutura `while` foi utilizada para controlar o monitoramento das temperaturas:

```c
while (consecutivas < 3)
```

O programa continua realizando novas leituras enquanto a quantidade de temperaturas consecutivas acima do limite for menor que três.

Quando o contador chega a três, a condição deixa de ser verdadeira e o monitoramento é encerrado automaticamente.

### do...while

A estrutura `do...while` foi utilizada para validar o limite e as temperaturas informadas pelo usuário.

Ela permite que o programa solicite a entrada pelo menos uma vez e, depois, verifique se o valor informado é válido.

Caso o valor seja inválido, uma nova entrada é solicitada.

A combinação das duas estruturas permitiu separar a função de **validação das entradas** do **controle principal do monitoramento**.

---

## 5. Como executar

Para executar o projeto, é necessário ter um compilador de linguagem C instalado.

No terminal, entre na pasta onde está o arquivo `monitoramento.c` e utilize o seguinte comando para compilar:

```bash
gcc monitoramento.c -o monitoramento
```

Depois, execute o programa com:

```bash
./monitoramento
```

No Windows, dependendo do compilador utilizado, o executável poderá ser iniciado com:

```bash
monitoramento.exe
```

---

## 6. Testes realizados

### Teste 1 — Validação de entradas inválidas

Foi realizada uma entrada com valor fora da faixa permitida para verificar o funcionamento da validação.

**Resultado:** o programa identificou o valor como inválido, apresentou uma mensagem de erro e solicitou uma nova entrada válida.

**Evidência:** `evidencias/teste01.png`

---

### Teste 2 — Temperaturas acima do limite, porém não consecutivas

Foram informadas temperaturas acima do limite, mas com temperaturas dentro do limite entre elas.

**Resultado:** o contador de temperaturas consecutivas foi reiniciado quando uma temperatura dentro do limite foi informada. Dessa forma, o programa não encerrou o monitoramento antes de ocorrerem três temperaturas consecutivas acima do limite.

**Evidência:** `evidencias/teste02.png`

---

### Teste 3 — Três temperaturas consecutivas acima do limite

Foram informadas três temperaturas consecutivas acima do limite definido.

**Resultado:** o programa identificou as três temperaturas consecutivas, encerrou automaticamente o monitoramento e apresentou o relatório final.

**Evidência:** `evidencias/teste03.png`

---

## 7. Reflexão final

A escolha do `while` e do `do...while` foi feita de acordo com a função de cada parte do algoritmo.

O `do...while` foi utilizado na validação das entradas porque era necessário solicitar o valor pelo menos uma vez antes de verificar se ele era válido. Caso o valor fosse inválido, a estrutura permitia repetir a solicitação.

Já o `while` foi utilizado no monitoramento porque a repetição deveria continuar enquanto não fossem registradas três temperaturas consecutivas acima do limite.

A diferença entre testar a condição antes ou depois da execução foi importante principalmente na validação das entradas. Com o `do...while`, a entrada é solicitada primeiro e somente depois sua validade é verificada. No `while` principal, a condição é verificada antes de cada nova leitura, permitindo que o monitoramento continue somente enquanto ainda não houver três temperaturas consecutivas acima do limite.
