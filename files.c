#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "admin.h"
#include "files.h"

void uploadCompanies(Empresas *listaEmpresas) {
    int i, sucesso = 0;
    
    FILE *ficheiro = fopen("data.bin", "rb");
    FILE *logFile = fopen("logs.txt", "a");
    
    if (ficheiro != NULL && logFile != NULL) {
        fread(&listaEmpresas->contador, sizeof (int), 1, ficheiro);

        if (listaEmpresas->contador > 0) {
            listaEmpresas->alocadas = listaEmpresas->contador;
            listaEmpresas->empresas = (Empresa*) malloc(listaEmpresas->contador * sizeof (Empresa));
            
            if (listaEmpresas->empresas == NULL) {
                printf("Erro ao alocar memória para empresas\n");
                exit(EXIT_FAILURE);
            }
            
            for (i = 0; i < listaEmpresas->contador; i++) {
                fread(&listaEmpresas->empresas[i], sizeof (Empresa), 1, ficheiro);
                
                 // Alocação de memória para classis
                listaEmpresas->empresas[i].classis = (Classificacao *)malloc(sizeof(Classificacao) * listaEmpresas->empresas[i].nClassis);
                
                // Ler classis do ficheiro
                fread(listaEmpresas->empresas[i].classis, sizeof(Classificacao), listaEmpresas->empresas[i].nClassis, ficheiro);

                 // Alocação de memória para comments
                listaEmpresas->empresas[i].comments = (Comentario *)malloc(sizeof(Comentario) * listaEmpresas->empresas[i].nComments);

                // Ler comments do ficheiro
                fread(listaEmpresas->empresas[i].comments, sizeof(Comentario), listaEmpresas->empresas[i].nComments, ficheiro);
            }
            sucesso = 1;
        }

        fclose(ficheiro);
        fclose(logFile);
    }

    if (!sucesso) {
        ficheiro = fopen("data.bin", "wb");
        if (ficheiro != NULL) {

            listaEmpresas->alocadas = COMPANY_INITIAL_ALLOCATION;
            listaEmpresas->empresas = (Empresa*) malloc(COMPANY_INITIAL_ALLOCATION * sizeof(Empresa));
            
            if (listaEmpresas->empresas == NULL) {
                printf("Erro ao alocar memória para empresas\n");
                exit(EXIT_FAILURE);
            }
            
            listaEmpresas->contador = 0;

            fclose(ficheiro);
            fclose(logFile);
        }
    }
}


void uploadActivityBranches(RamosAtividade *ramosAtividade) {
    int i, sucesso = 0;
    
    FILE *ficheiro = fopen("data.bin", "rb");
    FILE *logFile = fopen("logs.txt", "a");
    
    if (ficheiro != NULL && logFile != NULL) {
        fread(&ramosAtividade->contador, sizeof (int), 1, ficheiro);

        if (ramosAtividade->contador > 0) {
            ramosAtividade->alocados = ramosAtividade->contador;
            ramosAtividade->rAtividade = (RamoAtividade*) malloc(ramosAtividade->contador * sizeof (RamoAtividade));
            
            if (ramosAtividade->rAtividade == NULL) {
                printf("Erro ao alocar memória para ramos atividade\n");
                exit(EXIT_FAILURE);
            }
            
            for (i = 0; i < ramosAtividade->contador; i++) {
                fread(&ramosAtividade->rAtividade[i], sizeof (RamoAtividade), 1, ficheiro);
            }
            sucesso = 1;
        }

        fclose(ficheiro);
        fclose(logFile);
    }

    if (!sucesso) {
        ficheiro = fopen("data.bin", "wb");
        if (ficheiro != NULL) {

            ramosAtividade->alocados = COMPANY_INITIAL_ALLOCATION;
            ramosAtividade->rAtividade = (RamoAtividade*) malloc(BRANCHES_INITIAL_ALLOCATION * sizeof(RamoAtividade));
            
            if (ramosAtividade->rAtividade == NULL) {
                printf("Erro ao alocar memória para ramos atividade\n");
                exit(EXIT_FAILURE);
            }
            
            ramosAtividade->contador = 0;

            fclose(ficheiro);
            fclose(logFile);
        }
    }
}

void saveActivityBranches(RamosAtividade *rAtividade) {
    FILE *ficheiro = fopen("data.bin", "ab");
    FILE *logFile = fopen("logs.txt", "a");
    int i;
    
    if (ficheiro == NULL || logFile == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite(&rAtividade->contador, sizeof(int), 1, ficheiro);

    for (i = 0; i < rAtividade->contador; i++) {
        fprintf(logFile, "Ramo Atividade #%d:\n", i + 1);
        fprintf(logFile, "Nome Ramo: %s\n", rAtividade->rAtividade[i].nome);
        fprintf(logFile, "Estado: %d\n", rAtividade->rAtividade[i].estado);

        //Escrever cada ramo individualmente 
        fwrite(&rAtividade->rAtividade[i], sizeof(RamoAtividade), 1, ficheiro);
    }

    fclose(ficheiro);
    fclose(logFile);
}

void saveCompanies(Empresas *listaEmpresas) {
    FILE *ficheiro = fopen("data.bin", "ab");
    FILE *logFile = fopen("logs.txt", "a");
    int i;
    
    if (ficheiro == NULL || logFile == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite(&listaEmpresas->contador, sizeof(int), 1, ficheiro);

    for (i = 0; i < listaEmpresas->contador; i++) {
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
        
        //Escrever cada empresa individualmente 
        fwrite(&listaEmpresas->empresas[i], sizeof(Empresa), 1, ficheiro);

        
        // Escrever a lista de classificações
       fwrite(listaEmpresas->empresas[i].classis, sizeof(Classificacao), listaEmpresas->empresas[i].nClassis, ficheiro);
            
        // Escrever a lista de comentários
        fwrite(listaEmpresas->empresas[i].comments, sizeof(Comentario), listaEmpresas->empresas[i].nComments, ficheiro);
    }

    fclose(ficheiro);
    fclose(logFile);
}