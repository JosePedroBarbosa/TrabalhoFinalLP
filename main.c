#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menus.h"
#include "utils.h"
#include "admin.h"
#include "users.h"
#include "companies.h"

int main() {
    int opcPrincipal, opcSubMenuAdmin, opcSubMenuEmpresa, opcSubMenuRamo, opcSubMenuRelatorio, opcSubMenuUtilizador;
    
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
        opcPrincipal = menuPrincipal();

        switch (opcPrincipal) {
            case 1: // Administrador
                do {
                    opcSubMenuAdmin = menuAdministrador();

                    switch (opcSubMenuAdmin) {
                        case 1:
                            do{
                                opcSubMenuEmpresa = subMenuAdminCatalogo();
                                switch(opcSubMenuEmpresa){
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
                            } while (opcSubMenuEmpresa != 0);
                            break;
                        case 2:
                            do{
                                opcSubMenuRamo = subMenuAdminRamo();
                                switch(opcSubMenuRamo){
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
                                } while (opcSubMenuRamo != 0);
                            break;
                        case 3:
                            do{
                                opcSubMenuRelatorio = subMenuAdminRelatorio();
                                switch(opcSubMenuRelatorio){
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
                                } while (opcSubMenuRelatorio != 0);
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
                } while (opcSubMenuAdmin != 0);

                break;

            case 2: // Utilizador
                do {
                    opcSubMenuUtilizador = menuUtilizador();

                    switch (opcSubMenuUtilizador) {
                        case 1:
                            pesquisarEmpresas(&listaEmpresas);
                            break;
                        case 2:
                            classificarEmpresas(&listaEmpresas);
                            break;
                        case 3:
                            comentarEmpresas(&listaEmpresas);
                            break;
                        case 0:
                            break;
                        case -1:
                            puts(APPLICATION_CLOSED);
                            return 0;
                        default:
                            puts(INVALID_OPTION);
                    }
                } while (opcSubMenuUtilizador != 0);

                break;
                
            case 3: // Empresa
                do {
                    opcSubMenuEmpresa = menuEmpresa();

                    switch (opcSubMenuEmpresa) {
                        case 1:
                            gerirInfosEmpresa(&listaEmpresas);
                            // Lógica para gerir as suas informacoes...
                            break;
                        case 2:
                            // Lógica para visualizar os seus comentarios (podem ocultar comentários, mas não os poderão eliminar.)...
                            break;
                        case 3:
                            // Lógica para analisar as pesquisas em que esta apareceu,sendo necessário para tal a criação de um relatório específico...
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
                } while (opcSubMenuEmpresa != 0);

                break;

            case 4: // Sair
                puts(APPLICATION_CLOSED);
                break;

            default:
                puts(INVALID_OPTION);
        }

    } while (opcPrincipal != 4);

    return 0;
}