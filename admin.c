#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "admin.h"
#include "users.h"
#include "companies.h"
#include "files.h"

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
    
    //administrador deve poder Eliminar, Ocultar comentarios de utiilizadores !!!
    char option;
    int company_state = (*empresa).estado;
    do{
        puts(MSG_CHANGE_COMPANY_STATE);
        scanf("%c", &option);
    } while((option != 'S') && (option != 'N'));
                
    if (option == 'S'){
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
            if((*empresa).comments[i].estado == 1){
                printf("Comentario # %d \n Nome Utilizador: %s \n Titulo: %s \n Texto: %s \n Ativo: %s \n",
                i + 1, (*empresa).comments[i].nomeUtilizador,
                (*empresa).comments[i].titulo, (*empresa).comments[i].texto,
                (*empresa).comments[i].estado == 1 ? "Sim" : "Não");
            }
        }

        do{
            puts("Deseja eliminar / ocultar comentarios? (S/N)");
            scanf(" %c", &opc2);
        } while((opc2 != 'S') && (opc2 != 'N'));
        
        if (opc2 == 'S'){
            do{
                puts("Deseja eliminar ou ocultar comentarios? (E / O)");
                scanf(" %c", &opc3);
            }while((opc3 != 'E') && (opc3 != 'O'));
            
            if (opc3 == 'E'){
                do{
                    puts("Insira Numero do Comentario a remover: ");
                    scanf("%d", &opc);
                }while(opc <= 0 || opc > (*empresa).nComments);
                
                strcpy((*empresa).comments[opc-1].emailUtilizador, "");
                strcpy((*empresa).comments[opc-1].nomeUtilizador, "");
                strcpy((*empresa).comments[opc-1].texto, "");
                strcpy((*empresa).comments[opc-1].titulo, "");
                (*empresa).comments[opc - 1].estado = 0;
                (*empresa).nComments--;
                puts(MSG_COMPANY_UPDATE_SUCESS);
            }else if (opc3 == 'O'){
                do{
                    puts("Insira Numero do Comentario a ocultar: ");
                    scanf("%d", &opc4);
                }while(opc4 <= 0 || opc4 > (*empresa).nComments);
                
                (*empresa).comments[opc4 - 1].estado = 0;
                puts(MSG_COMMENT_UPDATE_SUCESS);
            }
        }else{
            puts(MSG_COMPANY_UPDATE_SUCESS);
        }
    }
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
            
        } while (searchBranchIndexByName(*ramosAtividade, empresas->empresas[empresas->contador].ramo_atividade) == -1);    
        
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
    /*do{
        readString((*ramoAtividade).nome, MAX_COMPANY_BRANCHES_SIZE, MSG_GET_NEW_BRANCHES_NAME);
    } while(validateString((*ramoAtividade).nome) != 1); */
    
    char option;

    do{
        puts(MSG_CHANGE_BRANCHES_STATE_ACTIVE);
        scanf("%c", &option);
    } while((option != 'S') && (option != 'N'));
                
    if (option == 'S'){
        if ((*ramoAtividade).estado == 0) {
            (*ramoAtividade).estado = 1;
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

void viewReportMaxRating(Empresas *empresas, RamosAtividade *ramosAtividade){
    for (int i = 0; i < empresas->contador; i++) {
        if(empresas->empresas[i].estado == 1){
            if(searchBranchIndexAndState(*ramosAtividade, empresas->empresas[i].ramo_atividade) != -1){
                if (empresas->empresas[i].nClassis > 0) {
                    for (int j = 0; j < empresas->empresas[i].nClassis; j++) {
                        if (empresas->empresas[i].classis[j].nota == MAX_RATE) {
                            showCompanyInfo(empresas->empresas[i]);
                        }
                    }
                }
            }
        }
    }
}

void viewReportSameActivityBranch(Empresas *empresas, RamosAtividade *ramosAtividade){
    char branchName[MAX_COMPANY_BRANCHES_SIZE];

    do {
        cleanInputBuffer();
        readString(branchName, MAX_COMPANY_BRANCHES_SIZE, MSG_GET_BRANCHES_NAME);
    } while (searchBranchIndexByName(*ramosAtividade, branchName) == -1);
    
    for (int i = 0; i < empresas->contador; i++) {
        if(empresas->empresas[i].estado == 1){
            if(searchBranchIndexAndState(*ramosAtividade, branchName) != -1){
                if (strcmp(empresas->empresas[i].ramo_atividade, branchName) == 0) {
                    showCompanyInfo(empresas->empresas[i]);
               }
            }
        }
    }
}