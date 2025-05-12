import socket

client=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

client.connect(("localhost",3333))

while True:
    msg=input("You: ")
    client.send(msg.encode())
    if msg=="end":
        break
    data=client.recv(1024).decode()
    print(f"Server: {data}")

client.close()