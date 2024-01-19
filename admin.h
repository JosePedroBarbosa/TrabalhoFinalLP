/**
 * @file admin.h
 * @author Grupo20
 * @date 06-01-2024
 * @version 1
 *
 * @copyright Copyright (C) Grupo20 2023. All Rights MIT Licensed.
 *
 * @brief Header file containing declarations for administrative functions and data structures.
 *
 */

#ifndef ADMIN_H
#define ADMIN_H

#define MAX_COMPANY_NAME_SIZE 60
#define MAX_COMPANY_CATEGORY_SIZE 60
#define MAX_COMPANY_BRANCHES_SIZE 60
#define MAX_COMPANY_STREET_SIZE 60
#define MAX_COMPANY_LOCATION_SIZE 60
#define MAX_POSTALCODE_SIZE 9
#define MAX_COMPANY_POSTALCODE_SIZE 9
#define MIN_NIF_VALUE 100000000
#define MAX_NIF_VALUE 999999999
#define MAX_RATE 5

#define MAX_NAME_SIZE 50
#define MAX_EMAIL_SIZE 60
#define MAX_TITLE_SIZE 50
#define MAX_TEXT_SIZE 100
#define INITIAL_COMMENTS 50
#define INITIAL_CLASSIS 50

#define MSG_GET_NIF "Insert NIF: "
#define MSG_GET_NEW_NIF "Insert new NIF: "
#define MSG_GET_COMPANY_NAME "Insert Name: "
#define MSG_GET_NEW_COMPANY_NAME "Insert new Name: "
#define MSG_GET_CATEGORY_NAME "Insert Category: "
#define MSG_GET_NEW_CATEGORY_NAME "Insert new Category: "
#define MSG_GET_BRANCHES_NAME "Insert Activity Branch: "
#define MSG_UPDATE_BRANCHES_NAME "Insert new Activity Branch: "
#define MSG_GET_NEW_BRANCHES_NAME "Insert new name of Activity Branch: "
#define MSG_GET_STREET_NAME "Insert Street: "
#define MSG_GET_NEW_STREET_NAME "Insert new Street: "
#define MSG_GET_LOCATION_NAME "Insert Location: "
#define MSG_GET_NEW_LOCATION_NAME "Insert new Location: "
#define MSG_GET_POSTALCODE_NAME "Insert Postal Code (0000-000): "
#define MSG_GET_NEW_POSTALCODE_NAME "Insert new Postal Code (0000-000): "
#define MSG_COMPANY_INSERT_SUCESS "Company successfully integrated!"
#define MSG_COMPANY_INSERT_ERROR "There is already a company registered with this NIF!"
#define MSG_COMPANY_UPDATE_SUCESS "Company successfully updated!"
#define MSG_ERROR_HAVE_COMMENTS "The company has comments, so it cant be removed!"
#define MSG_COMPANY_REMOVE_SUCCESS "Company successfully removed!"
#define MSG_COMPANY_INACTIVE "Company status set to Inactive!"
#define MSG_COMPANY_ACTIVE "Company status set to Active!"
#define MSG_CHANGE_STATE "Change company status to Inactive? (Y/N)"
#define MSG_CHANGE_COMPANY_STATE "Change company status from Inactive to Active? (Y/N)?"
#define MSG_COMPANY_ALREADY_ACTIVE "The companies status is already Active!"
#define MSG_BRENCHES_ALREADY_EXIST "There is already an activity branch registered under this name!"
#define MSG_BRANCHES_INSERT_SUCESS "Activity Branch successfully integrated!"
#define MSG_BRANCHES_UPDATE_SUCESS "Activity Branch successfully updated!"
#define MSG_CHANGE_BRANCHES_STATE_ACTIVE "Change Activity Branch status from Inactive to Active? (Y/N)"
#define MSG_BRANCHES_CHANGE_STATE_SUCESS "Activity Branch status changed successfully!"
#define MSG_CHANGE_BRANCHES_STATE "Change Activity Branch status to Inactive (Y/N)?"
#define MSG_BRANCHES_ALREADY_ACTIVE "The Activity Branch status is already Active!"
#define ERROR_COMPANY_DONT_EXIST "The Company does not exist!"
#define ERROR_BRANCHES_DONT_EXIST "The Activity Branch does not exist!"
#define ERROR_COMPANY_ALREADY_HAVE_THIS_BRANCHES "The is already (at least one) active company with this branch!"
#define MSG_DELETE_HIDE_COMMENTS "Do you want to delete / hide comments? (Y/N)"
#define MSG_DELETE_OR_HIDE_COMMENTS "Do you want to delete or hide comments? (D / H)"
#define MSG_NUMBER_OF_COMMENT "Enter comment number to remove: "
#define MSG_NUMBER_OF_COMMENT_HIDE "Enter comment number to hide: "
#define ERROR_CANT_INSERT_NEW_COMPANY "It is not possible to insert a new companies."
#define ERROR_CANT_INSERT_NEW_BRANCH "It is not possible to insert a new branch."
#define MSG_NO_COMPANY_WITH_MAX_RATE "There is no company with max rate!"
#define MSG_NO_COMPANIES_SAME_BRANCH "There are no companies with same activity branch!"
#define MSG_ERROR_INVALID_BRANCH "Invalid Activity Branch!"

