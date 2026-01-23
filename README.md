# Raytracer

A simple raytracer implementation in C that renders a realistic 3D sphere with advanced lighting and anti-aliasing.

## Features

- **Ray-Sphere Intersection**: Accurate geometric intersection calculations using quadratic equations
- **Surface Normals**: Proper normal vector calculation for realistic shading
- **Phong Lighting Model**: 
  - Ambient lighting for base illumination
  - Diffuse lighting for matte surfaces
  - Specular highlights for shininess
- **Anti-aliasing**: Multi-sample per pixel rendering (32 samples) for smooth edges
- **PPM Image Output**: Renders to standard PPM image format

## Technical Details

### Lighting
- Light source positioned at (2, 2, 0)
- Ambient coefficient: 0.2
- Specular shininess: 64
- Combines diffuse and specular reflections for realistic appearance

### Camera
- Position: (0, 0, 0)
- Field of view: 90°
- Image resolution: 400x225 pixels

### Scene
- Single sphere at (0, 0, -1) with radius 0.5
- Gradient blue background

## Building
```bash
gcc main.c types/*.c utils/*.c -o raytracer
```

## Running
```bash
./raytracer
```

Outputs `test.ppm` in the current directory.

## Output

The raytracer produces a photorealistic sphere with:
- Smooth color gradients based on surface normals
- Bright specular highlight showing light reflection
- Anti-aliased edges for professional quality
- Gradient sky background

## Implementation Highlights

- Custom 3D vector math library (vec3)
- Intersection struct for ray-object hit detection
- Modular design with separate types for camera, sphere, and ray
- Random sampling for anti-aliasing with configurable sample count

## Future Enhancements

Possible extensions:
- Multiple objects and object types
- Shadows via shadow rays
- Reflections and refractions
- Texture mapping
- Different material properties
- More light sources
