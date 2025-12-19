KEY_HEIGHT = 5;
MAGNET_HEIGHT = 2;

$fn = 40;

linear_extrude(height=KEY_HEIGHT)
  import(file = "wheel-encoder-magnet-fitting.dxf", layer = "key");
  translate([0, 0, KEY_HEIGHT])
linear_extrude(height=MAGNET_HEIGHT)
  import(file = "wheel-encoder-magnet-fitting.dxf", layer = "magnet-holder");
