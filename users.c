#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menus.h"
#include "utils.h"
#include "admin.h"
#include "users.h"

float calculateAverageRating(Empresa empresa){
    float media = 0.0;
    
    if (empresa.nClassis > 0){
        media = (float)empresa.classis->nota / empresa.nClassis;
    }
    
    return media;
}

void showCompanyInfo(Empresa empresa){
    printf(UTILS_BARRAS);
    printf(COMPANY_INFO "\n");
    printf(COMPANY_AVERAGE_RATING "%.2f \n", calculateAverageRating(empresa));
    printf(COMPANY_NIF "%d\n", empresa.nif);
    printf(COMPANY_NAME "%s\n", empresa.nome);
    printf(COMPANY_CATEGORY "%s\n", empresa.categoria);
    printf(COMPANY_BRANCHES "%s \n", empresa.ramo_atividade);
    printf(COMPANY_STREET "%s \n", empresa.rua);
    printf(COMPANY_LOCATION "%s \n", empresa.location);
    printf(COMPANY_POSTAL_CODE "%s \n", empresa.postal_code);
    printf(UTILS_BARRAS);
}

void searchCompanyByName(Empresas *empresas, RamosAtividade *ramosAtividade){
    char companyName[MAX_COMPANY_NAME_SIZE];
    
    cleanInputBuffer();
    
    do{
        readString(companyName, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_NAME);
            
    } while(validateString(companyName) != 1);
    
    int companyFound = 0;
    
    for(int i = 0; i < empresas->contador; i++){
        if(strcmp(empresas->empresas[i].nome, companyName) == 0){
            if(empresas->empresas[i].estado == 1){
                if(searchBranchIndexAndState(*ramosAtividade, empresas->empresas[i].ramo_atividade) != -1 ){
                    companyFound = 1;
                    showCompanyInfo(empresas->empresas[i]);
                    empresas->empresas[i].nPesquisas++;
                }
            }
        }
    }
    
    if (!companyFound) {
        puts(COMPANY_NOT_FOUND);
    }
    
}

void searchCompanyByCategory(Empresas *empresas, RamosAtividade *ramosAtividade){
    char companyCategory[MAX_COMPANY_CATEGORY_SIZE];
    
    cleanInputBuffer();
    
     do{
        readString(companyCategory, MAX_COMPANY_CATEGORY_SIZE, MSG_GET_CATEGORY_NAME);
            
    } while(validateString(companyCategory) != 1);
        
    int companyFound = 0;
    
    for(int i = 0; i < empresas->contador; i++){
        if(strcmp(empresas->empresas[i].categoria, companyCategory) == 0){
            if(empresas->empresas[i].estado == 1){
                if(searchBranchIndexAndState(*ramosAtividade, empresas->empresas[i].ramo_atividade) != -1 ){
                    companyFound = 1;
                    showCompanyInfo(empresas->empresas[i]);
                    empresas->empresas[i].nPesquisas++;
                }
            }
        }
    }
    
    if (!companyFound) {
        puts(COMPANY_NOT_FOUND);
    }
    
}

void searchCompanyByBranch(Empresas *empresas, RamosAtividade *ramosAtividade){
    char companyBranch[MAX_COMPANY_BRANCHES_SIZE];

    cleanInputBuffer();
    
    do{
        readString(companyBranch, MAX_COMPANY_BRANCHES_SIZE, MSG_GET_BRANCHES_NAME);
            
    } while(validateString(companyBranch) != 1);
    
    int companyFound = 0;
    
    for(int i = 0; i < empresas->contador; i++){
        if(strcmp(empresas->empresas[i].ramo_atividade, companyBranch) == 0){
            if(empresas->empresas[i].estado == 1){
                if(searchBranchIndexAndState(*ramosAtividade, empresas->empresas[i].ramo_atividade) != -1 ){
                    companyFound = 1;
                    showCompanyInfo(empresas->empresas[i]);
                    empresas->empresas[i].nPesquisas++;
                }
            }
        }
    }
    
    if (!companyFound) {
        puts(COMPANY_NOT_FOUND);
    }
    
}

