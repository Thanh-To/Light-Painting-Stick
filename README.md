# Light-Painting-Stick

## 1. Overview

    This project is inspired by Adafruit's NeoPixel Painter (https://learn.adafruit.com/neopixel-painter). While the hardware is     similar, the software is completely re-written for improved ease of use, simplied code and wider support of image file extensions. In this project, an image file is converted to an array of RGB values in a txt file using a Processing sketch. The the Arduino will read the text file and display them on the RGB LED strip. The set up can be powered by any USD battery bank or directly to an USD port.
    
    Examples of the images created by this Light Painting Stick can be found here https://www.instagram.com/p/BUUVyVchu4Z/.
    The files to create the above image are also included in this repository.
    
## 2. Materials
  - 1 x Arduino Uno/ Arduino Leonardo
  - 1 x Adafruit NeoPixel Digital RGB 60 LED Strip  (https://www.adafruit.com/product/1461)
  - 1 x Adafruit Assembled Data Logging shield for Arduino (https://www.adafruit.com/product/1141)
  - 1 x USB battery bank
  - 1 x 1 meter long stick
  - 4 x zip ties
  
## 3. Construction and set up
- Step 1. Follow the instructions at https://learn.adafruit.com/adafruit-data-logger-shield/ to install, setup and format the Adafruit Assembled Data Logging shield.
- Step 2. Place the NeoPixel Digital RGB LED Strip on to a meter long stick and secure it with zipties
- Step 3. Assemble the circuit as instructed in the Light Painting Stick schematic. Then connect the circuit to the NeoPixel Digital RGB LED Strip.
  
## 4. Usage
- Step 1. Using a photo editing software, such as Photoshop, GIMP or Paint.NET, resize your image's height to 60 pixels. Then save them as a .jpg image. The files should be re-named as integers starting from 0 and saved in the same folder as ImageToText.pde. This will determines the order in which the image will be displayed on the light painting stick
- Step 2. Run the ImageToText.pde file via processing. Follow the instructions in the file to convert the images to arrays of RGB values in a .txt file.
- Step 3. Transfer the above .txt files to an empty SD card.
- Step 4. Modify the Arduino global variable to the appropriate number of file.
- Step 5. Plug the Ardunio into an USB set up to power the Light Painting Stick.
- Step 6. Set up a camera on a tripod for a long exposure shot, preferably for 10 to 20 seconds. The duration of the exposure depends on the width of your image.
- Step 7. Position the Light Painting Stick up right, press the TRIGGER button, as well as the camera's shutter button at the same time to start light painting. As soon as the TRIGGER button is pressed, walk forward with the camera on your right. Attempt a few times to find out the right walking speed for your setup.
- Step 8. To change to the next image, simply press the SELECT button. The Light Painting Stick will also display the current file number in binary with red as 1 and white as 0. Once the last image is reached, the Light Painting Stick will loop back to the first image.
 
 Good luck! Have fun light painting!
