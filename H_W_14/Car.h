#pragma once

#include <iostream>
#include <cstring>

struct Car {
    char color[20];
    char model[20];
    char number[10];
};

void fill_car(Car &car, const char *color, const char *model, const char *number);
void print_car(const Car &car);
void cars_struct();
void edit_car(Car *cars, int size);
void search_by_number(const Car *cars, int size);
