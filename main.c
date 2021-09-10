#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define MAX 300
#define BUZZ_SIZE 1024
typedef struct Student
{
	long id;
	char fName[MAX];
	char lName[MAX];
	char gender[MAX];
	char birth[MAX];
	char className[MAX];
	char country[MAX];
	float mediumScore;
	char fullName[MAX];
	//Student ID, First name, Last name, Gender, Date of birth, Classname, Country
}Student;
typedef Student ST;
typedef struct Subject
{
	long id;
	char name[MAX];
	int creadit;
	//Subject ID,Subject Name,Credit

}Subject;
typedef Subject SJ;
typedef struct Score
{
	int studentID;
	int subjectID;
	double Score;
	//Student ID,Subject ID,Score

}Score;
typedef Score SC;
int readFileSubject(FILE* file, SJ sj[MAX]) {
	if (file == NULL) {
		printf("can't open file");
	}
	int a;
	int size = 0;
	char line[200];
	while (fgets(line, sizeof(line), file))
	{
		a = 1;
		char* token;
		token = strtok(line, ",");
		while (token != NULL)
		{
			switch (a)
			{
			case 1:
				sj[size].id = atoi(token);
				break;
			case 2:
				strcpy(sj[size].name, token);
				break;
			case 3:
				sj[size].creadit = atoi(token);
			}
			//printf("%s\n", token);
			token = strtok(NULL, ",");
			a++;
		}
		size++;
	}
	fclose(file);
	return size;
}
int readFileStudent(FILE* file, ST st[]) {
	if (file == NULL) {
		printf("can't open file");
	}
	int a;
	int size = 0;
	char line[MAX];
	while (fgets(line, sizeof(line), file))
	{
		a = 1;
		char* token;
		token = strtok(line, ",");
		while (token != NULL)
		{
			switch (a)
			{
			case 1:
				st[size].id = atoi(token);
				break;
			case 2:
				strcpy(st[size].fName, token);
				break; 
			case 3:
				strcpy(st[size].lName, token);
				break;
			case 4:
				strcpy(st[size].gender, token);
				break;
			case 5:
				strcpy(st[size].birth, token);
				break;
			case 6:
				strcpy(st[size].className, token);
				break;
			case 7:
				strcpy(st[size].country, token);
				break;
			}
			//printf("%s\n", token);
			token = strtok(NULL, ",");
			a++;
		}
		size++;
	}
	fclose(file);
	return size;
}
void printListSubject(SJ sj[], int size) {
	for (int i = 0; i < size; i++) {
		printf("Subject ID:%d\n", sj[i].id);
		printf("Subject Name:%s\n", sj[i].name);
		printf("Creadit:%d\n", sj[i].creadit);
		printf("\n");
	}
}
void fullName(ST s[], int size) {
	char tr[30];
	char str[2] = " ";
	for (int i = 0; i < size; i++) {
		strcpy(s[i].fullName, s[i].fName);
		strcat(s[i].fullName, str);
		strcat(s[i].fullName, s[i].lName);
		strupr(s[i].fullName);
	}
}
void printListStudent(ST st[], int size) {
	FILE* f = fopen("result.csv", "w");
	for (int i = 0; i < size; i++) {
		printf("Student %d\n", i + 1);
		printf("ID: %d\n", st[i].id);
		printf("First Name: %s\n", st[i].fName);
		printf("Last Name: %s\n", st[i].lName);
		printf("Gender: %s\n", st[i].gender);
		printf("Date of  Birth: %s\n", st[i].birth);
		printf("Class Name: %s\n", st[i].className);
		printf("Country: %s\n", st[i].country);
		fprintf(f, "%d,%s,%s,%s,%s,%s,%s", st[i].id, st[i].fName, st[i].lName, st[i].gender, st[i].birth, st[i].className, st[i].country);
	}
	fclose(f);
}
void processFileStudent(ST s[]) {
	char buff[MAX];
	FILE* file = fopen("dssv.csv", "r");
	fgets(buff, 1000, file);
	int size = readFileStudent(file, s);
	printListStudent(s, size);
}
void processFileSubject(SJ sj[]) {
	char buff[MAX];
	FILE* f = fopen("dsmh.csv", "r");
	fgets(buff, 1000, f);
	int sz = readFileSubject(f, sj);
	printListSubject(sj, sz);
}

