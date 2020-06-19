#@author Levente Löffler

dirs:= libturn libdisplay libinit libmap_check main

all prog test clean:
	@for sub in $(dirs); do $(MAKE) -C $$sub $@; done
	
.PHONY: all test clean