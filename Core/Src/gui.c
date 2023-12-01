#include "gui.h"
#include "lock.h"
#include "main.h"
#include "stm32l4xx_ll_usart.h"
#include <string.h>

#include "ssd1306.h"
#include "ssd1306_fonts.h"


extern const uint8_t locked[];


void GUI_init(void)
{
	ssd1306_Init();
}
void USART1_Transmit(char *string) {
    while (*string != '\0') {
        while (!LL_USART_IsActiveFlag_TXE(USART1));
        LL_USART_TransmitData8(USART1, *string++);
    }
}
void GUI_locked(void)
{
	ssd1306_Fill(Black);
	ssd1306_SetCursor(20, 5);
	ssd1306_WriteString("Locked", Font_16x26, White);
	ssd1306_DrawBitmap(50, 35, locked, 30, 30, White);
	ssd1306_UpdateScreen();
	USART1_Transmit("\r\n");
	USART1_Transmit("Hola Mundo!\r\n");
	USART1_Transmit("Ingrese su contraseña\r\n");
	USART1_Transmit("    y luego presione   \r\n");
	USART1_Transmit("#--------Ingresar\r\n");
	USART1_Transmit("*--------Cambiar clave\r\n");
	USART1_Transmit("B--------Encender ultrasonido\r\n");
	USART1_Transmit("C--------Apagar ultrasonido\r\n");
	USART1_Transmit("D--------Pausar\r\n");
	USART1_Transmit("\r\n");
}

void GUI_kirby(void) {
	ssd1306_Fill(Black);
    ssd1306_UpdateScreen();
}

void GUI_unlocked(void)
{
	ssd1306_Fill(Black);
	ssd1306_SetCursor(5, 5);
	ssd1306_WriteString("Unlocked", Font_16x26, White);
	ssd1306_UpdateScreen();
	USART1_Transmit("\r\n");
	USART1_Transmit("Sistema desbloqueado\r\n");
	USART1_Transmit("*--------Bloquear\r\n");
	USART1_Transmit("B--------Encender ultrasonido\r\n");
	USART1_Transmit("C--------Apagar ultrasonido\r\n");
	USART1_Transmit("D--------Pausar\r\n");
	USART1_Transmit("\r\n");

}

void GUI_update_password_init(void)
{
	ssd1306_Fill(Black);
	ssd1306_SetCursor(5, 5);
	ssd1306_WriteString("New PW:", Font_16x26, White);
	ssd1306_UpdateScreen();
	USART1_Transmit("\r\n");
	USART1_Transmit("Ingrese su nueva contraseña\r\n");
	USART1_Transmit("    y luego presione       \r\n");
	USART1_Transmit("#--------Para guardar      \r\n");
	USART1_Transmit("*--------Para reiniciar      \r\n");
	USART1_Transmit("\r\n");
}

void GUI_update_password(uint8_t *password)
{
	ssd1306_SetCursor(10, 35);
	ssd1306_WriteString((char *)password, Font_7x10, White);
	ssd1306_UpdateScreen();
}

void GUI_update_password_success(void)
{
	ssd1306_SetCursor(5, 35);
	ssd1306_WriteString("Success!", Font_16x26, White);
	ssd1306_UpdateScreen();
	USART1_Transmit("\r\n");
	USART1_Transmit("Cambio de la contraseña\r\n");
	USART1_Transmit("C------con exito ------\r\n");
	USART1_Transmit("#    Para ir al inicio\r\n");
	USART1_Transmit("\r\n");

}

void GUI_display_key(char key, uint8_t x, uint8_t y) {
    char buffer[2] = {key, '\0'}; // Buffer para el carácter
    ssd1306_SetCursor(x, y);
    ssd1306_WriteString(buffer, Font_11x18, White);
    ssd1306_UpdateScreen();
}

