all:
	@javac *.java

edit:
	@vim Main.java

clean:
	@rm *.class

run:
	@java Main

