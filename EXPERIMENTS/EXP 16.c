#include <stdio.h>

struct Employee
{
    int id;
    char name[30];
    float salary;
};

int main()
{
    FILE *fp;
    struct Employee emp;
    int n, i, search;
    int found = 0;

    fp = fopen("employee.dat", "wb+");

    if(fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Store employee records
    for(i = 0; i < n; i++)
    {
        printf("\nEnter Employee ID: ");
        scanf("%d", &emp.id);

        printf("Enter Name: ");
        scanf("%s", emp.name);

        printf("Enter Salary: ");
        scanf("%f", &emp.salary);

        fwrite(&emp, sizeof(emp), 1, fp);
    }

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &search);

    rewind(fp);

    // Search employee
    while(fread(&emp, sizeof(emp), 1, fp) == 1)
    {
        if(emp.id == search)
        {
            printf("\nEmployee Found\n");
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Salary: %.2f\n", emp.salary);

            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Employee not found\n");

    fclose(fp);

    return 0;
}
