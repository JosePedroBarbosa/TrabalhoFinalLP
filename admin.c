#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "admin.h"
#include "users.h"
#include "companies.h"
#include "files.h"

void removeCompany(Empresa *empresa){
    empresa->nif = 0;
    strcpy(empresa->nome, "");
    strcpy(empresa->categoria, "");
    strcpy(empresa->ramo_atividade, "");
    strcpy(empresa->rua, "");
    strcpy(empresa->location, "");
    strcpy(empresa->postal_code, "");
    empresa->estado = 0;
    empresa->nClassis = 0;
    empresa->nComments = 0;
}

void removeCompanies(Empresas *empresas) {
    int i;
    int indiceEmpresa = searchCompanyIndexByNif(*empresas, getInt(MIN_NIF_VALUE, MAX_NIF_VALUE, MSG_GET_NIF));

    if(indiceEmpresa != -1){
        if (empresas->empresas[indiceEmpresa].nComments == 0){
            for (i = indiceEmpresa; i < empresas->contador - 1; i++) {
                empresas->empresas[i] = empresas->empresas[i + 1];
            }
            removeCompany(&empresas->empresas[i]);
            empresas->contador--;
            puts(MSG_COMPANY_REMOVE_SUCCESS);
            removeCompanyFromFile(*empresas, indiceEmpresa, DATA_FILE);
        }else{
            puts(MSG_ERROR_HAVE_COMMENTS);

            char option;
            do{
                puts(MSG_CHANGE_STATE);
                scanf(" %c", &option);
            } while((option != 'Y') && (option != 'N'));

            if (option == 'Y'){
                empresas->empresas[indiceEmpresa].estado = 0;
                puts(MSG_COMPANY_INACTIVE);
            }
        }
    }else{
        puts(ERROR_COMPANY_DONT_EXIST);
    }
}

void updateCompany(Empresas *listaEmpresas, Empresa *empresa, RamosAtividade *ramosAtividade, int companyIndex) {
    do{
        readString((*empresa).nome, MAX_COMPANY_NAME_SIZE, MSG_GET_NEW_COMPANY_NAME);

    } while(validateString((*empresa).nome) != 1);

    do{
        readString((*empresa).categoria, MAX_COMPANY_CATEGORY_SIZE, MSG_GET_NEW_CATEGORY_NAME);

    } while(validateString((*empresa).categoria) != 1);

    do{
        readString((*empresa).ramo_atividade, MAX_COMPANY_BRANCHES_SIZE, MSG_GET_NEW_BRANCHES_NAME);

    } while (searchBranchIndexByName(*ramosAtividade, (*empresa).ramo_atividade) == -1);

    do{
        readString((*empresa).rua, MAX_COMPANY_STREET_SIZE, MSG_GET_NEW_STREET_NAME);

    } while(validateString((*empresa).rua) != 1);

    do{
        readString((*empresa).location, MAX_COMPANY_LOCATION_SIZE, MSG_GET_NEW_LOCATION_NAME);

    } while(validateString((*empresa).location) != 1);

    do {
        readString((*empresa).postal_code, MAX_COMPANY_POSTALCODE_SIZE, MSG_GET_NEW_POSTALCODE_NAME);

    } while(validatePostalCode((*empresa).postal_code) != 1);

    char option;
    int company_state = (*empresa).estado;
    do{
        puts(MSG_CHANGE_COMPANY_STATE);
        scanf("%c", &option);
    } while((option != 'Y') && (option != 'N'));

    if (option == 'Y'){
        if (company_state == 0){
            (*empresa).estado = 1;
            puts(MSG_COMPANY_ACTIVE);
        }else{
            puts(MSG_COMPANY_ALREADY_ACTIVE);
        }
    }

    if ((*empresa).nComments > 0) {
        int opc, opc4;
        char opc2, opc3;

        for (int i = 0; i < (*empresa).nComments; i++) {
            printf("Comment # %d \n Username: %s \n Title: %s \n Text: %s \n State: %s \n",
                   i + 1, (*empresa).comments[i].nomeUtilizador,
                   (*empresa).comments[i].titulo, (*empresa).comments[i].texto,
                   (*empresa).comments[i].estado == 1 ? "Active" : "Inactive");
        }

        do{
            puts(MSG_DELETE_HIDE_COMMENTS);
            scanf(" %c", &opc2);
        } while((opc2 != 'Y') && (opc2 != 'N'));

        if (opc2 == 'Y'){
            do{
                puts(MSG_DELETE_OR_HIDE_COMMENTS);
                scanf(" %c", &opc3);
            }while((opc3 != 'D') && (opc3 != 'H'));

            if (opc3 == 'D'){
                do{
                    puts(MSG_NUMBER_OF_COMMENT);
                    scanf("%d", &opc);
                }while(opc <= 0 || opc > (*empresa).nComments);

                (*empresa).comments[opc-1] = (*empresa).comments[(*empresa).nComments-1];                
                strcpy((*empresa).comments[(*empresa).nComments-1].emailUtilizador, "");
                strcpy((*empresa).comments[(*empresa).nComments-1].nomeUtilizador, "");
                strcpy((*empresa).comments[(*empresa).nComments-1].texto, "");
                strcpy((*empresa).comments[(*empresa).nComments-1].titulo, "");
                (*empresa).comments[(*empresa).nComments - 1].estado = 0;
                (*empresa).nComments--;
                puts(MSG_COMPANY_UPDATE_SUCESS);
            }else if (opc3 == 'H'){
                do{
                    puts(MSG_NUMBER_OF_COMMENT_HIDE);
                    scanf("%d", &opc4);
                }while(opc4 <= 0 || opc4 > (*empresa).nComments);

                (*empresa).comments[opc4 - 1].estado = 0;
                puts(MSG_COMMENT_UPDATE_SUCESS);
            }
        }else{
            puts(MSG_COMPANY_UPDATE_SUCESS);
        }
    }
    updateCompanyInFile(*listaEmpresas, companyIndex, DATA_FILE);
}

