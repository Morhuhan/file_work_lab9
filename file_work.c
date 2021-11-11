#include <stdio.h>
#define N 10

void maximum (double B[0], double *min, double *max) {         // Функция для нахождения максимума и минимума
    double m = 0.0;
    double n = 99999999.0;
    for (int i = 0; i < N; i++) {
        if (B[i] > 0.0) {
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
    double min;
    double max;
    FILE *f;
    double B[N];                  // Массив,  в который происходит запись из файла
    int i_tmp = 0;
    int tmp;
    int a;

    f = fopen ("numbers.txt", "r");  // находим кол-во ненулевых элементов
    for (int i = 0; i < N; i++) {
        a = fscanf (f, "%lf", &B[i]);
        if (a < 0) {
            tmp = i;  // сохраняем номер первого "пустого" элемента в переменную tmp
            break;
        }
    }
    fclose(f);

    f = fopen ("numbers.txt", "r");  // Чтение чисел из файла в массив B
        for (int i = 0; i < N; i++) {
            if (i_tmp == tmp) {
                fseek (f, 0, SEEK_SET); // Сдвигаем указатель в начало файла каждые tmp итераций
                i_tmp = 0;              // Обнуляем счетчик
            }
            fscanf (f, "%lf", &B[i]);
            i_tmp++;
        }
    fclose(f);

    maximum (&B[0], &min, &max);
    
    f = fopen ("result.txt", "w");  // Запись результатов в текстовый файл
        for (int i = 0; i < N; i++) {
            fprintf (f, "%lf ", B[i]);
        }
        fprintf (f, "\n Maximum: %lf", max);
        fprintf (f, "\n Minimum: %lf", min);
    fclose(f);
}
