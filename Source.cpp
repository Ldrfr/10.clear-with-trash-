#define _CRT_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
#include<locale.h>
#include<string.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int j, n = 0;
    char word[100][100];
    FILE* fp1 = fopen("text.txt", "r+");
    FILE* fp2 = fopen("output.txt", "w");
    if (fp1 == NULL) return 1;
    char* str = (char*)malloc(100 * sizeof(char));
    fgets(str, 100, fp1); //считал файл в строку для записи
    //////////////////////////////////////////////////////////////////////////////////////
    char* str1 = strtok(str, " ");//разбивная строка
    char* s = (char*)malloc(100 * sizeof(char));//выделяю массив для записи
    char* t = 0;
    char* last = 0;
    s[0] = '\0';
    strcat(s, str1);//объединил с 1 словом
    str1 = strtok(NULL, " "); //вернул на исходную строку
    while (str1 != NULL) {
        strcat(s, " ");
        strcat(s, str1); //объединил
        t = str1;
        str1 = strtok(NULL, " .");//просто добавил воды(точку) -> удалил 
        if (str1 == NULL)
            last = t;
    }
    /////////////////////////////////////////////////////////////////////////////////////// all works with dot in the end -> clear string   
    for (int i = 0; s[i] != '\0';)//пока не конец (можно ноль поменять на точку или сделать и то ито)
    {
        while (s[i] == ' ' && s[i] != '\0')
            i++;//считаем до какого символа надо взять слово из нашей строки
        if (s[i] != '\0')
        {
            j = 0;
            while (s[i] != ' ' && s[i] != '\0')
                word[n][j++] = s[i++];//n-ое слово равно части строки до символа которого мы замерили
            word[n][j] = '\0';
            n++;//переходим к следующему слову
        }
    }
    //////////////////////////////////////////////////////////////////////////////////////
    char* c = (char*)malloc(100 * sizeof(char));
    c[0] = '\0';
    int k = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i - 1] != s[i]) {
            c[k++] = s[i];
        }
    }

    fprintf(fp2, "%s\n", s);
    fprintf(fp2, "%s\n", last);
    printf("Просто слова:\n");
    for (int i = 0; i < n; i++) {
        puts(word[i]);
    }
    printf("То что нужно:\n");
    for (int i = 0; i < n - 1; i++) {
        if (strcmp(word[i], word[n - 1]) != 0) {
            puts(word[i]);
        }
    }
    fprintf(fp2, "Просто слова:\n");
    for (int i = 0; i < n; i++) {
        fprintf(fp2, "%s\n", word[i]);
    }
    fprintf(fp2, "То что нужно:\n");
    for (int i = 0; i < n - 1; i++) {
        if (strcmp(word[i], word[n - 1]) != 0)
            fprintf(fp2, "%s\n", word[i]);
    }
    //for (int j = 0; c[j] != '\0';)
        //printf(&c[j]);
    printf("%s", c);
    fprintf(fp2, "%s", c);
    fclose(fp1);
    fclose(fp2);
}