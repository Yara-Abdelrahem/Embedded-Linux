import socket

def run_server():
    host = "127.0.0.1"  # Localhost
    port = 12345        # Port number

    # Create a socket object
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Bind the socket to the address and port
    server_socket.bind((host, port))

    # Listen for incoming connections
    server_socket.listen(1)
    print(f"Server is listening on {host}:{port}...")

    # Accept a connection
    conn, addr = server_socket.accept()
    print(f"Connected by {addr}")

    # Communicate with the client
    while True:
        data = conn.recv(1024).decode()  # Receive data
        if not data:
            break

        print(f"Received from client: {data}")

        # Parse the received data (operation and operands)
        try:
            operation, op1, op2 = data.split()
            if op1.lower() == "x" or op2.lower() == "x":
                print("Connection closing on client request...")
                break

            op1 = float(op1)
            op2 = float(op2)

            # Perform the operation
            if operation == "+":
                result = op1 + op2
            elif operation == "-":
                result = op1 - op2
            elif operation == "*":
                result = op1 * op2
            elif operation == "/":
                result = op1 / op2 if op2 != 0 else "Error: Division by zero"
            else:
                result = "Error: Unsupported operation"

        except ValueError:
            result = "Error: Invalid input format"

        # Send the result back to the client
        conn.sendall(str(result).encode())

    # Close the connection
    conn.close()
    print("Connection closed.")

# Run the server
run_server()
