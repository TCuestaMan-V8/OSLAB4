//
// Created by 100652479 on 3/27/2020.
//

#ifndef UNTITLED2_QUEUE_H
#define UNTITLED2_QUEUE_H


#include <stdbool.h>
#include "memory_mgmt.h"
#include "util.h"

/*************Process statuses*************/
#define NOT_STARTED 0
#define RUNNING 1
#define SUSPENDED 2
#define TERMINATED 3
/****************************************/

/*Process control block*/
struct PCB {
    int pid;							//Process ID
    char ** args; 					//Program name and arguments
    int arrival_time;
    int remaining_cpu_time;
    int priority;
    int status;						//Status of the process
    int * info;
    mabptr memory;					//Allocated memory block. NULL no memory has been allocated.
    struct PCB* next;				//Link for PCB handler
};
typedef struct PCB pcb;
typedef pcb * pcbptr;

/*Queue data strucutre*/
struct Queue {
    unsigned int timer;
    pcbptr front;
    pcbptr back;
};
typedef struct Queue queue;

void init_queue(queue * q);						//Initializes the queue
pcbptr dequeue(queue * q); 						//Removes element at the front of the queue. Also frees block and block's arg strings.
bool isEmptyQueue(queue q);						//Returns true if queue is empty. False otherwise.
void enqueue(queue * q, pcbptr value); 		//Adds element to queue.

#endif //UNTITLED2_QUEUE_H
