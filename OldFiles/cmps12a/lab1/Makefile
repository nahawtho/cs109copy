# A simple Makefile for the HelloWorld program
HelloWorld: HelloWorld.class
	echo Main-class: HelloWorld > Manifest
	jar cvfm HelloWorld Manifest HelloWorld.class
	rm Manifest
	chmod u+x HelloWorld

HelloWorld.class: HelloWorld.java
	javac -Xlint HelloWorld.java

clean:
	rm –f HelloWorld.class HelloWorld

submit: Makefile HelloWorld.java
	submit cmps012a-pt.w17 lab1 Makefile HelloWorld.java
