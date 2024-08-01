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

 


