import socket

# Step 1: Create a socket object
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Step 2: Bind the socket to a host and port
server_socket.bind(('localhost', 12345))

# Step 3: Listen for incoming connections
server_socket.listen(5)
print("Server listening on port 12345...")

while True:
    # Step 4: Accept client connection
    client_socket, addr = server_socket.accept()
    print(f"Connection from {addr}")

    # Step 5: Receive and echo the message
    while True:
        message = client_socket.recv(1024).decode()
        if not message:
            break
        print(f"Received: {message}")
        client_socket.send(message.encode())  # Echo the message back
    
    # Close the client socket
    client_socket.close()
