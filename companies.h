#ifndef COMPANIES_H
#define COMPANIES_H

#define MSG_GET_COMPANY_MANAGE "Insira nome da Empresa a gerir: "
#define NIF_CHANGED_SUCESS "Nif alterado com sucesso!"
#define NAME_CHANGED_SUCESS "Nome alterado com sucesso!"
#define CATEGORY_CHANGED_SUCESS "Categoria alterada com sucesso!"
#define BRANCHES_CHANGED_SUCESS "Ramo de Atividade alterado com sucesso!"
#define STREET_CHANGED_SUCESS "Rua alterada com sucesso!"
#define LOCATION_CHANGED_SUCESS "Localidade alterada com  sucesso!"
#define POSTAL_CODE_CHANGED_SUCESS "Codigo postal alterado com sucesso!"
#define COMPANY_DONT_HAVE_COMMENTS "A empresa nao tem comentarios!"
#define MSG_COMMENT_UPDATE_SUCESS "Comentario atuaizado com sucesso!"
#define COMPANY_INFO_SEARCHES "Relatorio Pesquisas"
#define COMPANY_NUMBER_SEARCHES "Numero de pesquisas de utilizadores: "

/**
 * @brief Displays the user a sub-menu to manage their company's information's.
 *
 * This function displays a sub-menu prompting the user to choose an option to modify a specific company information, such as
 * NIF, Name, Category, Activity Branch, Street, Location, Postal Code.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information
 * @return Returns 0 if the application is closed, otherwise calls different sub-functions to manage information.
 */
int manageCompanyInfo(Empresas *empresas, RamosAtividade *rAtividade);

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


//DOCUMENTAR
void manageComments(Empresas *empresas);

//DOCUMENTAR
void viewReportsSearches(Empresas *empresas, RamosAtividade *rAtividade);

//DOCUMENTAR
void showCompanySearches(Empresa empresa);

#endif /* COMPANIES_H */

