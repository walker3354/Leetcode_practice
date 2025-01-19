#include <iostream>

class DynamicArray {
    private:
        int capacity;
        int size;
        int *D_array;

    public:
        DynamicArray(int capacity) {
            this->size = 0;
            this->capacity = capacity;
            D_array = new int[capacity];
        }

        int get(int i) { return *(D_array + i); }

        void set(int i, int n) { *(D_array + i) = n; }

        void pushback(int n) {
            if (this->size == this->capacity) this->resize();
            *(D_array + this->size) = n;
            this->size++;
        }

        int popback() {
            this->size -= 1;
            return *(D_array + this->size);
        }

        void resize() {
            int *temp_array = new int[this->capacity * 2];
            for (int i = 0; i < this->size; i++) {
                *(temp_array + i) = *(D_array + i);
            }
            delete[] D_array;
            D_array = temp_array;
            this->capacity = this->capacity * 2;
        }

        int getSize() { return this->size; }

        int getCapacity() { return this->capacity; }
};