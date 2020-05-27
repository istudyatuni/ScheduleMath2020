#include <conio.h>
#include <string.h>
#include <math.h>
#include <fstream>
#include <windows.graphics.h>
#include <locale.h>
#include <windows.h>


struct diciplina //структура по дисциплинам
{
    char name_predmet[20];
    char dic_lec[20]; //наим. лекций
    char dic_sem[20]; //наим. семинаров
    char dic_lab[20]; //наим.лабораторных
};


struct prepodavatel //структура по преподавателям
{
    char FIO[25]; //ФИО преп-ля
};


struct auditoria //структура по аудиториям
{
    int nomer_audit; //номер аудитории
};

struct group //структура по группам
{
    int n_gr; //номер группы (всего их будет пять)
    int n_podgruppy; //номер подгруппы
};

void input() //функция, которая записывает в файлы данные по дисциплинам (лекциям, семинарам и лабам, преподов и аудитории)
{
    diciplina dic;
    prepodavatel pr;
    auditoria audit;
    group gr;
    char filename[100];
    char d = '\0';
    do {
        fflush(stdin);
        printf("\n 1).Vvesty dannye o diciplinah LEC");
        printf("\n 2).Vvesty dannye o diciplinah SEM");
        printf("\n 3).Vvesty dannye o diciplinah LAB");
        printf("\n4). Vvesty dannye o prep-yah");
        printf("\n5). Vvesty dannye o aud-yah");
        printf("\n6). Vvesty dannye o gruppah");
        d = getche();
        if (d == '1') {
            FILE* LEC;
            printf("\nVvedite imya dlya novogo file\n");
            gets(filename);
            LEC = fopen(filename, "wt+");
            do {
                fflush(stdin);
                printf("\n Vvedite naim. dic-ny: \n");
                gets(dic.dic_lec);
                fwrite(&dic, sizeof(dic), 1, LEC);
                printf("\nProdolzat vvod? [D/H]\n");
                fflush(stdin);
                d = getche();
            } while (d == 'D' || d == 'd');
            fclose(LEC);
        }

        if (d == '2') {
            FILE* SEM;
            printf("\nVvedite imya dlya novogo file\n");
            gets(filename);
            SEM = fopen(filename, "wt+");
            do {
                fflush(stdin);
                printf("\n Vvedite naim. dic-ny: \n");
                gets(dic.dic_sem);
                fwrite(&dic, sizeof(dic), 1, SEM);
                printf("\nProdolzat vvod? [D/H]\n");
                fflush(stdin);
                d = getche();
            } while (d == 'D' || d == 'd');
            fclose(SEM);
        }

        if (d == '3') {
            FILE* LAB;
            printf("\nVvedite imya dlya novogo file\n");
            gets(filename);
            LAB = fopen(filename, "wt+");
            do {
                fflush(stdin);
                printf("\n Vvedite naim. dic-ny: \n");
                gets(dic.dic_lab);
                fwrite(&dic, sizeof(dic), 1, LAB);
                printf("\nProdolzat vvod? [D/H]\n");
                fflush(stdin);
                d = getche();
            } while (d == 'D' || d == 'd');
            fclose(LAB);
        }


        if (d == '4') {
            FILE* D;
            printf("\nВведите имя для нового файла\n");
            gets(filename);
            D = fopen(filename, "wt+");
            do {
                printf("\nВведите ФИО преподавателя:");
                gets(pr.FIO);
                fwrite(&pr, sizeof(pr), 1, D);
                printf("\nПродолжать ввод? [D/H]\n");
                fflush(stdin);
                d = getche();
            } while (d == 'D' || d == 'd');
            fclose(D);
        }

        if (d == '5') {
            FILE* A;
            int kol_audit;
            printf("\nВведите имя для нового файла\n");
            gets(filename);
            A = fopen(filename, "wt+");
            do {
                printf("Vvedite kol-vo audit.");
                scanf("%d", &kol_audit);
                for (int i = 0; i < kol_audit; i++) {
                    printf("\nВведите аудитории:");
                    scanf("%d", &audit.nomer_audit);
                }
                fwrite(&audit, sizeof(audit), 1, A);
                printf("\nПродолжать ввод? [D/H]\n");
                fflush(stdin);
                d = getche();
            } while (d == 'D' || d == 'd');
            fclose(A);
        }

        if (d == '6') {
            FILE* G;
            printf("\nВведите имя для нового файла\n");
            gets(filename);
            G = fopen(filename, "wt+");
            do {
                printf("\nВведите номер группы:");
                scanf("%d", gr.n_gr);
                fwrite(&gr, sizeof(gr), 1, G);
                printf("\nПродолжать ввод? [D/H]\n");
                fflush(stdin);
                d = getche();
            } while (d == 'D' || d == 'd');
            fclose(G);
        }
    } while (d != 1 || d != 2 || d != 3 || d != 4);
}