/**
 * @brief Enumeration representing the state of a company or activity branch.
 */
typedef enum {INATIVO, ATIVO} Estado;

/**
 * @struct Classificacao
 * @brief Structure representing a classification with a rating, username, and email.
 */
typedef struct {
    float nota;
    char nomeUtilizador[MAX_NAME_SIZE], emailUtilizador[MAX_EMAIL_SIZE];
} Classificacao;

/**
 * @struct Comentario
 * @brief Structure representing a comment with a title, text, username, email, and state.
 */
typedef struct {
    Estado estado;
    char titulo[MAX_TITLE_SIZE], texto[MAX_TEXT_SIZE], nomeUtilizador[MAX_NAME_SIZE], emailUtilizador[MAX_EMAIL_SIZE];
} Comentario;

/**
 * @struct Empresa
 * @brief Structure representing a company with various information including NIF, Name, Category, etc.
 */
typedef struct {
    int nif;
    char nome[MAX_COMPANY_NAME_SIZE];
    char categoria[MAX_COMPANY_CATEGORY_SIZE];
    char ramo_atividade[MAX_COMPANY_BRANCHES_SIZE];
    char rua[MAX_COMPANY_STREET_SIZE];
    char location[MAX_COMPANY_LOCATION_SIZE];
    char postal_code[MAX_POSTALCODE_SIZE];
    Estado estado;
    int nClassis;
    Classificacao *classis;
    int nComments;
    Comentario *comments;
    int nPesquisas;
} Empresa;

/**
 * @struct Empresas
 * @brief Structure representing a collection of companies, counter of companies and number of companies allocated.
 */
typedef struct {
    int contador, alocadas;
    Empresa *empresas;
} Empresas;

/**
 * @struct RamoAtividade
 * @brief Structure representing an activity branch with a name and state.
 */
typedef struct {
    Estado estado;
    char nome[MAX_COMPANY_BRANCHES_SIZE];
} RamoAtividade;

/**
 * @struct RamosAtividade
 * @brief Structure representing a collection of activity branches, counter of activity branches and number of branches allocated.
 */
typedef struct {
    int contador, alocados;
    RamoAtividade *rAtividade;
} RamosAtividade;

/**
 * @brief Searches for a company by NIF within the 'Empresas' structure.
 *
 * This function iterates through the 'Empresas' structure to find a company
 * with the given NIF. If a matching company is found, the index of the company is returned, otherwise it returns -1.
 *
 * @param empresas The 'Empresas' structure containing company information.
 * @param nif The input NIF.
 * @return Returns the index of the company if found, otherwise returns -1.
 */
int searchCompanyIndexByNif(Empresas empresas, int nif);

/**
 * @brief Creates a new company and adds it to the 'Empresas' structure.
 *
 * This function prompts the user to input information for a new company,
 * such as NIF, Name, Category, Activity Branch, Street, Location, and Postal code.
 * The function checks if the NIF is unique and  ensures that the 'Empresas' structure is not full before adding a new one.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 * @param ramosAtividade Pointer to the 'RamosAtividade' structure.
 */
void createCompanies(Empresas *empresas, RamosAtividade *ramosAtividade);

/**
 * @brief Updates information for a company within the 'Empresas' structure.
 *
 * This function prompts the user to input a NIF, searches for the matching
 * company within the 'Empresas' structure, and then calls the 'updateCompany'
 * function to update the information for that specific company.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 * @param ramosAtividade Pointer to the 'RamosAtividade' structure.
 */
void updateCompanies(Empresas *empresas, RamosAtividade *ramosAtividade);

/**
 * @brief Updates information for a specific company.
 *
 * This function prompts the user to input new information for a company,
 * such as Name, Category, Activity Branch, Street, Location, and Postal code.
 * It also allows the administrator to change the state of the company (active or inactive).
 *
 * @param listaEmpresas Pointer to the 'Empresas' structure containing company information.
 * @param empresa Pointer to the 'Empresa' structure representing the company to be updated.
 * @param ramosAtividade Pointer to the 'RamosAtividade' structure.
 * @param companyIndex Index of the company to be updated in the 'Empresas' structure.
 */
void updateCompany(Empresas *listaEmpresas, Empresa *empresa, RamosAtividade *ramosAtividade, int companyIndex) ;


/**
 * @brief Removes a company from the 'Empresas' structure.
 *
 * This function prompts the user to input a NIF, searches for the matching
 * company within the 'Empresas' structure, and removes it if there are no comments.
 * If the company has comments, the function prompts the administrator to change
 * the state of the company (active or inactive).
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 */
void removeCompanies(Empresas *empresas);

