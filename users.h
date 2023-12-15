#ifndef USERS_H
#define USERS_H

#define MAX_NAME_SIZE 40
#define MAX_EMAIL_SIZE 50
#define MAX_TITLE_SIZE 40
#define MAX_TEXT_SIZE 100
#define COMPANY_NOT_FOUND "Nenhuma empresa encontrada."
#define COMPANY_INFO "Informacoes da empresa: \n"
#define COMPANY_NAME "Nome empresa: "
#define COMPANY_CATEGORY "Categoria empresa: "
#define COMPANY_BRANCHES "Ramo de atividade empresa: "
#define COMPANY_STREET "Rua empresa: "
#define COMPANY_LOCATION "Localizacao empresa: "
#define COMPANY_POSTAL_CODE "Codigo postal empresa: "
#define MIN_RATING_VALUE 0
#define MAX_RATING_VALUE 5
#define MSG_GET_COMPANY_TO_RATE "Insira nome da empresa a classificar: "
#define MSG_GET_RATING "Insira classificacao (0-5): "
#define COMPANY_RATING_SUCESS "Classificacao atribuida com sucesso!"
#define MSG_GET_COMPANY_TO_COMMENT "Insira nome da empresa a comentar: "
#define MAX_COMMENT_TITLE_SIZE 50
#define MSG_GET_COMMENT_TITLE "Insira titulo do comentario: "
#define MAX_USER_NAME_SIZE 50
#define MSG_GET_USER_NAME "Insira o seu nome de utilizador: "
#define MAX_USER_EMAIL_SIZE 60
#define MSG_GET_USER_EMAIL "Insira o seu email: "
#define MAX_COMMENT_TEXT_SIZE 120
#define MSG_GET_COMMENT_TEXT "Insira o seu comentario: "
#define COMMENT_ADD_SUCESS "Comentario adicionado com sucesso!"

/**
 * @brief Searches for companies based on user-selected criteria.
 * 
 * This function calls a submenu allowing the user to choose different criterias
 * for searching companies such as Name, Category, Activity Branches.
 * 
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 * @return Returns 0 if the application is closed, otherwise he calls another function for search companies with the selected criteria.
 * 
 */
int searchCompanies(Empresas *empresas);


/**
 * @brief Searches for a company by name within the provided 'Empresas' structure.
 * 
 * This function asks the user the name of the company, validates the input to check the matching company, 
 * if the name matches an existing one it displays all the information about it, otherwise displays a message saying that the company was not 
 * found.
 * 
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 * 
 */
void searchCompanyByName(Empresas *empresas);

/**
 * @brief Searches for a company by category within the provided 'Empresas' structure.
 * 
 * This function asks the user the category of the company, validates the input to check the matching company, 
 * if the category matches an existing one it displays all the information about it, otherwise displays a message saying that the company was not 
 * found.
 * 
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 * 
 */
void searchCompanyByCategory(Empresas *empresas);

/**
 * @brief Searches for a company by Activity Branches within the provided 'Empresas' structure.
 * 
 * This function asks the user the activity branches of the company, validates the input to check the matching company, 
 * if the activity branches matches an existing one it displays all the information about it, otherwise displays a message saying that the company was not 
 * found.
 * 
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 * 
 */
void searchCompanyByBranch(Empresas *empresas);

/**
 * @brief Displays information about a company.
 * 
 * This function prints details about a company, such as Name, Category, Activity Branches, Street, Location, Postal Code.
 * 
 * @param empresa The 'Empresa' structure containing information about the company to be displayed.
*/
void showCompanyInfo(Empresa empresa);

/**
 * @brief Rates and classifies a company within the 'Empresas' structure.
 * 
 * This function asks the user for the name of a company, validates the input to check the matching company,
 * and allows the user to rate the company. The rating is then stored in the company's
 * classification structure. If the company is not found, an information message is displayed.
 * 
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 */

void rankCompanies(Empresas *empresas);

/**
 * @brief Adds comments to a company within the 'Empresas' structure.
 * 
 * This function asks the user for the name of a company, validates the input to check the matching company,
 * and allows the user to add comments. The comments are then stored in the company's
 * comments array. If the company is not found, an information message is displayed.
 * 
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 */
void commentCompanies(Empresas *empresas);

#endif /* USERS_H */

