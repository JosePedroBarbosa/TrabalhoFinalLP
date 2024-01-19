#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "admin.h"
#include "files.h"
#include "users.h"
#include "companies.h"

int main() {
    int mainOption, opcSubMenuAdmin, opcSubMenuCompany, opcSubMenuBranch, opcSubMenuReport, opcSubMenuUser;

    Empresas listaEmpresas;
    loadCompanies(&listaEmpresas, DATA_FILE);

    RamosAtividade rAtividade;
    loadBranches(&rAtividade, BRANCHES_FILE);

    do {
        mainOption = mainMenu();

        switch (mainOption) {
            case 1:
                system("clear");
                do {
                    opcSubMenuAdmin = menuAdmin();

                    switch (opcSubMenuAdmin) {
                        case 1:
                            system("clear");
                            do {
                                opcSubMenuCompany = subMenuAdminCatalog();
                                switch (opcSubMenuCompany) {
                                    case 1:
                                        system("clear");
                                        createCompanies(&listaEmpresas, &rAtividade);
                                        break;
                                    case 2:
                                        system("clear");
                                        updateCompanies(&listaEmpresas, &rAtividade);
                                        break;
                                    case 3:
                                        system("clear");
                                        removeCompanies(&listaEmpresas);
                                        break;
                                    case 0:
                                        system("clear");
                                        break;
                                    case -1:
                                        puts(APPLICATION_CLOSED);
                                        saveProgramData(&listaEmpresas, &rAtividade);
                                        freeCompanies(&listaEmpresas);
                                        freeBranches(&rAtividade);
                                        return 0;
                                    default:
                                        puts(INVALID_OPTION);
                                }
                            } while (opcSubMenuCompany != 0);
                            break;
                        case 2:
                            system("clear");
                            do {
                                opcSubMenuBranch = subMenuAdminBranches();
                                switch (opcSubMenuBranch) {
                                    case 1:
                                        system("clear");
                                        createActivityBranches(&rAtividade);
                                        break;
                                    case 2:
                                        system("clear");
                                        updateActivityBranches(&rAtividade);
                                        break;
                                    case 3:
                                        system("clear");
                                        removeActivityBranches(&rAtividade, &listaEmpresas);
                                        break;
                                    case 0:
                                        system("clear");
                                        break;
                                    case -1:
                                        puts(APPLICATION_CLOSED);
                                        saveProgramData(&listaEmpresas, &rAtividade);
                                        freeCompanies(&listaEmpresas);
                                        freeBranches(&rAtividade);
                                        return 0;
                                    default:
                                        puts(INVALID_OPTION);
                                }
                            } while (opcSubMenuBranch != 0);
                            break;
                        case 3:
                            system("clear");
                            do {
                                opcSubMenuReport = subMenuAdminReport();
                                switch (opcSubMenuReport) {
                                    case 1:
                                        system("clear");
                                        viewReportMaxRating(&listaEmpresas, &rAtividade);
                                        break;
                                    case 2:
                                        system("clear");
                                        viewReportSameActivityBranch(&listaEmpresas, &rAtividade);
                                        break;
                                    case 0:
                                        system("clear");
                                        break;
                                    case -1:
                                        puts(APPLICATION_CLOSED);
                                        saveProgramData(&listaEmpresas, &rAtividade);
                                        freeCompanies(&listaEmpresas);
                                        freeBranches(&rAtividade);
                                        return 0;
                                    default:
                                        puts(INVALID_OPTION);
                                }
                            } while (opcSubMenuReport != 0);
                            break;
                        case 0:
                            system("clear");
                            break;
                        case -1:
                            puts(APPLICATION_CLOSED);
                            saveProgramData(&listaEmpresas, &rAtividade);
                            freeCompanies(&listaEmpresas);
                            freeBranches(&rAtividade);
                            return 0;
                        default:
                            puts(INVALID_OPTION);
                    }
                } while (opcSubMenuAdmin != 0);
                break;
            case 2:
                system("clear");
                do {
                    opcSubMenuUser = userMenu();

                    switch (opcSubMenuUser) {
                        case 1:
                            system("clear");
                            searchCompanies(&listaEmpresas, &rAtividade);
                            break;
                        case 2:
                            system("clear");
                            rankCompanies(&listaEmpresas);
                            break;
                        case 3:
                            system("clear");
                            commentCompanies(&listaEmpresas);
                            break;
                        case 0:
                            system("clear");
                            break;
                        case -1:
                            puts(APPLICATION_CLOSED);
                            saveProgramData(&listaEmpresas, &rAtividade);
                            freeCompanies(&listaEmpresas);
                            freeBranches(&rAtividade);
                            return 0;
                        default:
                            puts(INVALID_OPTION);
                    }
                } while (opcSubMenuUser != 0);
                break;
            case 3:
                system("clear");
                do {
                    opcSubMenuCompany = companyMenu();

                    switch (opcSubMenuCompany) {
                        case 1:
                            system("clear");
                            manageCompanyInfo(&listaEmpresas, &rAtividade);
                            break;
                        case 2:
                            system("clear");
                            manageComments(&listaEmpresas);
                            break;
                        case 3:
                            system("clear");
                            viewReportsSearches(&listaEmpresas, &rAtividade);
                            break;
                        case 0:
                            system("clear");
                            break;
                        case -1:
                            puts(APPLICATION_CLOSED);
                            saveProgramData(&listaEmpresas, &rAtividade);
                            freeCompanies(&listaEmpresas);
                            freeBranches(&rAtividade);
                            return 0;
                        default:
                            puts(INVALID_OPTION);
                    }
                } while (opcSubMenuCompany != 0);
                break;
            case 4:
                puts(APPLICATION_CLOSED);
                saveProgramData(&listaEmpresas, &rAtividade);
                freeCompanies(&listaEmpresas);
                freeBranches(&rAtividade);
                return 0;

            default:
                puts(INVALID_OPTION);
        }
    } while (mainOption != 4);

}