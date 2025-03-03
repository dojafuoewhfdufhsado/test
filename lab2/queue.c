#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue *queue_create(void)
{
  Queue *queue = malloc(sizeof(Queue));
  if (queue == NULL) { 
    printf("ERROR: malloc space failed, will return NULL.");
    return NULL;
  };                                                                // check if 
  queue->size = 0;
  queue->capacity = QUEUE_INITIAL_CAPACITY;
  queue->data = malloc(sizeof(double) * queue->capacity);
  if (queue->data == NULL) { 
    printf("ERROR: malloc space failed, will return NULL.");
    return NULL;
  };                                                                // check if
  return queue;
}

// first malloc space for Queue, next for data, malloc space for it. initial maximum length is 10

void push(Queue *queue, double element)
{
  if (queue == NULL) { return; }                                    // check valid, and i don't know how to solve it 
  if (queue->size == queue->capacity)
  {
    int capacity = queue->capacity * 2;

    double* data_temp = realloc(queue->data, sizeof(double) * capacity);
 
    if (data_temp == NULL) { 
      printf("ERROR: realloc space failed, will remain origin space.");
      return; 
    }                                                               // check if, and i don't know how to solve it 
    queue->data = data_temp
    queue->capacity = capacity;   
  }

  int insert_index = queue->size % queue->capacity;
  queue->data[insert_index] = element;
  queue->size++;
}



double back(Queue *queue)
{
  if (queue == NULL) { 
    printf("ERROR: accessing an invalid queue, will return -1.");
    return -1;
  } 
  if (queue-> size == 0) {
    printf("ERROR: accessing an empty queue, will return -2.");
    return -2;  
  }
  return queue->data[queue->size - 1];
}

void queue_free(Queue *queue)
{
  if (queue != NULL){ 
    free(queue->data);
    free(queue);
  }
}

void another_queue_free(Queue **queue) {
  if (queue != NULL && *queue != NULL) {
    free((*queue)->data); 
    free(*queue);        
    *queue = NULL;     
  }
}

