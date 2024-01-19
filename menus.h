/**
 * @file menus.h
 * @author Grupo20
 * @date 29-12-2023
 * @version 1
 *
 * @copyright Copyright (C) Grupo20 2023. All Rights MIT Licensed.
 *
 * @brief Contains function declarations for various menus for administrators, users and companies in the system.
 *
 */

#ifndef MENUS_H
#define MENUS_H

#define APPLICATION_CLOSED "Application closed."
#define INVALID_OPTION "Invalid Option!"

/**
 * @brief Displays the main menu of the system.
 *
 * This function presents the main menu options of the system, prompting
 * the user to choose between roles such as Administrator, User, Company,
 * or exit the program.
 *
 * @return Returns the user's choice as an integer.
 *
 */
int mainMenu();

/**
 * @brief Displays the administrator menu of the system.
 *
 * This function presents the administrator menu options of the system, prompting
 * the administrator to choose between options such as manage the catalog of companies, manage activity branches, view reports,
 * return to the main menu or exit the application.
 *
 * @return Returns the user's choice as an integer.
 *
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
 */
int subMenuAdminBranches();

/**
 * @brief Displays the sub menu for viewing reports.
 *
 * This function presents options for administrators to view different reports, such as reports of the companies with max rate and companies with same activity branch.
 * Furthermore, the administrator can choose to return to the previous menu or exit the application.
 *
 * @return Returns the administrator's choice as an integer.
 *
 */
int subMenuAdminReport();

/**
 * @brief Displays the user menu of the system.
 *
 * This function presents options prompting the users to choose between search for companies, rate companies, leave comments
 * return to the main menu or exit the application.
 *
 * @return Returns the user's choice as an integer.
 *
 */
int userMenu();

/**
 * @brief Displays the company menu of the system.
 *
 * This function presents options for companies, allowing them to manage their information's, view comments, view searches,
 * return to the main menu or exit the application.
 *
 * @return Returns the company's choice as an integer.
 *
 */
int companyMenu();


/**
 * @brief Displays a menu to choose the criteria for searching a company.
 *
 * This function presents different options for users, allowing them to select the criteria for searching a company, such as Name, Category, Activity Branch.
 *
 * @return Returns the company's choice as an integer.
 *
 */
int menuSearchCompanies();


/**
 * @brief Displays a menu for managing company's information's.
 *
 * This function presents different options for companies, allowing them to select which information
 * to modify in their company, such as NIF, Name, Category, Activity Branch, Street, Location, Postal Code.
 *
 * @return Returns the company's choice as an integer.
 *
 */
int menuManageCompanyInfo();

#endif /* MENUS_H */