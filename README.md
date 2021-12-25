# Client-server Unix signals

By sending signals between two processes, a connection can be formed
In this project, using bitwise operations, one program sends symbols to the PID of another program, which in turn receives them on its side

## Technologies

1. C
2. Make

## Launch

1. Build a project using Makefile

   ```sh
   $ make
   ```

2. Start the server, like this:

   ```sh
   $ ./server
   ```

   The terminal will show you the PID of the created process, for example:
      ```sh
      Server started
      PID: 26343
      ```
3. In the second terminal, start the client with two arguments: the server PID and the message you want to send:

   ```sh
   $ ./client <PID> [message]
   ```
