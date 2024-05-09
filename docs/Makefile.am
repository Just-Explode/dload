## Helder Correia <helder.correia@netcabo.pt>
## Modified by Just_Explode <explodedbruh@gmail.com>

man1_MAN = dload.1

install:
	$(mkinstalldirs) $(DESTDIR)$(mandir)/man1
	$(INSTALL_DATA) $(top_builddir)/docs/$(PACKAGE).1 $(DESTDIR)$(mandir)/man1
	gzip -f $(DESTDIR)$(mandir)/man1/$(PACKAGE).1

uninstall:
	rm $(DESTDIR)$(mandir)/man1/$(PACKAGE).1.gz
