#include<stdio.h>
#include<stdio.h>

int main()
{
    char *arr[] = {"ant", "bat", "cat", "dog", "egg", "fly"};
    char *ptr1, *ptr2;
    int i;
    unsigned int k;
    ptr1 = (arr+1)[2]; // *((arr + 1) + 2) => *(arr + 3)
    ptr2 = (*arr+2);
    for(i=0; i<10; i++)
    {
        k = k + (ptr2 - ptr1);
        k = k % 4;
    }
    printf("Out1: %s || Out2: %s || Out3: %s\n", ptr1, ptr2, arr[k]);
    return 0;
}