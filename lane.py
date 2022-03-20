import cv2
from lib.utils import detect_lane, show_image, display_lines

def main():
        
    frame = cv2.imread('./images/road1_240x320.jpeg')
    show_image("Original image", frame)

    lane_lines = detect_lane(frame)
    
    lane_lines_image = display_lines(frame, lane_lines)
    
    print('detected line_segment: \n', lane_lines)
    
    show_image("lane lines", lane_lines_image)

if __name__ == '__main__':
    main()