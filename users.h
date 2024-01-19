/**
 * @file users.h
 * @author Grupo20
 * @date 06-01-2024
 * @version 1
 *
 * @copyright Copyright (C) Grupo20 2023. All Rights MIT Licensed.
 *
 * @brief Header file containing declarations for users functions.
 *
 */

#ifndef USERS_H
#define USERS_H

#define MAX_NAME_SIZE 50
#define MAX_EMAIL_SIZE 60
#define MAX_TITLE_SIZE 50
#define MAX_TEXT_SIZE 100
#define MIN_RATING_VALUE 0.0
#define MAX_RATING_VALUE 5.0
#define COMPANY_NOT_FOUND "No active companies found."
#define COMPANY_INFO "Company information: \n"
#define COMPANY_NIF "Company NIF: "
#define COMPANY_NAME "Company Name: "
#define COMPANY_CATEGORY "Company Category: "
#define COMPANY_BRANCHES "Company Activity Branch: "
#define COMPANY_STREET "Company Street: "
#define COMPANY_LOCATION "Company location: "
#define COMPANY_POSTAL_CODE "Company postal code: "
#define MSG_GET_COMPANY_TO_RATE "Enter the name of the company to be rated: "
#define MSG_GET_RATING "Enter rating (0.0-5.0): "
#define COMPANY_RATING_SUCCESS "Rating successfully awarded!"
#define MSG_GET_COMPANY_TO_COMMENT "Enter the name of the company to comment: "
#define MSG_GET_COMMENT_TITLE "Insert comment title: "
#define MSG_GET_USER_NAME "Enter your username: "
#define MSG_GET_USER_EMAIL "Enter your email address: "
#define MSG_GET_COMMENT_TEXT "Enter your comment: "
#define COMMENT_ADD_SUCESS "Comment successfully added!"
#define COMPANY_AVERAGE_RATING "Average rating: "

/**
 * @brief Displays the user a sub-menu to search company's.
 *
 * This function displays a submenu allowing the user to choose different criteria
 * for searching companies such as Name, Category, Activity Branches.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 * @param rAtividade Pointer to the 'RamosAtividade' structure containing branches information
 *
 */
void searchCompanies(Empresas *empresas, RamosAtividade *rAtividade);


/**
 * @brief Searches for a company by name within the provided 'Empresas' structure.
 *
 * This function asks the user the name of the company, validates the input to check the matching company,
 * if the name matches an existing one it displays all the information about it, otherwise displays a message saying that the company was not
 * found.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 * @param rAtividade Pointer to the 'RamosAtividade' structure containing branches information
 *
 */
void searchCompanyByName(Empresas *empresas, RamosAtividade *rAtividade);

/**
 * @brief Searches for a company by category within the provided 'Empresas' structure.
 *
 * This function asks the user the category of the company, validates the input to check the matching company,
 * if the category matches an existing one it displays all the information about it, otherwise displays a message saying that the company was not
 * found.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 * @param rAtividade Pointer to the 'RamosAtividade' structure containing branches information
 *
 */
void searchCompanyByCategory(Empresas *empresas, RamosAtividade *rAtividade);

/**
 * @brief Searches for a company by Activity Branches within the provided 'Empresas' structure.
 *
 * This function asks the user the activity branches of the company, validates the input to check the matching company,
 * if the activity branches matches an existing one it displays all the information about it, otherwise displays a message saying that the company was not
 * found.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 * @param rAtividade Pointer to the 'RamosAtividade' structure containing branches information
 *
 */
void searchCompanyByBranch(Empresas *empresas, RamosAtividade *rAtividade);

/**
 * @brief Displays information about a company.
 *
 * This function prints details about a company, such as Rating, Name, Category, Activity Branches, Street, Location, Postal Code.
 *
 * @param empresa Pointer to the 'Empresa' structure containing information about the company to be displayed.
*/
void showCompanyInfo(Empresa empresa);

/**
 * @brief Allows users to rate a company within the 'Empresas' structure.
 *
 * This function asks the user for the name of a company, validates the input to check the matching company,
 * and allows the user to rate the company. The rating is then stored in the company's
 * classification structure. If the company is not found, an information message is displayed.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 */
void rankCompanies(Empresas *empresas);

/**
 * @brief Allows users to add comments to a company within the 'Empresas' structure.
 *
 * This function asks the user for the name of a company, validates the input to check the matching company,
 * and allows the user to add comments. The comments are then stored in the company's
 * comments structure. If the company is not found, an information message is displayed.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 */
void commentCompanies(Empresas *empresas);

/**
 * @brief Calculates the average rating for a specific company.
 *
 * This function calculates the average rating based on the ratings stored in the 'Classificacao' structure
 * associated with a specific company. If the company has received ratings, the function calculates and returns
 * the average rating; otherwise, it returns 0.0.
 *
 * @param empresa The 'Empresa' structure representing the company.
 * @return The average rating for the company. If no ratings are available, returns 0.0.
 */
float calculateAverageRating(Empresa empresa);

#endif /* USERS_H */