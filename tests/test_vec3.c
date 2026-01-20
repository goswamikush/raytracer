#include <stdio.h>
#include <math.h>
#include <stdbool.h> 
#include "../types/vec3.h"

const float ERROR_MARGIN = 1e-5f;

typedef struct {
    vec3_t v1;
    vec3_t v2;
    vec3_t ground_truth;
} BASE_TEST_CASE;

bool addition_test(BASE_TEST_CASE);
bool subtraction_test(BASE_TEST_CASE);
int base_test_runner(bool (*func)(BASE_TEST_CASE), BASE_TEST_CASE[], int);
bool is_equal(vec3_t, vec3_t);

int main() {
    int num_passed = 0;
    int num_failed = 0;

    // Setup addition test cases
    BASE_TEST_CASE addition_test_cases[2];

    BASE_TEST_CASE add_t1 = {
        {1, 5, 4},
        {2, 6, 8},
        {3, 11, 12}
    };

    BASE_TEST_CASE add_t2 = {
        {1.022, 5.891, 4.56},
        {2.2, 6.12, 8.97},
        {3.222, 12.0110, 13.53}
    };

    addition_test_cases[0] = add_t1;
    addition_test_cases[1] = add_t2;

    int num_add_cases = sizeof(addition_test_cases) / sizeof(addition_test_cases[0]);

    printf("Running addition tests\n");
    int add_fail = base_test_runner(*addition_test, addition_test_cases, num_add_cases);

    num_failed += add_fail;
    num_passed += num_add_cases - add_fail;
    
    // Setup subtraction test cases
    BASE_TEST_CASE subtraction_test_cases[3];

    BASE_TEST_CASE sub_t1 = {
        {9, 5, 4},
        {6, 3, 2},
        {3, 2, 2},
    };

    BASE_TEST_CASE sub_t2 = {
        {3, 1, 4},
        {6, 3, 2},
        {-3, -2, 2},
    };

    BASE_TEST_CASE sub_t3 = {
        {1.022, 6.891, 4.56},
        {2.2, 5.12, 8.97},
        {-1.178, 1.771, -4.41}
    };

    subtraction_test_cases[0] = sub_t1;
    subtraction_test_cases[1] = sub_t2;
    subtraction_test_cases[2] = sub_t3;

    int num_sub_cases = sizeof(subtraction_test_cases) / sizeof(subtraction_test_cases[0]);

    printf("Running subtraction tests\n");
    int sub_fail = base_test_runner(*subtraction_test, subtraction_test_cases, num_sub_cases);

    num_failed += sub_fail;
    num_passed += num_sub_cases - sub_fail;

    printf("Total passed: %d\n", num_passed);
    printf("Total failes: %d\n", num_failed);

    return 1;
}

// Test addition
bool addition_test(BASE_TEST_CASE test_case) {
    vec3_t res = vec3_add(test_case.v1, test_case.v2);

    bool passed = is_equal(res, test_case.ground_truth);

    return passed;
}

// Test subtraction
bool subtraction_test(BASE_TEST_CASE test_case) {
    vec3_t res = vec3_sub(test_case.v1, test_case.v2);

    bool passed = is_equal(res, test_case.ground_truth);

    return passed;
}

int base_test_runner(bool (*func)(BASE_TEST_CASE), BASE_TEST_CASE test_cases[], int num_cases) {
    int num_passed = 0;
    int num_failed = 0;

    int i;
    for (i = 0; i < num_cases; i++) {
        bool passed = func(test_cases[i]);
        if (passed) {
            printf("Passed test case %d\n", i);
            num_passed++;
        } else {
            printf("Passed test case %d\n", i);
            num_failed++;
        }
    }

    return num_failed;
};

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
