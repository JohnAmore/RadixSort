#include <time.h>

class Timer {
public:
	Timer();
	/* Post: Set the start time. */
	
	double elapsed_time();
	/* Post: return the time elapsed since start_time was last set (or reset). */
	
	void reset();
	/* Post: Reset the start_time. */
	
private:
	clock_t start_time;
};