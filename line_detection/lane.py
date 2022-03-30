import cv2
from lib.utils import detect_lane, show_image, display_lines, compute_steering_angle, display_heading_line, detect_direction

def detect():
        
    # frame = cv2.imread('./images/road1_240x320.jpeg')
    frame = cv2.imread('../images/image5.jpg')
    show_image("Original image", frame)

    lane_lines = detect_lane(frame)
    lane_lines_image = display_lines(frame, lane_lines)
    show_image("lane lines", lane_lines_image)
    
    steeringAngle = compute_steering_angle(frame, lane_lines)
    finalImage = display_heading_line(lane_lines_image, steeringAngle)
    show_image("finalImage", finalImage)
    
    direction = detect_direction(frame)
    print('direction: ', direction)

# if __name__ == '__main__':
    # main()
    
detect()