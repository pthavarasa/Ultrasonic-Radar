import serial
import time
from flask import Flask, render_template
from flask_socketio import SocketIO, emit

app = Flask(__name__)
socketio = SocketIO(app)

arduino = serial.Serial(port='COM4', baudrate=115200, timeout=.1)

def write_read():
    time.sleep(0.05)
    data = arduino.readline()
    return data

@app.route('/')
def index():
    return render_template('index.html')

@socketio.on('request_data')
def handle_request():
    while True:
        time.sleep(0.03)
        value = arduino.readline().decode().strip()
        print(value)
        socketio.emit('data_update', value)

if __name__ == '__main__':
    socketio.run(app)
