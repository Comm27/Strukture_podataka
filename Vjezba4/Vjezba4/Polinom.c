#include "Polinom.h"

Polinom * CreateNode(float k, float p)
{
	Polinom *node = (Polinom*)malloc(sizeof(Polinom));
	if (node == NULL)
	{
		//ErrorHandler(ALLOC_FAILED, "CreateNode");
		return NULL;
	}

	node->k = k;
	node->p = p;
	node->next = NULL;
	return node;
}

int AddFirst(Polinom *header, float k, float p)
{
	Polinom *node = NULL;
	node = CreateNode(k, p);

	node->next = header->next;
	header->next = node;

	return 0;
}

int AddLast(Polinom *header, float k, float p)
{
	Polinom *iter, *node = NULL;
	node = CreateNode(k, p);

	iter = header;
	while (iter->next != NULL)
		iter = iter->next;

	iter->next = node;
	return 0;
}

int ReadFromFile(Polinom *header, const char *filepath)
{
	float k, p;
	FILE *file = NULL;

	file = fopen(filepath, "r");
	if (file == NULL)
	{
		printf("Could not open file!\n");
		return -1;
	}

	while (!feof(file))
	{
		fscanf(file, "%f %f", &k, &p);
		AddFirst(header, k, p);
		SortList(header);
	}

	fclose(file);
	return 0;
}


int Print(Polinom *header)
{
	Polinom *iter = NULL;

	iter = header->next;
	while (iter != NULL)
	{
		printf("K = %f\tP = %f\n", iter->k, iter->p);
		iter = iter->next;
	}

	return 0;
}


int SortList(Polinom * header)
{
	Polinom *nodeA = NULL, *nodeB = NULL;
	Polinom *prev = NULL;
	Polinom *start = NULL, *sorted = NULL;
	int i = 0;

	start = header;
	prev = header;

	while (start->next != NULL)
	{
		prev = header;
		while (prev->next->next != sorted && prev->next->next != NULL)
		{
			nodeA = prev->next;
			nodeB = nodeA->next;
			if (nodeA->p < nodeB->p)
			{
				nodeA->next = nodeB->next;
				nodeB->next = nodeA;
				prev->next = nodeB;
			}
			prev = prev->next;
			++i;
		}
		sorted = nodeA;
		start = start->next;
	}

	return i;
}