#include <stdio.h>
#include <math.h>
#include <stdbool.h> 
#include "../types/vec3.h"

const float ERROR_MARGIN = 1e-5f;

// Structs representing test cases
typedef struct {
    vec3_t v1;
    vec3_t v2;
    vec3_t ground_truth;
} BASE_TEST_CASE;

typedef struct {
    vec3_t v1;
    float scalar;
    vec3_t ground_truth;
} SCALAR_TEST_CASE;

typedef struct {
    vec3_t v1;
    vec3_t v2;
    float ground_truth;

} DOT_PRODUCT_TEST_CASE;

// Test functions
bool addition_test(BASE_TEST_CASE);
bool subtraction_test(BASE_TEST_CASE);
bool multiplication_test(SCALAR_TEST_CASE);
bool division_test(SCALAR_TEST_CASE);
bool dot_product_test(DOT_PRODUCT_TEST_CASE);

// Test runner functions
int base_test_runner(bool (*func)(BASE_TEST_CASE), BASE_TEST_CASE[], int);
int scalar_test_runner(bool (*func)(SCALAR_TEST_CASE), SCALAR_TEST_CASE[], int);
int dp_test_runner(DOT_PRODUCT_TEST_CASE[], int);

// Equality functions
bool vec3_equal(vec3_t, vec3_t);
bool float_equal(float, float);

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

    printf("\nRunning subtraction tests\n");
    int sub_fail = base_test_runner(*subtraction_test, subtraction_test_cases, num_sub_cases);

    num_failed += sub_fail;
    num_passed += num_sub_cases - sub_fail;

    // Multiplication tests
    SCALAR_TEST_CASE mutliply_test_cases[3];

    SCALAR_TEST_CASE mult_t1 = {
        {5, 6, 4},
        5,
        {25, 30, 20}
    };

    SCALAR_TEST_CASE mult_t2 = {
        {5.1, 6.0567, 4.31234},
        5,
        {25.5, 30.2835, 21.5617}
    };

    SCALAR_TEST_CASE mult_t3 = {
        {5.1, 6.2, 4.3},
        4.5,
        {22.95, 27.9, 19.35}
    };

    mutliply_test_cases[0] = mult_t1;
    mutliply_test_cases[1] = mult_t2;
    mutliply_test_cases[2] = mult_t3;

    int num_mult_cases = sizeof(mutliply_test_cases) / sizeof(mutliply_test_cases[0]);

    printf("\nRunning multiplication tests\n");
    int mult_fail = scalar_test_runner(*multiplication_test, mutliply_test_cases, num_mult_cases);

    num_failed += mult_fail;
    num_passed += num_mult_cases - mult_fail; 

    // Division tests
    SCALAR_TEST_CASE division_test_cases[3];

    SCALAR_TEST_CASE div_t1 = {
        {5, 6, 4},
        5,
        {1, 1.2, 0.8}
    };

    SCALAR_TEST_CASE div_t2 = {
        {5.1, 6.0567, 4.31234},
        5,
        {1.02, 1.21134, 0.862468}
    };

    SCALAR_TEST_CASE div_t3 = {
        {5.1, 6.2, 4.3},
        4.5,
        {1.1333333, 1.377777, 0.95555555}
    };

    division_test_cases[0] = div_t1;
    division_test_cases[1] = div_t2;
    division_test_cases[2] = div_t3;

    int num_div_cases = sizeof(division_test_cases) / sizeof(division_test_cases[0]);

    printf("\nRunning division tests\n");
    int div_fail = scalar_test_runner(*division_test, division_test_cases, num_div_cases);

    num_failed += div_fail;
    num_passed += num_div_cases - div_fail; 

    // Dot product tests
    DOT_PRODUCT_TEST_CASE dot_product_test_cases[2];

    DOT_PRODUCT_TEST_CASE dp_t1 = {
        {2, 3, 4},
        {4, 5, -2},
        15
    };

    DOT_PRODUCT_TEST_CASE dp_t2 = {
        {2.12, 3.234, 4},
        {4.4535, 5.321, -2},
        18.649534
    };

    dot_product_test_cases[0] = dp_t1;
    dot_product_test_cases[1] = dp_t2;

    int num_dp_cases = sizeof(dot_product_test_cases) / sizeof(dot_product_test_cases[0]); 

    printf("\nRunning dot product tests\n");
    int dp_fail = dp_test_runner(dot_product_test_cases, num_dp_cases);

    num_failed += dp_fail;
    num_passed += num_dp_cases - dp_fail; 

    printf("\n=== Final Results ===\n");
    printf("Total passed: %d\n", num_passed);
    printf("Total failed: %d\n", num_failed);

    return 1;
}

// Test addition
bool addition_test(BASE_TEST_CASE test_case) {
    vec3_t res = vec3_add(test_case.v1, test_case.v2);

    bool passed = vec3_equal(res, test_case.ground_truth);

    return passed;
}

// Test subtraction
bool subtraction_test(BASE_TEST_CASE test_case) {
    vec3_t res = vec3_sub(test_case.v1, test_case.v2);

    bool passed = vec3_equal(res, test_case.ground_truth);

    return passed;
}

// Test multiplication
bool multiplication_test(SCALAR_TEST_CASE test_case) {
    vec3_t res = vec3_mult(test_case.v1, test_case.scalar);

    bool passed = vec3_equal(res, test_case.ground_truth);

    return passed;
}

// Test division
bool division_test(SCALAR_TEST_CASE test_case) {
    vec3_t res = vec3_div(test_case.v1, test_case.scalar);

    bool passed = vec3_equal(res, test_case.ground_truth);

    return passed;
}

// Test dot product
bool dot_product_test(DOT_PRODUCT_TEST_CASE test_case) {
    float res = vec3_dot(test_case.v1, test_case.v2);

    bool passed = float_equal(res, test_case.ground_truth);

    return passed;
}

// Test runners
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
            printf("Failed test case %d\n", i);
            num_failed++;
        }
    }

    return num_failed;
};

int scalar_test_runner(bool (*func)(SCALAR_TEST_CASE), SCALAR_TEST_CASE test_cases[], int num_cases) {
    int num_passed = 0;
    int num_failed = 0;

    int i;
    for (i = 0; i < num_cases; i++) {
        bool passed = func(test_cases[i]);
        if (passed) {
            printf("Passed test case %d\n", i);
            num_passed++;
        } else {
            printf("Failed test case %d\n", i);
            num_failed++;
        }
    }

    return num_failed;
};

int dp_test_runner(DOT_PRODUCT_TEST_CASE test_cases[], int num_cases) {
    int num_passed = 0;
    int num_failed = 0;

    int i;
    for (i = 0; i < num_cases; i++) {
        bool passed = dot_product_test(test_cases[i]);
        if (passed) {
            printf("Passed test case %d\n", i);
            num_passed++;
        } else {
            printf("Failed test case %d\n", i);
            num_failed++;
        }
    }

    return num_failed;
}

// Equality function
bool vec3_equal(vec3_t v1, vec3_t v2) {
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

bool float_equal(float f1, float f2) {
    return fabs(f1 - f2) < ERROR_MARGIN;
}
