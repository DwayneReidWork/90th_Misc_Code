#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char  first_name[50];
    char  last_name[50];
    char  id[50];
    float math;
    float english;
    float science;
    float average;
    char  letter_grade[10];
} Class_Info;

const char * FILE_NAME = "StudentGradebook.txt";

int get_num_file_lines();
Class_Info * read_write_data(Class_Info *arr, const char * ACTION);
void add_students(Class_Info * Students, int file_size_counter);
void update_students(Class_Info * Students);
void print_student_list(Class_Info * Students);

int main()
{
    int  menu_choice;
    int num_lines = get_num_file_lines();

    // allocate enough memory for a max of 20 students
    Class_Info * Students = (Class_Info *)malloc(num_lines * sizeof(Class_Info));

    // Read existing data into the array
    if (read_write_data(Students, "read") == NULL)
    {
        // If no file or error, just start fresh with empty array
        Students[0].id[0] = '\0';
    }

    printf("Thank you for using Eck's Gradebook\n"
           "1 - To add new students\n"
           "2 - To update grades for an existing student\n"
           "3 - To get the average class grade\n"
           "4 - To exit\n>>> ");
    scanf("%d", &menu_choice);

    switch (menu_choice)
    {
    case 1:
        add_students(Students, num_lines);
        break;

    case 2:
        update_students(Students);
        break;

    case 3:
        // future code for class average
        break;

    case 4:
        printf("Goodbye\n");
        exit(0);

    default:
        printf("Invalid, Goodbye\n");
        break;
    }

    free(Students);
    return 0;
}

void update_students(Class_Info * Students)
{
    print_student_list(Students);
    int user_switch_choice;
    //char
/*
    printf("\nPlease choose one of the following menu options:\n"
        "1 - Print student list\n"
        "2 - Select student to update\n"
        "3 - Exit\n>>>"
    );
    if(scanf("%d",&user_switch_choice) == 1)
    {
        printf("Not implemented")
    }
    else
    {
        printf("Invalid entry, please try again!\n");
    }

    switch (expression)
    {
    case 1:
        printf("Not yet implemented...\n");
        break;
    
    case 2:
        printf("Not yet implemented...\n");
        break;
    
    case 3:
        printf("Would you like to save changes? (Y/N)\n>>> ");
        if ()
        break;
    
    default:
        printf("Invalid option. Please try again.")
        break;
    } */
}

void print_student_list(Class_Info * Students)
{
    // Assuming the Students array is terminated by an empty id
    // or that there's a maximum of 20 students
    int i = 0;
    while (i < 20 && Students[i].id[0] != '\0')
    {
        printf("%s: %s %s\n", Students[i].id, Students[i].first_name, Students[i].last_name);
        i++;
    }
}

Class_Info * read_write_data(Class_Info *arr, const char * ACTION)
{
    FILE *fp = NULL;

    if (strcmp(ACTION, "read") == 0)
    {
        fp = fopen(FILE_NAME, "r");
        if (!fp)
        {
            // If we can't open the file, return NULL to indicate failure
            return NULL;
        }

        int index = 0;
        while (fscanf(fp, "%49s %49s %49s %f %f %f %f %9s",
                      arr[index].first_name,
                      arr[index].last_name,
                      arr[index].id,
                      &arr[index].math,
                      &arr[index].english,
                      &arr[index].science,
                      &arr[index].average,
                      arr[index].letter_grade) == 8)
        {
            index++;
        }

        // Terminate the array with an empty id so we know where it ends
        if (index < 20) {
            arr[index].id[0] = '\0';
        }

        fclose(fp);
        return arr;
    }
    else if (strcmp(ACTION, "save") == 0)
    {
        fp = fopen(FILE_NAME, "w");
        if (!fp)
        {
            return NULL;
        }

        for (int i = 0; arr[i].id[0] != '\0'; i++)
        {
            fprintf(fp, "%s %s %s %.2f %.2f %.2f %.2f %s\n",
                    arr[i].first_name,
                    arr[i].last_name,
                    arr[i].id,
                    arr[i].math,
                    arr[i].english,
                    arr[i].science,
                    arr[i].average,
                    arr[i].letter_grade);
        }

        fclose(fp);
        return arr;
    }
    else
    {
        // Invalid ACTION
        return NULL;
    }
}

void add_students(Class_Info * Students, int file_size_counter)
{
    int added_students = 0;
    printf("How many students would you like to add? ");
    scanf("%d", &added_students);

    // ensure you dont add more than 20 students
    if ((file_size_counter + added_students) > 20)
    {
        printf("you cant have more than 20 students\n");
        exit(0);
    }
    else
    {
        // find the current number of students read into the array
        int current_count = 0;
        while (current_count < 20 && Students[current_count].id[0] != '\0')
        {
            current_count++;
        }

        // for each student added enter all values
        for (int i = 0; i < added_students; i++)
        {
            printf("Enter the student's first name: ");
            scanf("%s", Students[current_count + i].first_name);
            printf("Enter the student's last name: ");
            scanf("%s", Students[current_count + i].last_name);
            printf("Enter the student's id: ");
            scanf("%s", Students[current_count + i].id);
            printf("Enter the student's math grade: ");
            scanf("%f", &Students[current_count + i].math);
            printf("Enter the student's english grade: ");
            scanf("%f", &Students[current_count + i].english);
            printf("Enter the student's science grade: ");
            scanf("%f", &Students[current_count + i].science);
            Students[current_count + i].average = ((Students[current_count + i].math
                                                  + Students[current_count + i].english
                                                  + Students[current_count + i].science) / 3);
            printf("Average: %.2f\n", Students[current_count + i].average);

            // set the letter grade
            if (Students[current_count + i].average < 60)
            {
                strcpy(Students[current_count + i].letter_grade, "F");
            }
            else if (Students[current_count + i].average < 70)
            {
                strcpy(Students[current_count + i].letter_grade, "D");
            }
            else if (Students[current_count + i].average < 80)
            {
                strcpy(Students[current_count + i].letter_grade, "C");
            }
            else if (Students[current_count + i].average < 90)
            {
                strcpy(Students[current_count + i].letter_grade, "B");
            }
            else
            {
                strcpy(Students[current_count + i].letter_grade, "A");
            }
        }

        // After adding all new students, save changes using the given function
        if (read_write_data(Students, "save") == NULL)
        {
            printf("Error saving data.\n");
        }
    }
}

int get_num_file_lines()
{
    FILE *file = fopen("StudentGradebook.txt", "r");
    int  file_size_counter = 0;
    char ch;

    // make sure file properly opens
    if (file == NULL) 
    {
        perror("Error opening file");
        return 1;
    }

    // count the lines in the gradebook textfile
    while(!feof(file))
    {
        ch = fgetc(file);
        if(ch == '\n')
        {
            file_size_counter++;
        }
    }

    fclose(file);
    
    return file_size_counter;
}