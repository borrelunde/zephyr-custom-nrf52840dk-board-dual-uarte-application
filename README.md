# Custom nRF52840 DK board dual UARTE Zephyr application

## Overview

This is an application that demonstrates how to implement a simple board that inherits from the `nRF52` series. The board defines two UARTEs that are used in the application.

The custom board can be found in `boards\arm\nrf52840dk`.

You can flash this application to the [nRF52840 DK](https://www.nordicsemi.com/Products/Development-hardware/nrf52840-dk) board.

## Getting Started

This application relies on the project and workspace structure described in [zephyr-application](https://github.com/borrelunde/zephyr-application).

## Building and Running

Build the application using the custom `nRF52840dk` board. Not to be confused with the [nrf52840dk_nrf52840](https://github.com/zephyrproject-rtos/zephyr/tree/main/boards/arm/nrf52840dk_nrf52840) board that is provided already.

```shell
west build -b nrf52840dk app
```

Flash the application.

```shell
west flash
```

## Output

Output on UART0 (`115200 8N1)`:

```
uart0: uart@40002000
*** Booting Zephyr OS build v3.4.0-rc2-121-g402d4eb0dab2 ***
[00:00:00.253,417] <inf> main: Application version 1.0.0 initialized on board nrf52840dk!
[00:00:00.257,141] <inf> main: Application version 1.0.0 shutting down on board nrf52840dk!
```

Output on UART1 (`115200 8N1`):

```
uart1: uart@40028000
```