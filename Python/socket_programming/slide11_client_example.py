import socket

# Create a client socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    # Connect to the server
    client_socket.connect(('localhost', 8080))
    print("Connected to the server.")
except ConnectionRefusedError:
    print("Connection failed. Is the server running?")
finally:
    client_socket.close()  # Always close the socket


