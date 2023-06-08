#include <app_version.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

// Register logging in this module.
LOG_MODULE_REGISTER(main);

// Get the UART device node labels from the device tree.
#define UART0_DEVICE_NODE DT_NODELABEL(uart0)
#define UART1_DEVICE_NODE DT_NODELABEL(uart1)

// Create UART devices.
static const struct device *const uart0_dev = DEVICE_DT_GET(UART0_DEVICE_NODE);
static const struct device *const uart1_dev = DEVICE_DT_GET(UART1_DEVICE_NODE);

/**
 * @brief Write a null-terminated string, character by character, to the UART
 * interface.
 *
 * @param dev the UART device to write to.
 * @param str the null-terminated string to write.
 */
void write_uart(const struct device *dev, const char *str) {
    const size_t str_len = strlen(str);
    for (size_t i = 0; i < str_len; i++) {
        uart_poll_out(dev, str[i]);
    }
}

/**
 * @brief This is where the magic happens.
 */
int main(void) {
    // Log initialization.
    LOG_INF("Application version %s initialized on board %s!",
            APP_VERSION_STRING, CONFIG_BOARD);

    // Write to uart0.
    write_uart(uart0_dev, "uart0: ");
    write_uart(uart0_dev, uart0_dev->name);
    write_uart(uart0_dev, "\r\n");

    // Write to uart1.
    write_uart(uart1_dev, "uart1: ");
    write_uart(uart1_dev, uart1_dev->name);
    write_uart(uart1_dev, "\r\n");

    // Log shutdown.
    LOG_INF("Application version %s shutting down on board %s!",
            APP_VERSION_STRING, CONFIG_BOARD);

    return 0;
}