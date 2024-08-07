#include "StringCalculator.h"
#include <gtest/gtest.h>

int add(const char* numbers) {
    char delimiter[2] = ",";
    // If input is empty, return 0
    if (numbers == NULL || strlen(numbers) == 0) {
        return 0;
    }

    // Create a copy of the input string to work with
    char *numbers_copy = strdup(numbers);
    if (numbers_copy == NULL) {
        return -1; // Memory allocation failed
    }

    // Check for custom delimiter
    if (strncmp(numbers, "//", 2) == 0) {
        const char *newline = strchr(numbers, '\n');
        if (newline != NULL) {
            // Extract custom delimiter
            char *custom_delim = strndup(numbers + 2, newline - numbers - 2);
            if (custom_delim != NULL) {
                snprintf(delimiter, sizeof(delimiter), "%s", custom_delim);
                free(custom_delim);
                numbers_copy = strdup(newline + 1);
                if (numbers_copy == NULL) {
                    free(numbers_copy);
                    return -1; // Memory allocation failed
                }
            }
        }
    }

    // Replace newline characters with commas for consistency
    for (char *p = numbers_copy; *p; ++p) {
        if (*p == '\n') {
            *p = ',';
        }
    }

    // Tokenize the input string using the delimiter
    char *token = strtok(numbers_copy, delimiter);
    int sum = 0;

    while (token != NULL) {
        int number = atoi(token); // Convert token to integer
        if (number <= 1000) {     // Ignore numbers greater than 1000
            sum += number;
        }
        token = strtok(NULL, delimiter); // Get the next token
    }

    free(numbers_copy); // Free the allocated memory
    return sum;
}

// GTest test cases
TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
    int expectedresult = 0;
    const char* input = "";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
    int expectedresult = 0;
    const char* input = "0";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
    int expectedresult = 3;
    const char* input = "1,2";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
    int expectedresult = 6;
    const char* input = "1\n2,3";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
    int expectedresult = 1;
    const char* input = "1,1001";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
    int expectedresult = 3;
    const char* input = "//;\n1;2";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
