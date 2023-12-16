#ifndef ADMIN_H
#define ADMIN_H

#define MAX_POSTALCODE_SIZE 9
#define MIN_NIF_VALUE 100000000
#define MAX_NIF_VALUE 999999999
#define MSG_GET_NIF "Insira NIF da Empresa: "
#define MSG_GET_NEW_NIF "Insira novo NIF da Empresa: "
#define MAX_COMPANY_NAME_SIZE 60
#define MSG_GET_COMPANY_NAME "Insira Nome da Empresa: "
#define MSG_GET_NEW_COMPANY_NAME "Insira novo Nome da Empresa: "
#define MAX_COMPANY_CATEGORY_SIZE 60
#define MSG_GET_CATEGORY_NAME "Insira a Categoria: "
#define MSG_GET_NEW_CATEGORY_NAME "Insira nova Categoria: "
#define MAX_COMPANY_BRANCHES_SIZE 60
#define MSG_GET_BRANCHES_NAME "Insira o Ramo de Atividade: "
#define MSG_UPDATE_BRANCHES_NAME "Insira o nome do Ramo de Atividade que deseja alterar:"
#define MSG_GET_NEW_BRANCHES_NAME "Insira novo nome do Ramo de Atividade:"
#define MAX_COMPANY_STREET_SIZE 60
#define MSG_GET_STREET_NAME "Insira a Rua: "
#define MSG_GET_NEW_STREET_NAME "Insira nova Rua: "
#define MAX_COMPANY_LOCATION_SIZE 60
#define MSG_GET_LOCATION_NAME "Insira a Localidade: "
#define MSG_GET_NEW_LOCATION_NAME "Insira nova Localidade: "
#define MAX_COMPANY_POSTALCODE_SIZE 9
#define MSG_GET_POSTALCODE_NAME "Insira o codigo postal (0000-000): "
#define MSG_GET_NEW_POSTALCODE_NAME "Insira novo codigo postal (0000-000): "
#define MSG_MAX_COMPANYS "Numero maximo de empresas atingido."
#define MSG_COMPANY_INSERT_SUCESS "Empresa inserida com sucesso!"
#define MSG_COMPANY_INSERT_ERROR "Ja existe uma empresa registada com este NIF!"
#define ERROR_COMPANY_DONT_EXIST "A empresa nao existe!"
#define MSG_COMPANY_UPDATE_SUCESS "Empresa atualizada com sucesso!"
#define MSG_ERROR_HAVE_COMMENTS "A empresa possui comentarios, logo nao pode ser removida!"
#define MSG_COMPANY_REMOVE_SUCCESS "Empresa removida com sucesso!"
#define MSG_COMPANY_INACTIVE "Estado da empresa definido como Inativo!"
#define MSG_COMPANY_ACTIVE "Estado da empresa definico como Ativo!"
#define MSG_CHANGE_STATE "Alterar Estado Empresa para Inativo? (S/N)"
#define MSG_CHANGE_COMPANY_STATE "Alterar Estado Empresa de Inativo para Ativo? (S/N)?"
#define MSG_COMPANY_ALREADY_ACTIVE "O estado da empresa ja esta ativo!"
#define MSG_MAX_COMPANY_BRANCHES "Numero maximo de ramos de atividade atingido."
#define MSG_BRENCHES_ALREADY_EXIST "Ja existe um ramo de atividade registado com este nome!"
#define MSG_BRANCHES_INSERT_SUCESS "Ramo de atividade inserido com sucesso!"
#define ERROR_BRANCHES_DONT_EXIST "O Ramo de atividade nao existe!"
#define MSG_BRANCHES_UPDATE_SUCESS "Ramo de atividade atualizado com sucesso!"
#define MSG_BRANCHES_REMOVE_SUCCESS "Ramo de atividade removido com sucesso!"
#define ERROR_BRANCHES_REMOVE "Nao podes remover o Ramo, esta a ser usado numa empresa ativa!"
#define ERROR_BRANCHES_INACTIVE_NOT_ALLOWED "Nao pode alterar o estado da empresa para Ativo!"
#define MSG_CHANGE_BRANCHES_STATE_ACTIVE "Alterar Estado Ramo de Ativdade de Inativo para Ativo? (S/N)?"
#define MSG_BRANCHES_CHANGE_STATE_SUCESS "Estado do Ramo de Ativdade alterado com sucesso!"
#define ERROR_INVALID_BRANCHES_INDEX "Indice do ramo de atividade invalido!"
#define MSG_CHANGE_BRANCHES_STATE "Alterar Estado Ramo de Atividade Inativo (S/N)?"
#define ERROR_COMPANY_ALREADY_HAVE_THIS_BRANCHES "Ja existe uma empresa com este Ramo de Atividade ativo!"
#define MSG_BRANCHES_ALREADY_ACTIVE "O estado do ramo de atividade ja esta ativo!"
#define MAX_COMPANY_NAME_SIZE 60
#define MAX_COMPANY_CATEGORY_SIZE 60
#define MAX_COMPANY_BRANCHES_SIZE 60
#define MAX_COMPANY_STREET_SIZE 60
#define MAX_COMPANY_LOCATION_SIZE 60
#define MAX_COMPANY_POSTALCODE_SIZE 9
#define MAX_EMAIL_SIZE 50
#define MAX_TITLE_SIZE 40
#define MAX_TEXT_SIZE 100
#define MAX_RATE 5

