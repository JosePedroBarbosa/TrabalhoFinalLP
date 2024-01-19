/**
 * @file companies.h
 * @author Grupo20
 * @date 06-01-2024
 * @version 1
 *
 * @copyright Copyright (C) Grupo20 2023. All Rights MIT Licensed.
 *
 * @brief Header file containing declarations for company functions.
 *
 */

#ifndef COMPANIES_H
#define COMPANIES_H

#define MSG_GET_COMPANY_MANAGE "Enter the name of the company to be managed: "
#define NIF_CHANGED_SUCESS "NIF changed successfully!"
#define NAME_CHANGED_SUCESS "Name changed successfully!"
#define CATEGORY_CHANGED_SUCESS "Category changed successfully!"
#define BRANCHES_CHANGED_SUCESS "Activity Branch changed successfully!"
#define STREET_CHANGED_SUCESS "Street changed successfully!"
#define LOCATION_CHANGED_SUCESS "Location changed successfully!"
#define POSTAL_CODE_CHANGED_SUCESS "Postal Code changed successfully!"
#define COMPANY_DONT_HAVE_COMMENTS "The company do not have comments!"
#define MSG_COMMENT_UPDATE_SUCESS "Comment updated successfully!"
#define COMPANY_INFO_SEARCHES "Searches Report"
#define COMPANY_NUMBER_SEARCHES "Number of user searches: "
#define COMPANY_DONT_HAVE_ACTIVE_COMMENTS "\n Your company do not have active comments! \n"
#define MSG_HIDE_COMMENTS "Do you want to hide comments (Y/N)"
#define MSG_NUMBER_COMMENT_TO_HIDE "Enter the comment number to hide: "
#define MSG_HIDE_COMMENT_SUCESS "Comment successfully updated!"

/**
 * @brief Displays the user a sub-menu to manage their company's information's.
 *
 * This function displays a sub-menu prompting the user to choose an option to modify a specific company information, such as
 * NIF, Name, Category, Activity Branch, Street, Location, Postal Code.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information
 * @param rAtividade Pointer to the 'RamosAtividade' structure containing branches information
 */
void manageCompanyInfo(Empresas *empresas, RamosAtividade *rAtividade);

/**
 * @brief Manages and modifies the NIF of a company within the 'Empresas' structure.
 *
 * This function asks the user for the name of a company, validates the input to check the matching company,
 * and allows the user to modify the NIF of the company.
 * The changes are applied directly to the 'Empresas' structure, if the company is not found an information message is displayed.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 */
void manageCompanyNif(Empresas *empresas);

/**
 * @brief Manages and modifies the Name of a company within the 'Empresas' structure.
 *
 * This function asks the user for the name of a company, validates the input to check the matching company,
 * and allows the user to modify the Name of the company.
 * The changes are applied directly to the 'Empresas' structure, if the company is not found an information message is displayed.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 */
void manageCompanyName(Empresas *empresas);

/**
 * @brief Manages and modifies the Category of a company within the 'Empresas' structure.
 *
 * This function asks the user for the name of a company, validates the input to check the matching company,
 * and allows the user to modify the Category of the company.
 * The changes are applied directly to the 'Empresas' structure, if the company is not found an information message is displayed.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 */
void manageCompanyCategory(Empresas *empresas);

/**
 * @brief Manages and modifies the Activity Branch of a company within the 'Empresas' structure.
 *
 * This function asks the user for the name of a company, validates the input to check the matching company,
 * and allows the user to modify the Activity Branch of the company.
 * The changes are applied directly to the 'Empresas' structure, if the company is not found an information message is displayed.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 * @param rAtividade Pointer to the 'RamosAtividade' structure containing branches information.
 */
void manageCompanyBranch(Empresas *empresas, RamosAtividade *rAtividade);

/**
 * @brief Manages and modifies the Street of a company within the 'Empresas' structure.
 *
 * This function asks the user for the name of a company, validates the input to check the matching company,
 * and allows the user to modify the Street of the company.
 * The changes are applied directly to the 'Empresas' structure, if the company is not found an information message is displayed.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 */
void manageCompanyStreet(Empresas *empresas);

/**
 * @brief Manages and modifies the Location of a company within the 'Empresas' structure.
 *
 * This function asks the user for the name of a company, validates the input to check the matching company,
 * and allows the user to modify the Location of the company.
 * The changes are applied directly to the 'Empresas' structure, if the company is not found an information message is displayed.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 */
void manageCompanyLocation(Empresas *empresas);

/**
 * @brief Manages and modifies the Postal Code of a company within the 'Empresas' structure.
 *
 * This function asks the user for the name of a company, validates the input to check the matching company,
 * and allows the user to modify the Postal Code of the company.
 * The changes are applied directly to the 'Empresas' structure, if the company is not found an information message is displayed.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 */
void manageCompanyPostalCode(Empresas *empresas);

/**
 * @brief Manages comments for a specific company in the 'Empresas' structure.
 *
 * This function allows the administrator to manage comments for a specific company. The administrator can view
 * active comments, hide comments, and change their status. The function prompts the user to enter the NIF of the
 * company, searches for the company in the 'Empresas' structure, and displays information about active comments.
 * The administrator can choose to hide specific comments by entering the comment number.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 */
void manageComments(Empresas *empresas);

/**
 * @brief Displays reports of the number of searches for a specific company.
 *
 * This function prompts the user to enter the NIF of a company, searches for the company in the 'Empresas' structure,
 * and displays reports of the number of searches if the company exists, is active, and has a valid activity branch.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 * @param rAtividade Pointer to the 'RamosAtividade' structure containing activity branch information.
 */
void viewReportsSearches(Empresas *empresas, RamosAtividade *rAtividade);

/**
 * @brief Displays the number of searches for a specific company.
 *
 * This function prints information about the total count of searches for a specific company.
 *
 * @param empresa The 'Empresa' structure representing the company.
 */
void showCompanySearches(Empresa empresa);

#endif /* COMPANIES_H */
