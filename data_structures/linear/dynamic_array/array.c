#include <stdio.h>
#include <stdlib.h>

#include "array.h"

Array* arr_create(int initial_size) {
    Array* arr = malloc(sizeof(Array));
    if (arr == NULL) return NULL;

    arr->data = malloc(initial_size * sizeof(int));
    if (arr->data == NULL) {
        free(arr);
        return NULL;
    }
    arr->size = initial_size;
    arr->used = 0;

    return arr;
}

void arr_destroy(Array* arr) {
    if (arr != NULL) {
        free(arr->data);
        free(arr);
    }
}

void arr_resize(Array* arr, int new_size) {
    if (new_size <= arr->used){
        printf("New size must be greater than the number of used elements.\n");
        return;
    }

    int* new_data = realloc(arr->data, new_size * sizeof(int));
    if (new_data == NULL) return;

    arr->data = new_data;
    arr->size = new_size;
}

void arr_insert(Array* arr, int value) {
    if (arr->used >= arr->size) {
        printf("Array is full, resizing...\n");
        arr_resize(arr, arr->size + 1);
    }
    arr->data[arr->used++] = value;
}

void arr_remove_at(Array* arr, int index) {
    if (index < 0 || index >= arr->used) {
        printf("Index out of bounds.\n");
        return;
    }

    for (int i = index; i < arr->used - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->used--;
}

void arr_print(Array* arr) {
    if (arr == NULL || arr->used == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("[");
    for (int i = 0; i < arr->used; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("]");
    printf("\n");
}