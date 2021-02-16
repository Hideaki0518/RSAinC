#include "unit_test.h"
#include "rsa.h"
#include <stdio.h>

unsigned int test_primnum(){
    unsigned int ans[10];
    unsigned int i,temp;
    unsigned int ret = 1;   /* 1:test OK */

    for(i=0; i < sizeof(ans)/sizeof(ans[0]); i++){
            ans[i] = make_prime();
    }

    for(i=0; i < sizeof(ans)/sizeof(ans[0]); i++){
        temp = is_prime(ans[i]);
        if(temp == 0){
            ret = 0;
        }
    }

    if(ret){
        printf("is_prime()  is working!\tOK\n");
    }

    return ret;
}

unsigned int test_gcd(){
    /* input[a][b] a,b:int num */
    unsigned int input[5][2] = {{336,34},{88,240},{45,90},{48,1600},{90,500}};
    unsigned int ans[5] = {2,8,45,16,10};
    unsigned int i,temp;
    unsigned int ret = 1;   /* 1:test OK */

    for(i=0; i < sizeof(input)/sizeof(input[0]); i++){
        temp = gcd(input[i][0],input[i][1]);

        if(temp != ans[i]){
            printf("gcd() is working badly\t gcd():%d\tans:%d\n",temp,ans[i]);
            ret = 0;
        }
    }
    if(ret){
        printf("gcd()  is working!\tOK\n");
    }

    return ret;
}

unsigned int test_lcm(){
    /* input[a][b] a,b:int num */
    unsigned int input[5][2] = {{630,300},{232,431},{94,33},{23,75},{552,1004}};
    unsigned int ans[5] = {6300,99992,3102,1725,138552};
    unsigned int i,temp;
    unsigned int ret = 1;   /* 1:test OK */

    for(i=0; i < sizeof(input)/sizeof(input[0]); i++){
        temp = lcm(input[i][0],input[i][1]);

        if(temp != ans[i]){
            printf("lcm() is working badly\t lcm():%d\tans:%d\n",temp,ans[i]);
            ret = 0;
        }
    }
    if(ret){
        printf("lcm()  is working!\tOK\n");
    }
    return ret;
}


void test_init(test_class *test){
    test->p_test_primnum = test_primnum;
    test->p_test_gcd = test_gcd;
    test->p_test_lcm = test_lcm;
    return;
}

void test_exec(test_class *test){
    test->p_test_primnum();
    test->p_test_gcd();
    test->p_test_lcm();
    return;
}