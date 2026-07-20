#include <stdio.h>
#include <string.h>

#include "uart_driver.h"
#include "uart_config.h"
#include "error_injector.h"
#include "statistics.h"

int main(void)
{
    UART_Config config;
    uint8_t data;
    int choice;
    char message[100];

    /* Load default UART configuration */
    uart_config_default(&config);

    printf("=====================================\n");
    printf("     UART Communication Simulator\n");
    printf("=====================================\n\n");

    /*---------------- Parity Selection ----------------*/

    printf("Select Parity Mode\n");
    printf("1. None\n");
    printf("2. Even\n");
    printf("3. Odd\n");

    printf("\nChoice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        config.parity = UART_PARITY_NONE;
        break;

    case 2:
        config.parity = UART_PARITY_EVEN;
        break;

    case 3:
        config.parity = UART_PARITY_ODD;
        break;

    default:
        printf("Invalid choice. Using NONE.\n");
        config.parity = UART_PARITY_NONE;
        break;
    }

    /*---------------- Error Injection ----------------*/

    printf("\nEnable Error Injection?\n");
    printf("1. Yes\n");
    printf("2. No\n");

    printf("\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        error_injector_enable(true);
    }
    else
    {
        error_injector_enable(false);
    }

    /* Remove newline left by scanf() */
    getchar();

    /*---------------- Message Input ----------------*/

    printf("\nEnter Message: ");
    fgets(message, sizeof(message), stdin);

    /* Remove trailing newline */
    message[strcspn(message, "\n")] = '\0';

    /*---------------- Initialize UART ----------------*/

    uart_init(&config);
    statistics_init();

    /*---------------- Transmit ----------------*/

    for (int i = 0; message[i] != '\0'; i++)
    {
        uart_transmit((uint8_t)message[i]);
    }

    /*---------------- Receive ----------------*/

    printf("\nReceiving...\n\n");

    while (uart_receive(&data))
    {
        printf("%c ", data);
    }

    printf("\n\n");

    /*---------------- Statistics ----------------*/

    statistics_print();

    return 0;
}