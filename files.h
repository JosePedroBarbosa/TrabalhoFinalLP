#ifndef FILES_H
#define FILES_H  

#define COMPANY_INITIAL_ALLOCATION 30
#define BRANCHES_INITIAL_ALLOCATION 30

//DOCUMENTAR TODAS AS FUNCOES!!

void logMsg(char *msg, char *filename);
void uploadActivityBranches(RamosAtividade *ramosAtividade);
void saveActivityBranches(RamosAtividade *rAtividade);
void uploadCompanies(Empresas *listaEmpresas);
void saveCompanies(Empresas *listaEmpresas);

#endif /* FILES_H */