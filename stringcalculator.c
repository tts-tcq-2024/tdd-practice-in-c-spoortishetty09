#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "StringCalculator.h"




void test_empty_string()
{
    assert(string_calculator("") == 0);
}

int main() {
    test_empty_string();
     test_empty_input();
    test_single_zero();
    test_two_numbers();
    test_newline_delimiter();
    test_ignore_numbers_greater_than_1000();
    test_custom_delimiter();
    printf("All tests passed!\n");
    return 0;
}

// Function to add numbers from the input string
int add(const char* numbers) 
{
    // If input is empty, return 0
    if (numbers == NULL || strlen(numbers) == 0) 
    {
        return 0;
    }

    // Create a copy of the input string to work with
    
    char *numbers_copy = strdup(numbers);
    if (numbers_copy == NULL)
    {
        return -1; // Memory allocation failed
    }

    // Default delimiter is a comma
    
    char *delimiter = "," ;
    
    // Check for custom delimiter
    if (strncmp(numbers, "//", 2) == 0) 
    {
        char *newline = strchr(numbers, '\n');
        if (newline != NULL)
        {
            *newline = '\0'; // Split the delimiter part from numbers
            delimiter = numbers + 2; // Custom delimiter
            numbers_copy = newline + 1; // Update numbers_copy to skip the delimiter line
        }
    }

    // Replace newline characters with commas for consistency
    for (char *p = numbers_copy; *p; ++p)
        {
        if (*p == '\n')
        {
            *p = ',';
        }
    }

    // Tokenize the input string using the delimiter
    char *token = strtok(numbers_copy, delimiter);
    int sum = 0;
    
    while (token != NULL) 
    {
        int number = atoi(token); // Convert token to integer
        if (number <= 1000) 
        {     // Ignore numbers greater than 1000
            sum += number;
        }
        token = strtok(NULL, delimiter); // Get the next token
    }

    free(numbers_copy); // Free the allocated memory
    return sum;
}


// Test cases
void test_empty_input()
{
    assert(add("") == 0);
}

void test_single_zero()
{
    assert(add("0") == 0);
}

void test_two_numbers() {
    assert(add("1,2") == 3);
}

void test_newline_delimiter()
{
    assert(add("1\n2,3") == 6);
}

void test_ignore_numbers_greater_than_1000()
{
    assert(add("1,1001") == 1);
}

void test_custom_delimiter() 
{
    assert(add("//;\n1;2") == 3);
}

 


