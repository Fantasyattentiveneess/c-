#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
typedef struct PeoInfo {
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];

}PeoInfo;
typedef struct Contact {
	PeoInfo data[MAX];
	int count;

}Contact;
//初始化通讯录
void InitContact(Contact* pc);
//添加成员
void AddContact(Contact* pc);
// 打印通讯录
void ShowContact(Contact* pc);
//删除通讯录成员
void DelContact(Contact* pc);
//查找通讯录成员
void SearchContact(Contact* pc);
//修改通讯录指定联系人
void ModifyContact(Contact* pc);
//按照姓名排序通讯录
void SortContact(Contact* pc);
