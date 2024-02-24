# Binary Picture Generator

This is a small program in C for generating binary pictures from normal images.

Currently it only outputs an image with pixels of either black or white. However I will later add functionality for actually replacing the pixels with 1s and 0s. Possibly allowing the user to specify which characters they would like to use or colors for conversion, down the road.

## Why?

Because it's fun.

## Image after converted to gray-scale
![Gray-scale Image](images/128/gray_image.jpg)

## Converted to binary from gray-scale
Pixels of RGB value < 128 converted to black  
Pixels of RGB value > 128 converted to white

![Binary Image](images/128/binary_image.jpg)

Pixels of RGB value < 50 converted to black  
Pixels of RGB value > 50 converted to white

![Binary Image](images/50/binary_image.jpg)