CXX = gcc
OBJS = cs392_exec.o cs392_log.o cs392_signal.o cs392_shell.o
TARGET = cs392_shell

cs392_shell: $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

cs392_shell.o: cs392_shell.c
	$(CXX) -o cs392_shell.o -c cs392_shell.c

cs392_exec.o: cs392_exec.c
	$(CXX) -o cs392_exec.o -c cs392_exec.c

cs392_log.o: cs392_log.c
	$(CXX) -o cs392_log.o -c cs392_log.c

cs392_signal.o: cs392_signal.c
	$(CXX) -o cs392_signal.o -c cs392_signal.c

clean:
	$ rm *.o cs392_shell cs392_shell.log