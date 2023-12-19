#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void liberarEmpresa(Empresa *empresa) {
    // Libere a memória alocada para classis e comments conforme necessário
}

void liberarEmpresas(Empresas *listaEmpresas) {
    for (int i = 0; i < listaEmpresas->contador; ++i) {
        liberarEmpresa(&(listaEmpresas->empresas[i]));
    }
    free(listaEmpresas->empresas);
}

void liberarRamosAtividade(RamosAtividade *rAtividadeList) {
    free(rAtividadeList->rAtividade);
}

void write() {
    Empresas listaEmpresas;

    FILE *fp = fopen(FILENAME, "wb");
    FILE *logFile = fopen(LOG_FILE, "w");

    if (fp == NULL || logFile == NULL) {
        exit(EXIT_FAILURE);
    }
        
    fprintf(logFile, "Número de empresas: %d\n", listaEmpresas.contador);

    fwrite(&listaEmpresas.contador, sizeof(int), 1, fp);
    
    for (int i = 0; i < listaEmpresas.contador; ++i) {
        fprintf(logFile, "Empresa #%d:\n", i + 1);
        fprintf(logFile, "NIF: %d\n", listaEmpresas.empresas[i].nif);

        fwrite(&(listaEmpresas.empresas[i]), sizeof(Empresa), 1, fp);
    }

    fclose(fp);
    fclose(logFile);
    
    liberarEmpresas(&listaEmpresas);
}

void ler() {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    Empresas listaEmpresas;
    // Inicialize listaEmpresas antes de ler

    // Ler informações da listaEmpresas
    fread(&listaEmpresas.contador, sizeof(int), 1, fp);

    // Alocar memória para as empresas
    listaEmpresas.empresas = malloc(sizeof(Empresa) * listaEmpresas.contador);

    // Ler cada empresa individualmente
    for (int i = 0; i < listaEmpresas.contador; ++i) {
        fread(&(listaEmpresas.empresas[i]), sizeof(Empresa), 1, fp);
    }

    fclose(fp);

    // Usar os dados lidos

    // Libere a memória alocada dinamicamente após ler
    liberarEmpresas(&listaEmpresas);
}