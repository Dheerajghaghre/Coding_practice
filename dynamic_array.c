#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

// Complete the dynamicArray function below.

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */
int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    int lastans=0;
    static int aa[2]={7,3};
    printf("%d",aa[0] );
    printf("\n" );
    printf("%d",aa[1] );
    printf("\n" );

    int *S1=(int *)malloc(sizeof(int));
    int *S2=(int *)malloc(sizeof(int));
    int *a=(int *)malloc(sizeof(int));
    
    int ss1=0,ss2=0,a1=0;
    for(int i=0;i<queries_rows;i++){
        if(queries[i][0]==1){
          int index =((queries[i][1]^lastans)%n);
          if(index==0){
              if(ss1==0){
                  S1[0]=queries[i][2];
                  ss1=ss1+1;
              }
              else{
                  *S1 = (int *)realloc(*S1,ss1*sizeof(int));
                    S1[ss1]=queries[i][2];
                    ss1=ss1+1;
              }
          }
          if(index==1){
              if(ss2==0){
                  S2[0]=queries[i][2];
                  ss2=ss2+1;
              }
              else{
                  *S2 = (int *)realloc(*S2,ss2*sizeof(int));
                    S2[ss2]=queries[i][2];
                    ss2=ss2+1;
              }
          }
        }
        if(queries[i][0]==2){
            int index =((queries[i][1]^lastans)%n);
            if(index==0){
                if(a1==0){
                    lastans=S1[queries[i][1]];
                    a[0]=lastans;
                    a1=a1+1;
                    printf("%d ",lastans);
                    printf("\n");

                }
                else{
                    *a=(int *)realloc(*a,a1*sizeof(int));
                    
                    lastans=S1[queries[i][1]];
                    a[0]=lastans;
                    a1=a1+1;
                    printf("%d ",lastans);
                    printf("\n");
                }

            }
            if(index==1){
                if(a1==0){
                    lastans=S2[queries[i][1]];
                    a[0]=lastans;
                    a1=a1+1;
                    printf("%d ",lastans);
                    printf("\n");

                }
                else{
                    *a=(int *)realloc(*a,a1*sizeof(int));
                    lastans=S2[queries[i][1]];
                    a[a1]=lastans;
                    a1=a1+1;
                    printf("%d ",lastans);
                    printf("\n");
                }

            }

        }
    }
    *result_count=2;
    return aa;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nq = split_string(rtrim(readline()));

    char* n_endptr;
    char* n_str = nq[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* q_endptr;
    char* q_str = nq[1];
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    int** queries = malloc(q * sizeof(int*));

    for (int i = 0; i < q; i++) {
        *(queries + i) = malloc(3 * (sizeof(int)));

        char** queries_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 3; j++) {
            char* queries_item_endptr;
            char* queries_item_str = *(queries_item_temp + j);
            int queries_item = strtol(queries_item_str, &queries_item_endptr, 10);

            if (queries_item_endptr == queries_item_str || *queries_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(*(queries + i) + j) = queries_item;
        }
    }

    int queries_rows = q;
    int queries_columns = 3;

    int result_count;
    int* result = dynamicArray(n, queries_rows, queries_columns, queries, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
