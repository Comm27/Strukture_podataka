#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#define NDEBUG
#include <assert.h>

#include "Polinom.h"

void Izbornik(Polinom *header);

int main(int argc, char*argv[])
{
	Polinom *header = CreateNode(INT_MIN, INT_MIN);
	assert(header);

	Izbornik(header);


	free(header);
	return 0;
}

void Izbornik(Polinom *header)
{
	int ans;
	char filePath[250];

	while (1)
	{
		printf("\n----------IZBORNIK----------\n");
		printf("1. Unesi listu iz file-a\n");
		printf("2. Ispisi listu\n");
		printf("3. Izlaz iz programa\n");

		printf("\n>> ");
		scanf("%d", &ans);

		switch (ans)
		{
		case 1:
			printf("Unesite ime file-a: ");
			scanf("%s", filePath);
			ReadFromFile(header, filePath);
			break;
		case 2:
			Print(header);
			break;
		case 3:
			return;
			break;
		}
	}
}