import socket

# Server-side: Sending data
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', 8080))
server_socket.listen(1)
conn, addr = server_socket.accept()

conn.send(b'Hello, Client!')
conn.close()
server_socket.close()

# Client-side: Receiving data
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('localhost', 8080))

data = client_socket.recv(1024)
print("Received from server:", data.decode())
client_socket.close()
