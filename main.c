#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define SIZE 8

int major[] = {0, 2, 4, 5, 7, 9, 11, 12};
double base_freq = 261.63;
double ms_time = 1000;

void play_scale(double base_freq, int *semitones, char *scale) {
    double factor = pow(2, 1.0 / 12.0);
    int i;
    printf("PLAYING: %s\n", scale);
    for (i = 0; i < SIZE; ++i) {
        double note = base_freq * pow(factor, semitones[i]);
        printf("Playing frequency: %.2f Hz\n", note);
        Beep((DWORD)note, (DWORD)ms_time);
    }
    for(--i; i >= 0; --i){
        double note = base_freq * pow(factor, semitones[i]);
        printf("Playing frequency: %.2f Hz\n", note);
        Beep((DWORD)note, (DWORD)ms_time);
    }
}

void lower(char *str){
    for(int i = 0; str[i]; ++i){
        str[i] = tolower((unsigned char) str[i]);
    }   
}

int main() {
    printf("Enter the scale you want to play (e.g., C Major, D Major, E Major): ");
    char scale[20];
    fgets(scale, 20, stdin);
    scale[strcspn(scale, "\n")] = '\0';
    lower(scale);

    if (strcmp(scale, "c major") == 0) {
        play_scale(base_freq, major, scale);
    } else if (strcmp(scale, "d major") == 0) {
        play_scale(base_freq * pow(2, 2.0 / 12.0), major, scale);
    } else if (strcmp(scale, "e major") == 0) {
        play_scale(base_freq * pow(2, 4.0 / 12.0), major, scale);
    } else if (strcmp(scale, "f major") == 0) {
         play_scale(base_freq * pow(2, 5.0 / 12.0), major, scale);
    } else if (strcmp(scale, "g major") == 0) {
        play_scale(base_freq * pow(2, 7.0 / 12.0), major, scale);
    } else if (strcmp(scale, "a major") == 0) {
        play_scale(base_freq * pow(2, 9.0 / 12.0), major, scale);
    } else if (strcmp(scale, "b major") == 0) {
        play_scale(base_freq * pow(2, 11.0 / 12.0), major, scale);
    } else {
        printf("Scale not recognized. Please enter a valid scale.\n");
    }

    return 0;
}
