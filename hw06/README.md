# HW06
Wesley Van Pelt - CM3289

## Project
I added a project with my name.

## Watch
1. Where does Julia Cartwright work?
	* National Instruments
2. What is PREEMT_RT? Hint: Google it.
	* Real-Time version of the Linux Kernel
3. What is mixed criticality?
	* Having time critical and non-time critical stuff running at the same
	  time
4. How can drivers misbehave?
	* Using `local_irq_disable()` and `local_irq_enable()`
5. What is Δ in Figure 1?
	* The amount of time between an event occurring and the relevant
	  application finding out about it
6. What is Cyclictest[2]?
	* The delta between how long a thread was supposed to sleep for and how
	  long it actually sleeps for
7. What is plotted in Figure 2?
	* How long the standard preemnt deltas are (purple) vs how long the
	  preemnt_rt deltas are for the cyclictest
8. What is dispatch latency? Scheduling latency?
	* Dispatch: The amount of time it takes between the hardware interrupt
	  firing and the scheduler being told a thread needs to run
	* Scheduling: The time it takes between the scheduler finding out a
	  thread needs to run and when that thread is actually run
9. What is mainline?
	* The standard implementation of the Linux Kernel
10. What is keeping the External event in Figure 3 from starting?
	* A non-critical IRQ
11. Why can the External event in Figure 4 start sooner?
	* The amount of code executing in the hardirq mode is much smaller, so
	  the non-critical IRQs can be interrupted by another critical IRQ

Professor Yoder's Comments
==========================

Score:  10/10
