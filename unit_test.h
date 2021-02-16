#ifndef UNIT_TEST_H
#define UNIT_TEST_H

/* structure */
typedef struct {
    unsigned int (*p_test_primnum)();
    unsigned int (*p_test_gcd)();
    unsigned int (*p_test_lcm)();
}test_class;

/*** prototype declaration ***/
unsigned int test_primum();
unsigned int test_gcd();
unsigned int test_lcm();
void test_init(test_class *test);
void test_exec(test_class *test);

#endif