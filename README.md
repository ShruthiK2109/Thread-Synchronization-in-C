# Thread-Synchronization-in-C
This project demonstrates the use of multithreading in C using the POSIX pthread library and explores synchronization mechanisms like mutex locks and semaphores to manage concurrent file access.

Overview:

The program consists of three parts:

i) Without Locking – Two threads write to a shared file concurrently, leading to an interleaved output.

ii) Using Mutex Locking – A mutex is used to ensure only one thread writes at a time, preventing race conditions.

iii) Using Semaphores – A semaphore achieves the same effect as a mutex, enforcing sequential execution of threads.

Implementation Details:

I. Multithreading Without Synchronization

The program creates two threads:

Thread 1 writes 1s to a file.

Thread 2 writes 2s to the same file.

Since no locking mechanism is used, both threads write simultaneously, causing a race condition.

The output is a random mix of 1s and 2s due to concurrent access.

II. Synchronization Using Mutex Locks

A mutex (mutual exclusion lock) is used to ensure that only one thread can write to the file at a time.

Thread 1 acquires the lock, writes 1s, and releases it.

Thread 2 waits for the lock, writes 2s, and releases it.

This prevents overlapping writes and ensures that one thread completes execution before the other starts.

As a result, the file contains only 1s or only 2s, depending on which thread executed first.

III. Synchronization Using Semaphores

A semaphore is used instead of a mutex to control thread execution.

Thread 1 waits for the semaphore, writes 1s, then signals the semaphore.

Thread 2 does the same, ensuring sequential execution.

Similar to the mutex approach, this prevents data corruption and ensures controlled file access.
