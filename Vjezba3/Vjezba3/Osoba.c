#include "Osoba.h"

Osoba * CreateNode(int define)
{
	Osoba *node = (Osoba*)malloc(sizeof(Osoba));
	if (node == NULL)
	{
		ErrorHandler(ALLOC_FAILED, "CreateNode");
		return NULL;
	}

	node->next = NULL;

	if (define)
		DefineObj(node);

	return node;
}

int DefineObj(Osoba *node)
{
	if (node == NULL)
	{
		ErrorHandler(NULL_ARG, "DefineObj");
		return -1;
	}

	printf("Unesite ime: ");
	scanf("%s", node->mIme);
	printf("Unesite prezime: ");
	scanf("%s", node->mPrezime);
	printf("Unesite godinu rodenja: ");
	scanf("%d", &node->mGodRod);
	if (node->mGodRod <= 1900)
	{
		ErrorHandler(WRONG_INPUT, "DefineObj");
		// Enter again number
	}

	return 0;
}

int AddFirst(Osoba *header)
{
	Osoba *node = NULL;
	node = CreateNode(1);

	node->next = header->next;
	header->next = node;

	return 0;
}

int AddLast(Osoba *header)
{
	Osoba *iter, *node = NULL;
	node = CreateNode(1);

	iter = header;
	while (iter->next != NULL)
		iter = iter->next;

	iter->next = node;
	return 0;
}

int AddFirstNode(Osoba * header, Osoba * node)
{
	if (node == NULL)
		return -1;
	node->next = header->next;
	header->next = node;

	return 0;
}

int AddLastNode(Osoba * header, Osoba * node)
{
	Osoba *iter;
	if (node == NULL)
		return -1;

	iter = header;
	while (iter->next != NULL)
		iter = iter->next;

	iter->next = node;
	return 0;
}

int Print(Osoba *header)
{
	Osoba *iter = NULL;

	iter = header->next;
	while (iter != NULL)
	{
		printf("Ime i prezime: %s %s Godina rodenja: %d\n", iter->mIme, iter->mPrezime, iter->mGodRod);
		iter = iter->next;
	}

	return 0;
}

Osoba* FindBefore(Osoba *header, const char *prezime)
{
	Osoba *iter = NULL;
	assert(header);
	if (prezime == NULL)
	{
		ErrorHandler(NULL_ARG, "FindBefore");
		return NULL;
	}

	iter = header;
	while (iter->next != NULL)
	{
		if (strcmp(iter->next->mPrezime, prezime) == 0)
			return iter;
		iter = iter->next;
	}

	ErrorHandler(NO_OBJECT_FOUND, "FindBefore");
	return NULL;
}

Osoba* Find(Osoba *header, const char *prezime)
{
	return FindBefore(header, prezime)->next;
}

Osoba* FindAfter(Osoba *header, const char *prezime)
{
	return Find(header, prezime)->next;
}

int Insert(Osoba *header, const char *prezime, pos position)
{
	Osoba *temp = NULL, *node = NULL;

	if (position == BEFORE)
	{
		temp = FindBefore(header, prezime);
	}
	else if (position == AFTER)
	{
		temp = Find(header, prezime);
	}
	else
	{
		ErrorHandler(UNDEFINED_POSITION, "Insert");
		return 0;
	}

	if (temp == NULL)
	{
		ErrorHandler(NO_OBJECT_FOUND, "InsertBefore");
		return -1;
	}

	node = CreateNode(1);

	node->next = temp->next;
	temp->next = node;

	return 0;
}

int InsertBefore(Osoba *header, const char *prezime)
{
	return Insert(header, prezime, BEFORE);
}

int InsertAfter(Osoba *header, const char *prezime)
{
	return Insert(header, prezime, AFTER);
}

int RemoveNode(Osoba *header, const char *prezime)
{
	Osoba *temp = NULL, *toDelete = NULL;
	temp = FindBefore(header, prezime);

	if (temp == NULL)
		return -1;

	toDelete = temp->next;
	temp->next = toDelete->next;

	free(toDelete);
	return 0;
}

int WriteToFile(Osoba * header, const char * filePath)
{
	FILE *file = NULL;
	Osoba *iter = header->next;
	if (filePath == NULL)
		return -1;

	file = fopen(filePath, "w");
	if (file == NULL)
		return -1;

	while (iter != NULL)
	{
		fprintf(file, "%s %s %d\n", iter->mIme, iter->mPrezime, iter->mGodRod);
		iter = iter->next;
	}

	fclose(file);
	return 0;
}

int ReadFromFile(Osoba * header, const char * filePath)
{
	FILE *file;
	char ime[BUFFER_MAX_LENGTH];
	char prez[BUFFER_MAX_LENGTH];
	int god_rod = 0;
	Osoba *node = NULL;

	if (filePath == NULL)
	{
		return -1;
	}

	file = fopen(filePath, "r");
	if (file == NULL)
	{
		ErrorHandler(NO_FILE_FOUND, "ReadFromFile");
		return -1;
	}

	while (fscanf(file, "%s %s %d", ime, prez, &god_rod) > 0)
	{
		node = CreateNode(0);
		if (node == NULL)
		{
			ErrorHandler(ALLOC_FAILED, "ReadFromFile");
			return -1;
		}

		strcpy(node->mIme, ime);
		strcpy(node->mPrezime, prez);
		node->mGodRod = god_rod;
		AddLastNode(header, node);
	}

	fclose(file);
	return 0;
}

int SortList(Osoba * header)
{
	Osoba *nodeA = NULL,*nodeB = NULL;
	Osoba *prev = NULL;
	Osoba *start = NULL, *sorted = NULL;
	int i = 0;

	start = header;
	prev = header;

	while (start->next != NULL)
	{
		prev = header;
		while (prev->next->next != sorted)
		{
			nodeA = prev->next;
			nodeB = nodeA->next;
			if (strcmp(nodeA->mPrezime, nodeB->mPrezime) > 0)
			{
				prev->next = nodeB;
				nodeA->next = nodeB->next;
				nodeB->next = nodeA;
			}
			prev = prev->next;
			++i;
		}
		sorted = nodeA;
		start = start->next;
	}

	return i;
}