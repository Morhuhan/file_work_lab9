#include <stdio.h>
#define N 10

void main (void) {

    FILE *f;

    int A[N] = {1,2,3,4,5,6};
    int B[N];

    int i_tmp = 0;

    f = fopen ("test2.txt", "w");  // Запись в файл чисел из массива А
        fwrite (A, sizeof(A[0]), sizeof(A) / sizeof(A[0]), f);
    fclose(f);

    f = fopen ("test2.txt", "r");  // Чтение чисел из файла в массив B

        for (int i = 0; i_tmp < N; i++) {  // Цикл выполнится N раз

            if (A[i] == 0) {  // находим пустой(нулевой) элемент в массиве А

                fseek (f, 0, SEEK_SET); // передвигаем каретку в начало файла

                i = i - i_tmp; // Так как элемент А[i] был пустой, нужно вернуться в начало массива А

            }

            fread(&B[i_tmp], sizeof(B[0]), 1, f);  // Чтение чисел из файла в массив B
            
            i_tmp++;  // Переменная i_tmp должна нарасчиаться чтобы происходило предидущее условие

        }   

    fclose(f);

    for (int i = 0; i < N; i++) {   // Вывод массива B
        printf("%d \n", B[i]);
    }    

}
