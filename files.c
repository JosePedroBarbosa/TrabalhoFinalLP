#include <stdio.h>
#include <stdlib.h>

#include "admin.h"
#include "files.h"

void loadBranches(RamosAtividade *rAtividade, char *filename) {
    int i, success = 0;

    FILE *fp = fopen(filename, "rb");
    if (fp != NULL) {

        fread(&rAtividade->contador, sizeof (int), 1, fp);

        if (rAtividade->contador > 0) {
            rAtividade->alocados = rAtividade->contador;
            rAtividade->rAtividade = (RamoAtividade*) malloc(rAtividade->contador * sizeof (RamoAtividade));
            for (i = 0; i < rAtividade->contador; i++) {
                fread(&rAtividade->rAtividade[i], sizeof (RamoAtividade), 1, fp);
            }
            success = 1;
        }

        fclose(fp);
    }

    if (!success) {
        fp = fopen(filename, "wb");
        if (fp != NULL) {
            rAtividade->rAtividade = (RamoAtividade*) malloc(BRANCHES_INITIAL_CAPACITY * sizeof (RamoAtividade));
            rAtividade->contador = 0;
            rAtividade->alocados = BRANCHES_INITIAL_CAPACITY;
            fclose(fp);
        }
    }
}


void loadCompanies(Empresas *listaEmpresas, char *filename) {
    int i, success = 0;

    FILE *fp = fopen(filename, "rb");
    if (fp != NULL) {
        fread(&listaEmpresas->contador, sizeof (int), 1, fp);

        if (listaEmpresas->contador > 0) {
            listaEmpresas->alocadas = listaEmpresas->contador;
            listaEmpresas->empresas = (Empresa*) malloc(listaEmpresas->contador * sizeof (Empresa));

            for (i = 0; i < listaEmpresas->contador; i++) {
                fread(&listaEmpresas->empresas[i], sizeof (Empresa), 1, fp);

                fread(&listaEmpresas->empresas[i].nClassis, sizeof (int), 1, fp);
                listaEmpresas->empresas[i].classis = (Classificacao*)malloc(sizeof(Classificacao) * listaEmpresas->empresas[i].nClassis);
                fread(listaEmpresas->empresas[i].classis, sizeof(Classificacao), listaEmpresas->empresas[i].nClassis, fp);

                fread(&listaEmpresas->empresas[i].nComments, sizeof (int), 1, fp);
                listaEmpresas->empresas[i].comments = (Comentario*)malloc(sizeof(Comentario) * listaEmpresas->empresas[i].nComments);
                fread(listaEmpresas->empresas[i].comments, sizeof(Comentario), listaEmpresas->empresas[i].nComments, fp);
            }
            success = 1;
        }

        fclose(fp);
    }

    if (!success) {
        fp = fopen(filename, "wb");
        if (fp != NULL) {
            listaEmpresas->empresas = (Empresa*) malloc(COMPANYS_INITIAL_CAPACITY * sizeof (Empresa));
            listaEmpresas->contador = 0;
            listaEmpresas->alocadas = COMPANYS_INITIAL_CAPACITY;
            fclose(fp);
        }
    }
}

void expandCompaniesCapacity(Empresas *listaEmpresas) {
    int tam = (listaEmpresas->alocadas) == 0 ? COMPANYS_INITIAL_CAPACITY : listaEmpresas->alocadas * 2;
    Empresa *temp = (Empresa*) realloc(listaEmpresas->empresas, sizeof (Empresa) * (tam));
    if (temp != NULL) {
        listaEmpresas->alocadas = tam;
        listaEmpresas->empresas = temp;
    }
}

void expandBranchesCapacity(RamosAtividade *rAtividade) {
    int tam = (rAtividade->alocados) == 0 ? BRANCHES_INITIAL_CAPACITY : rAtividade->alocados * 2;
    RamoAtividade *temp = (RamoAtividade*) realloc(rAtividade->rAtividade, sizeof (RamoAtividade) * (tam));
    if (temp != NULL) {
        rAtividade->alocados = tam;
        rAtividade->rAtividade = temp;
    }
}

