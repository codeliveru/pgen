default:
	gcc pwgen.c -o pwgen
clean:
	rm pwgen
install:
	mv pwgen /usr/bin/pwgen
