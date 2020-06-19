all : cs392_log cs392_echoserver cs392_echoclient 

cs392_echoserver : cs392_echoserver.o
	gcc -o cs392_echoserver cs392_echoserver.o cs392_log.o
cs392_echoclient : cs392_echoclient.o
	gcc -o cs392_echoclient cs392_echoclient.o
cs392_echoserver.o : cs392_echoserver.c
	gcc -c cs392_echoserver.c
cs392_echoclient.o : cs392_echoclient.c
	gcc -c cs392_echoclient.c
cs392_log : cs392_log.c
	gcc -c cs392_log.c
clean:
	rm *.o cs392_socket.log cs392_echoserver cs392_echoclient