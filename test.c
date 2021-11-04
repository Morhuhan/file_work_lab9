#include <stdio.h>
#define N 10

void main (void) {

    int A[N] = {1,2,3};

    int i_tmp = 0;
    
    for (int i = 0; i < N; i++) {

        if (A[i] == 0) {

            int tmp[i-1];

            for (i_tmp = 0; i_tmp < i; i_tmp++) {

                tmp[i_tmp] = A[i_tmp]; 

                printf ("%d ", tmp[i_tmp]);

            }

            for (; i < N; i++) {

                A[i] = tmp[i_tmp] 

            }

            //break;

        }


    }

}