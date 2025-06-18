import socket

# Create and bind a socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', 8080))
server_socket.listen(5)

print("Server is listening on port 8080...")
conn, addr = server_socket.accept()
print(f"Connection established with {addr}")
conn.close()
server_socket.close()


