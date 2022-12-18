#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

struct Data
{
    int low;
    int high;
};

int arr[100];

void merge(int low, int mid, int high)
{
    int i, j, k;
    int a1 = mid - low + 1;
    int a2 = high - mid;

    int left[a1], right[a2];
    for (i = 0; i < a1; ++i)
        left[i] = arr[low + i];
    for (j = 0; j < a2; ++j)
        right[j] = arr[mid + j + 1];

    i = 0;
    j = 0;
    k = low;
    while (i < a1 && j < a2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            ++i;
        }
        else
        {
            arr[k] = right[j];
            ++j;
        }
        ++k;
    }
    while (i < a1)
    {
        arr[k] = left[i];
        ++i;
        ++k;
    }
    while (j < a2)
    {
        arr[k] = right[j];
        ++j;
        ++k;
    }
}

void *merge_sort(void *indexes)
{
    Data data = *((Data *)indexes);
    int low = data.low;
    int high = data.high;

    if (low < high)
    {
        int mid = low + (high - low) / 2;

        pthread_t thread_1;
        Data d1 = {low, mid};

        pthread_t thread_2;
        Data d2 = {mid + 1, high};

        if (pthread_create(&thread_1, NULL, merge_sort, &d1) != 0)
        {
            perror("Unable to create a thread.");
            void* error = (void*)1;
            return error;
        }
        if (pthread_create(&thread_2, NULL, merge_sort, &d2) != 0)
        {
            perror("Unable to create a thread.");
            void* error = (void*)1;
            return error;
        }

        pthread_join(thread_1, NULL);
        pthread_join(thread_2, NULL);

        merge(low, mid, high);
    }
    return NULL;
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    for (int i = 0; i < 100; ++i)
        arr[i] = rand() % 1024;

    Data data = {0, 100};

    pthread_t thread;
    if (pthread_create(&thread, NULL, merge_sort, &data) != 0)
    {
        perror("Unable to create a thread.");
        return 1;
    }
    pthread_join(thread, NULL);

    printf("The merge sorted array is:\n");
    for (int i = 0; i < 100; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}