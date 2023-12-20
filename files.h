#ifndef FILES_H
#define FILES_H

#define FILENAME "companies.bin"
#define FILENAME_BRACHES "branches.bin"
#define LOG_FILE "logs.txt"
#define MAX_COMPANIES 50

void liberarEmpresa(Empresa *empresa);
void liberarEmpresas(Empresas *listaEmpresas);
void liberarRamosAtividade(RamosAtividade *rAtividadeList);
void logMsg(char *msg, char *filename);


void writeCompanies(Empresas *listaEmpresas);
void readCompanies(Empresas *listaEmpresas);
void removeCompanyFromFile(int nif);
void updateCompanyInFile(Empresa *empresa);
void writeActivityBranches(RamosAtividade *ramosAtividade);
void readActivityBranches(RamosAtividade *ramosAtividade);
void removeActivityBranchFromFile(char *nome);
void updateActivityBranchInFile(RamoAtividade *ramoAtividade);


#endif /* FILES_H */