void saveCompanies(Empresas *listaEmpresas, char *filename) {
    int i;

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite(&listaEmpresas->contador, sizeof (int), 1, fp);

    for (i = 0; i < listaEmpresas->contador; i++) {
        fwrite(&listaEmpresas->empresas[i], sizeof (Empresa), 1, fp);

        fwrite(&listaEmpresas->empresas[i].nClassis, sizeof (int), 1, fp);
        fwrite(listaEmpresas->empresas[i].classis, sizeof (Classificacao), listaEmpresas->empresas[i].nClassis, fp);

        fwrite(&listaEmpresas->empresas[i].nComments, sizeof (int), 1, fp);
        fwrite(listaEmpresas->empresas[i].comments, sizeof (Comentario), listaEmpresas->empresas[i].nComments, fp);
    }

    fclose(fp);
}

void saveBranches(RamosAtividade *rAtividade, char *filename) {
    int i;

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite(&rAtividade->contador, sizeof (int), 1, fp);

    for (i = 0; i < rAtividade->contador; i++) {
        fwrite(&rAtividade->rAtividade[i], sizeof (RamoAtividade), 1, fp);
    }

    fclose(fp);
}

void updateCompanyInFile(Empresas listaEmpresas, int index, char *filename) {
    FILE *fp = fopen(filename, "rb+");

    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fseek(fp, sizeof (int), SEEK_SET);
    fseek(fp, sizeof (Empresa) * index, SEEK_CUR);

    fwrite(&listaEmpresas.empresas[index], sizeof (Empresa), 1, fp);

    fclose(fp);
}

void updateBranchInFile(RamosAtividade rAtividade, int index, char *filename) {
    FILE *fp = fopen(filename, "rb+");

    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fseek(fp, sizeof (int), SEEK_SET);
    fseek(fp, sizeof (RamoAtividade) * index, SEEK_CUR);

    fwrite(&rAtividade.rAtividade[index], sizeof (RamoAtividade), 1, fp);

    fclose(fp);
}

void removeCompanyFromFile(Empresas listaEmpresas, int index, char *filename) {
    FILE *fpOriginal = fopen(filename, "rb");
    if (fpOriginal == NULL) {
        perror("ERROR OPENING ORIGINAL FILE");
        exit(EXIT_FAILURE);
    }

    fread(&listaEmpresas.contador, sizeof(int), 1, fpOriginal);
    listaEmpresas.empresas = (Empresa *)malloc(sizeof(Empresa) * listaEmpresas.contador);
    fread(listaEmpresas.empresas, sizeof(Empresa), listaEmpresas.contador, fpOriginal);

    fclose(fpOriginal);

    if (index == 0) {
        for (int i = 0; i < listaEmpresas.contador - 1; ++i) {
            listaEmpresas.empresas[i] = listaEmpresas.empresas[i + 1];
        }
    } else if (index > 0 && index < listaEmpresas.contador) {
        for (int i = index; i < listaEmpresas.contador - 1; ++i) {
            listaEmpresas.empresas[i] = listaEmpresas.empresas[i + 1];
        }
    } else {
        fprintf(stderr, "INVALID INDEX\n");
        free(listaEmpresas.empresas);
        exit(EXIT_FAILURE);
    }

    FILE *fpTemp = fopen(TEMP_FILE_COMPANIES, "wb");
    if (fpTemp == NULL) {
        perror("ERROR CREATING TEMP FILE");
        free(listaEmpresas.empresas);
        exit(EXIT_FAILURE);
    }

    fwrite(&listaEmpresas.contador, sizeof(int), 1, fpTemp);
    fwrite(listaEmpresas.empresas, sizeof(Empresa), listaEmpresas.contador, fpTemp);

    fclose(fpTemp);

    remove(filename);
    rename(TEMP_FILE_COMPANIES, filename);

    free(listaEmpresas.empresas);
}


void saveProgramData(Empresas *listaEmpresas, RamosAtividade *rAtividade){
    saveCompanies(listaEmpresas, DATA_FILE);
    saveBranches(rAtividade, BRANCHES_FILE);
}

void freeCompanies(Empresas *listaEmpresas) {
    if(listaEmpresas->empresas){
        for (int i = 0; i < listaEmpresas->alocadas; i++) {
            free(listaEmpresas->empresas[i].classis);
            free(listaEmpresas->empresas[i].comments);
        }

        free(listaEmpresas->empresas);
        listaEmpresas->empresas = NULL;
    }
}

void freeBranches(RamosAtividade *rAtividade) {
    if (rAtividade->rAtividade) {
        free(rAtividade->rAtividade);
        rAtividade->rAtividade = NULL;
    }
}