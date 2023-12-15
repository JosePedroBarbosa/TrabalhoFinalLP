#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "admin.h"
#include "users.h"
#include "companies.h"

void removeCompany(Empresa *empresa){
    (*empresa).nif = 0;
    strcpy(empresa->nome, "");
    strcpy(empresa->categoria, "");
    strcpy(empresa->ramo_atividade, "");
    strcpy(empresa->rua, "");
    strcpy(empresa->location, "");
    strcpy(empresa->postal_code, "");
    (*empresa).estado = 0;
    (*empresa).nClassis = 0;
    (*empresa).nComments = 0;
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
        }else{
            puts(MSG_ERROR_HAVE_COMMENTS);
            
            char option;
            do{
                puts(MSG_CHANGE_STATE);
                scanf(" %c", &option);
            } while((option != 'S') && (option != 'N'));
                
            if ((option == 'S')){
                empresas->empresas[indiceEmpresa].estado = 0;
                puts(MSG_COMPANY_INACTIVE);
            }
        }
    }else{
        puts(ERROR_COMPANY_DONT_EXIST);
    }
}

void updateCompany(Empresa *empresa, RamosAtividade *ramosAtividade) {
    do{
        readString((*empresa).nome, MAX_COMPANY_NAME_SIZE, MSG_GET_NEW_COMPANY_NAME);
            
    } while(validateString((*empresa).nome) != 1);
        
    do{
        readString((*empresa).categoria, MAX_COMPANY_CATEGORY_SIZE, MSG_GET_NEW_CATEGORY_NAME);
            
    } while(validateString((*empresa).categoria) != 1);
        
    do{
        readString((*empresa).ramo_atividade, MAX_COMPANY_BRANCHES_SIZE, MSG_GET_NEW_BRANCHES_NAME);
            
    } while (searchBranchIndexAndState(*ramosAtividade, (*empresa).ramo_atividade) == -1);
        
    do{
        readString((*empresa).rua, MAX_COMPANY_STREET_SIZE, MSG_GET_NEW_STREET_NAME);
            
    } while(validateString((*empresa).rua) != 1);
        
    do{
        readString((*empresa).location, MAX_COMPANY_LOCATION_SIZE, MSG_GET_NEW_LOCATION_NAME);
            
    } while(validateString((*empresa).location) != 1);
        
    do {
        readString((*empresa).postal_code, MAX_COMPANY_POSTALCODE_SIZE, MSG_GET_NEW_POSTALCODE_NAME);    
 
    } while(validatePostalCode((*empresa).postal_code) != 1);
    
    //administrador deve poder Eliminar, Ocultar comentarios de utiilizadores !!!
    char option;
    int company_state = (*empresa).estado;
    do{
        puts(MSG_CHANGE_COMPANY_STATE);
        scanf(" %c", &option);
    } while((option != 'S') && (option != 'N'));
                
    if (option == 'S'){
        if (company_state == 0){
            company_state = 1;
            puts(MSG_COMPANY_ACTIVE);
        }else{
            puts(MSG_COMPANY_ALREADY_ACTIVE);
        }
    }
    puts(MSG_COMPANY_UPDATE_SUCESS);

}

void updateCompanies(Empresas *empresas, RamosAtividade *ramosAtividade) {
    int companyIndex = searchCompanyIndexByNif(*empresas, getInt(MIN_NIF_VALUE, MAX_NIF_VALUE, MSG_GET_NIF));

    if (companyIndex != -1) {
        updateCompany(&(*empresas).empresas[companyIndex], ramosAtividade);
    } else {
        puts(ERROR_COMPANY_DONT_EXIST);
    }
}

//procurar O indice da empresa caso exista (nif igual ao inserido.)
int searchCompanyIndexByNif(Empresas empresas, int nif) {
    for (int i = 0; i < empresas.contador; i++) {
        if (empresas.empresas[i].nif == nif) {
            return i;
        }
    }
    return -1; //nif nao encontrado!
}

//procurar o indice do ramo de atividade caso exista (nome ramo igual ao inserido.)
int searchBranchIndexByName(RamosAtividade ramosAtividade, char *nome) {
    for (int i = 0; i < ramosAtividade.contador; i++) {
        if (strcmp(ramosAtividade.rAtividade[i].nome, nome) == 0){
            return i;
        }
    }
    return -1; //nome ramo nao encontrado!
}

int searchBranchIndexAndState(RamosAtividade ramosAtividade, char *nome){
    for (int i = 0; i < ramosAtividade.contador; i++){
        if (strcmp(ramosAtividade.rAtividade[i].nome, nome) == 0){
            if (ramosAtividade.rAtividade[i].estado == 1){
               return i; 
            }
        }
    }
    return -1;
}

