#include <stdio.h>
#include <stdint.h>



#define TX_BUFFER_SIZE   4
#define RX_BUFFER_SIZE   TX_BUFFER_SIZE


void funcwrite(const void* sendBuf, size_t len);
void read(void* recBuf, size_t maxLen);

void main(){

    uint8_t TX_BUFFER[TX_BUFFER_SIZE] = {0x01, 0x02, 0x03, 0x04};
    uint8_t RX_BUFFER[RX_BUFFER_SIZE] = {0x09, 0x00, 0x00, 0x00};

    uint8_t *pt_tx = &TX_BUFFER;
    uint8_t *pt_rx = &RX_BUFFER;

    funcwrite(pt_tx , TX_BUFFER_SIZE);
    read(RX_BUFFER, TX_BUFFER_SIZE);

    printf("valore 1 recebido: %d \n valore 2 recebido: %d \n valore 3 recebido: %d \n valore 4 recebido: %d \n", RX_BUFFER[0],RX_BUFFER[1] ,RX_BUFFER[2] ,RX_BUFFER[3] );
}

void funcwrite(const void* sendBuf, size_t len){

    int TxBufferIndex = 0;
	uint8_t *pointer;
    pointer = (uint8_t*)sendBuf;
    uint8_t val;

    for(TxBufferIndex; TxBufferIndex < len; TxBufferIndex++){
		val = *(pointer + TxBufferIndex);
		printf("valores enviados: %d \n", val);
	}
}

void read(void* recBuf, size_t maxLen){

    int RxBufferIndex = 0;
	uint8_t *pointer;
    pointer = (uint8_t*)recBuf;

    //send addrs
    printf("envia addr: %d \n",  *pointer);

    for(RxBufferIndex=0; RxBufferIndex < maxLen; RxBufferIndex++){
        printf("send 0 \n");
        //*(pointer + RxBufferIndex) = 4;
        pointer = pointer + RxBufferIndex;
        *pointer = 4; 
	}
}