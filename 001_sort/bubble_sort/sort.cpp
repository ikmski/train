
#include <stdio.h>
#include "../ProcTime.h"

void bubbleSort(int* const data, const int size)
{

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size-1; ++j) {
            if (data[j+1] < data[j]) {
                int tmp = data[j+1];
                data[j+1] = data[j];
                data[j] = tmp;
            }
        }
    }

    return;
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

    bubbleSort(data, maxSize);

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


