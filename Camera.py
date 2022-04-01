import numpy as np
import requests
import cv2

class VideoCamera():
    def __init__(self):
        
    # Replace the below URL with your own. Make sure to add "/shot.jpg" at last.
      #  self.url = "http://172.28.131.140:8080/shot.jpg"
       self.url = "http://172.28.132.212:8080/shot.jpg"
      
   
       
    def get_frame(self):

            img_resp = requests.get(self.url)
            img_arr = np.array(bytearray(img_resp.content), dtype=np.uint8)
            img = cv2.imdecode(img_arr, -1)

            # img = imutils.resize(img, width=1000, height=1800)

            cv2.imwrite('image'+'.jpg', img)
            cv2.destroyAllWindows()
