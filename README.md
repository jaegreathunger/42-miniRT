# miniRT - My First Ray Tracer with miniLibX

## Project Overview

**miniRT** is a project that introduces the fundamentals of ray tracing, a technique used to render 3D images by simulating how rays of light interact with objects in a scene. In this project, a simple ray tracer is developed using **miniLibX**, a lightweight graphical library. The ray tracer renders scenes composed of basic geometric shapes and lighting effects. This project serves as an introduction to computer graphics and demonstrates how mathematical formulas are applied to generate realistic images.

---

## Key Features

- **Program Name**: `miniRT`
- **Core Functionality**:
  - **Ray Tracing**: Implement a simple ray tracing algorithm to render 3D scenes.
  - **Geometric Objects**: Supports rendering of planes, spheres, and cylinders.
  - **Lighting**: Implements ambient and diffuse lighting effects with hard shadows.
  - **Transformations**: Supports translation and rotation for objects, lights, and cameras (except spheres and lights for rotation).
  - **File Input**: The program reads a scene description from a `.rt` file and renders the scene accordingly.

---

## Technical Details

- **Rendering**: The program generates images using ray tracing, producing realistic reflections and shadows for basic objects.
- **Supported Objects**:
  - **Plane**: Defined by a point and a normal vector.
  - **Sphere**: Defined by its center and diameter.
  - **Cylinder**: Defined by its center, axis, diameter, and height.
- **Lighting**:
  - **Ambient Lighting**: Ensures that objects are never fully dark.
  - **Diffuse Lighting**: Adds realism to how light interacts with surfaces.
- **Scene File (.rt)**:
  - The program reads a scene description file in `.rt` format. Each element (camera, light, object) is defined by its parameters in a specific order.
  - Example of a scene description:
    ```txt
    A 0.2 255,255,255
    C -50,0,20 0,0,1 70
    L -40.0,50.0,0.0 0.6 255,255,255
    sp 0.0,0.0,20.6 12.6 255,0,255
    pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
    cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
    ```

- **Window Management**:
  - The rendered image is displayed in a window.
  - The window is responsive, maintaining content when minimized or resized.
  - Exiting the window via the red cross or pressing `ESC` closes the program cleanly.

---

## Bonus Features

In addition to the mandatory features, the following bonus features were implemented:

- **Specular Reflection**: Adds support for specular highlights using the Phong reflection model.
- **Checkerboard Pattern**: Introduces a color disruption effect, such as a checkerboard texture on objects.
- **Colored and Multiple Light Sources**: Supports multiple light sources with different colors for more complex lighting effects.
- **Additional Object Types**: Added support for rendering other second-degree objects like cones.
- **Bump Mapping**: Adds texture details to objects by using bump maps.

---

## Conclusion

The **miniRT** project provided an excellent introduction to ray tracing and computer graphics. By implementing a basic ray tracer from scratch, I gained valuable experience in mathematical modeling, geometric computations, and graphical rendering. This project lays a strong foundation for more advanced computer graphics work in the future.
