default:
	gcc pgen.c -o pgen
clean:
	rm pgen
install:
	mv pgen /usr/bin/pgen
