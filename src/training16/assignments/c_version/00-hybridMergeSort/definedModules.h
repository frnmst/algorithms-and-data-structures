/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#define ISOC99_SOURCE

#define _POSIX_C_SOURCE 199309L

#if __STDC_VERSION__ != 199901L
#error "ANSI C99 not available"
#endif

/* Comment out the following to disable all asserts.  */
/*#define NDEBUG*/