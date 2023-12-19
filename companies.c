#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menus.h"
#include "utils.h"
#include "admin.h"
#include "companies.h"

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
                readString(newCompanyName, MAX_COMPANY_NAME_SIZE, MSG_CHANGE_NAME);
            
            } while(validateString(newCompanyName) != 1);

            strcpy(empresas->empresas[i].nome, newCompanyName);
            puts(NAME_CHANGED_SUCESS);
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
                readString(newCategory, MAX_COMPANY_CATEGORY_SIZE, MSG_CHANGE_CATEGORY);
            
            } while(validateString(newCategory) != 1);

            strcpy(empresas->empresas[i].categoria, newCategory);
            puts(CATEGORY_CHANGED_SUCESS);
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
                readString(newBranch, MAX_COMPANY_BRANCHES_SIZE, MSG_CHANGE_BRANCHES);
            
            } while (searchBranchIndexByName(*rAtividade, newBranch) == -1);

            strcpy(empresas->empresas[i].ramo_atividade, newBranch);
            puts(BRANCHES_CHANGED_SUCESS);
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
                readString(newStreet, MAX_COMPANY_STREET_SIZE, MSG_CHANGE_STREET);
            
            } while(validateString(newStreet) != 1);

            strcpy(empresas->empresas[i].rua, newStreet);
            puts(STREET_CHANGED_SUCESS);
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
                readString(newLocation, MAX_COMPANY_LOCATION_SIZE, MSG_CHANGE_LOCATION);
            
            } while(validateString(newLocation) != 1);

            strcpy(empresas->empresas[i].location, newLocation);
            puts(LOCATION_CHANGED_SUCESS);
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
                readString(newPostalCode, MAX_COMPANY_POSTALCODE_SIZE, MSG_CHANGE_POSTAL_CODE);
            
            } while(validateString(newPostalCode) != 1);

            strcpy(empresas->empresas[i].postal_code, newPostalCode);
            puts(POSTAL_CODE_CHANGED_SUCESS);
        }
    }
    
    if(!companyFound){
        puts(ERROR_COMPANY_DONT_EXIST);
    }
}

int manageCompanyInfo(Empresas *empresas, RamosAtividade *rAtividade){
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