#include <stdio.h>
#include <time.h>


struct DateTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};


union DateUnion {
    struct DateTime date;
    long epoch;
};


long convertToEpoch(union DateUnion *du) {
    struct tm timeStruct = {0};
    timeStruct.tm_year = du->date.year - 1900;
    timeStruct.tm_mon = du->date.month - 1;
    timeStruct.tm_mday = du->date.day;
    timeStruct.tm_hour = du->date.hour;
    timeStruct.tm_min = du->date.minute;
    timeStruct.tm_sec = du->date.second;

    du->epoch = mktime(&timeStruct);
    return du->epoch;
}


void getValidDateTime(union DateUnion *du, const char *message) {
    int valid = 0;
    while (!valid) {
        printf("%s (GG.AA.YYYY SS:DD:SS): ", message);
        if (scanf("%d.%d.%d %d:%d:%d", &du->date.day, &du->date.month, &du->date.year, &du->date.hour, &du->date.minute, &du->date.second) == 6) {
            if (du->date.month >= 1 && du->date.month <= 12 && du->date.day >= 1 && du->date.day <= 31 &&
                du->date.hour >= 0 && du->date.hour < 24 && du->date.minute >= 0 && du->date.minute < 60 && du->date.second >= 0 && du->date.second < 60) {
                valid = 1;
            } else {
                printf("Hatali tarih veya saat girdiniz, lutfen tekrar deneyin.\n");
            }
        } else {
            printf("Hatali format, lutfen tekrar deneyin.\n");
            while (getchar() != '\n');
        }
    }
}

int main() {
    union DateUnion dt1, dt2;

    getValidDateTime(&dt1, "Birinci tarihi giriniz");
    getValidDateTime(&dt2, "Ikinci tarihi giriniz");



    long epoch1 = convertToEpoch(&dt1);
    long epoch2 = convertToEpoch(&dt2);

    printf("\nEpoch zamanlari: \n");
    printf("Tarih 1: %ld\n", epoch1);
    printf("Tarih 2: %ld\n", epoch2);

    long fark = epoch2 - epoch1;
    if (fark < 0) fark = -fark;
    printf("Iki tarih arasindaki fark (saniye): %ld saniye\n", fark);

    return 0;
}
