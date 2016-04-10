/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef M_STDLIB_H
#define M_STDLIB_H
#include <stdlib.h>
#endif

#ifndef M_STDIO_H
#define M_STDIO_H
#include <stdio.h>
#endif

#ifndef M_ASSERT_H
#define M_ASSERT_H
#include <assert.h>
#endif

#ifndef M_LIMITS_H
#define M_LIMITS_H
#include <limits.h>
#endif

#ifndef M_TIME_H
#define M_TIME_H
#include <time.h>
#endif

#ifndef M_SYSTIME_H
#define M_SYSTIME_H
#include <sys/time.h>
#endif


#ifndef M_GLOBALDEFINES_H
#define M_GLOBALDEFINES_H
#include "../globalDefines.h"
#endif

#ifndef M_GENRANDOMARRAY_H
#define M_GENRANDOMARRAY_H
#include "../utils/genRandomArray/genRandomArray.h"
#endif

#ifndef M_MEASURERUNNINGTIME_H
#define M_MEASURERUNNINGTIME_H
#include "../utils/measureRunningTime/measureRunningTime.h"
#endif

#ifndef M_ISARRAYSORTED_H
#define M_ISARRAYSORTED_H
#include "../utils/isArraySorted/isArraySorted.h"
#endif


void mergeSort( int *V, int p, int r );
void merge( int *V, int p, int q, int r );