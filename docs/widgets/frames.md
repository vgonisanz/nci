# Frames

Frames are the most basic implementation of a VirtualFrame. Ideally, all widgets must inherit from
this widget but this is optional. It is recommended to inherit your classes from this one and customize
the behavior.

**TODO**: Add example of image

## Frames requirements

* REQ-FRM-001: Any Frame shall implement virtual run function to take the control of its behaviour. The frame
  can let the control in own of its children. When the actions are completed, the control is returned to the caller.
* REQ-FRM-002: Any Frame shall overrides virtual functions to be drawn. Any special behaviour will be implemented
  on private functions.
* REQ-FRM-003: Any Frame shall contain a map with keybinding to execute an actions for each registered key.
* REQ-FRM-004: Any Frame object shall manage static part of the window.
* REQ-FRM-005: Any Frame shall draw its border if an option is True.
* REQ-FRM-006: Any Element drawable with a custom behaviour shall hierarchy from another Frame class.
* REQ-FRM-007: Class VirtualFrame shall be the parent of all Frame classes.
* REQ-FRM-008: Class VirtualFrame shall determine its position with a struct Point2D and a struct Size2D.
* REQ-FRM-009: Class VirtualFrame shall contain a draw kmethod to draw properly the element according its coordinates.