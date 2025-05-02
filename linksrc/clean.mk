# Deleting all files created by building the program
# --------------------------------------------------

clean:
	rm -f *core *[%~] *.[oa]
	rm -f .[a-z]*~
	rm -f *.dep
	rm -rf obj