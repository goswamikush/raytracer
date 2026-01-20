#include <stdio.h>
#include <math.h>
#include <stdbool.h> 
#include "../types/vec3.h"

const float ERROR_MARGIN = 1e-5f;

typedef struct {
    vec3_t v1;
    vec3_t v2;
    vec3_t ground_truth;
} ADDITION_TEST_CASE;

bool addition_test(ADDITION_TEST_CASE);
bool is_equal(vec3_t, vec3_t);

int main() {
    int num_passed = 0;
    int num_failed = 0;

    // Setup addition test cases
    ADDITION_TEST_CASE addition_test_cases[2];

    ADDITION_TEST_CASE simple = {
        {1, 5, 4},
        {2, 6, 8},
        {3, 11, 12}
    };

    addition_test_cases[0] = simple;

    ADDITION_TEST_CASE complex = {
        {1.022, 5.891, 4.56},
        {2.2, 6.12, 8.97},
        {3.222, 12.0110, 13.53}
    };

    addition_test_cases[1] = complex;

    // Loop through all test cases
    int num_cases = sizeof(addition_test_cases) / sizeof(addition_test_cases[0]);
    int i;
    bool passed;

    printf("Running addition tests");
    for (i = 0; i < num_cases; i++) {
        passed = addition_test(addition_test_cases[i]);
        if (passed) {
            printf("Passed test case %d\n", i);
            num_passed++;
        } else {
            printf("Passed test case %d\n", i);
            num_failed++;
        }
    };

    printf("Total passed: %d\n", num_passed);
    printf("Total failes: %d\n", num_failed);

    return 1;
}

// Test addition
bool addition_test(ADDITION_TEST_CASE test_case) {
    vec3_t res = vec3_add(test_case.v1, test_case.v2);

    bool passed = is_equal(res, test_case.ground_truth);

    return true;
}

// Equality function
bool is_equal(vec3_t v1, vec3_t v2) {
    bool passed = true;

    if (fabs(v1.x - v2.x) > ERROR_MARGIN) {
        passed = passed && false;

        printf("X value mismatch\n");
        printf("V1: %f\n", v1.x);
        printf("V2: %f\n", v2.x);
    };

    if (fabs(v1.y - v2.y) > ERROR_MARGIN) {
        passed = passed && false;

        printf("Y value mismatch\n");
        printf("V1: %f\n", v1.y);
        printf("V2: %f\n", v2.y);
    };

    if (fabs(v1.z - v2.z) > ERROR_MARGIN) {
        passed = passed && false;

        printf("Z value mismatch\n");
        printf("V1: %f\n", v1.z);
        printf("V2: %f\n", v2.z);
    };

    return passed;
}
