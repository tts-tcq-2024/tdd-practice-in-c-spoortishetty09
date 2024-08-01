#include <stdio.h>
#include <assert.h>

// Function prototype
int string_calculator(const char *numbers);

void test_empty_string() {
    assert(string_calculator("") == 0);
}

int main() {
    test_empty_string();
    printf("All tests passed!\n");
    return 0;
}

