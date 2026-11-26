```c
#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    int marks[3];
    int total;
    float percentage;
    char grade;
};

struct Student s[100];
int count = 0;

// Calculate total, percentage and grade
void calculate(int i)
{
    s[i].total = 0;

    for (int j = 0; j < 3; j++)
    {
        s[i].total += s[i].marks[j];
    }

    s[i].percentage = s[i].total / 3.0;

    if (s[i].percentage >= 90)
        s[i].grade = 'A';
    else if (s[i].percentage >= 80)
        s[i].grade = 'B';
    else if (s[i].percentage >= 70)
        s[i].grade = 'C';
    else if (s[i].percentage >= 60)
        s[i].grade = 'D';
    else
        s[i].grade = 'F';
}

// Add student details
void addStudent()
{
    int roll;

    if (count >= 100)
    {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &roll);

    // Check duplicate roll number
    for (int i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            printf("\nRoll Number already exists!\n");
            return;
        }
    }

    s[count].roll = roll;

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", s[count].name);

    printf("Enter marks in 3 subjects:\n");

    for (int i = 0; i < 3; i++)
    {
        printf("Subject %d: ", i + 1);
        scanf("%d", &s[count].marks[i]);

        if (s[count].marks[i] < 0 ||
            s[count].marks[i] > 100)
       
