#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "admin.h"
#include "files.h"

void uploadCompanies(Empresas *listaEmpresas) {
    FILE *ficheiro = fopen("data.bin", "rb");
    FILE *logFile = fopen("logs.txt", "a");

    if (ficheiro == NULL || logFile == NULL) {
        printf("Erro ao abrir o ficheiro para leitura\n");
        exit(EXIT_FAILURE);
    } else {
        fread(&(listaEmpresas->contador), sizeof(int), 1, ficheiro);
        
        listaEmpresas->empresas = (Empresa *)malloc(listaEmpresas->contador * sizeof(Empresa));
        
        if (listaEmpresas->empresas != NULL) {
            fread(listaEmpresas->empresas, sizeof (Empresas), listaEmpresas->contador, ficheiro);
            printf("\nSucesso\n");
        }
        
    }
    fclose(ficheiro);
    fclose(logFile);
}


void uploadActivityBranches(RamosAtividade *ramosAtividade) {
    FILE *ficheiro = fopen("data.bin", "rb");
    FILE *logFile = fopen("logs.txt", "a");

    if (ficheiro == NULL || logFile == NULL) {
        printf("Erro ao abrir o ficheiro para leitura\n");
        exit(EXIT_FAILURE);
    } else {
        fread(&(ramosAtividade->contador), sizeof(int), 1, ficheiro);

        // Aloca memória para o array de RamoAtividade
        ramosAtividade->rAtividade = (RamoAtividade *)malloc(ramosAtividade->contador * sizeof(RamoAtividade));

        if (ramosAtividade->rAtividade != NULL) {
            fread(ramosAtividade->rAtividade, sizeof(RamoAtividade), ramosAtividade->contador, ficheiro);
            printf("\nSucesso\n");
        }
    }

    fclose(ficheiro);
    fclose(logFile);
}

void saveActivityBranches(RamosAtividade *rAtividade) {
    FILE *ficheiro = fopen("data.bin", "wb");
    FILE *logFile = fopen("logs.txt", "a");

    if (ficheiro == NULL || logFile == NULL) {
        printf("Erro ao abrir o ficheiro para escrita\n");
        exit(EXIT_FAILURE);
    } else {
        fwrite(&(rAtividade->contador), sizeof(int), 1, ficheiro);

        for (int i = 0; i < rAtividade->contador; ++i) {
            fprintf(logFile, "Ramo Atividade #%d:\n", i + 1);
            fprintf(logFile, "Nome: %s\n", rAtividade->rAtividade[i].nome);
            fprintf(logFile, "Estado: %d\n", rAtividade->rAtividade[i].estado);

            fwrite(&(rAtividade->rAtividade[i]), sizeof(RamoAtividade), 1, ficheiro);
        }

        fclose(ficheiro);
        fclose(logFile);

        printf("Sucesso ao salvar activity branches\n");
    }
}

void saveCompanies(Empresas *listaEmpresas) {
    FILE *ficheiro = fopen("data.bin", "wb");
    FILE *logFile = fopen("logs.txt", "a");
     
    if (ficheiro == NULL || logFile == NULL) {
        printf("Erro ao abrir o ficheiro para escrita\n");
        exit(EXIT_FAILURE);
    } else {
        // Escrever o número de empresas
        fwrite(&(listaEmpresas->contador), sizeof(int), 1, ficheiro);
                
        // Escrever cada empresa individualmente
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
            fwrite(&(listaEmpresas->empresas[i]), sizeof(Empresa), 1, ficheiro);

            // Escrever a lista de classificações
            fwrite(listaEmpresas->empresas[i].classis, sizeof(Classificacao), listaEmpresas->empresas[i].nClassis, ficheiro);

            // Escrever a lista de comentários
            fwrite(listaEmpresas->empresas[i].comments, sizeof(Comentario), listaEmpresas->empresas[i].nComments, ficheiro);
        }

        printf("Gravou\n");
    }
    fclose(ficheiro);
    fclose(logFile);
}