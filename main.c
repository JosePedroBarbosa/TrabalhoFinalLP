#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menus.h"
#include "utils.h"
#include "admin.h"
#include "users.h"
#include "companies.h"
#include "files.h"

#define NUM_EMPRESAS 20
#define NUM_COMENTARIOS 20
#define NUM_RAMOS_ATIVIDADE 20
#define NUM_CLASSIFICACOES 20

int main() {
    int mainOpc, opcSubMenuAdmin, opcSubMenuCompany, opcSubMenuBranch, opcSubMenuReport, opcSubMenuUser;

    // Alocação de memória para Empresas
    Empresas listaEmpresas;
    listaEmpresas.contador = 0;
    listaEmpresas.alocadas = NUM_EMPRESAS;
    listaEmpresas.empresas = malloc(sizeof(Empresa) * listaEmpresas.alocadas);

    if (listaEmpresas.empresas == NULL) {
        // Lida com falha na alocação de memória
        return 1;  // Ou qualquer valor de retorno que faça sentido para o seu programa
    }

    // Inicialização de cada Empresa dentro da lista
    for (int i = 0; i < listaEmpresas.alocadas; i++) {
        listaEmpresas.empresas[i].nClassis = 0;
        listaEmpresas.empresas[i].classis = NULL;  // Inicializa como NULL por enquanto
        listaEmpresas.empresas[i].nComments = 0;
        listaEmpresas.empresas[i].comments = NULL;  // Inicializa como NULL por enquanto
    }

    // Alocação de memória para RamosAtividade
    RamosAtividade rAtividade;
    rAtividade.contador = 0;
    rAtividade.alocados = NUM_RAMOS_ATIVIDADE;
    rAtividade.rAtividade = malloc(sizeof(RamoAtividade) * rAtividade.alocados);

    if (rAtividade.rAtividade == NULL) {
        free(listaEmpresas.empresas);  
        return 1;
    }

    // Alocação de memória para Classificacao e Comentario (dentro da Empresa)
    for (int i = 0; i < listaEmpresas.alocadas; i++) {
        // Alocação de memória para Classificacao
        listaEmpresas.empresas[i].classis = malloc(sizeof(Classificacao) * NUM_CLASSIFICACOES); 

        if (listaEmpresas.empresas[i].classis == NULL) {
            // Lida com falha na alocação de memória
            free(listaEmpresas.empresas);  // Libera a memória alocada anteriormente
            free(rAtividade.rAtividade);   // Libera a memória alocada anteriormente
            return 1;
        }

        // Alocação de memória para Comentario
        listaEmpresas.empresas[i].comments = malloc(sizeof(Comentario) * NUM_COMENTARIOS);  // Exemplo: inicialmente alocando espaço para 20 comentários

        if (listaEmpresas.empresas[i].comments == NULL) {
            // Lida com falha na alocação de memória
            free(listaEmpresas.empresas);  // Libera a memória alocada anteriormente
            free(rAtividade.rAtividade);   // Libera a memória alocada anteriormente
            return 1;
        }

    }
    
    /*if (!loadDataFromFile(&listaEmpresas, &rAtividade)) {
        puts("Erro ao carregar dados do arquivo binário.");
        return 1;
    }*/
        
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
                                        createCompanies(&listaEmpresas, &rAtividade);
                                        saveCompanies(&listaEmpresas);
                                       break;
                                    case 2:
                                        updateCompanies(&listaEmpresas, &rAtividade);
                                       break;
                                    case 3:
                                        removeCompanies(&listaEmpresas);
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
                                        createActivityBranches(&rAtividade);
                                        saveActivityBranches(&rAtividade);
                                       break;
                                    case 2:
                                        updateActivityBranches(&rAtividade);
                                       break;
                                    case 3:
                                        removeActivityBranches(&rAtividade, &listaEmpresas);
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
                                        viewReportMaxRating(&listaEmpresas, &rAtividade);
                                       break;
                                    case 2:
                                        viewReportSameActivityBranch(&listaEmpresas, &rAtividade);
                                       break;
                                    case 0:
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
                            searchCompanies(&listaEmpresas, &rAtividade);
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
                            manageCompanyInfo(&listaEmpresas, &rAtividade);
                            break;
                        case 2:
                            manageComments(&listaEmpresas, &rAtividade);
                            break;
                        case 3:
                            //DEPOIS ALTERAR ISTO PARA OUTRO SITIO DO CODIGO
                            viewReportsSearches(&listaEmpresas, &rAtividade);
                            //uploadCompanies(&listaEmpresas);
                            //uploadActivityBranches(&rAtividade);
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
                /*if (!saveDataToFile(&listaEmpresas, &rAtividade)) {
                    puts("Erro ao salvar dados no arquivo binário.");
                }*/
                puts(APPLICATION_CLOSED);
                break;

            default:
                puts(INVALID_OPTION);
        }

    } while (mainOpc != 4);

    //a sequencia de leitura deve ser de acordo com aquilo que eu aloquei (sequencia de alocacao)
    
    //GUARDAR DADOS DO PROGRAMA EM FICHEIRO E SO DEPOIS LIBERTAMOS A MEMORIA!!
    
    //FALTA LIBERTAR PESQUISAS

    // Carregar dados do arquivo binário
   
    
    // Liberação de memória no final do programa
    for (int i = 0; i < listaEmpresas.alocadas; i++) {
        free(listaEmpresas.empresas[i].classis);
        free(listaEmpresas.empresas[i].comments);
    }

    free(listaEmpresas.empresas);
    free(rAtividade.rAtividade);
    return 0;
}
