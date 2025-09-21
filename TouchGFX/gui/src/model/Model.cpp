#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include "fdcan.h"
#include "string.h"

extern "C"
{
	extern FDCAN_HandleTypeDef hfdcan1;
	extern FDCAN_TxHeaderTypeDef TxHeader;
	extern osMessageQueueId_t canQueueHandle;
}
#endif

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
#ifndef SIMULATOR
	if(osMessageQueueGetCount(canQueueHandle) > 0)
	{
		if(osMessageQueueGet(canQueueHandle, &receptionBuffer, 0, 0)  == osOK)
		{
			modelListener->receptionData(receptionBuffer);
		}
	}
#endif
	//modelListener->receptionData(receptionBuffer);
}

void Model::sendData(uint8_t *data)
{
#ifndef SIMULATOR
	uint8_t sendData[8] = {data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]};
	TxHeader.Identifier = data[8] + 0x140;
	HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, sendData);
#endif
}