/**
 * @brief Resets the information of a company to default/empty values.
 *
 * This function changes all information's of a company structure to default values, removing or resetting the information.
 *
 * @param empresa Pointer to the 'Empresa' structure representing the company to be removed.
 */
void removeCompany(Empresa *empresa);


/**
 * @brief Searches for a specific Activity Branch within the 'RamosAtividade' structure.
 *
 * This function iterates through the 'RamosAtividade' structure to find an matching Branch
 * with a specified name. If the Branch is found, it returns the index of the Branch,
 * otherwise, it returns -1.
 *
 * @param ramosAtividade The 'RamosAtividade' structure containing branches information.
 * @param nome Pointer to a string representing the name of the Activity Branch.
 * @return If the Branch is found, the function returns the index of the industry, otherwise, returns -1.
 */
int searchBranchIndexByName(RamosAtividade ramosAtividade, char *nome);

/**
 * @brief Searches for a specific Activity Branch within the 'RamosAtividade' structure and verify the current state.
 *
 * This function iterates through the 'RamosAtividade' structure to find an matching Branch
 * with a specified name. If the Branch is found and the current state is active, it returns the index of the Branch,
 * otherwise, it returns -1.
 *
 * @param ramosAtividade The 'RamosAtividade' structure containing branches information.
 * @param nome Pointer to a string representing the name of the Activity Branch.
 * @return If the Branch is found and current state is active, the function returns the index of the Activity Branch, otherwise, returns -1.
 */
int searchBranchIndexAndState(RamosAtividade ramosAtividade, char *nome);

/**
 * @brief Creates a new company Branch and adds it to the 'RamoAtividade' structure.
 *
 * This function prompts the user to input the name of a new na Activity Branch,
 * The function checks if the Name is unique and ensures that the 'RamosAtividade' structure is not full before adding a new one.
 *
 * @param ramosAtividade Pointer to the RamosAtividade structure representing the collection of activity branches.
 */
void createActivityBranches(RamosAtividade *ramosAtividade);

/**
 * @brief Updates the state of an activity branch, based on user choice.
 *
 * This function allows the user to update the state (active or inactive) of an existing Activity Branch
 * represented by the provided RamoAtividade structure.
 *
 * @param listaRamos Pointer to the 'RamosAtividade' structure containing branches information.
 * @param ramoAtividade Pointer to the RamoAtividade structure representing the activity branch.
 * @param branchIndex Index of the branch to be updated in the 'RamosAtividade' structure.
 *
 */
void updateActivityBranch(RamosAtividade *listaRamos, RamoAtividade *ramoAtividade, int branchIndex);

/**
 * @brief Updates information for a specific activity branch provided by the user.
 *
 * This function prompts the user to enter the name of the activity branch to be updated.
 * The function searches for the activity branch index in the provided RamosAtividade structure and, if found,
 * calls the updateActivityBranch function to update it.
 *
 * @param rAtividade Pointer to the RamosAtividade structure representing the collection of activity branches.
 */
void updateActivityBranches(RamosAtividade *rAtividade);

/**
 * @brief Finds the index of a company with a specified activity branch name.
 *
 * This function searches through the provided collection of companies (Empresas)
 * to find a company with the specified activity branch name. If it matches,
 * the function returns the index of the company, otherwise, it returns -1.
 *
 * @param nome The name of the activty branch to search for.
 * @param empresas Pointer to the Empresas structure representing the collection of companies.
 * @return If the Branch with a specific name is found, the function returns the index of the activity branch, otherwise, returns -1.
 */
int companyWithBranchName(char *nome, Empresas *empresas);

/**
 * @brief Removes an activity branch from a collection and handles associated companies.
 *
 * This function prompts the user to enter the name of the activity branch to be removed.
 * It then searches for the branch in the provided RamosAtividade collection and checks if
 * any companies have that branch. If no companies are found,
 * the function allows changing the state of the branch. If there are associated companies,
 * it displays an error message.
 *
 * @param ramosAtividade Pointer to the RamosAtividade structure representing the collection of activity branches.
 * @param empresas Pointer to the Empresas structure representing the collection of companies.
 */
void removeActivityBranches(RamosAtividade *ramosAtividade, Empresas *empresas);

/**
 * @brief Generates and displays a report of companies with the maximum rating.
 *
 * This function generates a report listing companies with the maximum rating. The report includes company details such as
 * the company name, category, activity branch, rating, and other relevant information for each matching company.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 * @param ramosAtividade Pointer to the 'RamosAtividade' structure containing activity branch information.
 */
void viewReportMaxRating(Empresas *empresas, RamosAtividade *ramosAtividade);

/**
 * @brief Generates and displays a report of companies with the same activity branch.
 *
 * This function generates a report listing companies that share the same activity branch. The report includes details
 * such as the company name, category, activity branch, and other relevant information for each matching company.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 * @param ramosAtividade Pointer to the 'RamosAtividade' structure containing activity branch information.
 */
void viewReportSameActivityBranch(Empresas *empresas, RamosAtividade *ramosAtividade);

#endif /* ADMIN_H */