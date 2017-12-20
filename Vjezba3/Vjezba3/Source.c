#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//#define NDEBUG
#include <assert.h>

#include "Osoba.h"
#include "../../libs/mylibs/textmanip.h"

void Izbornik(Osoba *);

int main(int argc, char *argv[])
{
	
	Osoba *header = CreateNode(0);
	int i = 0;
	assert(header);

	Izbornik(header);

	free(header);

	
	getchar();
	getchar();
	return 0;
}

void Izbornik(Osoba *header)
{
	int ans;
	char prezime[50];
	char filePath[250];
	Osoba *node = NULL;

	while (1)
	{
		printf("\n----------IZBORNIK----------\n");
		printf("1. Dodaj element na pocetak\n");
		printf("2. Dodaj element na kraj\n");
		printf("3. Pronadi element prije _____\n");
		printf("4. Pronadi element\n");
		printf("5. Pronadi element iza _____\n");
		printf("6. Umetni ispred elementa _____\n");
		printf("7. Umetni iza elementa _____\n");
		printf("8. Izbrisi element\n");
		printf("9. Ispisi listu u file\n");
		printf("10. Unesi listu iz file-a\n");
		printf("11. Sortiraj listu(po prezimenu)\n");
		printf("12. Ispisi listu\n");
		printf("13. Izlaz iz programa\n");

		printf("\n>> ");
		scanf("%d", &ans);

		switch (ans)
		{
		case 1:
			AddFirst(header);
			break;
		case 2:
			AddLast(header);
			break;
		case 3:
			printf("Unesite prezime: ");
			scanf("%s", prezime);
			node = FindBefore(header, prezime);
			if(node != NULL)
				printf("Element pronaden!\n%s %s %d", node->mIme, node->mPrezime, node->mGodRod);
			break;
		case 4:
			printf("Unesite prezime: ");
			scanf("%s", prezime);
			node = Find(header, prezime);
			if(node != NULL)
				printf("Element pronaden!\n%s %s %d", node->mIme, node->mPrezime, node->mGodRod);
			break;
		case 5:
			printf("Unesite prezime: ");
			scanf("%s", prezime);
			node = FindAfter(header, prezime);
			if(node != NULL)
				printf("Element pronaden!\n%s %s %d", node->mIme, node->mPrezime, node->mGodRod);
			break;
		case 6:
			printf("Unesite prezime: ");
			scanf("%s", prezime);
			InsertBefore(header, prezime);
			break;
		case 7:
			printf("Unesite prezime: ");
			scanf("%s", prezime);
			InsertAfter(header, prezime);
			break;
		case 8:
			printf("Unesite prezime: ");
			scanf("%s", prezime);
			RemoveNode(header, prezime);
			break;
		case 9:
			printf("Unesite ime file-a: ");
			scanf("%s", filePath);
			WriteToFile(header, filePath);
			break;
		case 10:
			printf("Unesite ime file-a: ");
			scanf("%s", filePath);
			ReadFromFile(header, filePath);
			break;
		case 11:
			ans = SortList(header);
			printf("Izvrsio se %d puta.\n", ans);
			break;
		case 12:
			Print(header);
			break;
		case 13:
			return;
			break;
		}
	}
}