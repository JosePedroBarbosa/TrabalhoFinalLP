#include <stdio.h>
#include <stdlib.h>

int mainMenu(){
    int opc;
    printf("\n------ Menu Principal ------\n");
    printf("1. Administrador\n");
    printf("2. Utilizador\n");
    printf("3. Empresa\n");
    printf("4. Sair Aplicacao\n");
    printf("Opcao: ");
    scanf("%d", &opc);
    return opc;
}

int menuAdmin(){
    int opc;
    printf("\n------ Menu Administrador ------\n");
    printf("1. Gerir Catalogo de Empresas\n");
    printf("2. Gerir Ramos de Atividade\n");
    printf("3. Visualizar Relatorios\n");
    printf("0. Voltar ao menu principal\n");
    printf("-1. Sair da Aplicacao\n");
    printf("Opcao: ");
    scanf("%d", &opc);
    return opc;
}

int subMenuAdminCatalog(){
    int opc;
    printf("\n------ Gerir Catalogo de Empresas ------\n");
    printf("1. Criar empresa\n");
    printf("2. Editar empresa\n");
    printf("3. Remover empresa\n");
    printf("0. Voltar ao menu anterior\n");
    printf("-1. Sair da Aplicacao\n");
    printf("Opcao: ");
    scanf("%d", &opc);
    return opc;
}

int subMenuAdminBranches(){
    int opc;
    printf("\n------ Gerir Ramos de Atividade ------\n");
    printf("1. Criar ramo atividade\n");
    printf("2. Editar ramo atividade\n");
    printf("3. Remover ramo atividade\n");
    printf("0. Voltar ao menu anterior\n");
    printf("-1. Sair da Aplicacao\n");
    printf("Opcao: ");
    scanf("%d", &opc);
    return opc;
}

int subMenuAdminReport(){
    int opc;
    printf("\n------ Visualizar Relatorios ------\n");
    printf("1. Relatorio de Palavras-Chave Mais Procuradas\n");
    printf("2. Relatorio de Estatisticas de Uso\n");
    printf("0. Voltar ao menu anterior\n");
    printf("-1. Sair da Aplicacao\n");
    printf("Opcao: ");
    scanf("%d", &opc);
    return opc;
}

int userMenu(){
    int opc;
    printf("\n------ Menu Utilizador ------\n");
    printf("1. Pesquisar Empresas\n");
    printf("2. Classificar Empresa\n");
    printf("3. Comentar Empresa\n");
    printf("0. Voltar ao menu principal\n");
    printf("-1. Sair da Aplicacao\n");
    printf("Escolha: ");
    scanf("%d", &opc);
    return opc;
}

int companyMenu(){
    int opc;
    printf("\n------ Menu Empresa ------\n");
    printf("1. Gerir Informacoes Empresa\n");
    printf("2. Ver comentarios\n");
    printf("3. Analisar Pesquisas\n");
    printf("0. Voltar ao menu principal\n");
    printf("-1. Sair da Aplicacao\n");
    printf("Escolha: ");
    scanf("%d", &opc);
    return opc;
}

int menuSearchCompanies(){
    int opc;
    printf("\nEscolha o criterio de pesquisa: \n");
    printf("1. Nome\n");
    printf("2. Categoria\n");
    printf("3. Ramo de Atividade\n");
    printf("0. Voltar ao menu principal\n");
    printf("-1. Sair da Aplicacao\n");
    printf("Escolha: ");
    scanf("%d", &opc);
    return opc;
}

int menuManageCompanyInfo(){ 
    int opc;
    printf("\nEscolha informacao a alterar: \n");
    printf("1. NIF\n");
    printf("2. Nome\n");
    printf("3. Categoria\n");
    printf("4. Ramo de Atividade\n");
    printf("5. Rua\n");
    printf("6. Localidade\n");
    printf("7. Codigo Postal\n");
    printf("0. Voltar ao menu principal\n");
    printf("-1. Sair da Aplicacao\n");
    printf("Escolha: ");
    scanf("%d", &opc);
    return opc;
}
