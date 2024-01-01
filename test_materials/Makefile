CFLAGS = -Wno-implicit-function-declaration


all: final

final: hello.o main.o
	@echo "FINAL-LINKAGE-OF-MODULES"
	@gcc $(CFLAGS) main.o hello.o -o final
	@chmod +x final

hello.o: hello.c
	@echo "hello:MODULE-COMPILATION"
	@gcc $(CFLAGS) -c hello.c


main.o: main.c
	@echo "main:MODULE-COMPILATION"
	@gcc $(CFLAGS) -c main.c

clean:
	@echo "CLEANING-REPOSITORY"
	@rm main.o hello.o final

