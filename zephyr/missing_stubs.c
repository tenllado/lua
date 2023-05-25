#include <zephyr/fs/fs.h>
#include <stdio.h>
#include <errno.h>
#include <sys/times.h>

/* FIXME: this stubs should be properly implemented, in zephyr itself or here.
 * This is just a temporal non-working implementation to start testing lua with
 * zephyr.
 */

#ifdef CONFIG_PICOLIBC

clock_t times(struct tms* tms)
{
	errno = ENOTSUP;
	return (clock_t) -1;
}

#endif

#ifdef CONFIG_NEWLIB_LIBC

int _unlink(const char *pathname)
{
	errno = ENOTSUP;
	return -1;
}

int _open(const char *pathname)
{
	errno = ENOTSUP;
	return -1;
}


int _times(const char *pathname)
{
	errno = ENOTSUP;
	return -1;
}

#endif
