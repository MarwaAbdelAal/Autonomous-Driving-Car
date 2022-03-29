import cv2
from Line_detection.Lib.utils import detect_lane, show_image, display_lines, compute_steering_angle, display_heading_line, detect_direction
import numpy as np
import math

def detect():
        
    frame = cv2.imread('../Server/image.jpg')
    # show_image("Original image", frame)

    lane_lines = detect_lane(frame)
    
    lane_lines_image = display_lines(frame, lane_lines)
    
    print('detected line_segment: \n', lane_lines)
    
    # show_image("lane lines", lane_lines_image)
    
    steeringAngle = compute_steering_angle(frame, lane_lines)
    finalImage = display_heading_line(lane_lines_image, steeringAngle)
    
    print("Steering angle: ", steeringAngle)
    # show_image("Route", finalImage)
    direction = detect_direction(frame)
    print('direction: ', direction)

    return steeringAngle , direction
