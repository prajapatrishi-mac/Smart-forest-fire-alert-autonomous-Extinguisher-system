// SMART FOREST FIRE ALERT SYSTEM
// 3D Enclosure CAD Model
// Units: millimeters

$fn = 64;

// Main dimensions
length = 180;
width = 120;
height = 45;
wall = 3;
base_thickness = 3;

// Mounting settings
post_diameter = 7;
hole_diameter = 3;
post_height = 8;

// Enclosure base
module enclosure_base() {
    difference() {
        // Outer box
        cube([length, width, height]);

        // Hollow interior
        translate([wall, wall, base_thickness])
            cube([
                length - 2*wall,
                width - 2*wall,
                height
            ]);

        // Cable opening
        translate([length/2 - 15, -1, 10])
            cube([30, wall + 2, 12]);
    }

    // Four mounting posts
    for (x = [12, length - 12]) {
        for (y = [12, width - 12]) {
            translate([x, y, base_thickness])
                difference() {
                    cylinder(
                        h = post_height,
                        d = post_diameter
                    );

                    translate([0, 0, -1])
                        cylinder(
                            h = post_height + 2,
                            d = hole_diameter
                        );
                }
        }
    }
}

// Separate lid
module enclosure_lid() {
    difference() {
        cube([length, width, 3]);

        // Screw holes
        for (x = [12, length - 12]) {
            for (y = [12, width - 12]) {
                translate([x, y, -1])
                    cylinder(h = 5, d = hole_diameter);
            }
        }
    }
}

// Choose which part to display:
// "base" = enclosure base
// "lid"  = enclosure lid

part = "base";

if (part == "base") {
    enclosure_base();
} else {
    enclosure_lid();
}
