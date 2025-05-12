import socket

domain="youtube.com"

ip=socket.gethostbyname(domain)
print(f"IP Address:{ip}")

name=socket.gethostbyaddr(ip)
print(f"Name:{name}")