#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Save name and numbers to a csv file

int main(void)
{
    int entries = get_int("No of Entries :");

    FILE *file = fopen("phonebook.csv", "a");

    for(int i = 0; i < entries; i ++)
    {
        string name = get_string("Name : ");
        string number = get_string("Number : ");

        fprintf(file, "%s, %s\n", name, number);

    }

    fclose(file); // closing the file after use


}
