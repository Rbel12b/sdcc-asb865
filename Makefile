
all: sdas sdld

include clean.mk

sdas:
	cd asb865 && $(MAKE) all

sdld:
	cd linksrc && $(MAKE) all