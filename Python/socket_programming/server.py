"""
Establish an echo server
-----
- The server needs to receive a connection successfully and respond to the client with this information.
- The server then needs to wait and listen until the client disconnects, then it can end the program.
- If the client sends information, it needs to take this information and echo it back to the client.
- With version 2, the program continues running until client sends an exit command.
"""

import socket
import os


ADDRESS = "127.0.0.1"
PORT = 8001
FULL_ADDRESS = (ADDRESS,PORT)

def create_socket():
    try:
        # create the socket
        socket_connection = socket.socket()
        # bind the socket
        socket_connection.bind(FULL_ADDRESS)
        # set it to listen
        socket_connection.listen(5)
        return socket_connection
    except OSError:
        print("Error: OSError encountered")

def connect_with_client(socket_connection):
    try:
        # accept a connection
        conn, addr = socket_connection.accept()
        print(conn, addr)
        # send a confirmation message
        conn.send("Connected successfully. Listening to client...".encode("utf-8"))
        # maybe return the connection?
        return conn,addr
    except OSError:
        print("Error: OSError encountered")

def echo_client(connection):
    try:
        client_input = connection.recv(1024)
        print(f"Rcv'd: {client_input.decode('utf-8')}")
        connection.send(client_input)
    except OSError:
        print("Error: OSError encountered")

s = create_socket()
c,a = connect_with_client(s)
echo_client(c)
s.shutdown(socket.SHUT_RDWR)
s.close()