void updateCompanies(Empresas *empresas, RamosAtividade *ramosAtividade) {
    int companyIndex = searchCompanyIndexByNif(*empresas, getInt(MIN_NIF_VALUE, MAX_NIF_VALUE, MSG_GET_NIF));

    if (companyIndex != -1) {
        updateCompany(empresas, &(*empresas).empresas[companyIndex], ramosAtividade, companyIndex);
    } else {
        puts(ERROR_COMPANY_DONT_EXIST);
    }
}

int searchCompanyIndexByNif(Empresas empresas, int nif) {
    for (int i = 0; i < empresas.contador; i++) {
        if (empresas.empresas[i].nif == nif) {
            return i;
        }
    }
    return -1;
}

int searchBranchIndexByName(RamosAtividade ramosAtividade, char *nome) {
    for (int i = 0; i < ramosAtividade.contador; i++) {
        if (strcmp(ramosAtividade.rAtividade[i].nome, nome) == 0){
            return i;
        }
    }
    return -1;
}

int searchBranchIndexAndState(RamosAtividade ramosAtividade, char *nome){
    int foundBranch;
    for (int i = 0; i < ramosAtividade.contador; i++){
        if (strcmp(ramosAtividade.rAtividade[i].nome, nome) == 0){
            if (ramosAtividade.rAtividade[i].estado == 1){
                foundBranch = 1;
                return i;
            }
        }
    }
    if(!foundBranch){
        puts(MSG_ERROR_INVALID_BRANCH);
    }
    return -1;
}

