#@author Levente Löffler

libname:=init
lib:=lib$(libname).a
src:=init.c
obj:=$(patsubst %.c, %.o, $(src))

test:=utest
tsrc:=utest.c utest-$(libname).c
tobj:=$(patsubst %.c, %.o, $(tsrc))

dep:=$(patsubst %.c, %.d, $(src) $(tsrc))

cppflags:=-I../data -I../libturn $(CPPFLAGS)
ldlibs:=-lcunit -lturn -l$(libname)
ldflags:=-L. -L../libturn

all: $(lib)

test: $(test)
	./$<
	
$(test): $(tobj) $(lib)
	$(CC) $(CFLAGS) $(ldflags) $^ $(ldlibs) -o $@

$(lib): $(obj)
	$(AR) $(ARFLAGS) $@ $^
	
$(obj) $(tobj): %.o: %.c
	$(CC) $(cppflags) $(CFLAGS) -c $< -o $@
	
$(dep): %.d: %.c
	$(CC) $(cppflags) -MM $< -MF $@
	
clean:
	rm -rf $(lib) $(test) $(tobj) $(obj) $(dep)
	
.PHONY: all clean

include $(dep)