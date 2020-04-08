#include <iostream>
#include <ctime>
#include <cstdlib>

#include "class.cpp"

using namespace std;

//classes

void sort_sub(subject a[]){//сортировка предметов по убыванию часов
	cout << "sorting . .\n";
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10 - i - 1; j++){
			if (a[j].num < a[j+1].num)
				swap(a[j], a[j+1]);
			cout << i << '.' << j << "  ";
		}
		cout << '\n';
	}
}
void print_sub(subject a[]) {
	cout << "\ntable subjects:\n";
	for (int i = 0; i < 10; i++) {
		a[i].print();
	}
	cout << endl;
}
void print_tut(tutor a[]){
	cout << "table tutors:\n";
	for (int i = 0; i < 10; i++) {
		a[i].print();
	}
	cout << '\n';
}
void input_sub(subject a[]) {
	srand(time(0));
	cout << "input subjects:\n";
	for (int i = 0; i < 10; i++) {
		a[i].input(i);
	}
}
void input_tut(tutor a[]) {
	srand(time(0));
	cout << "\nenter tutors:\n";
	for (int i = 0; i < 10; i++){
		a[i].input(i);
	}
	//return a;
}
void calculate_shedule(subject (&sub)[10], tutor (&tut)[10], shedule (&shed)[4][5], audit (&aud)[10])
{
	for (int i = 0; i < 10; ++i){//цикл по предметам
		int tmp = sub[i].num;
		while (tmp > 2){ //если количество часов больше 2
			int mx = 0;
			int k = 0;//номер самого свободного дня
			for (int j = 0; j < 5; ++j){//сколько пар sub[i] предмета в неделю
				int sum = 0;
				for (int h = 0; h < 4; ++h){
					sum += tut[sub[i].tId].work[h][j];
				}
				if (sum > mx){
					mx = sum;
					k = j;//запомнить номер дня
				}
			}
			int l = 0;//номер первой свободной пары k-го дня
			while (tut[sub[i].tId].work[l][k] == 0){
				l++;//первая строка с единицей
			}
			shed[l][k].name = sub[i].name;
			shed[l][k].tut = tut[sub[i].tId].name;
			//в  массиве work пометить у преподавателя занятую пару нулем
			tut[sub[i].tId].work[l][k] = 0;
			//tmp уменьшить на единицу
         tmp--;
         cout << "\n-------------\n";
            for (int i = 0; i < 4; ++i, cout << endl){
                for (int j = 0; j < 5; ++j){
                    cout << shed[i][j].name;// << " " << shed[i][j].tut << ' ';
                }
            }
		}
	}
	/*int temp[5] = { 0, 0, 0, 0, 0 };
	for (int i = 0; i < 10; ++i){ int nm = sub[i].num;         //цикл по предметам
		while(nm > 2){
			int maks = 0, indmaks;
			for(int j = 0; j < 5; j++){
				temp[j] = 0;
				for (int k = 0; k < 4; ++k)
					temp[j] += tut[sub[i].tId].work[j][k];
				if (temp[j] > maks) {
					maks = temp[j];
					indmaks = j;
				}
			}
			int k = 0;
			while(tut[sub[i].tId].work[k][indmaks] == 0)
				k++; // пропускаем нули в столбце ворк, ищем 1цу
			shed[k][indmaks].name = sub[i].name;
			tut[sub[i].tId].work[k][indmaks] = 0;
			while(tut[sub[i].tId].work[k][indmaks] == 0)
				k++;
			shed[k][indmaks].name = sub[i].name;
			tut[sub[i].tId].work[k][indmaks] = 0;
			nm -= 2;
		}
		while(nm > 0){
			int mins = 0, indmin;
			for(int j = 0; j < 5; j++){
				temp[j] = 0;
				for (int k = 0; k < 4; ++k)
				temp[j] += tut[sub[i].tId].work[j][k];
				if (temp[j] < mins && temp[j] > 0) {
					mins = temp[j];
					indmin = j;
				}
			}
			int k = 0;
			while(tut[sub[i].tId].work[k][indmin] == 0)
				k++; // пропускаем нули в столбце ворк, ищем 1цу
			shed[k][indmin].name = sub[i].name;
			tut[sub[i].tId].work[k][indmin] = 0;
			nm--;
		}
	}*/
}
int main()
{
	subject sub[10];
	tutor tut[10];
    //tut[0].work = {1,0,1,1,1,0,0,0,1,0,1,0,1,0,1,0,1,1,0,1};
	tut[0].input_work();
	shedule shed[4][5];
	audit aud[10];

	input_sub(sub);
	input_tut(tut);

	print_sub(sub);


	print_tut(tut);

	sort_sub(sub);
	cout << "after sort:\n";
	print_sub(sub);
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 5; ++j){
			shed[i][j].name = '-';
		}
	}
	calculate_shedule(sub, tut, shed ,aud);
	cout << "shedule:" << endl;
	for (int i = 0; i < 4; ++i, cout << endl){
		for (int j = 0; j < 5; ++j){
			cout << shed[i][j].name;// << " " << shed[i][j].tut << ' ';
		}
	}
	/*
	system("pause");
	system("exit");*/
	return 0;
}
//начать с 51 строки - 21 марта. НЕ РАНЬШЕ
//что то мы уже сделали
//check for both
//what next