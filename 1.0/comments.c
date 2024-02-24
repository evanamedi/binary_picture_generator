#define STB_IMAGE_IMPLEMENTATION    // Define macro for stb_image implementation
#include "stb_image.h"  // Include the stb_image header

#define STB_IMAGE_WRITE_IMPLEMENTATION  // Define macro for stb_image_write implementation
#include "stb_image_write.h"    // Include te stb_image_write header

int main(int argc, char** argv) // Main function, entry point of the program
{
    if (argc != 2)  // If the number of command-line arguments is not 2
    {
        printf("usage: DisplayImage.out <Image_Path>\n");   // Print usage message
        return -1;  // Exit with status -1
    }

    int width, height, channels;    // Declare variables for image dimensions and channels
    unsigned char* img = stbi_load(argv[1], &width, &height, &channels, 0);    // Load Image and get its data
    
    if (img == NULL)    // If the image data is NULL (image loading failed)
    {
        printf("Error in loading the image\n");    // Print error message
        return -1;    // Exit with status -1
    }

    size_t img_size = width * height;   // Calculate image size (total number of pixels)
    unsigned char* gray_img = malloc(img_size);    // Allocate memory for grayscale image
    unsigned char* binary_img = malloc(img_size);    // Allocate memory for binary image

    for (size_t i = 0; i < img_size; i++)   // For each pixel in the image
    {
        int gray = 0;   // Initialize grayscale value
        
        for (int c = 0; c < channels; c++)    // For each color channel
        {
            gray += img[i*channels + c];    // Add the color value to the grayscale value
        }
        gray /= channels;   // Average the grayscale value
        gray_img[i] = gray;    // Store the grayscale value in the grayscale image
        binary_img[i] = gray > 50 ? 255 : 0;    // Store a black or white value in the binary image
    }

    stbi_write_jpg("gray_image.jpg", width, height, 1, gray_img, 100);    // Write the grayscale image to a file
    stbi_write_jpg("binary_image.jpg", width, height, 1, binary_img, 100);    // Write the binary image to a file

    free(img);    // Free the memory for the original image
    free(gray_img);    // Free the memory for the grayscale image
    free(binary_img);    // Free the memory for the binary image

    return 0;    // Return 0 to indicate success
}