//insere os valores inseridos pelo utilizador na empresa correspondente (caso o nif nao esteja registado).
void createCompanies(Empresas *empresas, RamosAtividade *ramosAtividade) {
    int nif = getInt(MIN_NIF_VALUE, MAX_NIF_VALUE, MSG_GET_NIF);
        
    if (empresas->contador < empresas->alocadas){
        if (searchCompanyIndexByNif(*empresas, nif) == -1) {
        empresas->empresas[empresas->contador].nif = nif;
        
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

        puts(MSG_COMPANY_INSERT_SUCESS);
        empresas->contador++;
        }else{
            puts(MSG_COMPANY_INSERT_ERROR);
        }
    }else {
        //devo alocar mais memoria! dar mais alocadas
        puts(MSG_MAX_COMPANYS);
    }
   
}

void createActivityBranches(RamosAtividade *ramosAtividade) {
    char nome[MAX_COMPANY_BRANCHES_SIZE];
    
    do{
        cleanInputBuffer(); 
        readString(nome, MAX_COMPANY_BRANCHES_SIZE, MSG_GET_BRANCHES_NAME);

    }while(validateString(nome) != 1);
    
    if (ramosAtividade->contador < ramosAtividade->alocados){
        if (searchBranchIndexByName(*ramosAtividade, nome) == -1) {
            strcpy(ramosAtividade->rAtividade[ramosAtividade->contador].nome, nome);
            ramosAtividade->rAtividade[ramosAtividade->contador].estado = 1;
            puts(MSG_BRANCHES_INSERT_SUCESS);
            ramosAtividade->contador++;
        }else{
            puts(MSG_BRENCHES_ALREADY_EXIST);
        }
    }else{
        //devo alocar mais memoria! dar mais ramos alocados
        puts(MSG_MAX_COMPANY_BRANCHES);
    } 
}

void updateActivityBranch(RamoAtividade *ramoAtividade) {
    do{
        readString((*ramoAtividade).nome, MAX_COMPANY_BRANCHES_SIZE, MSG_GET_NEW_BRANCHES_NAME);
    } while(validateString((*ramoAtividade).nome) != 1);
    
    char option;
    int branches_state = (*ramoAtividade).estado;
    do{
        puts(MSG_CHANGE_BRANCHES_STATE_ACTIVE);
        scanf("%c", &option);
    } while((option != 'S') && (option != 'N'));
                
    if (option == 'S'){
        if (branches_state == 0){
            branches_state = 1;
            puts(MSG_BRANCHES_CHANGE_STATE_SUCESS);
        }else{
            puts(MSG_BRANCHES_ALREADY_ACTIVE);
        }
    }
      
    puts(MSG_BRANCHES_UPDATE_SUCESS);
}

void updateActivityBranches(RamosAtividade *ramosAtividade) {
    char nome[MAX_COMPANY_BRANCHES_SIZE];
    
    do{
        cleanInputBuffer();
        readString(nome, MAX_COMPANY_BRANCHES_SIZE, MSG_UPDATE_BRANCHES_NAME);
        
     }while(validateString(nome) != 1);
    
    int indiceRamo = searchBranchIndexByName(*ramosAtividade, nome);
    
    if (indiceRamo != -1) {
        updateActivityBranch(&(*ramosAtividade).rAtividade[indiceRamo]);
    } else {
        puts(ERROR_BRANCHES_DONT_EXIST);
    }
}

int companyWithBranchName(char *nome, Empresas *empresas) {
     for (int i = 0; i < empresas->contador; i++) {
        if (strcmp(empresas->empresas[i].ramo_atividade, nome) == 0) {
            printf("Existe ramo com este nome \n");
            return i;
        }
    }
    return -1; //empresa com mesmo nome ramo nao encontrada
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
        //nao existe nenhuma empresa com o nome do ramo de atividade inserido
        
        //neste caso so podemos alterar o estado do ramo para Inativo!
        char option;
        do{
            puts(MSG_CHANGE_BRANCHES_STATE);
            scanf(" %c", &option);
        } while((option != 'S') && (option != 'N'));

        if (option == 'S'){
            ramosAtividade->rAtividade[indiceRamo].estado = 0;
            puts(MSG_BRANCHES_CHANGE_STATE_SUCESS);
        }
    }

    if(!companyFound){
        puts(ERROR_COMPANY_ALREADY_HAVE_THIS_BRANCHES);
    }
}