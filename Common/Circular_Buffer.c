#include <stdint.h>
#include <stdlib.h>

/*
 * Ring buffer for byte streams.
 *
 * Core idea:
 * - write_pos points to the next write slot.
 * - read_pos points to the next read slot.
 * - data_counter separates empty and full states.
 *
 * Time: O(n) for reading/writing n bytes.
 * Space: O(capacity).
 *
 * C notes:
 * - Validate NULL pointers and non-positive lengths.
 * - Clip read/write length to the current available data/space.
 */

typedef struct RingBuffer {
        int capacity;
        int data_counter;
        int write_pos;
        int read_pos;

        uint8_t* data;
} RingBuffer;

RingBuffer* rb_create(int capacity) {
    if (capacity <= 0) return NULL;

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

int rb_write(RingBuffer* rb, const uint8_t* data,
             int len) { // return write data num
    if (rb == NULL || len <= 0 || data == NULL ||
        rb->data_counter == rb->capacity)
        return 0;

    int available = rb->capacity - rb->data_counter;
    int write_data_num = len < available ? len : available;

    for (int i = 0; i < write_data_num; i++) {
        rb->data[rb->write_pos] = data[i];
        rb->write_pos = (rb->write_pos + 1) % rb->capacity;
        rb->data_counter++;
    }
    return write_data_num;
}

int rb_read(RingBuffer* rb, uint8_t* buf, int len) {
    if (rb == NULL || len <= 0 || buf == NULL || rb->data_counter == 0)
        return 0;
    int read_data_num = (rb->data_counter - len) >= 0 ? len : rb->data_counter;

    for (int i = 0; i < read_data_num; i++) {
        buf[i] = rb->data[rb->read_pos];
        rb->read_pos = (rb->read_pos + 1) % rb->capacity;
        rb->data_counter--;
    }
    return read_data_num;
}

void rb_free(RingBuffer* rb) {
    if (rb == NULL) return;
    free(rb->data);
    free(rb);
}
