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

void write(Empresas *listaEmpresas) {
    FILE *fp = fopen(FILENAME, "wb");
    FILE *logFile = fopen(LOG_FILE, "w");

    if (fp == NULL || logFile == NULL) {
        exit(EXIT_FAILURE);
    }
        
    fprintf(logFile, "Número de empresas: %d\n", listaEmpresas->contador);
    
    fwrite(&listaEmpresas->contador, sizeof(int), 1, fp);

    for (int i = 0; i < listaEmpresas->contador; ++i) {
        fprintf(logFile, "Empresa #%d:\n", i + 1);
        fprintf(logFile, "NIF: %d\n", listaEmpresas->empresas[i].nif);
        fprintf(logFile, "Nome: %s\n", listaEmpresas->empresas[i].nome);
        fprintf(logFile, "Categoria: %s\n", listaEmpresas->empresas[i].categoria);
        fprintf(logFile, "Ramo Atividade: %s\n", listaEmpresas->empresas[i].ramo_atividade);
        fprintf(logFile, "Rua: %s\n", listaEmpresas->empresas[i].rua);
        fprintf(logFile, "Localidade: %s\n", listaEmpresas->empresas[i].location);
        fprintf(logFile, "Codigo Postal: %s\n", listaEmpresas->empresas[i].postal_code);
        fprintf(logFile, "Estado: %d\n", listaEmpresas->empresas[i].estado);
        fprintf(logFile, "Numero Classificacoes: %d\n", listaEmpresas->empresas[i].nClassis);
        fprintf(logFile, "Numero Comentarios: %d\n", listaEmpresas->empresas[i].nComments);
        
        fwrite(&(listaEmpresas->empresas[i]), sizeof(Empresa), 1, fp);
    }

    fclose(fp);
    fclose(logFile);

    liberarEmpresas(listaEmpresas);
}

void ler(Empresas *listaEmpresas) {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    // Ler informações da listaEmpresas
    fread(&listaEmpresas->contador, sizeof(int), 1, fp);

    // Ler cada empresa individualmente
    for (int i = 0; i < listaEmpresas->contador; ++i) {
        fread(&(listaEmpresas->empresas[i]), sizeof(Empresa), 1, fp);
    }

    fclose(fp);
}