int searchCompanies(Empresas *empresas, RamosAtividade *rAtividade){
    int opcSubMenuSearch;
    
    do {
        opcSubMenuSearch = menuSearchCompanies();

        switch (opcSubMenuSearch) {
            case 1:
                searchCompanyByName(empresas, rAtividade);
                break;
            case 2:
                searchCompanyByCategory(empresas, rAtividade);
                break;
            case 3:
                searchCompanyByBranch(empresas, rAtividade);
                break;
            case 0:
                break;
            case -1:
                puts(APPLICATION_CLOSED);
                exit(0); 
            default:
                puts(INVALID_OPTION);
        }
    } while(opcSubMenuSearch != 0);
    
}

void rankCompanies(Empresas *empresas) {
    char companyName[MAX_COMPANY_NAME_SIZE];

    cleanInputBuffer();

    do {
        readString(companyName, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_TO_RATE);

    } while (validateString(companyName) != 1);

    int companyFound = 0;

    for (int i = 0; i < empresas->contador; i++) {
        if (strcmp(empresas->empresas[i].nome, companyName) == 0) {
            companyFound = 1;
            float rate = getFloat(MIN_RATING_VALUE, MAX_RATING_VALUE, MSG_GET_RATING);

            if (empresas->empresas[i].nClassis == 0) {
                empresas->empresas[i].classis->nota = 0.0;
            }

            empresas->empresas[i].classis->nota += rate;
            
            empresas->empresas[i].nClassis++;

            puts(COMPANY_RATING_SUCCESS);
            break;
        }
    }

    if (!companyFound) {
        puts(COMPANY_NOT_FOUND);
    }
}

void commentCompanies(Empresas *empresas){
    char companyName[MAX_COMPANY_NAME_SIZE];
    char title[MAX_TITLE_SIZE], text[MAX_TEXT_SIZE], userName[MAX_COMPANY_NAME_SIZE], userEmail[MAX_EMAIL_SIZE];
    
    cleanInputBuffer();
        
    do{
        readString(companyName, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_TO_COMMENT);
            
    } while(validateString(companyName) != 1);    
    
    int companyFound = 0;
    
    for(int i = 0; i < empresas->contador; i++){
       if(strcmp(empresas->empresas[i].nome, companyName) == 0){
           
        companyFound = 1;
        
        do{
            readString(userName, MAX_USER_NAME_SIZE, MSG_GET_USER_NAME);
            
        } while(validateString(userName) != 1);
           
        do{
            readString(userEmail, MAX_EMAIL_SIZE, MSG_GET_USER_EMAIL);
            
        } while(validateString(userEmail) != 1);  
        
        do{
            readString(title, MAX_COMMENT_TITLE_SIZE, MSG_GET_COMMENT_TITLE);
            
        } while(validateString(title) != 1);
        
        do{
            readString(text, MAX_COMMENT_TEXT_SIZE, MSG_GET_COMMENT_TEXT);
            
        } while(validateString(text) != 1);
        
        strcpy(empresas->empresas[i].comments[empresas->empresas[i].nComments].nomeUtilizador, userName);
        strcpy(empresas->empresas[i].comments[empresas->empresas[i].nComments].emailUtilizador, userEmail);
        strcpy(empresas->empresas[i].comments[empresas->empresas[i].nComments].titulo, title);
        strcpy(empresas->empresas[i].comments[empresas->empresas[i].nComments].texto, text);
        empresas->empresas[i].comments->estado = 1;
        
        empresas->empresas[i].nComments++;
        puts(COMMENT_ADD_SUCESS);
        break;
       }          
    }
    
    if (!companyFound) {
        puts(COMPANY_NOT_FOUND);
    }
    
}