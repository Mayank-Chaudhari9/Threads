#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t tid[2];


void * test( void *arg)
{
	unsigned long i=0;

	pthread_t id= pthread_self();

	if (pthread_equal(id,tid[0]))
	{
		printf("First thread\n");

	}
	else
	{
		printf("second thread\n");
	}


for (int i = 0; i < 10;i++)
{
	printf("running\n");
}

return NULL;

}

int main(int argc, char const *argv[])
{
	int i=0;
	int error;

	while(i<2)
	{
		error = pthread_create(&(tid[1]),NULL,&test,NULL);

		if (error!=0)
		{
			printf("\n thread creation failed : [%s]\n",strerror(error) );
		}
		else
			printf("\n Thread created successfully\n");
	
		i++;
	}


	sleep(5);

	return 0;
}
