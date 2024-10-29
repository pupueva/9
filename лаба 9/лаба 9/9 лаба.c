//9 лаба
#define CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#define ROW 9
#define COL 9
#define M_PI 3.14159265358979323846 // Определение числа Pi

#include <stdio.h>
#include <stdlib.h> 
#include <locale.h>
#include <math.h>
void main()
{
    setlocale(LC_CTYPE, "RUS");
    //1
    int row, col;
    printf("\n");
    for (row = 1; row <= ROW; ++row)
    {
        for (col = 1; col <= row; col++)
            printf("%5d", col * row);
        printf("\n");

    }
    {
        int row, col;

        printf("\nТаблица умножения\n");
        for (row = 1; row <= ROW; ++row)
        {
            for (col = 1; col <= COL; ++col)
            {
                printf("%d*%d=%-3d ", col, row, col * row);
            }
            printf("\n");
        }
    }


    //2
    {
        while (1)
        {
            int num;
            int digit, count3 = 0, lastDigit = -1, lastDigitCount = 1, evenCount = 0, greater5Count = 0, oddSum = 0, sum7 = 0, allProduct = 1, secondProd = 1, evenSum = 0, sameAdjacentDigits = 0;
            int numDigits = 0;
            printf("Введите число: ");
            scanf_s("%d", &num);

            while (num > 0) {
                digit = num % 10;
                num = num / 10;
                numDigits++;

                if (digit == 3) {
                    count3++;
                }

                if (digit == lastDigit) {
                    lastDigitCount++;
                }
                else {
                    lastDigit = digit;
                    lastDigitCount = 1;
                }

                if (digit % 2 == 0) {
                    evenCount++;
                    evenSum += digit;
                }

                if (digit > 5) {
                    greater5Count++;
                }

                if (digit % 2 != 0) {
                    oddSum += digit;
                }

                if (digit >= 7) {
                    sum7 += digit;
                }

                if (digit != 0) {
                    allProduct *= digit;
                }

                if (numDigits == 2) {
                    secondProd = digit;
                }

                if (numDigits > 1 && digit == lastDigit) {
                    sameAdjacentDigits = 1;
                }
            }

            int halfDigits = numDigits / 2;
            int firstHalfSum = 0, secondHalfSum = 0;
            num = num / 10;
            for (int i = 0; i < numDigits; i++) {
                if (i < halfDigits) {
                    firstHalfSum += num % 10;
                }
                else {
                    secondHalfSum += num % 10;
                }
                num = num / 10;
            }

            int evenProd = evenSum * oddSum;

            printf("1) Количество цифр 3: %d\n", count3);
            printf("2) Количество повторений последней цифры: %d\n", lastDigitCount);
            printf("3) Количество четных цифр: %d\n", evenCount);
            printf("4) Количество цифр больше 5: %d\n", greater5Count);
            printf("5) Сумма нечетных цифр: %d\n", oddSum);
            printf("6) Сумма цифр больше или равно 7: %d\n", sum7);
            printf("7) Произведение всех цифр, исключая 0: %d\n", allProduct);
            printf("8) Произведение предпоследней и второй цифры: %d\n", secondProd);
            printf("9) Сумма четных цифр, исключая последнюю: %d\n", evenSum - (numDigits >= 1 ? num % 10 : 0));
            printf("10) Рядом расположенные одинаковые цифры: %s\n", sameAdjacentDigits ? "Да" : "Нет");
            printf("11) Сумма цифр первой половины равна сумме цифр второй половины: %s\n", firstHalfSum == secondHalfSum ? "Да" : "Нет");
            printf("12) Произведение сумм цифр четных и нечетных разрядов: %d\n", evenProd);

            char a;
            printf("Продолжить? (Да - y, Нет - n): ");
            scanf_s(" %c", &a);

            if (a == 'n') {
                break;
            }
            //3

            return 0;
        }



    }

    // Функция для вычисления площади пентагона
    float area_pentagon(float radius) {
        return (5 * radius * radius) / (4 * tan(M_PI / 5));
    }

    // Функция для рисования линии на холсте
    void drawLine(char** canvas, int x0, int y0, int x1, int y1, char symbol, int height, int width) {
        int dx = abs(x1 - x0);
        int dy = abs(y1 - y0);
        int sx = (x0 < x1) ? 1 : -1;
        int sy = (y0 < y1) ? 1 : -1;
        int err = dx - dy;

        while (1) {
            if (y0 >= 0 && y0 < height && x0 >= 0 && x0 < width) {
                canvas[y0][x0] = symbol; // Рисуем символ
            }
            if (x0 == x1 && y0 == y1) break;
            int err2 = err * 2;
            if (err2 > -dy) {
                err -= dy;
                x0 += sx;
            }
            if (err2 < dx) {
                err += dx;
                y0 += sy;
            }
        }
    }

    // Функция для заполнения области пентагона
    void fillPolygon(char** canvas, int width, int height, int x[], int y[], char fillSymbol) {
        // Простая реализация заливки: заполнение по строкам
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                // Проверяем, находится ли точка внутри пентагона
                if (isInsidePolygon(j, i, x, y)) {
                    canvas[i][j] = fillSymbol; // Заполнение символом
                }
            }
        }
    }

    // Проверка, находится ли точка внутри пентагона
    int isInsidePolygon(int x, int y, int polygonX[], int polygonY[]) {
        int inside = 0;
        for (int i = 0, j = 4; i < 5; j = i++) {
            if (((polygonY[i] > y) != (polygonY[j] > y)) &&
                (x < (polygonX[j] - polygonX[i]) * (y - polygonY[i]) / (polygonY[j] - polygonY[i]) + polygonX[i])) {
                inside = !inside;
            }
        }
        return inside;
    }

    // Функция для рисования пентагона
    void draw_pentagon(int radius, char borderSymbol, char fillSymbol) {
        int height = radius * 2; // Высота пентагона
        int width = radius * 3;  // Ширина пентагона
        char** canvas = (char**)malloc(height * sizeof(char*));

        for (int i = 0; i < height; i++) {
            canvas[i] = (char*)malloc(width * sizeof(char));
            for (int j = 0; j < width; j++) {
                canvas[i][j] = ' '; // Инициализация пробелами
            }
        }

        // Вычисление координат вершин пентагона
        double angle;
        int x[5], y[5];
        for (int i = 0; i < 5; i++) {
            angle = (2 * M_PI / 5) * i; // Угол для каждой вершины
            x[i] = (int)(radius * cos(angle) + width / 2);
            y[i] = (int)(radius * sin(angle) + height / 2);
        }

        // Рисуем грани пентагона
        for (int i = 0; i < 5; i++) {
            drawLine(canvas, x[i], y[i], x[(i + 1) % 5], y[(i + 1) % 5], borderSymbol, height, width);
        }

        // Заполняем пентагон
        fillPolygon(canvas, width, height, x, y, fillSymbol);

        // Вывод холста
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                putchar(canvas[i][j]);
            }
            putchar('\n');
        }

        // Освобождение памяти
        for (int i = 0; i < height; i++) {
            free(canvas[i]);
        }
        free(canvas);
    }

    // Функция для вывода названия фигуры
    void name(int sides) {
        if (sides == 5) {
            printf("Пятиугольник\n");
        }
        else {
            printf("Неизвестная фигура\n");
        }
    }

    int main() {
        setlocale(LC_CTYPE, "RUS"); // Установка локализации на русский
        int choice;
        float radius;

        printf("Введите радиус пентагона: ");
        scanf("%f", &radius);

        do {
            printf("\nМеню:\n");
            printf("1. Рассчитать площадь\n");
            printf("2. Вывести определение фигуры\n");
            printf("3. Нарисовать фигуру\n");
            printf("0. Выход\n");
            printf("Выберите операцию: ");
            scanf("%d", &choice);


            switch (choice) {
            case 1:
                printf("Площадь пентагона: %.2f\n", area_pentagon(radius));
                break;
            case 2:
                name(5);
                break;
            case 3:
            {
                char borderSymbol, fillSymbol;
                printf("Введите символ для границы пентагона: ");
                scanf(" %c", &borderSymbol);
                printf("Введите символ для заполнения пентагона: ");
                scanf(" %c", &fillSymbol);
                draw_pentagon((int)radius, borderSymbol, fillSymbol);
            }
            break;
            case 0:
                printf("Выход из программы.\n");
                break;
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
            }
        } while (choice != 0);

        return 0;
    }
    system("pause");

}