void createCompanies(Empresas *empresas, RamosAtividade *ramosAtividade) {

    if (empresas->contador == empresas->alocadas) {
        expandCompaniesCapacity(empresas);
    }

    if (empresas->contador < empresas->alocadas) {

        int nif = getInt(MIN_NIF_VALUE, MAX_NIF_VALUE, MSG_GET_NIF);

        if (searchCompanyIndexByNif(*empresas, nif) == -1) {

            empresas->empresas[empresas->contador].nif = nif;

            empresas->empresas[empresas->contador].classis = malloc(sizeof(Classificacao) * INITIAL_CLASSIS);
            if (empresas->empresas[empresas->contador].classis == NULL) {
                exit(EXIT_FAILURE);
            }

            empresas->empresas[empresas->contador].comments = malloc(sizeof(Comentario) * INITIAL_COMMENTS);
            if (empresas->empresas[empresas->contador].comments == NULL) {
                free(empresas->empresas[empresas->contador].classis);
                exit(EXIT_FAILURE);
            }

            do{
                readString(empresas->empresas[empresas->contador].nome, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_NAME);

            } while(validateString(empresas->empresas[empresas->contador].nome) != 1);

            do{
                readString(empresas->empresas[empresas->contador].categoria, MAX_COMPANY_CATEGORY_SIZE, MSG_GET_CATEGORY_NAME);

            } while(validateString(empresas->empresas[empresas->contador].categoria) != 1);

            do{
                readString(empresas->empresas[empresas->contador].ramo_atividade, MAX_COMPANY_BRANCHES_SIZE, MSG_GET_BRANCHES_NAME);
                
            } while (searchBranchIndexAndState(*ramosAtividade, empresas->empresas[empresas->contador].ramo_atividade) == -1);

            do{
                readString(empresas->empresas[empresas->contador].rua, MAX_COMPANY_STREET_SIZE, MSG_GET_STREET_NAME);

            } while(validateString(empresas->empresas[empresas->contador].rua) != 1);

            do{
                readString(empresas->empresas[empresas->contador].location, MAX_COMPANY_LOCATION_SIZE, MSG_GET_LOCATION_NAME);

            } while(validateString(empresas->empresas[empresas->contador].location) != 1);

            do {
                readString(empresas->empresas[empresas->contador].postal_code, MAX_COMPANY_POSTALCODE_SIZE, MSG_GET_POSTALCODE_NAME);

            } while(validatePostalCode(empresas->empresas[empresas->contador].postal_code) != 1);

            empresas->empresas[empresas->contador].estado = 1;
            empresas->empresas[empresas->contador].nClassis = 0;
            empresas->empresas[empresas->contador].nComments = 0;
            empresas->empresas[empresas->contador].nPesquisas = 0;

            puts(MSG_COMPANY_INSERT_SUCESS);
            empresas->contador++;
            saveCompanies(empresas, DATA_FILE);
        }else{
            puts(MSG_COMPANY_INSERT_ERROR);
        }
    }else{
        puts(ERROR_CANT_INSERT_NEW_COMPANY);
    }

}

void createActivityBranches(RamosAtividade *ramosAtividade) {
    if (ramosAtividade->contador == ramosAtividade->alocados) {
        expandBranchesCapacity(ramosAtividade);
    }

    if (ramosAtividade->contador < ramosAtividade->alocados) {

        char nome[MAX_COMPANY_BRANCHES_SIZE];

        do{
            cleanInputBuffer();
            readString(nome, MAX_COMPANY_BRANCHES_SIZE, MSG_GET_BRANCHES_NAME);

        }while(validateString(nome) != 1);

        if (searchBranchIndexByName(*ramosAtividade, nome) == -1) {
            strcpy(ramosAtividade->rAtividade[ramosAtividade->contador].nome, nome);
            ramosAtividade->rAtividade[ramosAtividade->contador].estado = 1;
            puts(MSG_BRANCHES_INSERT_SUCESS);
            ramosAtividade->contador++;
            saveBranches(ramosAtividade, BRANCHES_FILE);
        }else{
            puts(MSG_BRENCHES_ALREADY_EXIST);
        }
    }else {
        puts(ERROR_CANT_INSERT_NEW_BRANCH);
    }
}

void updateActivityBranch(RamosAtividade *listaRamos, RamoAtividade *ramoAtividade, int branchIndex) {
    char option;

    do{
        puts(MSG_CHANGE_BRANCHES_STATE_ACTIVE);
        scanf("%c", &option);
    } while((option != 'Y') && (option != 'N'));

    if (option == 'Y'){
        if ((*ramoAtividade).estado == 0) {
            (*ramoAtividade).estado = 1;
            puts(MSG_BRANCHES_CHANGE_STATE_SUCESS);
        }else{
            puts(MSG_BRANCHES_ALREADY_ACTIVE);
        }
    }

    puts(MSG_BRANCHES_UPDATE_SUCESS);
    updateBranchInFile(*listaRamos, branchIndex, BRANCHES_FILE);
}

