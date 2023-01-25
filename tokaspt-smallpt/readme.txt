http://code.google.com/p/tokaspt/
contact: tbptbp@gmail.com

Usage: ./tokaspt [-w width] [-h height] [filename]
If no filename is provided and if a valid 'default.scene' exist in the current directory, it's loaded; otherwise a builtin scene is used.

Vague description: spppp samples are accumulated ad vitam (per pass, per pixel) into a buffer, a gamma and conversion pass produces another smaller buffer which is then used to texture. So, due to the limited precision of the accumulation, more spppp is better (but slower). Note that rendering more sample per pixel per pass, also require allocating more memory for PRNG's states. The 'spp' statistic, next to fps, represents the current total of per pixel samples.
Each sample is limited to a deph of 'max paths', more being, obviously, better and, obviously again, way slower.

Sliders have limited precision and range, but every modifyiable floating point value has a button next to it which enables a manual input something (updates as you type, if you can't get rid of it, simply re-click the button that made it appear).

Window will resist being resized in non multiple of tile dimensions (current 256x256), and will not exceed current desktop dimensions either (not multi-monitor friendly i suppose).

kbd:
. u: toggles full 3D ui (otherwise only selection is augmented).
. q, esc: exit.
. z: zero sample accumulation buffer.
. p: unfold the parameter panel.
. s: enable/disable sphere parameter panel.
. arrows, pg-up/pg-down: move the camera (ctrl faster, shift slower).
. e: englobe the scene with... take a guess... a (templated) sphere.
. w: wipes the scene (hit twice in succession).
. +,-: cycle selection among spheres.
. del: delete selection.
. backspace: clear selection.
. home: look at selection.
. x: cycle world up.
. ctrl-c/ctrl-v: copy/paste current selection, clipboard content serves
                 as a template for all forms of sphere creation.
. F5/F9: save/load the whole scene and camera settings.


mouse: left button is for changing camera's direction and spawning spheres, middle to move camera, right to select and modify spheres.
. left: 
  . put the point clicked at the center of the camera.
  . [alt] spawn a (templated) sphere.
. middle
  . drag, move in the 'screen' plane.
  . [shift] drag, other plane.
. right
  . picking
  . [ctrl] drag, modify selection's radius.
  . [alt] drag, move selection in 'screen' plane.
  . [alt+shift] drag, move selection in the other plane.
