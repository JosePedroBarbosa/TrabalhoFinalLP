#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menus.h"
#include "utils.h"
#include "admin.h"
#include "companies.h"
#include "files.h"

void manageCompanyNif(Empresas *empresas){
    char companyName[MAX_COMPANY_NAME_SIZE];

    cleanInputBuffer();

    do{
        readString(companyName, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_MANAGE);

    } while(validateString(companyName) != 1);

    int companyFound = 0;

    for (int i = 0; i < empresas->contador; i++) {
        if(strcmp(empresas->empresas[i].nome, companyName) == 0){
            companyFound = 1;
            int nif = getInt(MIN_NIF_VALUE, MAX_NIF_VALUE, MSG_GET_NEW_NIF);
            empresas->empresas[i].nif = nif;
            puts(NIF_CHANGED_SUCESS);
            updateCompanyInFile(*empresas, i, DATA_FILE);
        }
    }

    if(!companyFound){
        puts(ERROR_COMPANY_DONT_EXIST);
    }

}

void manageCompanyName(Empresas *empresas){
    char companyName[MAX_COMPANY_NAME_SIZE];
    char newCompanyName[MAX_COMPANY_NAME_SIZE];

    cleanInputBuffer();

    do{
        readString(companyName, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_MANAGE);

    } while(validateString(companyName) != 1);

    int companyFound = 0;

    for (int i = 0; i < empresas->contador; i++) {
        if(strcmp(empresas->empresas[i].nome, companyName) == 0){
            companyFound = 1;
            do{
                readString(newCompanyName, MAX_COMPANY_NAME_SIZE, MSG_GET_NEW_COMPANY_NAME);

            } while(validateString(newCompanyName) != 1);

            strcpy(empresas->empresas[i].nome, newCompanyName);
            puts(NAME_CHANGED_SUCESS);
            updateCompanyInFile(*empresas, i, DATA_FILE);
        }
    }

    if(!companyFound){
        puts(ERROR_COMPANY_DONT_EXIST);
    }

}

void manageCompanyCategory(Empresas *empresas){
    char companyName[MAX_COMPANY_NAME_SIZE];
    char newCategory[MAX_COMPANY_CATEGORY_SIZE];

    cleanInputBuffer();

    do{
        readString(companyName, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_MANAGE);

    } while(validateString(companyName) != 1);

    int companyFound = 0;

    for (int i = 0; i < empresas->contador; i++) {
        if(strcmp(empresas->empresas[i].nome, companyName) == 0){
            companyFound = 1;
            do{
                readString(newCategory, MAX_COMPANY_CATEGORY_SIZE, MSG_GET_NEW_CATEGORY_NAME);

            } while(validateString(newCategory) != 1);

            strcpy(empresas->empresas[i].categoria, newCategory);
            puts(CATEGORY_CHANGED_SUCESS);
            updateCompanyInFile(*empresas, i, DATA_FILE);
        }
    }

    if(!companyFound){
        puts(ERROR_COMPANY_DONT_EXIST);
    }
}

void manageCompanyBranch(Empresas *empresas, RamosAtividade *rAtividade){
    char companyName[MAX_COMPANY_NAME_SIZE];
    char newBranch[MAX_COMPANY_CATEGORY_SIZE];

    cleanInputBuffer();

    do{
        readString(companyName, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_MANAGE);

    } while(validateString(companyName) != 1);

    int companyFound = 0;

    for (int i = 0; i < empresas->contador; i++) {
        if(strcmp(empresas->empresas[i].nome, companyName) == 0){
            companyFound = 1;
            do{
                readString(newBranch, MAX_COMPANY_BRANCHES_SIZE, MSG_UPDATE_BRANCHES_NAME);

            } while (searchBranchIndexByName(*rAtividade, newBranch) == -1);

            strcpy(empresas->empresas[i].ramo_atividade, newBranch);
            puts(BRANCHES_CHANGED_SUCESS);
            updateCompanyInFile(*empresas, i, DATA_FILE);
        }
    }

    if(!companyFound){
        puts(ERROR_COMPANY_DONT_EXIST);
    }
}

void manageCompanyStreet(Empresas *empresas){
    char companyName[MAX_COMPANY_NAME_SIZE];
    char newStreet[MAX_COMPANY_CATEGORY_SIZE];

    cleanInputBuffer();

    do{
        readString(companyName, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_MANAGE);

    } while(validateString(companyName) != 1);

    int companyFound = 0;

    for (int i = 0; i < empresas->contador; i++) {
        if(strcmp(empresas->empresas[i].nome, companyName) == 0){
            companyFound = 1;
            do{
                readString(newStreet, MAX_COMPANY_STREET_SIZE, MSG_GET_NEW_STREET_NAME);

            } while(validateString(newStreet) != 1);

            strcpy(empresas->empresas[i].rua, newStreet);
            puts(STREET_CHANGED_SUCESS);
            updateCompanyInFile(*empresas, i, DATA_FILE);
        }
    }

    if(!companyFound){
        puts(ERROR_COMPANY_DONT_EXIST);
    }
}

