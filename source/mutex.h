/* Copyright 2014 Richard Slater. Open Source under the MIT License */

#ifndef __mutex_h_included__
#define __mutex_h_included__

typedef struct {
	void* handle;
} mutex;

mutex* mutex_create();
void mutex_destroy(mutex* a_mut);
void mutex_lock(mutex* a_mut);
void mutex_unlock(mutex* a_mut);

#endif
