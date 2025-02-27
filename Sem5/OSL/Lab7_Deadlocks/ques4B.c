#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<errno.h>
#include<sys/ipc.h>
#include<semaphore.h>

#define N 5

time_t end_time;/*end time*/
sem_t mutex,customers,barbers;/*Three semaphors*/
int count=0;/*The number of customers waiting for haircuts*/

void barber(void *arg)/*Barber Process*/{
	while(time(NULL)<end_time || count>0){
		sem_wait(&customers);/*P(customers)*/            
		sem_wait(&mutex);/*P(mutex)*/
		count--;
		printf("Barber:cut hair,count is:%d.\n",count);
		sem_post(&mutex);/*V(mutex)*/
		sem_post(&barbers);/*V(barbers)*/
		sleep(3);       
	}
}

void customer(void *arg)/*Customers Process*/{
	while(time(NULL)<end_time){
		sem_wait(&mutex);/*P(mutex)*/
		if(count<N){
			count++;
			printf("Customer:add count,count is:%d\n",count);
			sem_post(&mutex);/*V(mutex)*/
			sem_post(&customer);/*V(customers)*/
			sem_wait(&barbers);/*P(barbers)*/
		}
		else
			/*V(mutex)*/
			/*If the number is full of customers,just put the mutex lock let go*/
			sem_post(&mutex);
		sleep(1);
	}
}

int main(int argc,char *argv[]){
	pthread_t id1,id2;
	int status=0;
	end_time=time(NULL)+20;/*Barber Shop Hours is 20s*/

	/*Semaphore initialization*/
	sem_init(&mutex,0,1);
	sem_init(&customers,0,0);
	sem_init(&barbers,0,1);

	/*Barber_thread initialization*/
	status=pthread_create(&id1,NULL,(void *)barber,NULL);
	if(status!=0)
		perror("create barbers is failure!\n");
	/*Customer_thread initialization*/
	status=pthread_create(&id2,NULL,(void *)customer,NULL);
	if(status!=0)
		perror("create customers is failure!\n");

	/*Customer_thread first blocked*/
	pthread_join(id2,NULL);
	pthread_join(id1,NULL);

	exit(0);
}