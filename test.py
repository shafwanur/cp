import json
import base64
import requests
import datetime

client_id = "8b0bb0fbdb304a4cbe1c4fd3df74f881"
client_secret = "4212943b7dcc4fe8a698d5e611a71b14"

token_url = "https://accounts.spotify.com/api/token"
method = "POST"

token_data = {
    "grant_type": "client_credentials"
}

client_credentials = f"{client_id}:{client_secret}"
client_credentials_base64 = base64.b64encode(client_credentials.encode())

token_headers = {
    "Authorization": f"Basic {client_credentials_base64.decode()}"
}

r = requests.post(token_url, data = token_data, headers = token_headers)
valid_request = r.status_code in range(200, 299)

if valid_request:
    token_response_data = r.json()
    now = datetime.datetime.now()
    access_token = token_response_data['access_token']
    expires_in = token_response_data['expires_in']
    expires = now + datetime.timedelta(second = expires_in)
