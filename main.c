#include<stdio.h>
#include<string.h>

struct student
{
    int roll;
    char name[50];
    float marks;
};
void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main(int argc, char const *argv[])
{
    int choice;

    do {
        printf("\n====== Student Record Management ======\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }

    } while(choice != 6);

    return 0;
}

void addStudent(){
    FILE *fp = fopen("student.dat","ab");
    struct student s;
    printf("Enter the student roll no :\n");
    scanf("%d",&s.roll);
    printf("Enter the name of student :\n");
    scanf("%s",s.name);
    printf("Enter the marks :\n");
    scanf("%f",&s.marks);

    fwrite(&s,sizeof(s),1,fp);
    fclose(fp);
    printf("student added successfully\n");
}

void viewStudents(){
    FILE *fp =fopen("student.dat","rb");
    struct student s;

    printf("<--- all students --->\n");
    while (fread(&s,sizeof(s),1,fp))
    {
        printf("roll :%d\n ,name :%s\n , marck: %2f\n",s.roll,s.name,s.marks);
    }
    
    fclose(fp);
}

void searchStudent(){
    FILE *fp = fopen("students.dat", "rb");
    struct student s;
    int roll, found = 0;

    printf("Enter Roll Number to Search: ");
    scanf("%d", &roll);

    while(fread(&s, sizeof(s), 1, fp)) {
        if(s.roll == roll) {
            printf("Found: Roll: %d, Name: %s, Marks: %.2f\n", s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Student with Roll %d not found.\n", roll);
    }

    fclose(fp);
}
void updateStudent(){
    FILE *fp = fopen("students.dat", "rb+");
    struct student s;
    int roll, found = 0;

    printf("Enter Roll Number to Update: ");
    scanf("%d", &roll);

    while(fread(&s, sizeof(s), 1, fp)) {
        if(s.roll == roll) {
            printf("Current Name: %s, Marks: %.2f\n", s.name, s.marks);
            printf("Enter New Name: ");
            scanf("%s", s.name);
            printf("Enter New Marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);  // move file pointer back
            fwrite(&s, sizeof(s), 1, fp);
            found = 1;
            printf("Record updated.\n");
            break;
        }
    }

    if(!found) {
        printf("Student with Roll %d not found.\n", roll);
    }

    fclose(fp);
}
void deleteStudent(){
    FILE *fp = fopen("students.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct student s;
    int roll, found = 0;

    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);

    while(fread(&s, sizeof(s), 1, fp)) {
        if(s.roll != roll) {
            fwrite(&s, sizeof(s), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if(found) {
        printf("Student deleted successfully.\n");
    } else {
        printf("Student with Roll %d not found.\n", roll);
    }
}


