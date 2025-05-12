import socket

server=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

server.bind(("localhost",4567))
print("Server is ready...")

while True:
    data,add=server.recvfrom(1024)
    print(f"Client: {data.decode()}")
    if data.decode()=="end":
        break
    msg=input("You: ")
    server.sendto(msg.encode(),add)

server.close()