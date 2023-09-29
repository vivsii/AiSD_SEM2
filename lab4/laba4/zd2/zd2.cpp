#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int N, priz = 0, sum = 0, max_buff = 10000;
    int min;

    printf("Введите количество призеров: ");
    scanf_s("%d", &N);

    int* arr = new int[N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 100 + 1;

        printf("%d ", arr[i]);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i] > arr[j])
            {
                min = arr[i];
                arr[i] = arr[j];
                arr[j] = min;
            }
        }
    }

    while (priz < 3)
    {
        int max = 0;

        for (int i = 0; i < N; i++)

            if (arr[i] > max && arr[i] < max_buff)

                max = arr[i];

        for (int i = 0; i < N; i++)

            if (arr[i] == max)

                sum++;

        max_buff = max;
        priz++;
    }

    printf("\nЧисло призеров = %d\n", sum);

    delete[] arr;
}