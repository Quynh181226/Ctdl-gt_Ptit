//
// Created by TDG on 31/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Employee {
    char name[50];
    char date[20];
    struct Employee *left;
    struct Employee *right;
} Emplyee;
Emplyee* createEmployee(char* name, char* date) {
    Emplyee* newE=
}