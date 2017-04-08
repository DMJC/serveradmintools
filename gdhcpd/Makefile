gdhcpcd:
	clang -rdynamic `pkg-config --libs --cflags gtk+-3.0` gdhcpd.c gui.c input.c output.c callbacks.c manipulate.c -o gdhcpd 
clean:
	rm gdhcpd
