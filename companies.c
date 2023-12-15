#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menus.h"
#include "utils.h"
#include "admin.h"
#include "companies.h"

void gerirNifEmpresa(Empresas *empresas){
    char nomeEmpresa[MAX_COMPANY_NAME_SIZE];
    
    cleanInputBuffer();
        
    do{
        readString(nomeEmpresa, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_MANAGE);
            
    } while(validarString(nomeEmpresa) != 1);
    
    int empresaEncontrada = 0;
    
    for (int i = 0; i < empresas->contador; i++) {
        if(strcmp(empresas->empresas[i].nome, nomeEmpresa) == 0){
            empresaEncontrada = 1;
            int nif = getInt(MIN_NIF_VALUE, MAX_NIF_VALUE, MSG_GET_NIF);
            empresas->empresas[i].nif = nif;
            puts(NIF_CHANGED_SUCESS);
        }
    }
    
    if(!empresaEncontrada){
        puts(ERROR_COMPANY_DONT_EXIST);
    }
    
}

void gerirNomeEmpresa(Empresas *empresas){
    char nomeEmpresa[MAX_COMPANY_NAME_SIZE];
    char novoNomeEmpresa[MAX_COMPANY_NAME_SIZE];
    
    cleanInputBuffer();
        
    do{
        readString(nomeEmpresa, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_MANAGE);
            
    } while(validarString(nomeEmpresa) != 1);
    
    int empresaEncontrada = 0;
    
    for (int i = 0; i < empresas->contador; i++) {
        if(strcmp(empresas->empresas[i].nome, nomeEmpresa) == 0){ 
            empresaEncontrada = 1;
            do{
                readString(novoNomeEmpresa, MAX_COMPANY_NAME_SIZE, MSG_CHANGE_NAME);
            
            } while(validarString(novoNomeEmpresa) != 1);

            strcpy(empresas->empresas[i].nome, novoNomeEmpresa);
            puts(NAME_CHANGED_SUCESS);
        }
    }
    
    if(!empresaEncontrada){
        puts(ERROR_COMPANY_DONT_EXIST);
    }
    
}

void gerirCategoriaEmpresa(Empresas *empresas){
    char nomeEmpresa[MAX_COMPANY_NAME_SIZE];
    char novaCategoria[MAX_COMPANY_CATEGORY_SIZE];
    
    cleanInputBuffer();
    
    do{
        readString(nomeEmpresa, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_MANAGE);
            
    } while(validarString(nomeEmpresa) != 1);
    
    int empresaEncontrada = 0;
    
    for (int i = 0; i < empresas->contador; i++) {
        if(strcmp(empresas->empresas[i].nome, nomeEmpresa) == 0){ 
            empresaEncontrada = 1;
            do{
                readString(novaCategoria, MAX_COMPANY_CATEGORY_SIZE, MSG_CHANGE_CATEGORY);
            
            } while(validarString(novaCategoria) != 1);

            strcpy(empresas->empresas[i].categoria, novaCategoria);
            puts(CATEGORY_CHANGED_SUCESS);
        }
    }
    
    if(!empresaEncontrada){
        puts(ERROR_COMPANY_DONT_EXIST);
    }
}

void gerirRamoEmpresa(Empresas *empresas){
    char nomeEmpresa[MAX_COMPANY_NAME_SIZE];
    char novoRamo[MAX_COMPANY_CATEGORY_SIZE];
    
    cleanInputBuffer();
    
    do{
        readString(nomeEmpresa, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_MANAGE);
            
    } while(validarString(nomeEmpresa) != 1);
    
    int empresaEncontrada = 0;
    
    for (int i = 0; i < empresas->contador; i++) {
        if(strcmp(empresas->empresas[i].nome, nomeEmpresa) == 0){ 
            empresaEncontrada = 1;
            do{
                readString(novoRamo, MAX_COMPANY_BRANCHES_SIZE, MSG_CHANGE_BRANCHES);
            
            } while(validarString(novoRamo) != 1);

            strcpy(empresas->empresas[i].ramo_atividade, novoRamo);
            puts(BRANCHES_CHANGED_SUCESS);
        }
    }
    
    if(!empresaEncontrada){
        puts(ERROR_COMPANY_DONT_EXIST);
    }
}

