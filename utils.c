/**
 * @file input.c
 * @author ESTG
 * @date 28-10-2023
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2023. All Rights MIT Licensed.
 *
 * @brief Contains functions for user input.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

/**
 * @brief A string constant representing an invalid value message.
 *
 * This constant is used to define a standard error message for invalid input values.
 * It can be used throughout the program to provide consistent error messages to the user
 * when they enter an invalid value.
 */

void cleanInputBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int getInt(int minValor, int maxValor, char *msg) {
    int valor;
    printf(msg);
    while (scanf("%d", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(INVALID_VALUE);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return valor;
}

float getFloat(float minValor, float maxValor, char *msg) {
    float valor;
    printf(msg);
    while (scanf("%f", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(INVALID_VALUE);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return valor;
}

double getDouble(double minValor, double maxValor, char *msg) {
    double valor;
    printf(msg);
    while (scanf("%lf", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(INVALID_VALUE);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return valor;
}

char getChar(char *msg) {
    char valor;
    printf(msg);
    valor = getchar();
    cleanInputBuffer();
    return valor;
}

void readString(char *string, unsigned int tamanho, char *msg) {
    printf(msg);

    if (fgets(string, tamanho, stdin) != NULL) {
        unsigned int len = strlen(string) - 1;
        if (string[len] == '\n') {
            string[len] = '\0';
        } else {
            cleanInputBuffer();
        }
    }
}

int validateString(char *string){
    if (strlen(string) == 0){
        puts(FILL_IN_FIELD);
        return 0;
    }
    return 1;
}

int validatePostalCode(char *postalCode){

    if (strlen(postalCode) != 8){
        puts(INVALID_POSTAL_CODE);
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        if (!isdigit(postalCode[i])) {
            puts(INVALID_POSTAL_CODE_4_FDIGITS);
            return 0;
        }
    }

    if (postalCode[4] != '-'){
        puts(INVALID_POSTAL_CODE_HIFFEN);
        return 0;
    }

    for (int i = 5; i < 8; i++) {
        if (!isdigit(postalCode[i])) {
            puts(INVALID_POSTAL_CODE_3_LDIGITS);
            return 0;
        }
    }

    return 1;
}