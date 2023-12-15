#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menus.h"
#include "utils.h"
#include "admin.h"
#include "users.h"

void mostrarInfoEmpresa(Empresa empresa){
    printf(UTILS_BARRAS);
    printf(COMPANY_INFO "\n");
    printf(COMPANY_NAME "%s\n", empresa.nome);
    printf(COMPANY_CATEGORY "%s\n", empresa.categoria);
    printf(COMPANY_BRANCHES "%s \n", empresa.ramo_atividade);
    printf(COMPANY_STREET "%s \n", empresa.rua);
    printf(COMPANY_LOCATION "%s \n", empresa.location);
    printf(COMPANY_POSTAL_CODE "%s \n", empresa.postal_code);
    printf(UTILS_BARRAS);
}

void pesquisarEmpresaNome(Empresas *empresas){
    char nomeEmpresa[MAX_COMPANY_NAME_SIZE];
    
    cleanInputBuffer();
    
    do{
        readString(nomeEmpresa, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_NAME);
            
    } while(validarString(nomeEmpresa) != 1);
    
    int empresaEncontrada = 0;
    
    for(int i = 0; i < empresas->contador; i++){
        if(strcmp(empresas->empresas[i].nome, nomeEmpresa) == 0){
            empresaEncontrada = 1;
            mostrarInfoEmpresa(empresas->empresas[i]);
            break; 
        }
    }
    
    if (!empresaEncontrada) {
        puts(COMPANY_NOT_FOUND);
    }
    
}

void pesquisarEmpresaCategoria(Empresas *empresas){
    char categoriaEmpresa[MAX_COMPANY_CATEGORY_SIZE];
    
    cleanInputBuffer();
    
     do{
        readString(categoriaEmpresa, MAX_COMPANY_CATEGORY_SIZE, MSG_GET_CATEGORY_NAME);
            
    } while(validarString(categoriaEmpresa) != 1);
        
  
    int empresaEncontrada = 0;
    
    for(int i = 0; i < empresas->contador; i++){
        if(strcmp(empresas->empresas[i].categoria, categoriaEmpresa) == 0){
            empresaEncontrada = 1;
            mostrarInfoEmpresa(empresas->empresas[i]);
            break; 
        }
    }
    
    if (!empresaEncontrada) {
        puts(COMPANY_NOT_FOUND);
    }
    
}

void pesquisarEmpresaRamo(Empresas *empresas){
    char ramoAtividade[MAX_COMPANY_BRANCHES_SIZE];
    
    cleanInputBuffer();
    
    do{
        readString(ramoAtividade, MAX_COMPANY_BRANCHES_SIZE, MSG_GET_BRANCHES_NAME);
            
    } while(validarString(ramoAtividade) != 1);
    
    int empresaEncontrada = 0;
    
    for(int i = 0; i < empresas->contador; i++){
        if(strcmp(empresas->empresas[i].ramo_atividade, ramoAtividade) == 0){
            empresaEncontrada = 1;
            mostrarInfoEmpresa(empresas->empresas[i]);
            break; 
        }
    }
    
    if (!empresaEncontrada) {
        puts(COMPANY_NOT_FOUND);
    }
    
}

int pesquisarEmpresas(Empresas *empresas){
    int opcSubMenuPesquisar;
    
    do {
        opcSubMenuPesquisar = menuPesquisarEmpresas();

        switch (opcSubMenuPesquisar) {
            case 1:
                pesquisarEmpresaNome(empresas);
                break;
            case 2:
                pesquisarEmpresaCategoria(empresas);
                break;
            case 3:
                pesquisarEmpresaRamo(empresas);
                break;
            case 0:
                break;
            case -1:
                puts(APPLICATION_CLOSED);
                return 0;
            default:
                puts(INVALID_OPTION);
        }
    } while(opcSubMenuPesquisar != 0);
    
}

//VER AQUI PROBLEMA QUANDO TEMOS UMA SEGUNDA EMPRESA ELE MANDA A MSG A DIZER QUE N EXISTE E DEIXA CLASSIFICAR NA MESMA!

