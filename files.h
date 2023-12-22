#ifndef FILES_H
#define FILES_H  

void logMsg(char *msg, char *filename);

void uploadActivityBranches(RamosAtividade *ramosAtividade);
void saveActivityBranches(RamosAtividade *rAtividade);
void uploadCompanies(Empresas *listaEmpresas);
void saveCompanies(Empresas *listaEmpresas);

#endif /* FILES_H */