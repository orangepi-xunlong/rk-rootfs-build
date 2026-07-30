#!/bin/bash

./yolov5 model/yolov5.nb input_data/dog.jpg
./yolov5_bench model/yolov5.nb input_data/dog.jpg 100
