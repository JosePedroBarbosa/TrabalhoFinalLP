#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menus.h"
#include "utils.h"
#include "admin.h"
#include "users.h"
#include "companies.h"

int main() {
    int mainOpc, opcSubMenuAdmin, opcSubMenuCompany, opcSubMenuBranch, opcSubMenuReport, opcSubMenuUser;
    
    Empresas listaEmpresas;
    listaEmpresas.contador = 0;
    listaEmpresas.alocadas = 10; // tamanho inicial
    listaEmpresas.empresas = malloc(sizeof(Empresa) * listaEmpresas.alocadas);  // memoria dinamica
    
    if (listaEmpresas.empresas == NULL){
        puts(MEMORY_ALOCATION_ERROR);
        return 1;
    }
    
    RamosAtividade rAtividade;
    rAtividade.contador = 0;
    rAtividade.alocados = 10; // tamanho inicial
    rAtividade.rAtividade = malloc(sizeof(RamosAtividade) * rAtividade.alocados);  // memoria dinamica
    
    if (rAtividade.rAtividade == NULL){
        puts(MEMORY_ALOCATION_ERROR);
        return 1;
    }
    
    do {
        mainOpc = mainMenu();

        switch (mainOpc) {
            case 1: 
                do {
                    opcSubMenuAdmin = menuAdmin();

                    switch (opcSubMenuAdmin) {
                        case 1:
                            do{
                                opcSubMenuCompany = subMenuAdminCatalog();
                                switch(opcSubMenuCompany){
                                    case 1:
                                        criarEmpresa(&listaEmpresas);
                                       break;
                                    case 2:
                                        atualizarEmpresas(&listaEmpresas);
                                       break;
                                    case 3:
                                        removerEmpresas(&listaEmpresas);
                                       break;
                                    case 0:
                                       break;
                                    case -1:
                                        puts(APPLICATION_CLOSED);
                                        return 0;
                                    default:
                                        puts(INVALID_OPTION);
                               }
                            } while (opcSubMenuCompany != 0);
                            break;
                        case 2:
                            do{
                                opcSubMenuBranch = subMenuAdminBranches();
                                switch(opcSubMenuBranch){
                                    case 1:
                                        criarRamosAtividade(&rAtividade);
                                       break;
                                    case 2:
                                        atualizarRamos(&rAtividade);
                                       break;
                                    case 3:
                                        removerRamos(&rAtividade, &listaEmpresas);
                                        break;
                                    case 0:
                                       break;
                                    case -1:
                                        puts(APPLICATION_CLOSED);
                                        return 0;
                                    default:
                                        puts(INVALID_OPTION);
                                   }
                                } while (opcSubMenuBranch != 0);
                            break;
                        case 3:
                            do{
                                opcSubMenuReport = subMenuAdminReport();
                                switch(opcSubMenuReport){
                                    case 1:
                                       //logica Relatorio de Palavras-Chave Mais Procuradas
                                       break;
                                    case 2:
                                       //logica Relatorio de Estatisticas de Uso
                                       break;
                                    case 0:
                                       // Voltar ao Menu Principal
                                       break;
                                    case -1:
                                        puts(APPLICATION_CLOSED);
                                        return 0;
                                    default:
                                        puts(INVALID_OPTION);
                                   }
                                } while (opcSubMenuReport != 0);
                            break;  
                        case 0:
                            break;
                        case -1:
                            puts(APPLICATION_CLOSED);
                            return 0;
                        default:
                            puts(INVALID_OPTION);
                    }
                } while (opcSubMenuAdmin != 0);

                break;

            case 2: 
                do {
                    opcSubMenuUser = userMenu();

                    switch (opcSubMenuUser) {
                        case 1:
                            searchCompanies(&listaEmpresas);
                            break;
                        case 2:
                            rankCompanies(&listaEmpresas);
                            break;
                        case 3:
                            commentCompanies(&listaEmpresas);
                            break;
                        case 0:
                            break;
                        case -1:
                            puts(APPLICATION_CLOSED);
                            return 0;
                        default:
                            puts(INVALID_OPTION);
                    }
                } while (opcSubMenuUser != 0);

                break;
                
            case 3: 
                do {
                    opcSubMenuCompany = companyMenu();

                    switch (opcSubMenuCompany) {
                        case 1:
                            gerirInfosEmpresa(&listaEmpresas);
                            break;
                        case 2:
                            // Lógica para visualizar os seus comentarios (podem ocultar comentários, mas não os poderão eliminar.)...
                            break;
                        case 3:
                            // Lógica para analisar as pesquisas em que esta apareceu,sendo necessário para tal a criação de um relatório específico...
                            break;
                        case 0:
                            break;
                        case -1:
                            puts(APPLICATION_CLOSED);
                            return 0;
                        default:
                            puts(INVALID_OPTION);
                    }
                } while (opcSubMenuCompany != 0);

                break;

            case 4: 
                puts(APPLICATION_CLOSED);
                break;

            default:
                puts(INVALID_OPTION);
        }

    } while (mainOpc != 4);

    return 0;
}