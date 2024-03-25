#include "timer.h"

Timer::Timer()
/* Post: Set the start time. */
{
	start_time = clock();
}

double Timer::elapsed_time()
/* Post: Return the time elapsed since start_time was last set (or reset). */
{
	clock_t end_time = clock();
	return ((double)(end_time - start_time))/((double) CLOCKS_PER_SEC);
}

void Timer::reset()
/* Post: Reset the start_time. */
{
	start_time = clock();
}
	