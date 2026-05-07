#include <stdint.h>
#include <stdlib.h>

typedef struct RingBuffer {
        int capacity;
        int data_counter;
        int write_pos;
        int read_pos;

        uint8_t* data;
} RingBuffer;

RingBuffer* rb_create(int capacity) {
    RingBuffer* rb = malloc(sizeof(RingBuffer));
    if (rb == NULL) return NULL;

    rb->data = malloc(capacity * sizeof(uint8_t));
    if (rb->data == NULL) {
        free(rb);
        return NULL;
    }
    rb->capacity = capacity;
    rb->data_counter = 0;
    rb->write_pos = 0;
    rb->read_pos = 0;
    return rb;
}

int rb_write(RingBuffer* rb, const uint8_t* data, int len) { // return wite data num 
    if (len <= 0) return 0;
    int write_data_num = rb->data_counter
}

int rb_read(RingBuffer* rb, uint8_t* buf, int len) {}

void rb_free(RingBuffer* rb) {
    free(rb->data);
    free(rb);
}