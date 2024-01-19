#include <stdio.h>

int mainMenu(){
    int opc;
    printf("\n------ Main Menu ------\n");
    printf("1. Administrator\n");
    printf("2. User\n");
    printf("3. Company\n");
    printf("4. Exit Application\n");
    printf("\n-----------------------\n");
    printf("Option: ");
    scanf("%d", &opc);
    return opc;
}

int menuAdmin(){
    int opc;
    printf("\n------ Administrator Menu  ------\n");
    printf("1. Manage Companies Catalog\n");
    printf("2. Manage Activity Branches\n");
    printf("3. View Reports\n");
    printf("0. Go Back\n");
    printf("-1. Exit Application\n");
    printf("\n-----------------------\n");
    printf("Option: ");
    scanf("%d", &opc);
    return opc;
}

int subMenuAdminCatalog(){
    int opc;
    printf("\n------ Manage Companies Catalog------\n");
    printf("1. Create Company\n");
    printf("2. Update Company\n");
    printf("3. Remove Company\n");
    printf("0. Go Back\n");
    printf("-1. Exit Application\n");
    printf("\n-----------------------\n");
    printf("Option: ");
    scanf("%d", &opc);
    return opc;
}

int subMenuAdminBranches(){
    int opc;
    printf("\n------ Manage Activity Branches ------\n");
    printf("1. Create Activity Branch\n");
    printf("2. Update Activity Branch\n");
    printf("3. Remove Activity Branch\n");
    printf("0. Go Back\n");
    printf("-1. Exit Application\n");
    printf("\n-----------------------\n");
    printf("Option: ");
    scanf("%d", &opc);
    return opc;
}

int subMenuAdminReport(){
    int opc;
    printf("\n------ View Reports ------\n");
    printf("1. Report companies with max rate\n");
    printf("2. Report companies with same activity branch\n");
    printf("0. Go Back\n");
    printf("-1. Exit Application\n");
    printf("\n-----------------------\n");
    printf("Option: ");
    scanf("%d", &opc);
    return opc;
}

int userMenu(){
    int opc;
    printf("\n------ User Menu ------\n");
    printf("1. Search Companies\n");
    printf("2. Rate Company\n");
    printf("3. Comment Company\n");
    printf("0. Go Back\n");
    printf("-1. Exit Application\n");
    printf("\n-----------------------\n");
    printf("Option: ");
    scanf("%d", &opc);
    return opc;
}

int companyMenu(){
    int opc;
    printf("\n------ Company Menu ------\n");
    printf("1. Manage Company Information\n");
    printf("2. View Comments\n");
    printf("3. View Searches\n");
    printf("0. Go Back\n");
    printf("-1. Exit Application\n");
    printf("\n-----------------------\n");
    printf("Option: ");
    scanf("%d", &opc);
    return opc;
}

int menuSearchCompanies(){
    int opc;
    printf("\nChoose your search criteria: \n");
    printf("1. Name\n");
    printf("2. Category\n");
    printf("3. Activity Branch\n");
    printf("0. Go Back\n");
    printf("-1. Exit Application\n");
    printf("\n-----------------------\n");
    printf("Option: ");
    scanf("%d", &opc);
    return opc;
}

int menuManageCompanyInfo(){
    int opc;
    printf("\nChoose information to change: \n");
    printf("1. NIF\n");
    printf("2. Name\n");
    printf("3. Category\n");
    printf("4. Activity Branch\n");
    printf("5. Street\n");
    printf("6. Location\n");
    printf("7. Postal Code\n");
    printf("0. Go Back\n");
    printf("-1. Exit Application\n");
    printf("\n-----------------------\n");
    printf("Option: ");
    scanf("%d", &opc);
    return opc;
}