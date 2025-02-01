# Projeto: Simulação de Semáforo com Raspberry Pi Pico W

## Descrição do Projeto
Este projeto implementa a simulação de um semáforo utilizando um Raspberry Pi Pico W (RP2040). O código alterna entre os LEDs vermelho, amarelo e verde de forma sequencial, representando o funcionamento de um semáforo tradicional. O tempo de mudança de estado é de 3 segundos, e o estado atual é impresso no terminal via `printf`.

## Objetivo
O objetivo deste projeto é demonstrar o uso de GPIOs e timers no RP2040 para controle sequencial de LEDs. Ele também serve como uma introdução ao uso de timers repetitivos para criar delays sem bloquear a execução principal do programa.

## Funcionalidades
- Controle sequencial de LEDs representando um semáforo:
  - **Vermelho:** Indica parada.
  - **Amarelo:** Indica alerta de mudança.
  - **Verde:** Indica liberação.
- Impressão do estado atual no terminal via `printf`.
- Uso de um timer repetitivo para alternar os estados automaticamente a cada 3 segundos.

## Estrutura do Código
O código é dividido nas seguintes partes:

### Definições e Inicialização
- Definição dos pinos GPIO dos LEDs (11, 12 e 13).
- Configuração inicial dos pinos e definição do estado inicial dos LEDs.

### Timer Repetitivo
- Um callback (`repeating_timer_callback`) que muda o estado dos LEDs a cada 3 segundos.
- A transição segue a ordem:
  - Vermelho → Amarelo
  - Amarelo → Verde
  - Verde → Vermelho

### Loop Principal
- Exibe no terminal o estado atual do semáforo a cada 1 segundo.

## Requisitos de Hardware
- **Raspberry Pi Pico W (RP2040)**
- **3 LEDs**
  - Vermelho conectado ao GPIO 11
  - Amarelo conectado ao GPIO 12
  - Verde conectado ao GPIO 13
- **3 resistores de 330Ω** (um para cada LED)

## Requisitos de Software
- **SDK do Raspberry Pi Pico**
- **Compilador para C/C++ (arm-none-eabi-gcc)**
- **Ambiente de desenvolvimento configurado para RP2040**

## Como Usar
### 1. Montagem do Circuito
Conecte os LEDs aos respectivos pinos conforme a lista de requisitos de hardware.

### 2. Compilar e Carregar o Código
1. Clone o repositório ou copie o código-fonte.
2. Compile o código utilizando o SDK do Raspberry Pi Pico.
3. Carregue o binário no Raspberry Pi Pico via USB.

### 3. Executar o Programa
1. Abra um terminal e conecte-se ao Pico via `minicom`, `picocom` ou outro terminal serial.
2. O estado do semáforo será impresso no terminal a cada 1 segundo.
3. Os LEDs mudarão de estado automaticamente a cada 3 segundos.

## Exemplo de Saída no Terminal
```
Vermelho
Vermelho
Vermelho
Amarelo
Amarelo
Amarelo
Verde
Verde
Verde
```

## Contribuidor

Hugo Martins Santana (TIC370101267)

## Licença
Este projeto é disponibilizado sob a licença MIT. Consulte o arquivo LICENSE para mais informações.

