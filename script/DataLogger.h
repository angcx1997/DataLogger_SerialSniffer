/*
 * DataLogger.h
 *
 *  Created on: Apr 29, 2022
 *      Author: angcx
 *
 * Message
 * 1. SOI (1 byte)
 * 2. Data size (1 byte)
 * 3. Info (number of byte based on data size)
 * 4. Checksum (2 byte)
 * 5. EOI (1 byte)
 */

#ifndef DATALOGGER_H_
#define DATALOGGER_H_

#define DATA_LOGGER_SOI 0xFF
#define DATA_LOGGER_EOI	0xFB

#include <stdint.h>
#include <stdbool.h>
#include <UnionDataStruct.h>

typedef struct{
	uint8_t* pMsg;
	uint16_t size;
	uint16_t arr_ptr_idx;
}DataLogger_Msg_t;

/**
 * @brief use to Init Tx Message
 * @param msg pointer to datalogger
 * @param size total number of byte user intend to send, exclude soi,eoi,checksum
 */
void DataLogger_Init(DataLogger_Msg_t* msg);

/**
 * @brief Add message to data_logger
 * @param num number of data that user want to  send
 */
void DataLogger_AddMessage(DataLogger_Msg_t* msg, uint8_t arr[], uint16_t Size);


/**
 * @brief use to construct Tx Message
 * @param num number of data that user want to  send
 */
void DataLogger_CompleteTxMessage(DataLogger_Msg_t* msg);




#endif /* DATALOGGER_H_ */
