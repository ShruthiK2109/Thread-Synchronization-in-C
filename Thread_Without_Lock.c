/* 
 * Main thread creates two child threads and join them.
 * Thread 1 fills file "datafile" with all 1s. Thread 2 fills file "datafile" with all 2s. 
 * Both executes concurrently.
 */ 

 #include <pthread.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <errno.h>
 
 void* f1();
 void* f2();
 FILE *fp,*fp1,*fp2;
 int i, j;
 int d=25;
 int main(){
     int third[d][d];
/* Fill matrix first with all 1s. Fill matrix second with all 2s.  */
     pthread_t tid1, tid2;
/* Open data file with two pointers fp1 and fp2  */
     fp1 = fopen("datafile", "wb");
     fp2 = fp1;
    //create the two child threads
     pthread_create(&tid1, NULL, f1, NULL);
     pthread_create(&tid2, NULL, f2, NULL);
    //joining the two child threads
     pthread_join(tid1, NULL); 
     pthread_join(tid2, NULL); 
     fclose(fp1);
/* Read the data written to the datafile by the two threads. Matrix third contains the reult. */
     fp = fopen("datafile", "rb");
     fread(third, sizeof(int), sizeof(third)/sizeof(int), fp);
     for (i=0; i<d; i++){
         printf("\n");
      for (j=0; j<d; j++)
            printf("%d ",third[i][j]);
     }

     printf("\nExit from main thread\n"); 
     return 0; 
 } 

/* f1 writes 1s to the data file digit by digit */
 void* f1(){
     int temp=1;
     for (i=0; i<d; i++)
         for (j=0; j<d; j++)
             fwrite(&temp, sizeof(int), sizeof(temp)/sizeof(int), fp1);
     pthread_exit(NULL); 
 } 

/* f writes 2s to the data file row by row */
 void* f2(){
     int temp=2;
     for (i=0; i<d; i++)
         for (j=0; j<d; j++)
             fwrite(&temp, sizeof(int), sizeof(temp)/sizeof(int), fp2);
     pthread_exit(NULL); 
 }