
#include <stdio.h>
#include "../ProcTime.h"


void _quickSort(int* data, int min, int max);
int partition(int* data, int min, int max);


void quickSort(int* const data, const int size)
{
    _quickSort(data, 0, size-1);

    return;
}

void _quickSort(int* data, int min, int max)
{
    int index = partition(data, min, max);

    if (min < index-1) {
        _quickSort(data, min, index-1);
    }
    if (index < max) {
        _quickSort(data, index, max);
    }

    return;
}

int partition(int* data, int min, int max)
{
    int pivot = (data[min] + data[max]) / 2;

    while (min <= max) {

        while (data[min] < pivot) ++min;
        while (data[max] > pivot) --max;

        if (min <= max) {
            int tmp = data[min];
            data[min] = data[max];
            data[max] = tmp;

            ++min;
            --max;
        }
    }
    return min;
}


int main(int argc, char* argv[])
{
    if (2 != argc) {
        printf("arg[1] = fileName\n");
        return -1;
    }

    char* fileName = argv[1];

    FILE* fp;
    int buf = 0;
    int data[1000000];

    fp = fopen(fileName, "r");
    if (!fp) {
        printf("file not open.\n");
        return -1;
    }

    int index = 0;
    while (EOF != fscanf(fp, "%d", &buf)) {
        data[index] = buf;
        buf = 0;
        ++index;
    }

    fclose(fp);

    int maxSize = index;

    ProcTime* procTime = new ProcTime();
    procTime->start();

    quickSort(data, maxSize);

    procTime->end();
    delete procTime;

    fp = fopen("./output.csv", "w");
    if (!fp) {
        printf("file not open.");
        return -1;
    }
    for (int i = 0; i < maxSize; ++i) {
        fprintf(fp, "%d\n", data[i]);
    }
    fclose(fp);

    return 0;
}


