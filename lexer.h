#pragma once
#include<stdio.h>
#include<string.h>
#pragma warning( disable : 4996)

void getline(char* buffer, FILE* f, int t) {
	fseek(f,0,SEEK_SET);
	int count = 0;
	while (count <= t) {
		fgets(buffer, 1024, f);
		count++;
	}
}
int howManyChar(char* buffer, char t) {
	char* p = buffer;
	int count = 0;
	while (*p != '\0') {
		if (*p == t)
			count++;
		p++;
	}
	return count;
}
bool checkVar(char* buffer) {
	if (howManyChar(buffer, '=') == 1 && *(strchr(buffer, '=') - 1) != '-' && *(strchr(buffer, '=') - 1) != '+' && *(strchr(buffer, '=') - 1) != '*' && *(strchr(buffer, '=') - 1) != '/' && *(strchr(buffer, '=') - 1) != '%') {
		return true;
	}
	return false;
}

int getVarType(char* buffer) {
	char* p = buffer;
	char type[10] = {'\0'};
	int count = 0;
	while (*p != ' ') {
		type[count] = *p;
		count++;
		p++;
	}
	if (strcmp(type, "int") == 0)
		return 1;
	if (strcmp(type, "float") == 0)
		return 2;
	if (strcmp(type, "char") == 0)
		return 3;
	perror("Type does not exist");
	return NULL;
	
}
void getVarName(char* buffer, char* rname) {
	char* p = strchr(buffer, ' ')+1;
	char name[10] = { '\0' };
	int count = 0;
	while (*p != ' ') {
		name[count] = *p;
		count++;
		p++;
	}
	strcpy(rname, name);
	
}
int getValueInt(char *b) {
	int mul = 1;
	int val = 0;
	char* p = strchr(b, '=') + 1;
	while (*p == ' ') {
		if (*p != ' ' && !(*p >= 0 && *p <= 9))
			perror("This is not an int");
		p++;
	}
	for (char* x = strrchr(b, ';') - 1; x >= p; x--) {
		val += mul * (*x - '0');
		mul *= 10;
	}
	return val;
}