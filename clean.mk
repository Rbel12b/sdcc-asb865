clean:
	rm -f *core *[%~] *.[oa]
	rm -f .[a-z]*~
	rm -f *.dep
	rm -rf obj
	cd asb865 && $(MAKE) clean
	cd linksrc && $(MAKE) clean
