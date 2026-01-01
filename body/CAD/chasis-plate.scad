$fn = 50;

CHASIS_PLATE_THICK = 3;
CHASIS_REINF_THICK = 3;

linear_extrude(height=CHASIS_PLATE_THICK)
  import(file = "chasis-plate.dxf", layer = "plate");

translate([0, 0, CHASIS_PLATE_THICK])
  linear_extrude(height=CHASIS_REINF_THICK)
    import(file = "chasis-plate.dxf", layer = "reinforcement");
