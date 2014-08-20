#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* outfp;

    // 出力ファイル
    outfp = fopen("./test", "w");
    if (!outfp) {
        printf("file not open.");
        return -1;
    }

    srand(10);

    int dataNum = 100;
    fprintf(outfp, "%d\n", dataNum);

    for (int i = 0; i < dataNum; ++i) {

        int numRed     = rand()%100+1;
        int numBlue    = rand()%100+1;
        int onlyRed    = rand()%2001 - 1000;
        int onlyBlue   = rand()%2001 - 1000;
        int bothColors = rand()%2001 - 1000;

        fprintf(outfp, "%d,%d,%d,%d,%d\n", numRed, numBlue, onlyRed, onlyBlue, bothColors);
    }

    fclose(outfp); // 出力ファイル

    return 0;
}