void updateActivityBranches(RamosAtividade *ramosAtividade) {
    char nome[MAX_COMPANY_BRANCHES_SIZE];

    do{
        cleanInputBuffer();
        readString(nome, MAX_COMPANY_BRANCHES_SIZE, MSG_GET_BRANCHES_NAME);

    }while(validateString(nome) != 1);

    int indiceRamo = searchBranchIndexByName(*ramosAtividade, nome);

    if (indiceRamo != -1) {
        updateActivityBranch(ramosAtividade ,&(*ramosAtividade).rAtividade[indiceRamo], indiceRamo);
    } else {
        puts(ERROR_BRANCHES_DONT_EXIST);
    }
}

int companyWithBranchName(char *nome, Empresas *empresas) {
    for (int i = 0; i < empresas->contador; i++) {
        if (strcmp(empresas->empresas[i].ramo_atividade, nome) == 0) {
            return i;
        }
    }
    return -1;
}

void removeActivityBranches(RamosAtividade *ramosAtividade, Empresas *empresas) {
    char nome[MAX_COMPANY_BRANCHES_SIZE];

    do{
        cleanInputBuffer();
        readString(nome, MAX_COMPANY_BRANCHES_SIZE, MSG_GET_BRANCHES_NAME);

    }while(validateString(nome) != 1);

    int companyFound = 0;
    int indiceRamo = searchBranchIndexByName(*ramosAtividade, nome);

    if (companyWithBranchName(nome, empresas) == -1){
        companyFound = 1;

        char option;
        do{
            puts(MSG_CHANGE_BRANCHES_STATE);
            scanf(" %c", &option);
        } while((option != 'Y') && (option != 'N'));

        if (option == 'Y'){
            ramosAtividade->rAtividade[indiceRamo].estado = 0;
            puts(MSG_BRANCHES_CHANGE_STATE_SUCESS);
        }
    }

    if(!companyFound){
        puts(ERROR_COMPANY_ALREADY_HAVE_THIS_BRANCHES);
    }
}

void viewReportMaxRating(Empresas *empresas, RamosAtividade *ramosAtividade){
    int found = 0;
    for (int i = 0; i < empresas->contador; i++) {
        if(empresas->empresas[i].estado == 1){
            if(searchBranchIndexAndState(*ramosAtividade, empresas->empresas[i].ramo_atividade) != -1){
                if (empresas->empresas[i].nClassis > 0) {
                    for (int j = 0; j < empresas->empresas[i].nClassis; j++) {
                        if (calculateAverageRating(empresas->empresas[i]) == MAX_RATE) {
                            showCompanyInfo(empresas->empresas[i]);
                            found = 1;
                        }
                    }
                }
            }
        }
    }
    
    if (!found) {
        puts(MSG_NO_COMPANY_WITH_MAX_RATE);
    }
}

void viewReportSameActivityBranch(Empresas *empresas, RamosAtividade *ramosAtividade) {
    char branchName[MAX_COMPANY_BRANCHES_SIZE];
    int foundCompany = 0;

    do {
        cleanInputBuffer();
        readString(branchName, MAX_COMPANY_BRANCHES_SIZE, MSG_GET_BRANCHES_NAME);
    } while (validateString(branchName) != 1);

    for (int i = 0; i < empresas->contador; i++) {
        if (empresas->empresas[i].estado == 1) {
            if(searchBranchIndexAndState(*ramosAtividade, empresas->empresas[i].ramo_atividade) != -1){
                if (strcmp(empresas->empresas[i].ramo_atividade, branchName) == 0) {
                    showCompanyInfo(empresas->empresas[i]);
                    foundCompany = 1;
                }
            }
        }
    }

    if (!foundCompany) {
        puts(MSG_NO_COMPANIES_SAME_BRANCH);
    }
}
