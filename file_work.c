#include <stdio.h>

void maximum(double* b, double* min, double* max, int size_b) {         // Функция для нахождения максимума и минимума
    double m;
    double n;
    if (b[0]>b[1]) {
        m = b[0];
        n = b[1];
    }
    else {
        m = b[1];
        n = b[0];
    }
    for(int i = 2; i < size_b; i++) {

        if (b[i] > m) {
            m = b[i];
        }

        else if (b[i] < n) {
            n = b[i];
        }

    }
    printf("%lf - max \n", m);
    printf("%lf - min \n", n);
    *min = n;
    *max = m;
}

int search(double* b, FILE* f, int size_b) {
    int tmp;
    int a;
    for (int i = 0; i < size_b; i++) {
        a = fscanf(f, "%lf", &b[i]);
        if (a < 0) {
            tmp = i;  // сохраняем номер первого "пустого" элемента в переменную tmp
            return tmp;
        }
    }
}

void reading(double* b, int tmp, FILE* f, int size_b) {
    int i_tmp = 0;
    for (int i = 0; i < size_b; i++) {
        if (i_tmp == tmp) {
            fseek(f, 0, SEEK_SET); // Сдвигаем указатель в начало файла каждые tmp итераций
            i_tmp = 0;              // Обнуляем счетчик
        }
        fscanf(f, "%lf", &b[i]);
        i_tmp++;
    }
}

void writing(FILE* f, double* b, double max, double min, int size_b) {
    for (int i = 0; i < size_b; i++) {
        fprintf(f, "%lf ", b[i]);
    }
    fprintf(f, "\n Maximum: %lf", max);
    fprintf(f, "\n Minimum: %lf", min);
}

void main (void) {
    double min;
    double max;
    FILE *f;
    int size_b = 10;
    double b[size_b];                  
    int tmp;
    f = fopen("numbers.txt", "r");  // находим кол-во ненулевых элементов
    tmp = search(b, f, size_b);
    fclose(f);
    f = fopen("numbers.txt", "r");  // Чтение чисел из файла в массив b
    reading(b, tmp, f, size_b);
    fclose(f);
    maximum(b, &min, &max, size_b);
    f = fopen("result.txt", "w");  // Запись результатов в текстовый файл
    writing(f, b, max, min, size_b);
    fclose(f);
}
