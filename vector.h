//
// Created by marty on 25.05.2022.
//

#ifndef ZADANIE_4_11_VECTOR_H
#define ZADANIE_4_11_VECTOR_H

#include <stdio.h>
#include <stdlib.h>

struct vector_t{
    int *ptr;
    int size;
    int capacity;
};

int vector_create_struct(struct vector_t **a, int N);
void vector_destroy_struct(struct vector_t **a);

int vector_create(struct vector_t *a, int N);
void vector_destroy(struct vector_t *a);

void vector_display(const struct vector_t *a);

int vector_push_back(struct vector_t *a, int value);
int vector_erase(struct vector_t *a, int value);

#endif //ZADANIE_4_11_VECTOR_H
