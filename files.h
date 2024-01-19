/**
 * @file files.h
 * @author Grupo20
 * @date 06-01-2024
 * @version 1
 *
 * @copyright Copyright (C) Grupo20 2023. All Rights MIT Licensed.
 *
 * @brief Header file containing declarations for files functions.
 *
 */

#ifndef FILES_H
#define FILES_H

#define COMPANYS_INITIAL_CAPACITY 30
#define BRANCHES_INITIAL_CAPACITY 30

#define DATA_FILE "companies.bin"
#define BRANCHES_FILE "branches.bin"
#define TEMP_FILE_COMPANIES "tempfile_companies.bin"


/**
 * @brief Loads activity branches from a file and initializes the 'RamosAtividade' structure.
 *
 * This function reads activity branches data from the specified file and initializes the 'RamosAtividade' structure.
 * If the file does not exist or contains no data, the function creates a new file and allocates initial capacity for branches.
 *
 * @param rAtividade Pointer to the 'RamosAtividade' structure to be initialized.
 * @param filename The name of the file to load activity branches data from.
 */
void loadBranches(RamosAtividade *rAtividade, char *filename);

/**
 * @brief Loads companies from a file and initializes the 'Empresas' structure.
 *
 * This function reads company data from the specified file and initializes the 'Empresas' structure.
 * If the file does not exist or contains no data, the function creates a new file and allocates initial capacity for companies.
 *
 * @param listaEmpresas Pointer to the 'Empresas' structure to be initialized.
 * @param filename The name of the file to load company data from.
 */
void loadCompanies(Empresas *listaEmpresas, char *filename);

/**
 * @brief Expands the capacity of the 'Empresas' structure to allocate more companies.
 *
 * This function dynamically reallocates memory to increase the capacity of the 'Empresas' structure.
 *
 * @param listaEmpresas Pointer to the 'Empresas' structure to be expanded.
 */
void expandCompaniesCapacity(Empresas *listaEmpresas);

/**
 * @brief Expands the capacity of the 'RamosAtividade' structure to allocate more activity branches.
 *
 * This function dynamically reallocates memory to increase the capacity of the 'RamosAtividade' structure.
 *
 * @param rAtividade Pointer to the 'RamosAtividade' structure to be expanded.
 */
void expandBranchesCapacity(RamosAtividade *rAtividade);

/**
 * @brief Saves company data to a file.
 *
 * This function writes company data from the 'Empresas' structure on the specified file.
 *
 * @param listaEmpresas Pointer to the 'Empresas' structure containing company data.
 * @param filename The name of the file to save company data to.
 */
void saveCompanies(Empresas *listaEmpresas, char *filename);

/**
 * @brief Saves activity branch data to a file.
 *
 * This function writes activity branch data from the 'RamosAtividade' structure on the specified file.
 *
 * @param rAtividade Pointer to the 'RamosAtividade' structure containing activity branch data.
 * @param filename The name of the file to save activity branch data to.
 */
void saveBranches(RamosAtividade *rAtividade, char *filename);

/**
 * @brief Updates a company's data in the file.
 *
 * This function updates a specific company's data in the file based on the given company index and the 'Empresas' structure.
 *
 * @param listaEmpresas The 'Empresas' structure containing company data.
 * @param index The index of the company to be updated in the file.
 * @param filename The name of the file to update company data in.
 */
void updateCompanyInFile(Empresas listaEmpresas, int index, char *filename);

/**
 * @brief Updates an activity branch's data in the file.
 *
 * This function updates a specific activity branch's data in the file based on the given branch index and the 'RamosAtividade' structure.
 *
 * @param rAtividade The 'RamosAtividade' structure containing activity branch data.
 * @param index The index of the activity branch to be updated in the file.
 * @param filename The name of the file to update activity branch data in.
 */
void updateBranchInFile(RamosAtividade rAtividade, int index, char *filename);

/**
 * @brief Removes a company from the file.
 *
 * This function removes a specific company's data from the file based on the given company index and the 'Empresas' structure.
 *
 * @param listaEmpresas The 'Empresas' structure containing company data.
 * @param index The index of the company to be removed from the file.
 * @param filename The name of the file to remove company data from.
 */
void removeCompanyFromFile(Empresas listaEmpresas, int index, char *filename);

/**
 * @brief Saves the program data to files.
 *
 * This function saves company and activity branch data to their respective files.
 *
 * @param listaEmpresas Pointer to the 'Empresas' structure containing company data.
 * @param rAtividade Pointer to the 'RamosAtividade' structure containing activity branch data.
 */
void saveProgramData(Empresas *listaEmpresas, RamosAtividade *rAtividade);

/**
 * @brief Frees the memory allocated for the 'RamosAtividade' structure.
 *
 * This function frees the memory allocated for the 'RamosAtividade' structure.
 *
 * @param rAtividade Pointer to the 'RamosAtividade' structure to be freed.
 */
void freeBranches(RamosAtividade *rAtividade);

/**
 * @brief Frees the memory allocated for the 'Empresas' structure.
 *
 * This function frees the memory allocated for the 'Empresas' structure, including classis and comments arrays.
 *
 * @param listaEmpresas Pointer to the 'Empresas' structure to be freed.
 */
void freeCompanies(Empresas *listaEmpresas);

#endif /* FILES_H */