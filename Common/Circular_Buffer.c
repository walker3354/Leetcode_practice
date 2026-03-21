#include <stdint.h>
#include <stdlib.h>

typedef struct {
        int data_counter;
        int max_capacity;

        int write_pointer;
        int read_pointer;
        uint8_t* data_head;
} RingBuffer;

RingBuffer* rb_create(int capacity) {
    RingBuffer* temp_buffer = malloc(sizeof(RingBuffer));

    temp_buffer->data_counter = 0;
    temp_buffer->max_capacity = capacity;
    temp_buffer->write_pointer = 0;
    temp_buffer->read_pointer = 0;

    return temp_buffer;
}

int rb_write(RingBuffer* rb, const uint8_t* data, int len) {
    if (rb->data_counter == rb->max_capacity) return 0;

    for (int i = 0; i < len; i++) {
        *(rb->data_head + rb->write_pointer) = *(data + i);
        rb->write_pointer = (rb->write_pointer + 1) % rb->max_capacity;
        rb->data_counter++;
        if (rb->data_counter == rb->max_capacity) return i + 1;
    }
    return len;
}

int rb_read(RingBuffer* rb, uint8_t* buf, int len) {
    if (rb->data_counter == 0) return 0;

    for (int i = 0; i < len; i++) {
        *(buf + i) = *(rb->data_head + rb->read_pointer);
        rb->read_pointer = (rb->read_pointer + 1) % rb->max_capacity;
        rb->data_counter--;
        if (rb->data_counter == 0) return i + 1;
    }
    return len;
}

void rb_free(RingBuffer* rb) {
    free(rb->data_head);
    free(rb);
}