void classificarEmpresas(Empresas *empresas){
    char nomeEmpresa[MAX_COMPANY_NAME_SIZE];
        
    cleanInputBuffer();
        
    do{
        readString(nomeEmpresa, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_TO_RATE);
            
    } while(validarString(nomeEmpresa) != 1);
    
    int empresaEncontrada = 0;
        
    for(int i = 0; i < empresas->contador; i++){
        if(strcmp(empresas->empresas[i].nome, nomeEmpresa) == 0){
            empresaEncontrada = 1;
            int rate = getInt(MIN_RATING_VALUE, MAX_RATING_VALUE, MSG_GET_RATING);
            
            //rever isto quando dermos a memoria dinamica!!!
            
            empresas->empresas[i].classis = (Classificacao *)malloc(sizeof(Classificacao));
            
            if (empresas->empresas[i].classis == NULL) {
                return; 
            }
            
            //falta usar o free() para LIBERTAR MEMORIA!
            
            //free(empresas->empresas[i].classis);
            //empresas->empresas[i].classis = NULL;

            empresas->empresas[i].classis->nota = rate;
            empresas->empresas[i].nClassis++;
            puts(COMPANY_RATING_SUCESS);
            break; 
        }
    }
    
    if (!empresaEncontrada) {
        puts(COMPANY_NOT_FOUND);
    }
    
}

void comentarEmpresas(Empresas *empresas){
    char nomeEmpresa[MAX_COMPANY_NAME_SIZE];
    char titulo[MAX_TITLE_SIZE], texto[MAX_TEXT_SIZE], nomeUtilizador[MAX_COMPANY_NAME_SIZE], emailUtilizador[MAX_EMAIL_SIZE];
    
    cleanInputBuffer();
        
    do{
        readString(nomeEmpresa, MAX_COMPANY_NAME_SIZE, MSG_GET_COMPANY_TO_COMMENT);
            
    } while(validarString(nomeEmpresa) != 1);    
    
    int empresaEncontrada = 0;
    
    for(int i = 0; i < empresas->contador; i++){
       if(strcmp(empresas->empresas[i].nome, nomeEmpresa) == 0){
           
        empresaEncontrada = 1;
        
        do{
            readString(nomeUtilizador, MAX_USER_NAME_SIZE, MSG_GET_USER_NAME);
            
        } while(validarString(nomeUtilizador) != 1);
           
        do{
            readString(emailUtilizador, MAX_EMAIL_SIZE, MSG_GET_USER_EMAIL);
            
        } while(validarString(emailUtilizador) != 1);  
        
        do{
            readString(titulo, MAX_COMMENT_TITLE_SIZE, MSG_GET_COMMENT_TITLE);
            
        } while(validarString(titulo) != 1);
        
        do{
            readString(texto, MAX_COMMENT_TEXT_SIZE, MSG_GET_COMMENT_TEXT);
            
        } while(validarString(texto) != 1);
        
        empresas->empresas[i].comments = (Comentario *)malloc(sizeof(Comentario));
        
        if (empresas->empresas[i].comments == NULL) {
            return; 
        }
        
        //falta usar o free() para LIBERTAR MEMORIA!
            
        //free(empresas->empresas[i].classis);
        //empresas->empresas[i].classis = NULL;
        
        strcpy(empresas->empresas[i].comments[empresas->empresas[i].nComments].nomeUtilizador, nomeUtilizador);
        strcpy(empresas->empresas[i].comments[empresas->empresas[i].nComments].emailUtilizador, emailUtilizador);
        strcpy(empresas->empresas[i].comments[empresas->empresas[i].nComments].titulo, titulo);
        strcpy(empresas->empresas[i].comments[empresas->empresas[i].nComments].texto, texto);
        
        empresas->empresas[i].nComments++;
        puts(COMMENT_ADD_SUCESS);
        break;
       }          
    }
    
    if (!empresaEncontrada) {
        puts(COMPANY_NOT_FOUND);
    }
    
}