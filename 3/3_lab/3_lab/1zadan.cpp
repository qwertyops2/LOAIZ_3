//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <Windows.h>
//
//struct node
//{
//	char inf[256];  // �������� ����������
//	int prior;
//	struct node* next; // ������ �� ��������� ������� 
//};
//
//struct node* head = NULL, * last = NULL, * f = NULL; // ��������� �� ������ � ��������� �������� ������
//
//// ������� ���������� ��������, ��������� ������
//void spstore(void), review(void), del(char* name);
//
//char find_el[256];
//struct node* find(char* name); // ������� ���������� ��������
//struct node* get_struct(void); // ������� �������� ��������
//
//struct node* get_struct(void)
//{
//	struct node* p = NULL;
//	char s[256];
//	int prior;
//
//	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // �������� ������ ��� ����� ������� ������
//	{
//		printf("������ ��� ������������� ������\n");
//		exit(1);
//	}
//
//	printf("������� �������� �������: \n");   // ������ ������
//	scanf("%s", s);
//	if (*s == 0)
//	{
//		printf("������ �� ���� �����������\n");
//		return NULL;
//	}
//	strcpy(p->inf, s);
//
//	printf("������� ��������� �������: \n");
//	scanf("%d", &prior);
//	p->prior = prior;
//
//	p->next = NULL;
//
//	return p;		// ���������� ��������� �� ��������� �������
//}
//
///* ���������������� ���������� � ������ �������� (� �����)*/
//void spstore(void)
//{
//	struct node* p = NULL;
//	p = get_struct();
//	if (head == NULL && p != NULL)	// ���� ������ ���, �� ������������� ������ ������
//	{
//		head = p;
//		last = p;
//	}
//	else if (head != NULL && p != NULL) // ������ ��� ����, �� ��������� � �����
//	{
//		if (head->prior < p->prior) {
//			p->next = head;
//			head = p;
//		}
//		else{
//			struct node* struc = head;
//			while (struc->next != NULL && struc->next->prior >= p->prior)
//			{
//				struc = struc->next;
//			}
//			p->next = struc->next;
//			struc->next = p;
//			if (p->next == NULL) last = p;
//		}
//	}
//	return;
//}
//
///* �������� ����������� ������. */
//void review(void)
//{
//	struct node* struc = head;
//	if (head == NULL)
//	{
//		printf("������ ����\n");
//	}
//	while (struc)
//	{
//		printf("��� - %s, ��������� - %d \n", struc->inf, struc->prior);
//		struc = struc->next;
//	}
//	return;
//}
//
///* ����� �������� �� �����������. */
//struct node* find(char* name)
//{
//	struct node* struc = head;
//	if (head == NULL)
//	{
//		printf("������ ����\n");
//	}
//	while (struc)
//	{
//		if (strcmp(name, struc->inf) == 0)
//		{
//			return struc;
//		}
//		struc = struc->next;
//	}
//	printf("������� �� ������\n");
//	return NULL;
//}
//
/////* �������� �������� �� �����������. */
//void del(char* name)
//{
//	struct node* struc = head; // ���������, ���������� �� ������ ���������� �� ������ ������
//	struct node* prev = NULL;// ��������� �� �������������� ���������� �������
//	int flag = 0;      // ��������� ���������� ���������� �������� � ������
//
//	if (head == NULL) // ���� ������ ������ ����� NULL, �� ������ ����
//	{
//		printf("������ ����\n");
//		return;
//	}
//
//	if (strcmp(name, struc->inf) == 0) // ���� ��������� ������� - ������
//	{
//		flag = 1;
//		head = struc->next; // ������������� ������ �� ��������� �������
//		free(struc);  // ������� ������ �������
//		struc = head; // ������������� ��������� ��� ����������� ������
//	}
//	else
//	{
//		prev = struc;
//		struc = struc->next;
//	}
//
//	while (struc) // ������ �� ������ � ����� ���������� ��������
//	{
//		if (strcmp(name, struc->inf) == 0) // ���� �����, ��
//		{
//			flag = 1;         // ���������� ���������
//			if (struc->next)  // ���� ��������� ������� �� ��������� � ������
//			{
//				prev->next = struc->next; // ������ ���������
//				free(struc);		    // �������  �������
//				struc = prev->next; // ������������� ��������� ��� ����������� ������
//			}
//			else			// ���� ��������� ������� ��������� � ������
//			{
//				prev->next = NULL; // �������� ��������� ��������������� ��������
//				free(struc);	// �������  �������
//				return;
//			}
//		}
//		else // ���� �� �����, ��
//		{
//			prev = struc; // ������������� ��������� ��� ����������� ������
//			struc = struc->next;
//		}
//	}
//
//	if (flag == 0)				// ���� ���� = 0, ������ ������ ������� �� ������
//	{
//		printf("������� �� ������\n");
//		return;
//	}
//}
//
//int main() {
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	int dlina;
//
//	printf("������� ���������� ��: \n");
//	scanf("%d", &dlina);
//
//	for (int i = 0; i < dlina; i++) {
//		spstore();
//	}
//
//	printf("\n������������ ������\n");
//	review();
//
//	return 0;
//}