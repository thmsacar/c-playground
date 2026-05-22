# About this repo

I just finished my second year at university and wanted to keep leveling up my skills. One day, I stumbled upon the *3D-to-2D projection formula*. It looked simple enough, and I wanted to test it out immediately. 

Since I was implementing such a fundamental concept entirely from scratch, I wanted full control over everything using a low-level language. That’s why I chose **C** for this repository. The biggest win here was definitely sharpening my low-level programming skills.

---

### The Journey 

* **The Foundation:** I started by projecting a single 3D point onto a 2D plane. Then, using rotation and transformation formulas, I managed to translate and rotate that point around the axes. 
* **The Spinning Cube:** From there, everything clicked. I built a spinning cube. It might look ordinary to some, but seeing that cube spin, knowing I built it from the ground up, was incredibly exciting. I’ve used modern 3D engines before, but building this from scratch felt way more rewarding.
* **Renderer Library:** After that, I refactored my functions into a reusable renderer library so I could easily use the same foundation across different files. To test it, I recreated the iconic *Windows 95 Starfield screensaver*.
* **Spatial Transformation Matrices:** To make rotations and transformations cleaner, I built a custom $4 \times 4$ linear algebra library from scratch. Instead of using separate, hardcoded functions for translation and rotation, everything is now handled by compounding transformation matrices and applying them to homogenic 3D coordinates.

---

### What I Learned 🎓

* **Memory Management:** Learned to balance stack vs. heap tradeoffs. Avoided dynamic allocation to ensure high CPU cache locality and completely eliminate memory leaks.
* **Applied Linear Algebra:** Took textbook math off the page and used it in real life. Combined $4 \times 4$ matrices and homogeneous coordinates into a single pipeline to control 3D space.
* **Vector Math:** Moved textbook vectors into live 3D space. Used dot products for depth and projection calculations, setting up the exact math needed for lighting and surface normals.

---

### What's Next?

Now that the mathematical foundation is solid and modular, the training wheels are coming off. The next challenge is transforming these wireframes into solid 3D objects. To achieve this, I am diving into:

* **Backface Culling & Polygon Sorting:** Implementing cross-product mathematics to determine face normals, ensuring the renderer only draws polygons facing the camera while sorting depth to prevent visual glitches.
* **Flat Shading:** Calculating dot products between surface normals and a dynamic light source vector to compute real-time lighting and shadows entirely on the CPU.

--
*TBC*