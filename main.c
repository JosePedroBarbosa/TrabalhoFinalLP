#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menus.h"
#include "utils.h"
#include "admin.h"
#include "users.h"
#include "companies.h"
#include "files.h"

int main() {
    int mainOpc, opcSubMenuAdmin, opcSubMenuCompany, opcSubMenuBranch, opcSubMenuReport, opcSubMenuUser;
    
    Empresas listaEmpresas;
    
    listaEmpresas.contador = 0;
    listaEmpresas.alocadas = 10;
    listaEmpresas.empresas = malloc(sizeof(Empresa) * listaEmpresas.contador);
    
    if (listaEmpresas.empresas == NULL){
        puts(MEMORY_ALOCATION_ERROR);
        return 1;
    }
    
    //ler(&listaEmpresas);
    logMsg("lER", LOG_FILE);
    
    RamosAtividade rAtividade;
    rAtividade.contador = 0;
    rAtividade.alocados = 10; // tamanho inicial DEVE SER UM N VARIAVEL CONFORME VAMOS PRECISANDO!
    rAtividade.rAtividade = malloc(sizeof(RamosAtividade) * rAtividade.alocados);  // memoria dinamica

    //FALTA ALOCAR MEMORIA PESQUISAS
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
                                        createCompanies(&listaEmpresas, &rAtividade);
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
                                        //RELATORIO EMPRESAS COM MAX RATING (5)
                                        viewReportMaxRating(&listaEmpresas, &rAtividade);
                                       break;
                                    case 2:
                                        viewReportMoreComments(&listaEmpresas, &rAtividade);
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
    
    //SE HOUVER FICHEIRO, CARREGAR DADOS EM MEMORIA, SENAO CRIAR UM FICHEIRO.
    
    //EM NAO GUARDA MOS APONTADORES NEM VARIAVEIS! GUARDAMOS INFORMACAO, QUE PRECISAMOS:
    
    //GUARDAR O CONTADOR PRIMEIRO, O ALOCADAS NAO PRECISAMOS DE ALOCAR! 
    //METER NO FICHEIRO NIF;RAMO;RUA;LOCALIDADE....;nclassis; no classis nao posso enviar o endereço, guardo no ficheiro nota;nomeutilizadoor;email ..;   
    //nComments; no comments nao posso enviar oendereço, guardo no ficheiro, nome ..
    
    //for(int i = 0; i < nClassis - 1; i++){
    //guardar as partes da struct classis
    //}
    
    //for(int i = 0; i < nComments - 1; i++{
    //guardar as partes das struct comments    
    //}
    
    //a sequencia de leitura deve ser de acordo com aquilo que eu aloquei (sequencia de alocacao)
    
    //GUARDAR DADOS DO PROGRAMA EM FICHEIRO E SO DEPOIS LIBERTAMOS A MEMORIA!!
    
    //FALTA LIBERTAR PESQUISAS

    // Carregar dados do arquivo binário
    
    //free(listaEmpresas.empresas);
    //free(rAtividade.rAtividade);
    
    write(&listaEmpresas);
    logMsg("Adicionar", LOG_FILE);
    liberarEmpresas(&listaEmpresas);
    return 0;
}
