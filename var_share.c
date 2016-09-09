/* Progarm to change value of shared variable by different threads */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *val_by_first_thread( void *ptr );
void *val_by_second_thread( void *ptr );


int main()
{
    pthread_t thread1, thread2;
    
    int  iret1, iret2;
    int share_var=10;
    int *share=&share_var;

    printf("value before modification %d\n",share_var );
    /* Create independent threads each of which will execute functions */

     iret1 = pthread_create( &thread1, NULL, val_by_first_thread, (void*) share);
     if(iret1)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
         exit(EXIT_FAILURE);
     }

     iret2 = pthread_create( &thread2, NULL, *val_by_second_thread, (void*) share);
     if(iret2)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
         exit(EXIT_FAILURE);
     }

     printf("pthread_create() for thread 1 returns: %d\n",iret1);
     printf("pthread_create() for thread 2 returns: %d\n",iret2);
     
     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     printf("fina value %d\n",share_var);

     exit(EXIT_SUCCESS);

     return 0;
}

void *val_by_first_thread( void *ptr )
{
     int *intp;
     intp = (int *) ptr;
    *intp=100;
    printf(" value modified by first thread %d\n",*intp);
}

void *val_by_second_thread( void *ptr )
{
     int *intp;
     intp = (int *) ptr;
     *intp=20000;
     printf(" value modified by second thread %d\n",*intp);
}

