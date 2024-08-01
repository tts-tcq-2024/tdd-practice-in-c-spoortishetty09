#include <stdio.h>
#include <assert.h>

// Function prototype
int string_calculator(const char *numbers);
int add(const char* numbers);

#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H



#endif // STRING_CALCULATOR_H

void test_empty_string() {
    assert(string_calculator("") == 0);
}

