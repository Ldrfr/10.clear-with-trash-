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
    fgets(str, 100, fp1); //������ ���� � ������ ��� ������
    //////////////////////////////////////////////////////////////////////////////////////
    char* str1 = strtok(str, " ");//��������� ������
    char* s = (char*)malloc(100 * sizeof(char));//������� ������ ��� ������
    char* t = 0;
    char* last = 0;
    s[0] = '\0';
    strcat(s, str1);//��������� � 1 ������
    str1 = strtok(NULL, " "); //������ �� �������� ������
    while (str1 != NULL) {
        strcat(s, " ");
        strcat(s, str1); //���������
        t = str1;
        str1 = strtok(NULL, " .");//������ ������� ����(�����) -> ������ 
        if (str1 == NULL)
            last = t;
    }
    /////////////////////////////////////////////////////////////////////////////////////// all works with dot in the end -> clear string   
    for (int i = 0; s[i] != '\0';)//���� �� ����� (����� ���� �������� �� ����� ��� ������� � �� ���)
    {
        while (s[i] == ' ' && s[i] != '\0')
            i++;//������� �� ������ ������� ���� ����� ����� �� ����� ������
        if (s[i] != '\0')
        {
            j = 0;
            while (s[i] != ' ' && s[i] != '\0')
                word[n][j++] = s[i++];//n-�� ����� ����� ����� ������ �� ������� �������� �� ��������
            word[n][j] = '\0';
            n++;//��������� � ���������� �����
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
    printf("������ �����:\n");
    for (int i = 0; i < n; i++) {
        puts(word[i]);
    }
    printf("�� ��� �����:\n");
    for (int i = 0; i < n - 1; i++) {
        if (strcmp(word[i], word[n - 1]) != 0) {
            puts(word[i]);
        }
    }
    fprintf(fp2, "������ �����:\n");
    for (int i = 0; i < n; i++) {
        fprintf(fp2, "%s\n", word[i]);
    }
    fprintf(fp2, "�� ��� �����:\n");
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