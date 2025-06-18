import socket

server_info = {
    "addr":"127.0.0.1",
    "port":8001
}

# Have a function to connect with server
def connect_to_server():
    try:
        # build the socket
        socket_connection = socket.socket()
    
        # connect to the server
        socket_connection.connect((server_info["addr"],server_info['port']))
        data = socket_connection.recv(1024)
        print(f"Message from server: {data.decode('utf-8')}")
        # return any relevant data
        return socket_connection
    except OSError as e:
        print(f"Error:{e}")
    except:
        print("Another error has occurred within the connect to server.")

# have a function to send to the server
    # also receive the response
def send_message(socket_connection):
    # take input
    uinput = input("Enter a message to send to the server:\n>>> ")
    print(f"Sending data: {uinput}")
    # maybe take the connection info (probably will need this actually)
    # send input to the server
    socket_connection.send(uinput.encode('utf-8'))
    # receive response
    echo_test = socket_connection.recv(1024)
    # print out response
    print(f"Echoed response: {echo_test.decode('utf-8')}")
    
# close

s = connect_to_server()
send_message(s)
s.close()