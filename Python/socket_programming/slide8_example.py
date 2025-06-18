import socket

# Create an IPv4 TCP socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

print("Socket created:", s)
s.close()  # Close the socket


