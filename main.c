#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menus.h"
#include "utils.h"
#include "admin.h"
#include "users.h"
#include "companies.h"

void saveData(const Empresas *empresas, const char *archiveName) {
    FILE *archive = fopen(archiveName, "wb");
    
    if (archive == NULL) {
        perror(ERROR_OPEN_FILE);
        return;
    }

    // Salvar o número de empresas
    fwrite(&empresas->contador, sizeof(int), 1, archive);

    // Salvar cada empresa
    for (int i = 0; i < empresas->contador; i++) {
        // Salvar cada campo da struct Empresa
        fwrite(&empresas->empresas[i].nif, sizeof(int), 1, archive);
        fwrite(&empresas->empresas[i].nome, sizeof(char), 1, archive);
        //adicionar o resto!
    }

    fclose(archive);
}

//FAZER ALTERACOES!
// Função para carregar dados de um arquivo binário
void loadData(Empresas *empresas, const char *archiveName) {
    FILE *archive = fopen(archiveName, "rb");

    if (archive == NULL) {
        perror(ERROR_OPEN_FILE);
        return;
    }

    // Carregar o número de empresas
    fread(&empresas->contador, sizeof(int), 1, archive);

    // Redimensionar o array de empresas se necessário
    if (empresas->contador > empresas->alocadas) {
        empresas->alocadas = empresas->contador;
        empresas->empresas = realloc(empresas->empresas, sizeof(Empresa) * empresas->alocadas);
    }

    // Carregar cada empresa
    for (int i = 0; i < empresas->contador; i++) {
        // Carregar cada campo da struct Empresa
        fread(&empresas->empresas[i], sizeof(Empresa), 1, archive);
    }

    fclose(archive);
}

int main() {
    int mainOpc, opcSubMenuAdmin, opcSubMenuCompany, opcSubMenuBranch, opcSubMenuReport, opcSubMenuUser;
    
    Empresas listaEmpresas;
    listaEmpresas.contador = 0;
    listaEmpresas.alocadas = 10; // tamanho inicial DEVE SER UM N VARIAVEL CONFORME VAMOS PRECISANDO!
    listaEmpresas.empresas = malloc(sizeof(Empresa) * listaEmpresas.alocadas);  // memoria dinamica
    
    if (listaEmpresas.empresas == NULL){
        puts(MEMORY_ALOCATION_ERROR);
        return 1;
    }
    
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
                                        viewReportMaxRating(&listaEmpresas);
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
                            manageCompanyInfo(&listaEmpresas);
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
    
    saveData(&listaEmpresas, "dados.bin");

    // Carregar dados do arquivo binário
    //loadData(&listaEmpresas, "dados.bin");
    
    free(listaEmpresas.empresas);
    free(rAtividade.rAtividade);
    
    return 0;
}