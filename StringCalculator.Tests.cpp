#include <gtest/gtest.h>
#include "StringCalculator.h"

TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
    int expectedresult = 0;
    const char* input = "Hello, world!";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}
/*
TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
    int expectedresult = 0;
    const char* input = "0";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers)
{
    int expectedresult = 3;
    const char*  input = "1,2";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) 
{
    int expectedresult = 6;
    const char*  input = "1\n2,3";
    int result =add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000)
{
    int expectedresult = 1;
    const char*  input = "1,1001";
    int result =add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) 
{
    int expectedresult = 3;
    const char*  input = "//;\n1;2";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}*/

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
       const char *newline = strchr(numbers, '\n');
        if (newline != NULL)
        {
            // Make a writable copy of numbers_copy
            char *numbers_copy_mod = strdup(numbers); // Create a modifiable copy
            if (numbers_copy_mod == NULL)
            {
                free(numbers_copy);
                return -1; // Memory allocation failed
            }
          // Split the delimiter part from numbers
            *numbers_copy_mod = '\0'; // Split at the newline character
            delimiter = (char *)(numbers + 2); // Custom delimiter
            numbers_copy = (char *)(newline + 1); // Update numbers_copy to skip the delimiter line
            free(numbers_copy_mod); // Free the allocated memory
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

 



