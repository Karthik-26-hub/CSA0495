#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FILENAME "employees.dat"
struct Employee
{
int id;char name[50];float salary;
};
void addEmployee()
{
    FILE *file=fopen(FILENAME,"ab");
    if(!file)
	{
	printf("Error opening file!\n");
	return;
	}
    struct Employee emp;
    printf("Enter Employee ID: ");
	scanf("%d",&emp.id);
    printf("Enter Employee Name: ");
	scanf(" %[^\n]",emp.name);
    printf("Enter Employee Salary: ");
	scanf("%f",&emp.salary);
    fwrite(&emp,sizeof(struct Employee),1,file);
    fclose(file);
    printf("Employee record added successfully!\n");
}
void searchEmployee()
{
    FILE *file=fopen(FILENAME,"rb");
    if(!file){printf("Error opening file!\n");return;}
    int id;struct Employee emp;
    printf("Enter Employee ID to search: ");scanf("%d",&id);
    while(fread(&emp,sizeof(struct Employee),1,file)){
    	
        if(emp.id==id)
		{
            printf("\nEmployee Found:\nID: %d\nName: %s\nSalary: %.2f\n",emp.id,emp.name,emp.salary);
            fclose(file);return;
        }
    }
    printf("Employee not found!\n");
    fclose(file);
}
void updateEmployee()
{
    FILE *file=fopen(FILENAME,"rb+");
    if(!file){printf("Error opening file!\n");return;}
    int id,found=0;struct Employee emp;
    printf("Enter Employee ID to update: ");scanf("%d",&id);
    while(fread(&emp,sizeof(struct Employee),1,file))
	{
        if(emp.id==id)
		{
            found=1;
            printf("Enter new Name: ");scanf(" %[^\n]",emp.name);
            printf("Enter new Salary: ");scanf("%f",&emp.salary);
            fseek(file,-sizeof(struct Employee),SEEK_CUR);
            fwrite(&emp,sizeof(struct Employee),1,file);
            printf("Employee record updated successfully!\n");
            break;
        }
    }
    if(!found)printf("Employee not found!\n");
    fclose(file);
}
void deleteEmployee()
{
    FILE *file=fopen(FILENAME,"rb");
    if(!file)
	{
	printf("Error opening file!\n");
	return;
	}
    FILE *temp=fopen("temp.dat","wb");
    if(!temp){printf("Error creating temporary file!\n");fclose(file);return;}
    int id,found=0;struct Employee emp;
    printf("Enter Employee ID to delete: ");scanf("%d",&id);
    while(fread(&emp,sizeof(struct Employee),1,file))
	{
        if(emp.id==id)found=1;
        else fwrite(&emp,sizeof(struct Employee),1,temp);
    }
    fclose(file);fclose(temp);
    remove(FILENAME);rename("temp.dat",FILENAME);
    if(found)printf("Employee record deleted successfully!\n");
    else printf("Employee not found!\n");
}
void displayEmployees()
{
    FILE *file=fopen(FILENAME,"rb");
    if(!file)
	{
	printf("Error opening file!\n");
	return;
	}
    struct Employee emp;
    printf("\nEmployee Records:\n");
    while(fread(&emp,sizeof(struct Employee),1,file))
        printf("ID: %d, Name: %s, Salary: %.2f\n",emp.id,emp.name,emp.salary);
    fclose(file);
}
int main()
{
    int choice;
    while(1)
	{
        printf("\nEmployee Management System (Random Access File)\n");
        printf("1. Add Employee\n2. Search Employee\n3. Update Employee\n4. Delete Employee\n5. Display All Employees\n6. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
		{
            case 1:addEmployee();break;
            case 2:searchEmployee();break;
            case 3:updateEmployee();break;
            case 4:deleteEmployee();break;
            case 5:displayEmployees();break;
            case 6:exit(0);
            default:printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
