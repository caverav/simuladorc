##
# Tarea 2 LP
#
# @simulacion

compile:
	gcc -g -o simulacion Animal.c simulacion.c -Wall -Wpedantic -Wextra
run:
	gcc -g -o simulacion Animal.c simulacion.c -Wall -Wpedantic -Wextra  && ./simulacion
clean:
	rm simulacion
memory:
	gcc -g -o simulacion Animal.c simulacion.c -Wall -Wpedantic -Wextra  && valgrind ./simulacion


# end
