#include <stdio.h>
#include <string.h>
#include "whitelist.h"

int is_whitelisted(const char *vendor,
                   const char *product) {

    FILE *fp = fopen("whitelist.conf", "r");

    if (!fp) {
        printf("Whitelist file not found!\n");
        return 0;
    }

    char v[10], p[10];

    while (fscanf(fp, "%s %s", v, p) != EOF) {
        if (strcmp(vendor, v) == 0 &&
            strcmp(product, p) == 0) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}