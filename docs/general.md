# General

The library base the references in two axis called X and Y, where X is the column and Y the row with the origin
in the left/top. NCurses use a different notation so it is important to not to confuse when you are designing
your app.

![NCI Axis](https://media.githubusercontent.com/media/vgonisanz/nci/master/docs/images/nci_axis.png)

![test image](images/nci.png)
![test image 2](./images/nci.png)
![test image 3](/images/nci.png)
![test 4](https://vgonisanz.github.io/nci/images/nci.png)

## General requirements

* REQ-GEN-001: Every feature and property of this library shall have a requirement with an unique description.
* REQ-GEN-002: GMock will test all features covered with these requirements.
* REQ-GEN-003: All classes will be nci namespace.
* REQ-GEN-004: The whole library shall be exception free. Raise them is not allowed. If something is detected as
  bad value or exist a rending problem, a warning should be display.
* REQ-GEN-005: The library should use a best effort policy. Correct display is not guaranteed if not enough space
  is given or coordinates are incorrect.
* REQ-GEN-006: The library shall support 256 colors.
* REQ-GEN-007: The library shall use by default user terminal font and colors.
* REQ-GEN-008: The library shall support Unicode Characters.
* REQ-GEN-009: The system of reference is x = column number, y = row number. The 0 is in the left in columns case and top in the row case.
* REQ-GEN-010: Any element that interact with use (focusable) shall look different (or have a visual effect) when it have the focus.
* REQ-GEN-011: A class manager will exist to manage main frame, children frames, general options, and control the scene..
* REQ-GEN-012: A class VirtualFrame is a pure virtual method, parent of all different frame types.
* REQ-GEN-013: A struct Point2D shall determine a x position in the screen and y position in the screen.
* REQ-GEN-014: A struct Size2D shall determine width (columns) and height (row)
