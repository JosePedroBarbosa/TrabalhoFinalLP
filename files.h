#ifndef FILES_H
#define FILES_H

#define FILENAME "companies.bin"
#define LOG_FILE "logs.txt"
#define MAX_COMPANIES 50

void liberarEmpresa(Empresa *empresa);
void liberarEmpresas(Empresas *listaEmpresas);
void liberarRamosAtividade(RamosAtividade *rAtividadeList);
void logMsg(char *msg, char *filename);
void write(Empresas *listaEmpresas);
void ler(Empresas *listaEmpresas);

#endif /* FILES_H */