#include <stdio.h>
#include <assert.h>

#define STRING_CALCULATOR_H

// Function prototype
int string_calculator(const char *numbers);
int add(const char* numbers);


void test_empty_string() {
    assert(string_calculator("") == 0);
}