void manageCompanyLocation(Empresas *empresas){
    char companyName[MAX_COMPANY_NAME_SIZE];
    char newLocation[MAX_COMPANY_CATEGORY_SIZE];

    cleanInputBuffer();

    do{
        readString(companyName, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_MANAGE);

    } while(validateString(companyName) != 1);

    int companyFound = 0;

    for (int i = 0; i < empresas->contador; i++) {
        if(strcmp(empresas->empresas[i].nome, companyName) == 0){
            companyFound = 1;
            do{
                readString(newLocation, MAX_COMPANY_LOCATION_SIZE, MSG_GET_NEW_LOCATION_NAME);

            } while(validateString(newLocation) != 1);

            strcpy(empresas->empresas[i].location, newLocation);
            puts(LOCATION_CHANGED_SUCESS);
            updateCompanyInFile(*empresas, i, DATA_FILE);
        }
    }

    if(!companyFound){
        puts(ERROR_COMPANY_DONT_EXIST);
    }
}

void manageCompanyPostalCode(Empresas *empresas){
    char companyName[MAX_COMPANY_NAME_SIZE];
    char newPostalCode[MAX_COMPANY_CATEGORY_SIZE];

    cleanInputBuffer();

    do{
        readString(companyName, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_MANAGE);

    } while(validateString(companyName) != 1);

    int companyFound = 0;

    for (int i = 0; i < empresas->contador; i++) {
        if(strcmp(empresas->empresas[i].nome, companyName) == 0){
            companyFound = 1;
            do{
                readString(newPostalCode, MAX_COMPANY_POSTALCODE_SIZE, MSG_GET_NEW_POSTALCODE_NAME);

            } while(validatePostalCode(newPostalCode) != 1);

            strcpy(empresas->empresas[i].postal_code, newPostalCode);
            puts(POSTAL_CODE_CHANGED_SUCESS);
            updateCompanyInFile(*empresas, i, DATA_FILE);
        }
    }

    if(!companyFound){
        puts(ERROR_COMPANY_DONT_EXIST);
    }
}

void manageCompanyInfo(Empresas *empresas, RamosAtividade *rAtividade){
    int opcSubMenuManage;

    do {
        opcSubMenuManage = menuManageCompanyInfo();

        switch (opcSubMenuManage) {
            case 1:
                manageCompanyNif(empresas);
                break;
            case 2:
                manageCompanyName(empresas);
                break;
            case 3:
                manageCompanyCategory(empresas);
                break;
            case 4:
                manageCompanyBranch(empresas, rAtividade);
                break;
            case 5:
                manageCompanyStreet(empresas);
                break;
            case 6:
                manageCompanyLocation(empresas);
                break;
            case 7:
                manageCompanyPostalCode(empresas);
                break;
            case 0:
                break;
            case -1:
                puts(APPLICATION_CLOSED);
                exit(0);
            default:
                puts(INVALID_OPTION);
        }

    } while(opcSubMenuManage != 0);
}

void manageComments(Empresas *empresas){
    int companyIndex = searchCompanyIndexByNif(*empresas, getInt(MIN_NIF_VALUE, MAX_NIF_VALUE, MSG_GET_NIF));
    char opc2;
    int opc4;

    if(companyIndex != -1){
        if (empresas->empresas[companyIndex].nComments > 0){
            int foundActiveComment = 0;
            for (int i = 0; i < empresas->empresas[companyIndex].nComments; i++) {
                foundActiveComment = 1;
                printf("Comment # %d \n Username: %s \n Title: %s \n Text: %s \n Status: %s \n",
                        i + 1, empresas->empresas[companyIndex].comments[i].nomeUtilizador,
                        empresas->empresas[companyIndex].comments[i].titulo,
                        empresas->empresas[companyIndex].comments[i].texto,
                        empresas->empresas[companyIndex].comments[i].estado == 1 ? "Active" : "Inactive");
            }

            do {
                puts(MSG_HIDE_COMMENTS);
                scanf(" %c", &opc2);
            } while ((opc2 != 'Y') && (opc2 != 'N'));

            if (opc2 == 'Y') {
                do {
                    puts(MSG_NUMBER_COMMENT_TO_HIDE);
                    scanf("%d", &opc4);
                } while (opc4 <= 0 || opc4 > empresas->empresas[companyIndex].nComments);

                empresas->empresas[companyIndex].comments[opc4 - 1].estado = 0;
                puts(MSG_HIDE_COMMENT_SUCESS);
                printf("\n");
            }

            if (!foundActiveComment) {
                printf(COMPANY_DONT_HAVE_ACTIVE_COMMENTS);
            }

        }else{
            puts(COMPANY_DONT_HAVE_COMMENTS);
        }
    }else{
        puts(ERROR_COMPANY_DONT_EXIST);
    }
}

void showCompanySearches(Empresa empresa){
    printf(UTILS_BARS);
    printf(COMPANY_INFO_SEARCHES "\n");
    printf(COMPANY_NUMBER_SEARCHES "%d \n", empresa.nPesquisas);
    printf(UTILS_BARS);
}

void viewReportsSearches(Empresas *empresas, RamosAtividade *rAtividade){
    int companyIndex = searchCompanyIndexByNif(*empresas, getInt(MIN_NIF_VALUE, MAX_NIF_VALUE, MSG_GET_NIF));

    if(companyIndex != -1){
        if(empresas->empresas[companyIndex].estado == 1){
            if(searchBranchIndexAndState(*rAtividade, empresas->empresas[companyIndex].ramo_atividade) != -1){
                showCompanySearches(empresas->empresas[companyIndex]);
            }
        }
    }else{
        puts(ERROR_COMPANY_DONT_EXIST);
    }

}