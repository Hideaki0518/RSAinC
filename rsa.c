#include "rsa.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

unsigned int make_prime(){
    unsigned int num;
    unsigned int i;
    unsigned int is_primenum = 0U;

    srand((unsigned int)time(NULL));

    while(is_primenum != 1){
        num = rand() % 1000U;
        if(num < 3 || num % 2 == 0){
            continue;
        }

        for(i = 3; i <= sqrt(num); i += 2U ){
            if(num % i == 0U){
                is_primenum = 0U;
                break;
            }
            is_primenum = 1U;
        }
    }
    return num;
}

/*** ret value 1(yes) 0(no) ***/
unsigned int is_prime(unsigned int num){
    unsigned int i;

    if (num < 3 || num % 2 == 0){
        return 0;
    }

     for(i = 3; i <= sqrt(num); i += 2U ){
        if(num % i == 0U){
            return 0;
        }
    }
    return 1;
}

/* greatest common divisor */
unsigned int gcd(unsigned int a, unsigned int b){
    unsigned int temp;

    if(a < b){
        temp = a;
        a = b;
        b = temp;
    }

    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}
/* least common multiple */
/* ( a * b ) / gcd = lcm */
unsigned int lcm(unsigned int a, unsigned int b){
    return a*b/gcd(a,b);
}

/*
 * 繰り返し自乗法を使った法nのべき乗計算（aのk乗をnで割った余りを求める）
 *
 * unsigned int a : 底
 * unsigned int k : 指数
 * unsigned int n : 法
*/
unsigned int extpower(unsigned int a, unsigned int k, unsigned int n) {

    a %= n;

    if(a == 0 || n == 0){
        return 0;
    }
    if(k == 0){
        return 1 % n;
    }

    int i;
    unsigned int value = 1;
    for(i = 0; i < k; i++) {
        value *= a;
        if(value >= n) {
            value %= n;
        }
    }
    return value;
}