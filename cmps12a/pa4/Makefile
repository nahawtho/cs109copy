# Makefile
# Nicholas Hawthorne
# 1536694
# PA4
# simple makefile for the Roots program
Roots: Roots.class
	echo Main-class: Roots > Manifest
	jar cvfm Roots Manifest Roots.class
	rm Manifest
	chmod u+x Roots

Roots.class: Roots.java
	javac -Xlint Roots.java

clean:
	rm Roots.class Roots

submit: Makefile Roots.java
	submit cmps012a-pt.w17 pa4 Makefile Roots.java
