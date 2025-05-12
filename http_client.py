import requests

res=requests.get("http://localhost:3030")
print(f"Status: {res.status_code}")
print(f"Response:\n{res.text}")