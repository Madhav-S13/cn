from http.server import SimpleHTTPRequestHandler, HTTPServer

ip,port="localhost",3030

server=HTTPServer((ip,port),SimpleHTTPRequestHandler)

print(f"Server running on http://{ip}:{port}")
server.serve_forever()