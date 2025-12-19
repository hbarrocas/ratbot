SUPPORT_MAIN_HEIGHT = 7.5;
SUPPORT_ENCODER_HEIGHT = 12;
SUPPORT_ENCODER_ENDS_HEIGHT = 1.5;
PLATE_THICK = 3;

$fn=40;

difference() {
  union() {
    linear_extrude(height=SUPPORT_MAIN_HEIGHT)
      import(file = "wheel-motor-support.dxf", layer = "supports-main");
    translate([0, 0, SUPPORT_MAIN_HEIGHT])
      linear_extrude(height=PLATE_THICK)
      import(file = "wheel-motor-support.dxf", layer = "plate");
    translate([0, 0, SUPPORT_MAIN_HEIGHT + PLATE_THICK])
      linear_extrude(height=SUPPORT_ENCODER_HEIGHT)
      import(file = "wheel-motor-support.dxf", layer = "supports-encoder-1");
    translate([0, 0, SUPPORT_MAIN_HEIGHT + PLATE_THICK + SUPPORT_ENCODER_HEIGHT])
      linear_extrude(height=SUPPORT_ENCODER_ENDS_HEIGHT)
      import(file = "wheel-motor-support.dxf", layer = "supports-encoder-2");
  }
  rotate([-90, 0, 0]) translate([0, -4, 24]) {
    translate([-20, 0, 0]) cylinder(h=6, d=3.5);
    translate([20, 0, 0]) cylinder(h=6, d=3.5);
  }
}


