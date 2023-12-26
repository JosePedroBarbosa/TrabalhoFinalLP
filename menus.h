/** 
 * @file menus.h
 * @author Grupo20
 * @date 04-12-2023
 * @version 1
 * 
 * @copyright Copyright (C) Grupo20 2023. All Rights MIT Licensed.
 * 
 * @brief Contains function declarations for various menus for administrators, users and companies in the system.
 *
 */

#ifndef MENUS_H
#define MENUS_H

#define APPLICATION_CLOSED "Aplicacao encerrada."
#define INVALID_OPTION "Opcao invalida!"

/**
 * @brief Displays the main menu of the system.
 *
 * This function presents the main menu options of the system, prompting
 * the user to choose between roles such as Administrator, User, Company,
 * or exit the program.
 *
 * @return Returns the user's choice as an integer.
 *
 * The function prints the main menu options:
 * 1. Administrator
 * 2. Utilizador
 * 3. Empresa
 * 4. Sair
 *
 * The user is then prompted to enter their choice, and the selected
 * option is returned.
 */

int mainMenu();

/**
 * @brief Displays the administrator menu of the system.
 *
 * This function presents the administrator menu options of the system, prompting
 * the administrator to choose between options such as manage the catalog of companies, manage activity branches, view reports,
 * return to the main menu or exit the application.
 * 
 * @return Returns the administrator's choice as an integer.
 *
 * The function prints the administrator menu options:
 * 1. Gerir Catalogo de Empresas
 * 2. Gerir Ramos de Atividade
 * 3. Visualizar Relatorios
 * 0. Voltar ao menu principal
 * -1. Sair da Aplicacao
 *
 * The administrator is then prompted to enter their choice, and the selected
 * option is returned.
 */

int menuAdmin();

/**
 * @brief Displays the sub menu for managing the company catalog. 
 *
 * This function presents options for managing the catalog of companies, the administrator is allowed to create, edit, remove companies
 * return to previous menu or exit the application.
 * 
 * @return Returns the administrator's choice as an integer.
 *
 * The function prints sub menu options for managing the company catalog:
 * 1. Criar empresa
 * 2. Editar empresa
 * 3. Remover empresa
 * 0. Voltar ao menu principal
 * -1. Sair da Aplicacao
 *
 * The administrator is then prompted to enter their choice, and the selected
 * option is returned.
 */

int subMenuAdminCatalog();

/**
 * @brief Displays the sub menu for managing activity branches. 
 *
 * This function presents options for managing the activity branches of companies, the administrator is allowed to create, edit, remove activity branches
 * return to previous menu or exit the application.
 * 
 * @return Returns the administrator's choice as an integer.
 *
 * The function prints sub menu options for managing the activity branches of companies:
 * 1. Criar ramo atividade
 * 2. Editar ramo atividade
 * 3. Remover ramo atividade
 * 0. Voltar ao menu principal
 * -1. Sair da Aplicacao
 *
 * The administrator is then prompted to enter their choice, and the selected
 * option is returned.
 */

int subMenuAdminBranches();

/**
 * @brief Displays the sub menu for viewing reports. 
 *
 * This function presents options for administrators to view different reports, such as reports of the most searched keyword and usage statistics.
 * Furthermore, the administrator can choose to return to the previous menu or exit the application.
 * 
 * @return Returns the administrator's choice as an integer.
 *
 * The function prints sub menu options for viewing reports of companies:
 * 1. Relatorio empresas classificacao maxima
 * 2. Relatorio de Estatisticas de Uso
 * 0. Voltar ao menu principal
 * -1. Sair da Aplicacao
 *
 * The administrator is then prompted to enter their choice, and the selected
 * option is returned.
 */


int subMenuAdminReport();

/**
 * @brief Displays the user menu of the system.
 *
 * This function presents the user menu options of the system, prompting
 * the user to choose between options such as search for companies, rate companies, leave comments,
 * return to the main menu or exit the application.
 * 
 * @return Returns the user's choice as an integer.
 *
 * The function prints the user menu options:
 * 1. Pesquisar Empresas
 * 2. Classificar Empresa
 * 3. Comentar Empresa
 * 0. Voltar ao menu principal
 * -1. Sair da Aplicacao
 *
 * The user is then prompted to enter their choice, and the selected
 * option is returned.
 */

int userMenu();

/**
 * @brief Displays the company menu of the system.
 *
 * This function presents options for companies, allowing them to manage their informations, view comments, analyze data about searches,
 * return to the main menu or exit the application.
 * 
 * @return Returns the users's choice as an integer.
 *
 * The function prints the company menu options:
 * 1. Gerir Informacoes Empresa
 * 2. Ver comentarios
 * 3. Analisar Pesquisas    
 * 0. Voltar ao menu principal
 * -1. Sair da Aplicacao
 *
 * The user is then prompted to enter their choice, and the selected
 * option is returned.
 */

int companyMenu();


/**
 * @brief Displays a menu to choose the criteria for searching a company.
 *
 * This function presents different options for users, allowing them to select the criteria for searching a company.
 * 
 * @return Returns the user's choice as an integer.
 *
 * The function prints the company searching criteria menu options:
 * 1. Nome
 * 2. Categoria
 * 3. Ramo de Atividade    
 * 0. Voltar ao menu principal
 * -1. Sair da Aplicacao
 *
 * The user is then prompted to enter their choice, and the selected
 * option is returned.
 */

int menuSearchCompanies();


/**
 * @brief Displays a menu for managing company's information's.
 *
 * This function presents different options for companys, allowing them to select which information
 * to modify in their company.
 * 
 * @return Returns the user's choice as an integer.
 *
 * The function prints the company searching criteria menu options:
 * 1. NIF
 * 2. Nome
 * 3. Categoria
 * 4. Ramo de Atividade
 * 5. Rua
 * 6. Localidade
 * 7. Codigo Postal    
 * 0. Voltar ao menu principal
 * -1. Sair da Aplicacao
 *
 * The user is then prompted to enter their choice, and the selected
 * option is returned.
 */
int menuManageCompanyInfo();

#endif /* MENUS_H */