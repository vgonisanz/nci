# Interfaces Manager

The interface manager is a special frame with additional methods in order to operate the scene
in a high level way. In example, you can use its static methods to check the size or status
of the standard screen. Also, you can force the redraw of all children if you need it (this is
useful when you invoke a popup or another element in front of the scene and you want to restore
it)

This class shall be initialize in the beggining and shall be the last to be destroyed. All static
methods are secure to use in any moment.

NCI define a pure virtual class to manage rendeable elements. This class is the `VirtualFrame`.

**TODO**: Add example of image

## Requirements

* REQ-IM-001: The manager shall draw all VirtualFrame in the whole interface.
* REQ-IM-002: The manager shall store all VirtualFrames in a stack.
* REQ-IM-003: The manager shall call draw in order, the high positions elements in the
  stack (>) will override low position elements (<).
* REQ-IM-004: The manager shall call to run function for the current active Frame. This
  logic shall take the control of the execution until the object return the control to the manager again.