#include <stdio.h>
#include <time.h>

void log_event(const char *action,
               const char *vendor,
               const char *product) {

    FILE *fp = fopen("logs/usb_log.txt", "a");

    if (!fp) return;

    time_t now = time(NULL);

    fprintf(fp, "%s | %s | Vendor:%s Product:%s\n",
            ctime(&now), action, vendor, product);

    fclose(fp);
}