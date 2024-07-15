/*****************************************/
/*File name: hello_world.c               */
/*Author: John Trinidad                  */
/*Date: 5/16/2024                        */
/*****************************************/

#include <stdio.h>
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

int main(void)
{
	char ch;

    char name[30], c;
    char ID[10];
    int i = 0;

    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();


    // Part 1 (1)
    PRINTF("hello world.\r\n");

    while (1) {
    	ch = GETCHAR();
    	PUTCHAR(ch);
    }

    /*
    // Part 1 (2)
    PRINTF("Part 2/Part 1/Modification 1.\r\n");
        PRINTF("Please input your full name: ");

        while (1) {
            c = GETCHAR();
            if (c == '\r' || c == '\n')
                break;
            name[i++] = c;
            PUTCHAR(c);
        }
        name[i] = '\0';
        PRINTF("\r\nYour name is:\r\n");
        PRINTF("%s\r\n", name);

        i = 0;
        PRINTF("Please input your student ID number: ");

        while (1) {
            c = GETCHAR();
            if (c == '\r' || c == '\n')
                break;
            ID[i++] = c;
            PUTCHAR(c);
        }
        ID[i] = '\0';

        PRINTF("\r\nYour student ID number is:\r\n");
        PRINTF("%s\r\n", ID);

    return 0;
	*/
}
