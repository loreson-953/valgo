# Most systems only need -lncurses to compile:
CFLAGS = -lncurses

# On some systems like Gentoo and Arch, -ltinfo is a required flag for ncurses
# Uncomment if this is the case on your system:
#CFLAGS += -ltinfo