void output() //функция, которая печатает на экран итоговую таблицу
{
    int kol_dic;
    diciplina dic;
    prepodavatel pr;
    auditoria audit;
    group gr;

    initwindow(800, 600);
    setcolor(3);
    rectangle(0, 40, 50, 0);
    setcolor(15);
    outtextxy(10, 15, "Нед.");
    setcolor(3);
    rectangle(50, 40, 170, 0);
    setcolor(15);
    outtextxy(65, 15, "Понедельник");
    setcolor(3);
    rectangle(170, 40, 290, 0);
    setcolor(15);
    outtextxy(185, 15, "Вторник");

    setcolor(3);
    rectangle(290, 40, 410, 0);
    setcolor(15);
    outtextxy(305, 15, "Среда");
    setcolor(3);
    rectangle(410, 40, 530, 0);
    setcolor(15);
    outtextxy(425, 15, "Четверг");
    setcolor(3);
    rectangle(530, 40, 650, 0);
    setcolor(15);
    outtextxy(545, 15, "Пятница");
    setcolor(3);
    rectangle(650, 40, 770, 0);
    setcolor(15);
    outtextxy(665, 15, "Суббота");
    setcolor(3);
    rectangle(0, 0, 50, 250);
    setcolor(15);
    outtextxy(10, 100, "1");
    setcolor(3);
    rectangle(0, 250, 50, 500);
    setcolor(15);
    outtextxy(10, 350, "2");
    setcolor(3);
    rectangle(50, 0, 170, 250);
    rectangle(170, 0, 290, 250);
    rectangle(290, 0, 410, 250);
    rectangle(410, 0, 530, 250);
    rectangle(530, 0, 650, 250);
    rectangle(650, 0, 770, 250);
    rectangle(50, 250, 170, 500);
    rectangle(170, 250, 290, 500);
    rectangle(290, 250, 410, 500);
    rectangle(410, 250, 530, 500);
    rectangle(530, 250, 650, 500);
    rectangle(650, 250, 770, 500);
    setfillstyle(1, YELLOW);
    bar(0, 550, 35, 570);
    settextstyle(0, 0, 0);
    setcolor(WHITE);
    outtextxy(45, 550, " - лекция.");
    setfillstyle(1, GREEN);
    bar(250, 550, 200, 570);
    outtextxy(250, 550, " - семинар.");
    setfillstyle(1, RED);
    bar(400, 550, 450, 570);
    outtextxy(455, 550, " - лабораторная.");
    setcolor(WHITE);
    outtextxy(3, 580, "Для того, чтобы выйти из программы, нажмите");
    setcolor(RED);
    outtextxy(390, 580, " 'Enter'. ");
    setcolor(WHITE);
    outtextxy(480, 580, "Спасибо!");

    ifstream fread("K:\\dicipliny"); //читает данные из файла, размещаю их по таблице вручную
    char* s1;
    fread » s1;
    fflush(stdin);
    setcolor(YELLOW);
    outtextxy(65, 50, s1);
    // ... и тд, пока в таблицу не будут забиты данные из всех пяти файлов

    //ввод предпочтений для группы (например, такой-то препод ведет такой-то предмет в такой-то день)
    fflush(stdin);
    printf("Vvedine nomer gruppy");
    scanf("%d", &gr.n_gr);
    printf("Vvedite nomer podgruppy");
    scanf("%d", &gr.n_podgruppy);
    printf("Vvedite kol-vo diciplin");
    scanf("%d", &kol_dic);
    for (int i = 0; i < kol_dic; i++) {
        printf("Vvedite ogr. po LEC");
        printf("Vvedite naim.predmeta");
        scanf("%s", &dic.name_predmet);
        printf("Vvedite prep-lya");
        scanf("%s", &pr.FIO);
        printf("Vvedite auditorii");
        scanf("%d", &audit.nomer_audit);
    }
    for (int i = 0; i < kol_dic; i++) {
        printf("Vvedite ogr. po SEM");
        printf("Vvedite naim.predmeta");
        scanf("%s", &dic.name_predmet);
        printf("Vvedite prep-lya");
        scanf("%s", &pr.FIO);
        printf("Vvedite auditorii");
        scanf("%d", &audit.nomer_audit);
    }
    for (int i = 0; i < kol_dic; i++) {
        printf("Vvedite ogr. po LAB");
        printf("Vvedite naim.predmeta");
        scanf("%s", &dic.name_predmet);
        printf("Vvedite prep-lya");
        scanf("%s", &pr.FIO);
        printf("Vvedite auditorii");
        scanf("%d", &audit.nomer_audit);
    }


    char c = getch();
    if (c == 13) exit(0);
    getch();
}


int main() //главная функция, которая печатает на экран графическое меню
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_CTYPE, "Russian");
    char c;
    initwindow(800, 600);
    settextstyle(0, 0, 32); //0 0 4
    setcolor(3);
    outtextxy(250, 100, "Расписание");
    setcolor(10);
    setlinestyle(0, 0, 5);
    circle(175, 185, 30);
    outtextxy(160, 170, "1");
    outtextxy(220, 170, "Ввод данных");
    setcolor(2);
    circle(175, 250, 30);
    outtextxy(159, 235, "2");
    outtextxy(220, 235, "Посмотреть расписание");
    setcolor(11);
    circle(175, 315, 30);
    outtextxy(159, 300, "3");
    outtextxy(220, 300, "Справка");
    setcolor(MAGENTA);
    circle(175, 380, 30);
    outtextxy(159, 365, "4");
    outtextxy(220, 365, "Ввод учебного плана");
    setcolor(4);
    circle(175, 445, 30);
    outtextxy(159, 430, "5");
    outtextxy(220, 430, "Выход!");
    c = getch();
    settextstyle(0, 0, 1);
    if (c == 51) {
        setcolor(4);
        outtextxy(7, 480, "Справка:");
        setcolor(7);
        outtextxy(75, 480, " Название: Расписание занятий ВУЗа.");
        outtextxy(7, 500, "Нажмите 1, чтобы посмотреть оптимальное расписание!");
    }
    if (c == 53) exit(0);
    if (c == 50) output();
    if (c == 49) input();
    if (c == 52) plan();

    getch();
}
