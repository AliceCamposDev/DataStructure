#ifndef ARRAY_H
#define ARRAY_H

typedef struct {
    int* data;
    int size;
    int used;
} Array;

Array* arr_create(int initial_size);

void arr_destroy(Array* arr);

void arr_resize(Array* arr, int new_size);

void arr_insert(Array* arr, int value);

void arr_remove_at(Array* arr, int index);

void arr_print(Array* arr);

#endif