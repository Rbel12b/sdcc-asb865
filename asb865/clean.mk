# Deleting all files created by building the program
# --------------------------------------------------

clean: mostlyclean
	rm -f *.dep
	rm -f $(ASOBJECTS) $(OBJDIR)/.stamp
	if [ -d $(OBJDIR) ]; then rmdir $(OBJDIR); fi

# Like clean but some files may still exist
# -----------------------------------------
mostlyclean:
	rm -f *core *[%~] *.[oa]
	rm -f .[a-z]*~
	rm -f $(top_builddir)/bin/sdasb865$(EXEEXT)
