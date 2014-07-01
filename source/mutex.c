/* Copyright 2014 Richard Slater. Open Source under the MIT License */

#include "mutex.h"
#include "stdlib.h"

/* windows */
#ifdef _WIN32
#include "windows.h"

mutex* mutex_create() {
	mutex* mut;
	mut = malloc(sizeof(*mut));
	mut->handle = CreateMutex(NULL, FALSE, NULL);
	return mut;
}

void mutex_destroy(mutex* a_mut) {
	CloseHandle(a_mut->handle);
	free(a_mut);
}

void mutex_lock(mutex* a_mut) {
	WaitForSingleObject(a_mut->handle, INFINITE);
}

void mutex_unlock(mutex* a_mut) {
	ReleaseMutex(a_mut->handle);
}

/* posix */
#else
#include "pthread.h"

mutex* mutex_create() {
	pthread_mutex_t* ptmut;
	ptmut = malloc(sizeof(*ptmut));
	pthread_mutex_init(ptmut, NULL);
	mutex* mut;
	mut = malloc(sizeof(*mut));
	mut->handle = ptmut;
	return mut;
}

void mutex_destroy(mutex* a_mut) {
	pthread_mutex_destroy(a_mut->handle);
	free(a_mut->handle);
	free(a_mut);
}

void mutex_lock(mutex* a_mut) {
	pthread_mutex_lock(a_mut->handle);
}

void mutex_unlock(mutex* a_mut) {
	pthread_mutex_unlock(a_mut->handle);
}

#endif
