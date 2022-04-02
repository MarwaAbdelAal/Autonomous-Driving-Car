from flask import Flask , request , Response
from flask_cors import CORS
from flask import jsonify
from Camera import VideoCamera
from line_detection.lane import detect 

# Create flask & cors instance 
app = Flask(__name__)
cors = CORS()
frame = VideoCamera()
cors.init_app(app)

directions = ['L']

@app.route('/video_feed',methods=['POST'])
def video_feed():

     request_data = request.get_json()
     mode = request_data["mode"]
     direction = request_data["direction"]

     if mode == "Automatic" :
          # frame.get_frame()
          angle, direction = detect()
          print(f'direction: {direction}, angle: {angle}' )
          directions.append(direction)
          state = {"mode": mode, "direction": direction}

     else:
          if direction != None:
               state = {"mode": mode, "direction": direction}
               directions.append(direction)   

     print(state)
     return state

# Serving ESP GET request 
@app.route('/direction',methods=["GET"])
def send_direction():
          print(directions[-1])
          return directions[-1]


if __name__ == "__main__":
    app.run(host='0.0.0.0', port= 8090,debug=True)
    	
