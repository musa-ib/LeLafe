#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAMES 6000
#define MAX_NAME_LEN 50

// Calculate alphabetical value of a name
int name_value(const char *name) {
    int sum = 0;
    for (int i = 0; name[i]; i++) {
        sum += toupper(name[i]) - 'A' + 1;
    }
    return sum;
}

// Compare function for qsort
int compare_names(const void *a, const void *b) {
    const char *nameA = *(const char **)a;
    const char *nameB = *(const char **)b;
    return strcmp(nameA, nameB);
}

int main() {
    FILE *f = fopen("C:/Users/mirma/OneDrive/Desktop/names.txt", "r");
    if (!f) {
        fprintf(stderr, "Cannot open names.txt\n");
        return 1;
    }

    // Get file size
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *buffer = malloc(fsize + 1);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(f);
        return 1;
    }

    fread(buffer, 1, fsize, f);
    buffer[fsize] = '\0';
    fclose(f);

    char *names[MAX_NAMES];
    int count = 0;

    // Parse names: file format is "NAME","NAME",...
    char *ptr = buffer;
    while (*ptr) {
        if (*ptr == '"') {
            ptr++;
            char *start = ptr;
            while (*ptr && *ptr != '"') ptr++;
            if (*ptr == '"') {
                *ptr = '\0';
                names[count] = strdup(start);  // duplicate string
                if (!names[count]) {
                    fprintf(stderr, "Memory allocation failed\n");
                    free(buffer);
                    for (int i = 0; i < count; i++) free(names[i]);
                    return 1;
                }
                count++;
                ptr++; // skip closing quote
            }
        } else {
            ptr++;
        }
    }

    // Sort names alphabetically
    qsort(names, count, sizeof(char *), compare_names);

    // Calculate total score
    long long total = 0;
    for (int i = 0; i < count; i++) {
        int val = name_value(names[i]);
        total += (long long)val * (i + 1);
    }

    printf("Total score: %lld\n", total);

    // Cleanup
    free(buffer);
    for (int i = 0; i < count; i++) {
        free(names[i]);
    }

    return 0;
}