void gerirRuaEmpresa(Empresas *empresas){
    char nomeEmpresa[MAX_COMPANY_NAME_SIZE];
    char novaRua[MAX_COMPANY_CATEGORY_SIZE];
    
    cleanInputBuffer();
    
    do{
        readString(nomeEmpresa, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_MANAGE);
            
    } while(validarString(nomeEmpresa) != 1);
    
    int empresaEncontrada = 0;
    
    for (int i = 0; i < empresas->contador; i++) {
        if(strcmp(empresas->empresas[i].nome, nomeEmpresa) == 0){ 
            empresaEncontrada = 1;
            do{
                readString(novaRua, MAX_COMPANY_STREET_SIZE, MSG_CHANGE_STREET);
            
            } while(validarString(novaRua) != 1);

            strcpy(empresas->empresas[i].rua, novaRua);
            puts(STREET_CHANGED_SUCESS);
        }
    }
    
    if(!empresaEncontrada){
        puts(ERROR_COMPANY_DONT_EXIST);
    }
}

void gerirLocalidadeEmpresa(Empresas *empresas){
    char nomeEmpresa[MAX_COMPANY_NAME_SIZE];
    char novaLocalidade[MAX_COMPANY_CATEGORY_SIZE];
    
    cleanInputBuffer();
    
    do{
        readString(nomeEmpresa, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_MANAGE);
            
    } while(validarString(nomeEmpresa) != 1);
    
    int empresaEncontrada = 0;
    
    for (int i = 0; i < empresas->contador; i++) {
        if(strcmp(empresas->empresas[i].nome, nomeEmpresa) == 0){ 
            empresaEncontrada = 1;
            do{
                readString(novaLocalidade, MAX_COMPANY_LOCATION_SIZE, MSG_CHANGE_LOCATION);
            
            } while(validarString(novaLocalidade) != 1);

            strcpy(empresas->empresas[i].location, novaLocalidade);
            puts(LOCATION_CHANGED_SUCESS);
        }
    }
    
    if(!empresaEncontrada){
        puts(ERROR_COMPANY_DONT_EXIST);
    }
}

void gerirCodigoPostalEmpresa(Empresas *empresas){
    char nomeEmpresa[MAX_COMPANY_NAME_SIZE];
    char novoCodigoPostal[MAX_COMPANY_CATEGORY_SIZE];
    
    cleanInputBuffer();
    
    do{
        readString(nomeEmpresa, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_MANAGE);
            
    } while(validarString(nomeEmpresa) != 1);
    
    int empresaEncontrada = 0;
    
    for (int i = 0; i < empresas->contador; i++) {
        if(strcmp(empresas->empresas[i].nome, nomeEmpresa) == 0){ 
            empresaEncontrada = 1;
            do{
                readString(novoCodigoPostal, MAX_COMPANY_POSTALCODE_SIZE, MSG_CHANGE_POSTAL_CODE);
            
            } while(validarString(novoCodigoPostal) != 1);

            strcpy(empresas->empresas[i].postal_code, novoCodigoPostal);
            puts(POSTAL_CODE_CHANGED_SUCESS);
        }
    }
    
    if(!empresaEncontrada){
        puts(ERROR_COMPANY_DONT_EXIST);
    }
}

int gerirInfosEmpresa(Empresas *empresas){
    int opcSubMenuGerirEmpresa;
    
    do {
        opcSubMenuGerirEmpresa = menuGerirInformacoes();

        switch (opcSubMenuGerirEmpresa) {
            case 1:
                gerirNifEmpresa(empresas);
                break;
            case 2:
                gerirNomeEmpresa(empresas);
                break;
            case 3:
                gerirCategoriaEmpresa(empresas);
                break;
            case 4:
                gerirRamoEmpresa(empresas);
                break;
            case 5:
                gerirRuaEmpresa(empresas);
                break;
            case 6: 
                gerirLocalidadeEmpresa(empresas);
                break;
            case 7: 
                gerirCodigoPostalEmpresa(empresas);
                break;
            case 0:
                break;
            case -1:
                puts(APPLICATION_CLOSED);
                return 0;
            default:
                puts(INVALID_OPTION);
        }
    } while(opcSubMenuGerirEmpresa != 0);
    
}