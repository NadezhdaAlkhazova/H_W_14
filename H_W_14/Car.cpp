#include <iostream>
#include <cstring>
#include "Car.h"

using namespace std;

void fill_car(Car &car, const char *color, const char *model, const char *number) {
    strcpy(car.color, color);
    strcpy(car.model, model);
    strcpy(car.number, number);
}

void print_car(const Car &car) {
    cout << "Color: " << car.color << endl;
    cout << "Model: " << car.model << endl;
    cout << "Number: " << car.number << endl;
}

void print_all_cars(const Car *cars, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Car: " << i + 1 << endl;
        print_car(cars[i]);
        cout << endl;
    }
    
}

void edit_car(Car *cars, int size) {
    int index;
    cout << "Enter the car index for edit: " ;
    cin >> index;
    
    if (index < 1 || index > size) {
        cout << "Invalid number! Please enter a number between 1 and " << size << endl;
        return;
    }
    
    index--;
    
    char new_color[20], new_model[20], new_number[10];
    
    cout << "Enter the new color: ";
    cin >> new_color;
    cout << "Enter the new model: ";
    cin >> new_model;
    cout << "Enter the new number: ";
    cin >> new_number;
    
    strcpy(cars[index].color, new_color);
    strcpy(cars[index].model, new_model);
    strcpy(cars[index].number, new_number);
    
    cout << "Car: " << index + 1 << " updated" << endl;
    
}

void search_by_number(const Car *cars, int size) {
    char search_num[10];
    
    cout << "Enter the car number to search: ";
    cin >> search_num;
    
    bool found = false;
    
    for (int i = 0; i < size; i++) {
        if (strcmp(cars[i].number, search_num) == 0) {
            cout << "Car found: " << endl;
            print_car(cars[i]);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Car with number " << search_num << " not found" << endl;
    }
   
}


void cars_struct() {
    int cars_size = 10;
    Car cars[cars_size];
    
    fill_car(cars[0], "Red", "Toyota", "AB1234");
    fill_car(cars[1], "Blue", "BMW", "CD5678");
    fill_car(cars[2], "Black", "Audi", "EF9012");
    fill_car(cars[3], "White", "Mercedes", "GH3456");
    fill_car(cars[4], "Green", "Ford", "IJ7890");
    fill_car(cars[5], "Gray", "Honda", "KL1122");
    fill_car(cars[6], "Yellow", "Chevrolet", "MN3344");
    fill_car(cars[7], "Silver", "Nissan", "OP5566");
    fill_car(cars[8], "Orange", "Mazda", "QR7788");
    fill_car(cars[9], "Purple", "Volvo", "ST9900");
    
    print_all_cars(cars, cars_size);
    edit_car(cars, cars_size);
    print_all_cars(cars, cars_size);
    search_by_number(cars, cars_size);
    
}
