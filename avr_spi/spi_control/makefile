# Wed Sep 02 09:58:15  2015
# Autogenerated by class creater script

UNITTESTDIR = ../../unittest
SRCDIR = .
INSTALLDIR = ../../unittest
# ================================================================
TESTNAME=test_spi_control
OUTTESTNAME=test_spi_control
CLASSNAME=spi_control
OUTCLASSNAME=spi_control
# ================================================================
DEFS=-DUNITTEST_MODE
CPP=g++
CC=g++
C=gcc
STRIP=strip

CFLAGS = -Wall -Wcpp -Wextra -Weffc++ -O2 $(DEFS)
# LDFLAGS = 
# LIBS= -lpthread
# ================================================================
$(OUTTESTNAME): $(OUTTESTNAME).o $(OUTCLASSNAME).o
	mkdir -p $(UNITTESTDIR)
	$(CPP) $(CFLAGS) $(LDFLAGS) -o $(UNITTESTDIR)/$(OUTTESTNAME) $(OUTTESTNAME).o $(OUTCLASSNAME).o $(LIBS)
# 	$(STRIP) -s $(OUTTESTNAME)

$(OUTTESTNAME).o: $(SRCDIR)/$(TESTNAME).hpp $(SRCDIR)/$(CLASSNAME).hpp
	$(CPP) $(CFLAGS) -o $(SRCDIR)/$(OUTTESTNAME).o -c $(SRCDIR)/$(TESTNAME).cpp

$(OUTCLASSNAME).o: $(SRCDIR)/$(CLASSNAME).hpp $(SRCDIR)/$(CLASSNAME).cpp
	$(CPP) $(CFLAGS) -o $(SRCDIR)/$(OUTCLASSNAME).o -c $(SRCDIR)/$(CLASSNAME).cpp

clean:
	rm -f *.o

