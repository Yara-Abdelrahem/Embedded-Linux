import socket

def run_client():
    host = "127.0.0.1"  # Localhost
    port = 12345        # Port number

    # Create a socket object
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Connect to the server
    client_socket.connect((host, port))
    print(f"Connected to server at {host}:{port}")

    # Send messages to the server
    while True:
        print("\nEnter operation and two operands (e.g., + 5 3). Type 'x' as an operand to exit.")
        operation = input("Operation (+, -, *, /): ").strip()
        operand1 = input("Operand 1: ").strip()
        operand2 = input("Operand 2: ").strip()

        if operation.lower() == "x" or operand1.lower() == "x" or operand2.lower() == "x":
            print("Exiting...")
            break
        
        # Send operation and operands to the server
        message = f"{operation} {operand1} {operand2}"
        client_socket.sendall(message.encode())

        # Receive response from the server
        response = client_socket.recv(1024).decode()
        print(f"Server responded: {response}")

    # Close the connection
    client_socket.close()
    print("Connection closed.")

# Run the client
run_client()
