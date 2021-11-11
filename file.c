#include <stdio.h>
#define N 10

void maximum (int B[], int *min, int *max) {         // Функция для нахождения максимума и минимума
    int m = 0;
    int n = 99999999;
    for (int i = 0; i < N; i++) {
        if (B[i] > 0) {
            if (B[i] > m) {
                m = B[i];
            }
        }
        else {
            if (B[i] < n) {
                n = B[i];
            }
        }
    }
    *min = n;
    *max = m;
}

void main (void) {
    int min;
    int max;
    FILE *f;
    int A[N] = {1, 2, 3, 4, 5, 6, -1, -2, -3, -4}; // Массив, из которого происходит запись в файл
    int B[N];                  // Массив,  в который происходит запись из файла
    int i_tmp = 0;

    f = fopen ("numbers.txt", "w");  // Запись в файл чисел из массива А
        fwrite (A, sizeof(A[0]), sizeof(A) / sizeof(A[0]), f);
    fclose(f);

    f = fopen ("numbers.txt", "r");  // Чтение чисел из файла в массив B
        for (int i = 0; i_tmp < N; i++) {  // Цикл выполнится N раз
            if (A[i] == 0) {  // находим пустой(нулевой) элемент в массиве А
                fseek (f, 0, SEEK_SET); // передвигаем каретку в начало файла
                i = i - i_tmp; // Так как элемент А[i] был пустой, нужно вернуться в начало массива А
            }
            fread(&B[i_tmp], sizeof(B[0]), 1, f);  // Чтение чисел из файла в массив B
            i_tmp++;  // Переменная i_tmp должна нарасчиаться чтобы происходило предидущее условие
        }   
    fclose(f);

    maximum (&B[N], &min, &max);
    
    f = fopen ("result.txt", "w");  // Запись результатов в текстовый файл
        for (int i = 0; i < N; i++) {
            fprintf (f, "%d ", B[i]);
        }
        fprintf (f, "\n Maximum: %d", max);
        fprintf (f, "\n Minimum: %d", min);
    fclose(f);
}
