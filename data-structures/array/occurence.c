#include <stdio.h>

int main()
{
    int arr[] = {23, -34, -45, 25, 675, -754, 2, 3, 13};
    int positive= 0, negative=0, odd=0, even=0;
    for (int i = 0; i < sizeof(arr) / 4; i++)
    {
        if (arr[i] < 0)
            negative++;
        else
            positive++;

        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    printf("-ve: %d |+ve: %d |even: %d |odd: %d", \
        negative, positive, even, odd);

}