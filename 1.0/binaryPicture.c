#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    int width, height, channels;
    unsigned char* img = stbi_load(argv[1], &width, &height, &channels, 0);
    
    if (img == NULL)
    {
        printf("Error in loading the image\n");
        return -1;
    }

    size_t img_size = width * height;
    unsigned char* gray_img = malloc(img_size);
    unsigned char* binary_img = malloc(img_size);

    for (size_t i = 0; i < img_size; i++)
    {
        int gray = 0;
       
        for (int c = 0; c < channels; c++)
        {
            gray += img[i*channels + c];
        }
        gray /= channels;
        gray_img[i] = gray;
        binary_img[i] = gray > 50 ? 255 : 0;
    }

    stbi_write_jpg("gray_image.jpg", width, height, 1, gray_img, 100);
    stbi_write_jpg("binary_image.jpg", width, height, 1, binary_img, 100);

    free(img);
    free(gray_img);
    free(binary_img);

    return 0;
}