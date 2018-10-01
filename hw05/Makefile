# *****************************************************************
#
# Starter Makefile
#
# Contains rules for:
#
# - .x (arm executable target)
# - .o (arm object file)
# - .PHONY (all, clean and test)
#
#
# Uses the following variables (built-in and user-defined):
#
# CC = C compiler (gcc)
# CFLAGS = compiler options (e.g. -g)
# LINKER_FLAGS = specify libraries to link in
# $@ = target
# $^ = all dependencies
# $< = first dependency only (not used in this solution)
#
# Generic "rule" terminology:
#
# target:dependency
# [TAB] <CMD1>
# [TAB] <CMD2>
#
# GCC options used in this Makefile:
#
# -c = "compile only"
# -o = "output filename"
# -g = "debug mode"
#
# Note1: if you use a filename other than "makefile", use the
# 	 -f option to enable make to use it:
# 	 e.g.  make -f my_make_file.mak
#
# Note2: .PHONY tells make that the rule's target is not
#        actually a file (to be created or searched for).
#
# Note3: When make runs without any rules specified on the
#        command line, it will make (by default) the FIRST
#        rule found in the makefile. Hence, it is common
#        to have a rule named "all" listed first (as below).
#
# ***************************************************************


# -----------------------
# ------ includes -------
# -----------------------
-include ./path.mak


# --------------------------------
# ------ user-defined vars -------
# --------------------------------
CC := $(LINUXarm_GCC)
CFLAGS := -g
LFLAGS := -lstdc++


# -----------------------
# ------ make all -------
# -----------------------
.PHONY: all
all: app.x


# -----------------------------------
# ------ executable rule (.x) -------
# -----------------------------------
app.x: app.o
	$(CC) $(CFLAGS) $(LFLAGS) $< -o $@
	@echo; echo $@ successfully created; echo


# ---------------------------------------------------
# ------ intermeditate object files rule (.o) -------
# ---------------------------------------------------
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# ----------------------
# ----- clean all ------
# ----------------------
.PHONY: clean
clean:
	rm -rf *.o
	rm -rf *.x
	rm -rf *.out


# -------------------------------------
# ----- basic debug for Makefile ------
#
# -----     example only         ------
# -------------------------------------
.PHONY: test
test:
	@echo CC = $(CC)
