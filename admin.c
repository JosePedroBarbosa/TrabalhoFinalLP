#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "admin.h"
#include "users.h"
#include "companies.h"

void removerEmpresa(Empresa *empresa){
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

void removerEmpresas(Empresas *empresas) {
    int i;
    int indiceEmpresa = procurarEmpresa(*empresas, getInt(MIN_NIF_VALUE, MAX_NIF_VALUE, MSG_GET_NIF));

    if(indiceEmpresa != -1){
        if (empresas->empresas[indiceEmpresa].nComments == 0){
            for (i = indiceEmpresa; i < empresas->contador - 1; i++) {
                empresas->empresas[i] = empresas->empresas[i + 1];
            }
            removerEmpresa(&empresas->empresas[i]);

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

void atualizarEmpresa(Empresa *empresa) {
    do{
        readString((*empresa).nome, MAX_COMPANY_NAME_SIZE, MSG_GET_NEW_COMPANY_NAME);
            
    } while(validarString((*empresa).nome) != 1);
        
    do{
        readString((*empresa).categoria, MAX_COMPANY_CATEGORY_SIZE, MSG_GET_NEW_CATEGORY_NAME);
            
    } while(validarString((*empresa).categoria) != 1);
        
    do{
        readString((*empresa).ramo_atividade, MAX_COMPANY_BRANCHES_SIZE, MSG_GET_NEW_BRANCHES_NAME);
            
    } while(validarString((*empresa).ramo_atividade) != 1);
        
    do{
        readString((*empresa).rua, MAX_COMPANY_STREET_SIZE, MSG_GET_NEW_STREET_NAME);
            
    } while(validarString((*empresa).rua) != 1);
        
    do{
        readString((*empresa).location, MAX_COMPANY_LOCATION_SIZE, MSG_GET_NEW_LOCATION_NAME);
            
    } while(validarString((*empresa).location) != 1);
        
    do {
        readString((*empresa).postal_code, MAX_COMPANY_POSTALCODE_SIZE, MSG_GET_NEW_POSTALCODE_NAME);    
 
    } while(validarCodigoPostal((*empresa).postal_code) != 1);
    
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

void atualizarEmpresas(Empresas *empresas) {
    int nif = procurarEmpresa(*empresas, getInt(MIN_NIF_VALUE, MAX_NIF_VALUE, MSG_GET_NIF));

    if (nif != -1) {
        atualizarEmpresa(&(*empresas).empresas[nif]);
    } else {
        puts(ERROR_COMPANY_DONT_EXIST);
    }
}

//procurar O indice da empresa caso exista (nif igual ao inserido.)
int procurarEmpresa(Empresas empresas, int nif) {
    for (int i = 0; i < empresas.contador; i++) {
        if (empresas.empresas[i].nif == nif) {
            return i;
        }
    }
    return -1; //nif nao encontrado!
}

//insere os valores inseridos pelo utilizador na empresa correspondente (caso o nif nao esteja registado).
int criarEmpresa(Empresas *empresas) {
    int nif = getInt(MIN_NIF_VALUE, MAX_NIF_VALUE, MSG_GET_NIF);
        
    if (empresas->contador < empresas->alocadas){
        if (procurarEmpresa(*empresas, nif) == -1) {
        empresas->empresas[empresas->contador].nif = nif;
        
        do{
            readString(empresas->empresas[empresas->contador].nome, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_NAME);
            
        } while(validarString(empresas->empresas[empresas->contador].nome) != 1);
        
        do{
            readString(empresas->empresas[empresas->contador].categoria, MAX_COMPANY_CATEGORY_SIZE, MSG_GET_CATEGORY_NAME);
            
        } while(validarString(empresas->empresas[empresas->contador].categoria) != 1);
        
        do{
            readString(empresas->empresas[empresas->contador].ramo_atividade, MAX_COMPANY_BRANCHES_SIZE, MSG_GET_BRANCHES_NAME);
            
        } while(validarString(empresas->empresas[empresas->contador].ramo_atividade) != 1);
        
        do{
            readString(empresas->empresas[empresas->contador].rua, MAX_COMPANY_STREET_SIZE, MSG_GET_STREET_NAME);
            
        } while(validarString(empresas->empresas[empresas->contador].rua) != 1);
        
        do{
            readString(empresas->empresas[empresas->contador].location, MAX_COMPANY_LOCATION_SIZE, MSG_GET_LOCATION_NAME);
            
        } while(validarString(empresas->empresas[empresas->contador].location) != 1);
        
        do {
            readString(empresas->empresas[empresas->contador].postal_code, MAX_COMPANY_POSTALCODE_SIZE, MSG_GET_POSTALCODE_NAME);    
 
        } while(validarCodigoPostal(empresas->empresas[empresas->contador].postal_code) != 1);
        
        empresas->empresas[empresas->contador].estado = 1;
        empresas->empresas[empresas->contador].nClassis = 0;
        empresas->empresas[empresas->contador].nComments = 0;

        puts(MSG_COMPANY_INSERT_SUCESS);
        return empresas->contador++;
        }else{
            puts(MSG_COMPANY_INSERT_ERROR);
        }
    }else {
        puts(MSG_MAX_COMPANYS);
    }
    
    return -1;
}

//procurar O indice do ramo de atividade caso exista (nome igual ao inserido.)
int procurarRamo(RamosAtividade ramosAtividade, char *nome) {
    for (int i = 0; i < ramosAtividade.contador; i++) {
        if (strcmp(ramosAtividade.rAtividade[i].nome, nome) == 0){
            return i;
        }
    }
    return -1; //nome ramo nao encontrado!
}

void criarRamosAtividade(RamosAtividade *ramosAtividade) {
    char nome[MAX_COMPANY_BRANCHES_SIZE];
    
    do{
        cleanInputBuffer(); 
        readString(nome, MAX_COMPANY_CATEGORY_SIZE, MSG_GET_CATEGORY_NAME);

    }while(validarString(nome) != 1);
    
    if (ramosAtividade->contador < ramosAtividade->alocados){
        if (procurarRamo(*ramosAtividade, nome) == -1) {
            strcpy(ramosAtividade->rAtividade[ramosAtividade->contador].nome, nome);
            ramosAtividade->rAtividade[ramosAtividade->contador].estado = 1;
            puts(MSG_BRANCHES_INSERT_SUCESS);
            ramosAtividade->contador++;
        }else{
            puts(MSG_BRENCHES_ALREADY_EXIST);
        }
    }else{
        puts(MSG_MAX_COMPANY_BRANCHES);
    } 
}

void atualizarRamo(RamoAtividade *ramoAtividade) {
    do{
        readString((*ramoAtividade).nome, MAX_COMPANY_BRANCHES_SIZE, MSG_GET_NEW_BRANCHES_NAME);
    } while(validarString((*ramoAtividade).nome) != 1);
    
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

void atualizarRamos(RamosAtividade *ramosAtividade) {
    char nome[MAX_COMPANY_BRANCHES_SIZE];
    
    do{
        cleanInputBuffer();
        readString(nome, MAX_COMPANY_BRANCHES_SIZE, MSG_UPDATE_BRANCHES_NAME);
        
     }while(validarString(nome) != 1);
    
    int indiceRamo = procurarRamo(*ramosAtividade, nome);
    
    if (indiceRamo != -1) {
        atualizarRamo(&(*ramosAtividade).rAtividade[indiceRamo]);
    } else {
        puts(ERROR_BRANCHES_DONT_EXIST);
    }
}

int empresaComRamo(char *nome, Empresas *empresas) {
     for (int i = 0; i < empresas->contador; i++) {
        if (strcmp(empresas->empresas[i].ramo_atividade, nome) == 0) {
            return i;
        }
    }
    return -1; //empresa com mesmo nome ramo nao encontrada
}

void removerRamos(RamosAtividade *ramosAtividade, Empresas *empresas) {
    char nome[MAX_COMPANY_BRANCHES_SIZE];
    
    do{
        cleanInputBuffer();
        readString(nome, MAX_COMPANY_BRANCHES_SIZE, MSG_GET_BRANCHES_NAME);
        
    }while(validarString(nome) != 1);
     
    int indiceRamo = procurarRamo(*ramosAtividade, nome);
    
    if (empresaComRamo(nome, empresas) == -1){
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
    }else{
        puts(ERROR_COMPANY_ALREADY_HAVE_THIS_BRANCHES);
        //existe uma empresa com o nome do ramo de atividade inserido pelo admin
    }
}