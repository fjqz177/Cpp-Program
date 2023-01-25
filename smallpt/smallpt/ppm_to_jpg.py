from PIL import Image
 
img = Image.open("image.ppm")
img.save("image.png",quality = 100)
img.show()