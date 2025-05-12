import socket

client=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

ip,port="localhost",4567

while True:
    msg=input("You: ")
    client.sendto(msg.encode(),(ip,port))
    if msg=="end":
        break
    data,add=client.recvfrom(1024)
    print(f"Server: {data.decode()}")
client.close()