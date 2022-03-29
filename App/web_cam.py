from flask import Flask , request , Response
from flask_cors import CORS
from flask import jsonify
from Camera import VideoCamera
from Line_detection.lane import detect 

# Create flask & cors instance 
app = Flask(__name__)
cors = CORS()
frame = VideoCamera()
cors.init_app(app)

state={"direction": "L"}

@app.route('/video_feed',methods=['POST'])
def video_feed():

     request_data = request.get_json()
     mode= request_data["mode"]
     direction=request_data["direction"]

     if mode == "Automatic" :
          frame.get_frame()
          angle, direction= detect()
          print(direction,angle)
          state= {"mode":mode, "direction":direction}

     else:
          if direction != None:
               state= {"mode":mode,"direction":direction}
     
     return state 

# Serving ESP GET request 
@app.route('/direction',methods=["GET"])
def send_direction():
           return state["direction"]


if __name__ == "__main__":
    app.run(host='0.0.0.0', port= 8090,debug=True)
    	
