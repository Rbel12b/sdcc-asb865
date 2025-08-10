
all: sdas sdld

include clean.mk

sdas:
	cd asb865 && $(MAKE) all

sdld:
	cd linksrc && $(MAKE) all

install: all
	cd asb865 && $(MAKE) install
	cd linksrc && $(MAKE) install
