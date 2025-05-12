import socket

server=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

server.bind(("localhost",3333))
server.listen(1)
print("Server is listening...")

conn,add=server.accept()
print(f"Connected to {add}")

while True:
    data=conn.recv(1024).decode()
    print(f"Client : {data}")
    if data=="end":
        break
    msg=input("You: ")
    conn.send(msg.encode())

server.close()