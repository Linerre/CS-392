# Signals Process

A signal is a notification of an event Event gains attention of the OS, Hardware generated faults/exceptions, Operating system/software generated faults/exceptions, Explicitly by a requesting process to another

Then, the OS stops the application process immediately, sending it a signal a signal handler executes to completion and the a pplication process resumes where it left off.

## Default Actions

By default each signal has a default action associated with it.

- `Term` Default action is to terminate the process.
- `Ign` Default action is to ignore the signal.
- `Core` Default action is to terminate the process and  dump  core.
- `Stop` Default action is to stop the process.
- `Cont` Default  action  is  to  continue the process if it is currently stopped.
- `SIGCHLD` Default action is to ignore the signal.

## Handling Signals

```C
// Examine and change the action to take on receipt of a signal signum
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);

 struct sigaction {
    void (*sa_handler)(int);
    void (*sa_sigaction)(int, siginfo_t *, void *)
    sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer)(void); 
};
```

- `act` New action to take, if not null 
- `oldact` Stores the previous action, if not null

### sa_sigaction

`sa_flags` is a set of bit flags. Setting `SA_SIGINFO` in sa_flags will cause the use sa_sigaction instead of sa_handler. *Never set both sa_handler and sa_sigaction*

### sa_mask

`sa_mask` specifies a set of signals which should be blocked while the signal handler is executing. The signal that caused entering the handler is always blocked, unless the `SA_NODEFER` option is specified.

## Interrupted Function Calls

Certain system calls are interrupted if a signal is delivered while executing them. `EINTR` is returned as error, or errno is set to `EINTR`. Some system calls can be automatically restarted (retried) after the signal handler finishes executing. By setting `SA_RESTART` in sa_flags signal() essentially uses that option by default.

## Sending Signals

### raise()

```C
int raise(int iSig);
```
Commands OS to send a signal of type `iSig` to current process and returns 0 to indicate success, non-0 to indicate failure.

### kill()

```C
int kill(pid_t iPid, int iSig);
```

Sends a `iSig` signal to the process whose id is iPid. Equivalent to `raise(iSig)` when iPid is the id of current process (Note: a better/more accurate function name would be `sendsig()`).
