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
//��ʼ��ͨѶ¼
void InitContact(Contact* pc);
//��ӳ�Ա
void AddContact(Contact* pc);
// ��ӡͨѶ¼
void ShowContact(Contact* pc);
//ɾ��ͨѶ¼��Ա
void DelContact(Contact* pc);
//����ͨѶ¼��Ա
void SearchContact(Contact* pc);
//�޸�ͨѶ¼ָ����ϵ��
void ModifyContact(Contact* pc);
//������������ͨѶ¼
void SortContact(Contact* pc);
