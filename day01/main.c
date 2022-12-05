#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING 1024
#define MAX_LINE 1024

int main(int argc, const char *argv[]){

    FILE *inputf;
    int sum_cals = 0;
    int read_status = 0;
    int current_cals;
    int max_cals = 0;
    char filename[MAX_STRING];
    char line[MAX_LINE];

    if (argc == 1){
        strcpy(filename, "sample_input.txt");
    } else {
        strcpy(filename, argv[1]);
    }

    inputf = fopen(filename, "r");

    while (fgets(line, MAX_LINE, inputf)) {
        if (line[0] == '\n') {
            if (sum_cals > max_cals){
                max_cals = sum_cals;
            }
            sum_cals = 0;
        } else {
            sum_cals += atoi(line);
        }
    }
    
    if (sum_cals > max_cals){
        max_cals = sum_cals;
    }

    printf("%d\n", max_cals);
    return 0;
}