int readFileScore(FILE* file, SC sc[]) {
	if (file == NULL) {
		printf("can't open file");
	}
	int a;
	int size = 0;
	char line[200];
	float score = 0;
	while (fgets(line, sizeof(line), file))
	{
		a = 1;
		char* token;
		token = strtok(line, ",");
		while (token != NULL)
		{
			switch (a)
			{
			case 1:
				sc[size].studentID = atoi(token);
				break;
			case 2:
				sc[size].subjectID = atoi(token);
				break;
			case 3:
				score = (double)atof(token);
				sc[size].Score = score;
			}
			//printf("%s\n", token);
			token = strtok(NULL, ",");
			a++;
		}
		size++;
	}
	fclose(file);
	return size;
}
void printListScore(SC sj[], int size) {
	for (int i = 0; i < size; i++) {
		printf("Subject ID:%d\n", sj[i].subjectID);
		printf("Student ID:%d\n", sj[i].studentID);
		printf("Score:%f\n", sj[i].Score);
		printf("\n");
	}
}
void processScore(SC sc[]) {
	char buff[MAX];
	FILE* f = fopen("diem.csv", "r");
	fgets(buff, 1000, f);
	int size = readFileScore(f, sc);
	printListScore(sc, size);
}
void printStudentByClassName(char className[], ST st[], int size) {
	int k = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp(className, st[i].className) == 0) {
			printf("Student %d\n", i + 1);
			printf("ID: %d\n", st[i].id);
			printf("First Name: %s\n", st[i].fName);
			printf("Last Name: %s\n", st[i].lName);
			printf("Gender: %s\n", st[i].gender);
			printf("Date of  Birth: %s\n", st[i].birth);
			printf("Class Name: %s\n", st[i].className);
			printf("Country: %s\n", st[i].country);
			k++;
		}
	}
	if (k == 0) {
		printf("Can't find class name:%s\n", className);
	}
}
int coutGender(ST st[]) {
	char buff[MAX];
	FILE* file = fopen("dssv.csv", "r");
	fgets(buff, 1000, file);
	int size = readFileStudent(file, st);
	int male = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp("Male", st[i].gender) == 0) {
			male++;
		}
	}
	return male;
}
void sortStudent(ST s[], int size) {
	ST temp;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (s[i].mediumScore > s[j].mediumScore) {
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
}
int sizeSubject(SJ sj[]) {
	char buff[MAX];
	FILE* f = fopen("dsmh.csv", "r");
	fgets(buff, 1000, f);
	int sz = readFileSubject(f, sj);
	return sz;
}

void topN(int n, ST st[], SC sc[], int count) {
	sortStudent(st, count);
	FILE* f = fopen("result.csv", "w");
	int j = 0;
	for (int i = count - 1; i >= 0; i--) {
		printf("Student %d\n", j);
		printf("ID: %d\n", st[i].id);
		printf("First Name: %s\n", st[i].fName);
		printf("Last Name: %s\n", st[i].lName);
		printf("Gender: %s\n", st[i].gender);
		printf("Date of  Birth: %s\n", st[i].birth);
		printf("Class Name: %s\n", st[i].className);
		printf("Country: %s\n", st[i].country);
		printf("Medium Score: %f\n", st[i].mediumScore);
		fprintf(f, "%d,%s,%s,%s,%s,%s,%s", st[i].id, st[i].fName, st[i].lName, st[i].gender, st[i].birth, st[i].className, st[i].country);
		j++;
		if (j == n) {
			return;
		}
	}
	fclose(f);
}
int sizeScore(SC sc[]) {
	char buff[MAX];
	FILE* f = fopen("diem.csv", "r");
	fgets(buff, 1000, f);
	int size = readFileScore(f, sc);
	return size;
}
void mediumSore(ST st[], SC sc[], int n ,int sizeSj) {
	int sizeSub = sizeScore(sc);
	float mediumScore = 0;
	for (int i = 0; i < n; i++) {
		mediumScore = 0;
		for (int j = 0; j < sizeSub; j++) {
			if (st[i].id == sc[j].studentID) {
				mediumScore += (float)sc[j].Score;
			}
		}
		st[i].mediumScore = mediumScore / sizeSj;
	}
}
void sortByNameDesc(ST st[], int size) {
	ST tmp;
	char tenSV1[30];
	char tenSV2[30];
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (strcmp(st[i].fName, st[j].fName) < 0) {
				tmp = st[i];
				st[i] = st[j];
				st[j] = tmp;
			}
		}
	}

	printListStudent(st, size);
}
void sortByNameAsc(ST st[], int size) {
	ST tmp;
	char tenSV1[30];
	char tenSV2[30];
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (strcmp(st[i].fName, st[j].fName) > 0) {
				tmp = st[i];
				st[i] = st[j];
				st[j] = tmp;
			}
		}
	}
	
	printListStudent(st, size);
}
void findByName(ST s[], char name[], int size) {
	fullName(s, size);
	ST arrayFound[MAX];
	char studentName[30];
	int found = 0;
	for (int i = 0; i < size; i++) {
		strcpy(studentName, s[i].fullName);
		if (strcmp(studentName, name)==0) {
			arrayFound[found] = s[i];
			found++;
		}
	}
	if (found == 0) {
		printf(" not found\n");
	}
	printListStudent(arrayFound, found);
}
int countStudent(ST st[]) {
	char buff[MAX];
	FILE* file = fopen("dssv.csv", "r");
	fgets(buff, 1000, file);
	int size = readFileStudent(file, st);
	return size;
}
char* cut(char str[], char comand[]) {
	char* p, * q;
	p = comand;
	puts(comand);
	while (q = strtok(p, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz<>")) {
		p = NULL;
		strcpy(str, q);
	}
	return str;
}
int sizeOf(char str[]) {
	int size = 0;
	while (str[size]!='>')
	{
		size++;
	}
	return size;
}
char* cutString(char str[], char comand[]) {
	strcpy(str, strncpy(str, comand + 8, strlen(comand)));
	int size = 0;
	size=sizeOf(str);
	str[size] = '\0';
	return str;
}
void saveComand_1(char className[], ST st[], int size) {
	FILE* f = fopen("result.csv", "w");
	int k = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp(className, st[i].className) == 0) {
			printf("Student %d\n", i + 1);
			printf("ID: %d\n", st[i].id);
			printf("First Name: %s\n", st[i].fName);
			printf("Last Name: %s\n", st[i].lName);
			printf("Gender: %s\n", st[i].gender);
			printf("Date of  Birth: %s\n", st[i].birth);
			printf("Class Name: %s\n", st[i].className);
			printf("Country: %s\n", st[i].country);
			k++;
			fprintf(f, "%d,%s,%s,%s,%s,%s,%s", st[i].id, st[i].fName,st[i].lName, st[i].gender, st[i].birth, st[i].className, st[i].country);
		}
	}
	if (k == 0) {
		printf("Can't find class name:%s\n", className);
	}
	fclose(f);
}
void findByClasName(char comand[], ST s[]) {
	char buff[MAX];
	FILE* file = fopen("dssv.csv", "r");
	fgets(buff, 1000, file);
	int size = readFileStudent(file, s);
	saveComand_1(comand, s, size);
	printStudentByClassName(comand, s, size);
}
char* readComand(char fileName[30]) {
	char buff[MAX];
	FILE* file = fopen(fileName, "r");
	fgets(buff, 1000, file);
	return buff;
}
int main() {
	FILE* f = fopen("result.csv", "w");
	ST* s = calloc(2000, sizeof(ST));
	SJ* sj = calloc(2000, sizeof(SJ));
	SC* sc = calloc(2000, sizeof(SC));
	int size = countStudent(s);
	char buff[100];
	int sizeSj = sizeSubject(sj);
	char*comand = readComand("cmd.txt");
	char str[50];
	static char strList[30] = "LIST";
	static char systemComand[30] = "COUNT";
	static char systemComandTop[30] = "TOP";
	static 	char systemComandASC[30] = "SORT";
	static char systemComandSearch[30] = "SEARCH";
	static 	char countMale[30] = "COUNT MALE";
	static 	char countFemale[30] = "COUNT FEMALE";
	static	char sortASC[30] = "SORT ASC";
	static	char sortDESC[30] = "SORT DESC";
	int n;
	int countGender;
	if (strstr(strupr(comand), strupr(strList))) {
		strcpy(str, cut(str, comand));
		findByClasName(str, s);
	}
	else if (strstr(strupr(comand), strupr(systemComand))) {
		if (strcmp(comand, countMale) == 0) {
			countGender = coutGender(s);
			printf("Number of Male:%d ", coutGender(s));
		}
		else if (strcmp(comand, countFemale) == 0)
		{
			countGender = countStudent(s) - coutGender(s);
			printf("Number of Female:%d ", countStudent(s) - coutGender(s));
		}
		else
		{
			printf("Illegal");
		}
		fprintf(f, "%d", countGender);
	}
	else if (strstr(strupr(comand), strupr(systemComandTop))) {
		n = atoi(cut(str, comand));
		mediumSore(s, sc, countStudent(s), sizeSj);
		topN(n, s, sc, countStudent(s));
	}
	else if (strstr(strupr(comand), strupr(systemComandASC))) {
		if (strcmp(comand, sortASC) == 0) {
			printf("-----Sort ASC--------\n");
			sortByNameAsc(s, size);
		}
		else if (strcmp(comand, sortDESC) == 0)
		{
			printf("-----Sort DESC----------\n");
			sortByNameDesc(s, size);
		}
		else
		{
			printf("Illegal");
		}
	}
	else if (strstr(strupr(comand), strupr(systemComandSearch))) {
		char* t = cutString(str, comand);
		printf("Find Name %s\n",t);
		
		findByName(s, t, size);
	}
	return 0;
}