import socket

# Step 1: Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Step 2: Connect to the server
client_socket.connect(('localhost', 12345))

while True:
    # Step 3: Take input from the user
    message = input("Enter message: ")
    if message.lower() == 'exit':
        break
    
    # Step 4: Send the message to the server
    client_socket.send(message.encode())

    # Step 5: Receive the echoed message
    response = client_socket.recv(1024).decode()
    print(f"Server response: {response}")

# Step 6: Close the client socket
client_socket.close()
