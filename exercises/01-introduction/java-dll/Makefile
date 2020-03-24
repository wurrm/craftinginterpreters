JCC = javac
JFLAGS = -g -Xlint

SRCDIR = .

SOURCES := $(shell find $(SRCDIR) -type f -name "*.java")
CLASSES := $(SOURCES:.java=.class)

.SUFFIXES: .java .class
.java.class:
	$(JCC) $(JFLAGS) -classpath $(SRCDIR) $*.java

default: classes

classes: $(CLASSES)

.PHONY: clean

clean:
	$(RM) $(CLASSES)
