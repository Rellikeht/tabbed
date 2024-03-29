# tabbed version
VERSION = 0.6

# Customize below to fit your system

# paths
PREFIX ?= /usr/local
MANPREFIX ?= ${PREFIX}/share/man

X11INC = /usr/X11R6/include
X11LIB = /usr/X11R6/lib

# freetype
FREETYPELIBS = -lfontconfig -lXft
#FREETYPEINC = /usr/local/include/freetype2
FREETYPEINC = /usr/include/freetype2
#FEETYPEINC = `pkg-config --cflags freetype2`
# OpenBSD (uncomment)
#FREETYPEINC = ${X11INC}/freetype2

# includes and libs
INCS = -I. -I/usr/include -I$(X11INC) -I${FREETYPEINC}
LIBS = -L/usr/lib -lc -L${X11LIB} -lX11 ${FREETYPELIBS} -lXrender

# flags
CPPFLAGS = -DVERSION=\"${VERSION}\" -D_DEFAULT_SOURCE
CFLAGS = -std=c99 -pedantic -Wall -O2 ${INCS} ${CPPFLAGS} # -mmusl 
LDFLAGS = -s ${LIBS}
 
 # flags
CPPFLAGS = -DVERSION=\"${VERSION}\" -D_DEFAULT_SOURCE

# Solaris
#CFLAGS = -fast ${INCS} -DVERSION=\"${VERSION}\"
#LDFLAGS = ${LIBS}

# compiler and linker
CC ?= gcc
