#ifndef MEM_23XX1024_DRIVER_H
#define MEM_23XX1024_DRIVER_H

#include "stm32l1XX_hal.h"
#include "stdbool.h"

/* INSTRUCTION CODES*/
#define MEM_23XX1024_READ		 			(0x03)
#define MEM_23XX1024_WRITE				(0x02)
#define MEM_23XX1024_EDIO					(0x3B)
#define MEM_23XX1024_EQIO					(0x38)
#define MEM_23XX1024_RSTIO				(0xFF)
#define MEM_23XX1024_RDMR					(0x05)
#define MEM_23XX1024_WRMR					(0x01)

#define MEM_23XX1024_WAIT_TIME_MAX	0xFFFF

typedef struct
{
		SPI_HandleTypeDef *spiHandle;
		bool isAvalible;
		GPIO_TypeDef *spiCsPort;
		uint16_t spiCsPin;
	  GPIO_TypeDef *holdPort;
		uint16_t holdPin;
}MEM_23XX1024;

int8_t MEM_23XX1024_Init(MEM_23XX1024 *dev, SPI_HandleTypeDef * spiHandle, GPIO_TypeDef *CS_GPIO_Port, uint16_t CS_GPIO_Pin, GPIO_TypeDef *HOLD_GPIO_Port, uint16_t HOLD_GPIO_Pin);
bool MEM_23XX1024_is_present(MEM_23XX1024 *dev);
int8_t MEM_23XX1024_PrintOutRegisters(MEM_23XX1024 *dev);

int8_t MEM_23XX1024_writeValue(MEM_23XX1024 *dev, uint32_t datasetAddress, uint8_t value);
int8_t MEM_23XX1024_writeDataset(MEM_23XX1024 *dev, uint32_t datasetAddress, uint16_t *dataset, uint16_t datasetSize);
int8_t MEM_23XX1024_readValue(MEM_23XX1024 *dev, uint32_t datasetAddress, uint8_t *value);
int8_t MEM_23XX1024_readDataset(MEM_23XX1024 *dev, uint32_t datasetAddress, uint16_t *dataset, uint16_t datasetSize, bool clearDatasetAfterRedaout);

int8_t MEM_23XX1024_enableWriteOperation(MEM_23XX1024 *dev);
int8_t MEM_23XX1024_disableWriteOperation(MEM_23XX1024 *dev);

int8_t MEM_23XX1024_clearMemory(MEM_23XX1024 *dev, uint32_t datasetAddress, uint32_t bytesToClear);

#endif /* MEM_23XX1024_DRIVER_H */
