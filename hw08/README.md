# HW08
Wesley Van Pelt - CM3289

## PREEMPT_RT
I was able to get the real time kernel installed and working (and accidentally running on it for a while without realizing it), and the tests were able to run on it.  But, I cannot get the tests to run on the standard kernel.  I tried both of the lines in `./setup.sh` and `ulimit -r unlimited`, along with a few random things I found online but I still get the "Unable to change scheduling policy" error.

========================
Professor Yoder's Comments

I wish we could figure out why it won't run some times.

Score:  10/10