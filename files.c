#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "admin.h"
#include "files.h"

void logMsg(char *msg, char *filename) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%d-%02d-%02d %02d:%02d:%02d - %s\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec, msg);

    fclose(fp);
}

void write() {
    int i;
    Empresas empresas;

    FILE *fp = fopen(FILENAME, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

     for (i = 0; i < MAX_COMPANIES; i++) {
        empresas.empresas[i].nif = i;
    }
    fwrite(&empresas, sizeof(Empresas), 1, fp);

    fclose(fp);
}

void read() {
    Empresas empresas;

    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    fread(&empresas, sizeof(Empresas), 1, fp);

    fclose(fp);

    // Exibir os dados lidos
    printf("Contador: %d\n", empresas.contador);

    for (int i = 0; i < MAX_COMPANIES; i++) {
        printf("NIF[%d]: %d\n", i, empresas.empresas[i].nif);
        // Exiba outros campos da estrutura Empresa conforme necessário
    }
}