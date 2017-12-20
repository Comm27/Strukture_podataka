#pragma once

typedef struct _Queue
{
	int mBroj;
	struct _Queue *next;
}Queue;

int IsEmpty(Queue *header);
Queue* CreateNode();

int Enqueue(Queue *header, int x);
int Dequeue(Queue *header);


Queue* Peek(Queue *header);
int Print(Queue *header);