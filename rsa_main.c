#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rsa.h"
#include "unit_test.h"

int main(){
    unsigned int n;   /* 公開鍵 n = p * q   p,q:prim number */
    unsigned int e=3;   /* 公開鍵 e は lと互いに素 */
    unsigned int l;   /* 最小公倍数 l = lcm(p-1, q-1) */
    unsigned int d;   /* 秘密鍵 d は e*d mod l = 1　を満たす*/
    unsigned int p,q;
    unsigned char plain[256],encrypted[256],dencrypted[256];
    unsigned int c,m;
    unsigned int i=0;
    test_class test;

    test_init(&test);
    test_exec(&test);

    do
    {
        p = make_prime();
        q = make_prime();
    } while (p == q);

    n = p * q;

    l = lcm(p-1, q-1);

    while(gcd(l,e) != 1){
        e++;
    }

    while((e*d)%l != 1){
        d++;
    }

    i = 0;
    printf("input : ");
    scanf("%50s", plain, 51);
    while( i < strlen(plain) )
    {
        /* 暗号化 */
        c = extpower(plain[i],e,n);
        encrypted[i] = c;

        /* 復号化 */
        m = extpower(c,d,n);
        dencrypted[i] = m;
        i++;
    }
    
    printf("\n");
    printf("encrypted :");
    printf("%s\n",encrypted);
    printf("dencrypeted :");
    printf("%s\n",dencrypted);
    printf("p:%d\t q:%d\t n:%d\t l:%d\t e:%d\t d:%d\n",p,q,n,l,e,d);
    return 0;
}

