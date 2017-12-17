#include "Osoba.h"

Osoba * CreateNode(int define)
{
	Osoba *node = (Osoba*)malloc(sizeof(Osoba));
	if (node == NULL)
	{
		//ErrorHandler(ALLOC_FAILED);
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
		//ErrorHandler(NULL_ARG);
		return -1;
	}

	printf("Unesite ime: ");
	scanf("%s", node->mIme);
	printf("Unesite prezime: ");
	scanf("%s", node->mPrezime);
	printf("Unesite godinu rodenja: ");
	scanf("%d", &node->mGodRod);

	return 0;
}

int AddFirst(Osoba *header)
{
	Osoba *node = NULL;
	assert(header);
	node = CreateNode(1);

	node->next = header->next;
	header->next = node;

	return 0;
}

int AddLast(Osoba *header)
{
	Osoba *iter, *node = NULL;
	assert(header);
	node = CreateNode(1);

	iter = header;
	while (iter->next != NULL)
		iter = iter->next;

	iter->next = node;
	return 0;
}

int Print(Osoba *header)
{
	Osoba *iter = NULL;
	assert(header);

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
		//ErrorHandler(NULL_ARG, "FindBefore");
		return NULL;
	}

	iter = header;
	while (iter->next != NULL)
	{
		if (strcmp(iter->next->mPrezime, prezime) == 0)
			return iter;
		iter = iter->next;
	}

	// ErrorHandler(NO_OBJECT_FOUND, "FindBefore");
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
		// ErrorHandler(UNDEFINED_POSITION, "Insert");
		return 0;
	}

	if (temp == NULL)
	{
		// ErrorHandler(NO_OBJECT_FOUND, "InsertBefore");
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