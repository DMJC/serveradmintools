gtftpd:
	clang `pkg-config --libs --cflags gtk+-3.0` -rdynamic gtftpd.c input.c gui.c output.c -o gtftpd

clean:
	rm gtftpd
