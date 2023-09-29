#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int size, k, buff;

    printf("введите количество товаров: ");
    scanf_s("%d", &size);

    int* arr = new int[size];


    for (int i = 0; i < size; i++)

        arr[i] = rand() % 100 + 1;

    for (int i = 0; i < size; i++)

        printf("%d ", arr[i]);

    for (int i = 1; i < size; i++)
    {
        buff = arr[i];
        k = i - 1;

        while (k >= 0 && arr[k] > buff)
        {
            arr[k + 1] = arr[k];
            arr[k] = buff;
            k--;
        }
    }

    int chek = 0;

    printf("\n*****************************************************************************************************************\n");

    for (int i = 0, j = size - 1; i < (size / 2); i++, j--)

        printf("%d %d ", arr[j], arr[i]);

    if (size % 2 == 1)

        printf("%d", arr[size / 2]);

    for (int i = (size / 2); i < size; i++)

        chek += arr[i];

    printf("\n*******************************************************************************************************************\n");

    printf("\nмаксимальная сумма чека: %d\n", chek);
    delete[] arr;



}