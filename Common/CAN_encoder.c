#include <stdint.h>
#include <stdlib.h>

void encode_can_payload(uint8_t data[8], uint16_t rpm, int16_t angle,
                        uint8_t status) {
    uint16_t u_angle = (uint16_t)angle;
    data[0] = (uint8_t)(rpm & 0xFF);
    data[1] = (uint8_t)((rpm >> 8) & 0xFF);
    data[2] = (uint8_t)(u_angle & 0xFF);
    data[3] = (uint8_t)((u_angle >> 8) & 0xFF);
    data[4] = status;
    data[5] = 0;
    data[6] = 0;
    data[7] = 0;
}

void decode_can_payload(const uint8_t data[8], uint16_t* rpm, int16_t* angle,
                        uint8_t* status) {
    uint16_t u_angle = (uint16_t)data[2] | (uint16_t)(data[3] << 8);
    *rpm = (uint16_t)data[0] | (uint16_t)(data[1] << 8);
    *angle = (int)u_angle;
    *status = data[4];
}