typedef enum {INATIVO, ATIVO} Estado;

typedef struct {
    int nota;
    char nomeUtilizador[MAX_COMPANY_NAME_SIZE], emailUtilizador[MAX_EMAIL_SIZE];
} Classificacao;
    
typedef struct {
    char titulo[MAX_TITLE_SIZE], texto[MAX_TEXT_SIZE], nomeUtilizador[MAX_COMPANY_NAME_SIZE], emailUtilizador[MAX_EMAIL_SIZE];
} Comentario;

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
} Empresa;  
    
typedef struct {
    int contador, alocadas;
    Empresa *empresas;
} Empresas;

typedef struct {
    Estado estado; 
    char nome[MAX_COMPANY_BRANCHES_SIZE];
} RamoAtividade;

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
 * The function checks if the NIF is unique and  ensures that the 'Empresas' structure is not full before adding a new one!
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 * @param ramosAtividade Pointer to the 'RamosAtividade' structure.
 */
void createCompanies(Empresas *empresas, RamosAtividade *ramosAtividade);

/**
 * @brief Updates information for a company within the 'Empresas' structure.
 *
 * This function prompts the user to input a NIF, searches for the matching
 * company within the 'Empresas' structure, and then calls the 'atualizarEmpresa'
 * function to update the information for that specific company.
 *
 * @param empresas Pointer to the 'Empresas' structure containing company information.
 */
void updateCompanies(Empresas *empresas, RamosAtividade *ramosAtividade);

/**
 * @brief Updates information for a specific company.
 *
 * This function prompts the user to input new information for a company,
 * such as Name, Category, Activity Branch, Street, Location, and Postal code.
 * It also allows the administrator to change the state of the company (active or inactive).
 *
 * @param empresa Pointer to the 'Empresa' structure representing the company to be updated.
 * @param ramosAtividade Pointer to the 'RamosAtividade' structure.
 */
void updateCompany(Empresa *empresa, RamosAtividade *ramosAtividade);


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
 * This function changes all informations of a company structure to default values, removing or resetting the information.
 *
 * @param empresa Pointer to the 'Empresa' structure representing the company to be reset.
 */
void removeCompany(Empresa *empresa);


/**
 * @brief Searches for a specific Activity Branch within the 'RamosAtividade' structure.
 *
 * This function iterates through the 'RamosAtividade' structure to find an matching Branch
 * with a specified name. If the Branch is found, it returns the index of the Branch,
 * otherwise, it returns -1.
 *
 * @param ramosAtividade The 'RamosAtividade' structure containing industry information.
 * @param nome Pointer to a string representing the name of the Activity Branch.
 * @return If the Branch is found, the function returns the index of the industry, otherwise, -1.
 */
int searchBranchIndexByName(RamosAtividade ramosAtividade, char *nome);

/**
 * @brief Searches for a specific Activity Branch within the 'RamosAtividade' structure and verifys the current state.
 *
 * This function iterates through the 'RamosAtividade' structure to find an matching Branch
 * with a specified name. If the Branch is found and the current state is active, it returns the index of the Branch,
 * otherwise, it returns -1.
 *
 * @param ramosAtividade The 'RamosAtividade' structure containing industry information.
 * @param nome Pointer to a string representing the name of the Activity Branch.
 * @return If the Branch is found and current state is active, the function returns the index of the Activity Branch, otherwise, -1.
 */
int searchBranchIndexAndState(RamosAtividade ramosAtividade, char *nome);

/**
 * @brief Creates a new company Branch and adds it to the 'RamoAtividade' structure.
 *
 * This function prompts the user to input the name of a new na Activity Branch,
 * The function checks if the Name is unique and ensures that the 'RamosAtividade' structure is not full before adding a new one!
 *
 * @param ramosAtividade Pointer to the RamosAtividade structure representing the collection of activity branches.
 */
void createActivityBranches(RamosAtividade *ramosAtividade);

/**
 * @brief Updates the state of a business branch, based on user choice.
 *
 * This function allows the user to update the name and state (active or inactive) of an existing Activity Branch
 * represented by the provided RamoAtividade structure.
 *
 * @param ramoAtividade Pointer to the RamoAtividade structure representing the activity branch.
 */
void updateActivityBranch(RamoAtividade *ramoAtividade);

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
 * @param ramosAtividade Pointer to the RamosAtividade structure representing the collection of business branches.
 * @param empresas Pointer to the Empresas structure representing the collection of companies.
 */

void removeActivityBranches(RamosAtividade *ramosAtividade, Empresas *empresas);

//DOCUMENTAR!!
void viewReportMaxRating(Empresas *empresas);

#endif /* ADMIN_H */