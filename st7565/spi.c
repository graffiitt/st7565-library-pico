/*
 * spi.c
 *
 *  Created on: Jun 23, 2024
 *      Author: vlad
 */
#include "spi.h"

void spiInit()
{
	spi_init(spi_default, 100 * 1000);
	gpio_set_function(PICO_SPI_RX_PIN, GPIO_FUNC_SPI);
	gpio_set_function(PICO_SPI_SCK_PIN, GPIO_FUNC_SPI);
	gpio_set_function(PICO_SPI_TX_PIN, GPIO_FUNC_SPI);
	// Make the SPI pins available to picotool
	bi_decl(bi_3pins_with_func(PICO_SPI_RX_PIN, PICO_SPI_TX_PIN, PICO_SPI_SCK_PIN, GPIO_FUNC_SPI));

	// Chip select is active-low, so we'll initialise it to a driven-high state
}

void spiWriteArr(uint8_t *data, uint16_t size)
{
	spi_write_blocking(spi_default, data, size);
}

void spiWriteChr(uint8_t data)
{
	spi_write_blocking(spi_default, &data, 1);
}
