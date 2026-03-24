#include <stdio.h>

int main() {
    printf("-------------------------------------------\n");
    lab7_tsk4();
    printf("-------------------------------------------\n");
    lab7_tsk5();
    printf("-------------------------------------------\n");
    lab7_tsk6();
    printf("-------------------------------------------\n");
    lab9_tsk3();
    printf("-------------------------------------------\n");
    lab9_tsk10();
    printf("-------------------------------------------\n");
}

int lab7_tsk4() {
    int arr[] = {10, 5, 3, 15, 2, 8}; // Исходный массив
    int n = sizeof(arr) / sizeof(arr[0]);
    int min_idx = 0, max_idx = 0;

    // 1. Поиск индексов min и max
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[min_idx]) min_idx = i;
        if (arr[i] > arr[max_idx]) max_idx = i;
    }

    printf("Min: %d (idx: %d), Max: %d (idx: %d)\n", arr[min_idx], min_idx, arr[max_idx], max_idx);

    // 2. Обмен местами
    int temp = arr[min_idx];
    arr[min_idx] = arr[max_idx];
    arr[max_idx] = temp;

    // 3. Вывод измененного массива
    printf("Измененный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

int lab7_tsk5() {
    
    int arr[] = {10, -5, 0, 7, 0, -1, 3, 0, -8};
    int n = sizeof(arr) / sizeof(arr[0]); // Вычисление размера массива
    int positive = 0, negative = 0, zero = 0;

    // Перебор элементов массива
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            positive++;
        } else if (arr[i] < 0) {
            negative++;
        } else {
            zero++;
        }
    }

    // Вывод результатов
    printf("Положительных: %d\n", positive);
    printf("Отрицательных: %d\n", negative);
    printf("Нулевых: %d\n", zero);

    return 0;
}

int lab7_tsk6() {
    // Инициализация матрицы 4x4 (можно изменить значения)
    int matrix[4][4] = {
        { 5, -2,  0,  8},
        {-1,  0,  3, -4},
        { 7,  2, -9,  0},
        { 0,  1,  6, -3}
    };
    int count = 0;
    int i, j;

    // Перебор элементов матрицы
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (matrix[i][j] > 0) {
                count++; // Увеличение счетчика, если > 0
            }
        }
    }

    printf("Количество элементов больше нуля: %d\n", count);
    return 0;
}

int lab9_tsk3() {
    char text[1000];

    printf("Введите текст (латиница): ");
    // Считываем строку с пробелами
    fgets(text, sizeof(text), stdin);

    printf("Результат: ");
    for (int i = 0; i < strlen(text); i++) {
        // Проверяем, является ли символ буквой
        if (isalpha(text[i])) {
            // Приводим к нижнему регистру и вычисляем позицию
            int position = tolower(text[i]) - 'a' + 1;
            printf("%d", position);
        } else {
            // Оставляем пробелы и знаки препинания
            printf("%c", text[i]);
        }
    }

    return 0;
}

int lab9_tsk10() {
    char text[1000];
    char targetChar;
    int k, wordCount = 0;

    // Ввод строки
    printf("Введите строку: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Удаление символа новой строки

    // Ввод символа и числа k
    printf("Введите символ: ");
    scanf(" %c", &targetChar);
    printf("Введите число k: ");
    scanf("%d", &k);

    // Разбиение строки на слова
    char *word = strtok(text, " ,.-!?\t\n");
    while (word != NULL) {
        int charInWordCount = 0;
        // Подсчет символов в слове
        for (int i = 0; i < strlen(word); i++) {
            if (word[i] == targetChar) {
                charInWordCount++;
            }
        }

        // Проверка условия
        if (charInWordCount == k) {
            wordCount++;
        }
        word = strtok(NULL, " ,.-!?\t\n");
    }

    printf("Количество слов, содержащих '%c' %d раз(а): %d\n", targetChar, k, wordCount);

    return 0;
}
