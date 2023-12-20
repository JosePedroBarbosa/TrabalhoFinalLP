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
    // Implemente a liberação de memória para classis e comments conforme necessário
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

// Seu código que usa as funções de leitura e escrita com as liberações de memória
void writeCompanies(Empresas *listaEmpresas) {
    FILE *fp = fopen(FILENAME, "wb");
    FILE *logFile = fopen(LOG_FILE, "a");

    if (fp == NULL || logFile == NULL) {
        exit(EXIT_FAILURE);
    }

    fprintf(logFile, "Número de empresas: %d\n", listaEmpresas->contador);

    fwrite(&(listaEmpresas->contador), sizeof(int), 1, fp);

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

void readCompanies(Empresas *listaEmpresas) {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    // Ler informações da listaEmpresas
    fread(&(listaEmpresas->contador), sizeof(int), 1, fp);

    // Aloca memória para empresas
    listaEmpresas->empresas = malloc(sizeof(Empresa) * listaEmpresas->contador);

    // Ler cada empresa individualmente
    for (int i = 0; i < listaEmpresas->contador; ++i) {
        fread(&(listaEmpresas->empresas[i]), sizeof(Empresa), 1, fp);
    }

    fclose(fp);
}

void writeActivityBranches(RamosAtividade *rAtividadeList) {
    FILE *fp = fopen(FILENAME_BRACHES, "wb");

    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite(&(rAtividadeList->contador), sizeof(int), 1, fp);

    for (int i = 0; i < rAtividadeList->contador; ++i) {
        fwrite(&(rAtividadeList->rAtividade[i]), sizeof(RamoAtividade), 1, fp);
    }

    fclose(fp);
}

void readActivityBranches(RamosAtividade *rAtividadeList) {
    FILE *fp = fopen(FILENAME_BRACHES, "rb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fread(&(rAtividadeList->contador), sizeof(int), 1, fp);

    rAtividadeList->rAtividade = malloc(sizeof(RamoAtividade) * rAtividadeList->contador);

    for (int i = 0; i < rAtividadeList->contador; ++i) {
        fread(&(rAtividadeList->rAtividade[i]), sizeof(RamoAtividade), 1, fp);
    }

    fclose(fp);
}

void removeCompanyFromFile(int nif) {
    FILE *fp = fopen(FILENAME, "rb+");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    Empresas listaEmpresas;
    readCompanies(&listaEmpresas);

    int indiceEmpresa = searchCompanyIndexByNif(listaEmpresas, nif);
    if (indiceEmpresa != -1) {
        // Atualize o estado da empresa ou remova do arquivo conforme necessário
        // Exemplo: listaEmpresas.empresas[indiceEmpresa].estado = 0;

        fseek(fp, sizeof(int) + (sizeof(Empresa) * indiceEmpresa), SEEK_SET);
        fwrite(&(listaEmpresas.empresas[indiceEmpresa]), sizeof(Empresa), 1, fp);
    }

    fclose(fp);
    liberarEmpresas(&listaEmpresas);
}

void updateCompanyInFile(Empresa *empresa) {
    FILE *fp = fopen(FILENAME, "rb+");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    Empresas listaEmpresas;
    readCompanies(&listaEmpresas);

    int indiceEmpresa = searchCompanyIndexByNif(listaEmpresas, empresa->nif);
    if (indiceEmpresa != -1) {
        // Atualize os dados da empresa no arquivo conforme necessário
        // Exemplo: listaEmpresas.empresas[indiceEmpresa] = *empresa;

        fseek(fp, sizeof(int) + (sizeof(Empresa) * indiceEmpresa), SEEK_SET);
        fwrite(&(listaEmpresas.empresas[indiceEmpresa]), sizeof(Empresa), 1, fp);
    }

    fclose(fp);
    liberarEmpresas(&listaEmpresas);
}

void removeActivityBranchFromFile(char *nome) {
    FILE *fp = fopen(FILENAME_BRACHES, "rb+");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    RamosAtividade ramosAtividade;
    readActivityBranches(&ramosAtividade);

    int indiceRamo = searchBranchIndexByName(ramosAtividade, nome);
    if (indiceRamo != -1) {
        // Atualize o estado do ramo ou remova do arquivo conforme necessário
        // Exemplo: ramosAtividade.rAtividade[indiceRamo].estado = 0;

        fseek(fp, sizeof(int) + (sizeof(RamoAtividade) * indiceRamo), SEEK_SET);
        fwrite(&(ramosAtividade.rAtividade[indiceRamo]), sizeof(RamoAtividade), 1, fp);
    }

    fclose(fp);
    liberarRamosAtividade(&ramosAtividade);
}

void updateActivityBranchInFile(RamoAtividade *ramoAtividade) {
    FILE *fp = fopen(FILENAME_BRACHES, "rb+");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    RamosAtividade ramosAtividade;
    readActivityBranches(&ramosAtividade);

    int indiceRamo = searchBranchIndexByName(ramosAtividade, ramoAtividade->nome);
    if (indiceRamo != -1) {
        // Atualize os dados do ramo no arquivo conforme necessário
        // Exemplo: ramosAtividade.rAtividade[indiceRamo] = *ramoAtividade;

        fseek(fp, sizeof(int) + (sizeof(RamoAtividade) * indiceRamo), SEEK_SET);
        fwrite(&(ramosAtividade.rAtividade[indiceRamo]), sizeof(RamoAtividade), 1, fp);
    }

    fclose(fp);
    liberarRamosAtividade(&ramosAtividade);
}