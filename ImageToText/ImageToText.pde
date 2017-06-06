// This program imports a jpg image file and convert it to an array of rgb values 
// and save it to a text file. 
// Written by Thanky To
// For more detailed instructions and examples, please visit https://github.com/ThankyTo/Light-Painting-Stick/

PImage img;
PrintWriter output;

int width;
int height;

//Declare image file name here
String imageFile = "1";

void setup() {
  img = loadImage(imageFile + ".jpg");
  output = createWriter(imageFile + ".txt");
  width = img.width;
  height = img.height;
}

void draw() {
  loadPixels(); 
  img.loadPixels(); 
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      int pixel = x + y*width;
      int r = int(red(img.pixels[pixel]));
      int g = int(green(img.pixels[pixel]));
      int b = int(blue(img.pixels[pixel]));
      output.print(r + "," + g + "," + b);
      output.println();
    }
  }
  updatePixels();
  output.flush(); 
  output.close(); 
  exit(); 
}