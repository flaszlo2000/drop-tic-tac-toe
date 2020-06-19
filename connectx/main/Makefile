#@author Levente Löffler

bin:=../connectx
src:=main.c
obj:=$(patsubst %.c, %.o, $(src))
dep:=$(patsubst %.c, %.d, $(src))

cppflags:=-I../libdisplay -I../libinit -I../libmap_check -I../libturn -I../data $(CPPFLAGS)
ldflags:=-L../libdisplay -L../libinit -L../libmap_check -L../libturn $(LDFLAGS)
ldlibs:=-ldisplay -linit -lmap_check -lturn $(LDLIBS)

all: $(bin)

$(bin): $(obj)
	$(CC) $(CFLAGS) $(ldflags) $^ $(ldlibs) -o $@
	
$(obj): %.o: %.c
	$(CC) -c $(cppflags) $(CFLAGS) $< -o $@
	
$(dep): %.d: %.c
	$(CC) $(cppflags) -MM $< -MF $@
	
clean:
	rm -rf $(bin) $(obj) $(dep)
	
.PHONY: all clean

include $(dep)